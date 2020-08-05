#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
#define MAX (10)

int kandidat(stack<int>s,bool a[MAX][MAX]){
    for(int p=0;p<=s.size();p++){
    int i=s.top();
    s.pop();
    int j=s.top();
    if(a[i][j])
        s.push(i);
    else
        s.push(j);
}
    return s.top();
}
void proveri(int kandidat,int n,bool a[MAX][MAX]){
    for(int i=0;i<n-1;i++){
        if(a[kandidat][i] && !a[i][kandidat])
        continue;
        else{
        cout << kandidat << "nije super star" << endl;
        return;
    }
    }
        cout<< kandidat <<" jeste";

}

int main(){
    stack<int> stek;
    int n;
    cin>>n;
    bool a[MAX][MAX];
    for(int i=0;i<n;i++){
        stek.push(i);
        for(int j=0;j<n;j++)
        cin>>a[i][j];
    }

int kand=kandidat(stek,a);
proveri(kand,n,a);





}