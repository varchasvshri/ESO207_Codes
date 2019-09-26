#include <bits/stdc++.h>
using namespace std;
typedef long long int ll; 

int prec(char a)
{
    if(a=='^') return 3;
    else if(a=='*'||a=='/') return 2;
    else if(a=='+'||a=='-') return 1;
    else return 0;
}

int main() {
    string str;cin>>str;
    stack <char> s;
    string out;
    for(int i=0;i<str.length();i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z')||(str[i] >= 'A' && str[i] <= 'Z')||(str[i]>='0' && str[i]<='9')) out.push_back(str[i]); //operand is scanned
        else if(str[i]=='(') s.push('(');
        else if(str[i]==')')
        {
            while(s.top()!='(')
            {
                out.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else // operator is scanned
        {
            while(!s.empty() && prec(s.top())>=prec(str[i]))
            {
                out.push_back(s.top());
                s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.empty())
    {
        out.push_back(s.top());
        s.pop();
    }
    cout<<out;
    return 0;
}