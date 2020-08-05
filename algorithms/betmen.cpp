#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    stack<int> zgrade;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        if(zgrade.empty()){
            cout<<" - ,";
            zgrade.push(x);
        }
        else if(x<zgrade.top()){
            cout<<zgrade.top()<<" ,";
            zgrade.push(x);  
        }
        else if(x>=zgrade.top()){
            while(!zgrade.empty() && x>=zgrade.top()){
                zgrade.pop();
            }
            if(zgrade.empty())
                cout<<" - ,";
            else 
                cout<<zgrade.top()<<" ,";
            
            zgrade.push(x);
        }
    }

}