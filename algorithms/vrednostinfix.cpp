#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

void operacija(stack<int>& operandi,stack<char>& operatori){
    int op1=operandi.top();
    operandi.pop();
    int op2=operandi.top();
    operandi.pop();
    char op=operatori.top();
    operatori.pop();
    int v;
    if(op=='+')
        v=op1+op2;
    else if(op=='*')
        v=op1*op2;
    operandi.push(v);
    //cout<<endl << v <<endl;
}
int main(){

    string izraz;
    cin>>izraz;
    stack<int>broj;
    stack<char>znak;
    for(char c:izraz){
        if(isdigit(c))
            broj.push(c-'0');
        else if(c=='(' || c=='*')
            znak.push(c);
        else if(c==')'){
            while(znak.top()!='(')
                operacija(broj,znak);
            znak.pop();
        }
        else{
            while(!znak.empty() && znak.top()=='*')
                operacija(broj,znak);
            znak.push(c);
        }
    }
    while(!znak.empty())
        operacija(broj,znak);


    cout<<broj.top()<<endl;

}