#include <iostream>

using namespace std;

int main()
{
    int sh,sm,h,m,vreme,timer,dan;


    string dani,celaNedelja[7]= {"pon","uto","sre","cet","pet","sub","ned"};

    cin>>dani;


    if(dani=="pon") dan=0;
    if(dani=="uto") dan=1;
    if(dani=="sre") dan=2;
    if(dani=="cet") dan=3;
    if(dani=="pet") dan=4;
    if(dani=="sub") dan=5;
    if(dani=="ned") dan=6;


    cin>>sh>>sm>>h>>m;

    vreme=sh*60+sm;
    timer=h*60+m;

    int celiDani=timer/1440;

    if(vreme+(timer%1440)>=1440)
        celiDani++;
    vreme+=timer;
    vreme%=1440;
    sh= vreme/60;
    sm= vreme%60;

    dan=(dan+celiDani)%7;
    cout<<celiDani<<endl;
    cout<<celaNedelja[dan]<<"   "<<sh<< "   "<<sm<<endl;



}
