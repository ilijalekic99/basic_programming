#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void f(int *a,int n){
    int i=0;
    while(i<n){
        int j=a[i];
        if(j==i)
            i++;
        else
            swap(a[i],a[j]);
    }

}
void raz(int *a,int n){
    for(int i=0;i<(n-1);i++){
        int p=a[i];
        int q=a[i+1];
        if((q-p)==0)
            cout<< p <<endl;
        else if((q-p)>1)
            cout << p <<endl;
}

}

int main(){
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    f(a,n);
    raz(a,n);


return 0;
}