#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
#define MAX (10)

int stepen(int x, int n) {
if (n == 0)
return 1;
return stepen(x, n-1) * x;
}

int vrednostPolinoma(int a[], int n, int x) {
if (n == 0)
return a[0];
return a[n] * stepen(x, n) + vrednostPolinoma(a, n-1, x);
}


int main(){
    int p=0,x,n;
    cin >> x >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    p=vrednostPolinoma(a,n,x);
    cout << p << endl;
    return 0;
}