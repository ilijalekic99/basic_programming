#include <iostream>

using namespace std;

int toDec(string s, int baza)
{
    int rez=0,stepen=1;
    for(int i=s.size()-1;i>=0;i--){
        rez+=(s[i]-'0')*stepen;
        stepen*=baza;
    }
    return rez;
}

int main()
{
    string a,b;
    int deca;
    cin>>a>>b;
    for(int i=0;i<a.size()-1;i++){
        int bit=a[i]-'0';
        if(i==0 && bit==1) continue;
        a[i]=!bit + '0';
        deca=toDec(a,2);
        for(int j=0;j<b.size()-1;j++){
            char pravi=b[j];
            if(j>0){
                b[j]='0';
                if(deca==toDec(b,3)){
                    cout<<deca;
                    return 0;
                }
            }
            b[j]='1';
            if(deca==toDec(b,3)){
                cout<<deca;
                return 0;
            }
            b[j]='2';
            if(deca==toDec(b,3)){
                cout<<deca;
                return 0;
            }
            b[j]=pravi;
        }
        a[i]=bit + '0';
    }
}
