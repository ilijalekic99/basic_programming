#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 1. nacin
//    int a,b,c;
//    cin >>a>>b>>c
//    string s;
//    cin >> s;
//    int maxi,mini,srednji;
//    maxi=max(a,max(b,c));
//    mini=min(a,min(b,c));
//    srednji=a+b+c-maxi-mini;
//    if (s == "ABC"){
//        cout << mini << " " << srednji << " " << maxi;
//    }
//   + 4 ifa

    int niz[3];
    for (int i = 0; i < 3; i++){
        cin >> niz[i];
    }
    string s;
    cin >> s;
    sort(niz, niz + 3);
    for (int i = 0; i < 3; i++){
        cout << niz[s[i]-'A'] << " ";
    }
}
