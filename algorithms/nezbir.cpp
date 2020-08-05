#include <iostream>
#include <vector>
using namespace std;

int najmanjiKojiNijeZbirPodskupa(vector<int> a, int n) {
int mozeDo = 0;
for (int i = 0; i < n; i++) {
if (a[i] > mozeDo + 1)
return mozeDo + 1;
mozeDo += a[i];
}
return mozeDo + 1;
}

int main(){
    int n;
    int x;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        cin>>x;
        a.push_back(x);
    }

   int m=najmanjiKojiNijeZbirPodskupa(a,n);
        cout<<m<<endl;
        





return 0;
}