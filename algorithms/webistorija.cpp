#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int main(){

    stack<string>istorija;
    string webStranica;
    while (cin>>webStranica)
    {  
        if(webStranica=="back" && !istorija.empty()){
            istorija.pop();
            cout<<istorija.top()<<endl;
    }
        istorija.push(webStranica);
    }







return 0;
}