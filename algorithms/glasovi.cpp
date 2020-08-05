#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX (10)

int main(){
    int n,b,max,pom;
    cin>>n;
    cin>>b;
    int a[n];
    for(int i=0;i<b;i++){
        a[i]=0;
        cin>>pom;
        a[pom]++;
    }

    for(int i=0;i<n;i++)
        cout<<a[i]<<endl;

return 0;
}