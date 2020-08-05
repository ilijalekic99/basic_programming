#include <bits/stdc++.h>

using namespace std;

string f(string i,string p){
    if(i.size()==0 || p.size()==0)
        return "";
    char sred = p[p.size()-1];
    size_t levo = i.find(sred);
    size_t desno = i.size() - levo -1;

    string l_i = i.substr(0,levo);
    string d_i = i.substr(levo+1,desno);
    string l_p = p.substr(0,levo);
    string d_p = p.substr(levo,desno);
    return sred+f(l_i,l_p)+f(d_i,d_p);

}


int main(){
    string p,i;
    cin >> p >> i;
    string prefix;
    prefix = f(i,p);
    cout << prefix << endl;

    return 0;
}