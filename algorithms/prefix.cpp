#include <iostream>
#include <vector>
#include <string>
using namespace std;

string nadjiPre(const string& post, const string& inf){
    if(post=="" && inf=="")
        return "";
    
    char koren=post[post.size()-1];
    size_t levo=inf.find(koren);
    size_t desno=inf.size()-levo-1;
    string in_levo=inf.substr(0,levo);
    string in_desno=inf.substr(levo+1,desno);
    string post_levo=post.substr(0,levo);
    string post_desno=post.substr(levo,desno);
    return koren+nadjiPre(post_levo,in_levo)+nadjiPre(post_desno,in_desno);
}

int main(){
    string post,inf;
    cin>>post>>inf;
    cout<<nadjiPre(post,inf)<<endl;






return 0;
}