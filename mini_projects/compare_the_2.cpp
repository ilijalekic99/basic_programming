#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    string a,b;
    cin >> a >> b;
    if (a.size() < b.size()){
        cout << "<";
    }
    if (a.size() > b.size()){
        cout << ">";
    }
    if (a.size() == b.size()){
        bool sviIsti = 1;
        for (int i = 0;i < a.size(); i++){
            if (a[i]!= b[i]){
                if (a[i]>b[i]){
                    cout << ">";
                }
                else {
                    cout << "<";
                }
                sviIsti = 0;
            }
        }
        if (sviIsti)
            cout << "=";
    }
}
