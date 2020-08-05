#include <bits/stdc++.h>
using namespace std;

int main()
{
    int na,nb;
    int a[100000],b[100000];
    cin >>na>>nb;
    for (int i=0;i<na;i++){
        cin>>a[i];
    }
    for (int i=0;i<nb;i++){
        cin>>b[i];
    }
    sort(a,a+na);
    for(int i=0;i<nb;i++){
        cout<<upper_bound(a,a+na,b[i])-a<<"     ";
    }

}
