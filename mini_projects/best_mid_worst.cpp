#include <iostream>

using namespace std;

int cnt=0;
int lp, lk, lm, np, nk, nm;

void best(int& n, int& l)
{
    while(l>0)
    {
        if(n>0)
        {
            if(n==1) cnt++;
            else cnt+=2;
            l--;
            n-=2;
        }
        else break;
    }
}

void mid(int& n, int& l)
{
    while (l>0)
    {
        if(n>0)
        {
            l--;
            n--;
            cnt++;
        }
        else break;
    }
}

void worst(int& n, int& l)
{
    while(l>1)
    {
        if(n>0)
        {
            l-=2;
            n--;
            cnt++;
        }
        else break;
    }
}

int main()
{
    cin>>np>>nk>>nm>>lp>>lk>>lm;

    best(np,lm);    best(nk,lp);    best(nm,lk);
    mid(np,lp);    mid(nk,lk);    mid(nm,lm);
    worst(np,lk);    worst(nk,lm);    worst(nm,lp);

    cout<<cnt;
}
