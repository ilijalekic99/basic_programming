#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void razmeni(int *a,int p1,int p2,int k){
    for(int i=0;i<k;i++)
        swap(a[p1+i],a[p2+i]);
}

void rotacija(int *a,int k,int n){
    k=k%n;
    int l=k;
    int d=n-k;
    if(k==0 || k==n)
         return;
    if(l==d)
        razmeni(a,0,l,k);
    if(l<d){
        razmeni(a,0,l,l);
        rotacija(a+l,d-l,n-l);
    }
    if(l>d){
        razmeni(a,0,l,d);
        rotacija(a+d,l-d,n-d);
    }
    return;
}

int main(){
    int n,k;
    cin >> n;
     int a[n+1];
    cin >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    rotacija(a,k,n);
    
    for(int i=0;i<n;i++)
        cout << a[i] <<endl;


    return 0;
}




