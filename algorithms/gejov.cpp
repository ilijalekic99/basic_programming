#include <iostream>
#include <vector>
using namespace std;

string grejov(int n,int k){
    if(n==0)
    return " ";
    if(k<(1<<(n-1)))
    return "0"+grejov(n-1,k);
    else 
    return "1"+grejov(n-1,(1<<n)-k-1);
}
int main(){
    int n,k;
    cin >> n >> k;
    cout << grejov(n,k)<<endl;


return 0;
}