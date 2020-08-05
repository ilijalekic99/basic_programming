#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

void pisajPo(stack<int>& sirotinja)
{
    int n;  cin>>n;
    int i;
    for(int x=0;x<n;x++){
        cin>>i;
        if(sirotinja.empty()){
           cout<< "- ";
           sirotinja.push(i);
        }
        else if(sirotinja.top()<i){
            cout << sirotinja.top() << " ";
            sirotinja.push(i);
        }
        else if(sirotinja.top()>i){
            while(!sirotinja.empty() && sirotinja.top()>=i){
                sirotinja.pop();
            }
            if(sirotinja.empty())
                cout << "-" << " ";
            else
                cout << sirotinja.top() << " ";
            
            sirotinja.push(i);
        }
    }
    return;
}

int main(){
    stack<int> sirotinji;
    
    pisajPo(sirotinji);

    return 0;
}