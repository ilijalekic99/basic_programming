#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    stack<char>stek;
    string izraz;
    cin>>izraz;
    for(char c:izraz){
        if(c=='(' || c=='{'|| c=='[' )
            stek.push(c);
        if(c==')' || c==']'|| c=='}' ){
            if(stek.empty()){
                cout<<"greska"<<endl;
                exit(EXIT_FAILURE);
            }
            if(c==')' && stek.top()=='(')
                continue;
            else{
            cout<<"greska"<<endl;
            exit(EXIT_FAILURE);}
            if(c=='}' && stek.top()=='{')
                continue;
            else{
            cout<<"greska"<<endl;
            exit(EXIT_FAILURE);}
            
            if(c==']' && stek.top()=='[')
                continue;
           else{
            cout<<"greska"<<endl;
            exit(EXIT_FAILURE);}    
        }  
    }
    cout<<"sve zagrade su uparene" <<endl;


}
