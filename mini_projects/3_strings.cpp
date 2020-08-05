#include <bits/stdc++.h>

using namespace std;

string obrni(string s){
    // 1. nacin
//    string obrnut = s;
//    reverse(obrnut.begin(), obrnut.end());
//    return obrnut;

    // 2. nacin
//    reverse(s.begin(), s.end());
//    return s;

    // 3. nacin
    for (int i = 0; i < s.size() / 2; i++){
        //   a)   swap(s[i], s[s.size() - 1 - i]);

        //   b)

        char c = s[i];
        s[i] = s[s.size()-1-i];
        s[s.size()-1-i] = c;
    }
    return s;
}

int main()
{
    string a,b,c;
    cin>>a>>b>>c;
    string res = "";

    a = obrni(a);
    b = obrni(b);
    c = obrni(c);

    res += a;
    res += b;
    res += c;
    cout << res;
}
