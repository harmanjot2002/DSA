#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int prec(char c){
    if(c == '^') return 3;
    else if(c == '/' || c == '*') return 2;
    else if(c =='+' || c == '-') return 1;
    else return -1;
}

void infiToPre(string s){
    reverse(s.begin(),s.end());
    stack<char> st;
    string result;
    for (int i = 0; i < s.length(); i++){
        char c = s[i];
        if(c <= 'z' && c >= 'a' || c <= 'Z' && c >= 'A'){
            result += c;
        }
        else if(c == ')') 
            st.push(')');
        else if(c == '('){
            while(st.top() != ')'){
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prec(c) <= prec(st.top())){
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(),result.end());
    cout << result << endl;
}


int main(){
    string str = "(x+y*z/w+u)";
    infiToPre(str);
    return 0;
}