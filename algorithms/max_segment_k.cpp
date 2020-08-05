#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,a,maxi;
    int k,zbir=0;
    cin>>n>>k;
    queue<int>red;
    for (int i = 0; i < n; i++)
    {
        cin>>a;
        if(i<k){
            red.push(a);
            zbir+=a;
            maxi=zbir;
        }
        else{
            zbir-=red.front();
            red.pop();
            red.push(a);
            zbir+=a;

            if(zbir>maxi)
                maxi=zbir;
        }
    }
    cout<<maxi<<endl;

    return 0;
}