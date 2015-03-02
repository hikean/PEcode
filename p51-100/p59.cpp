#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define MAXN 10000

char chr[MAXN],key[4],ch;
int data[MAXN],cnt=0,tmp,i;
bool check()
{
    string text(chr);
    if(text.find(".")==string::npos) return false;
    if(text.find(",")==string::npos) return false;
    if(text.find("the")==string::npos) return false;
    if(text.find("that")==string::npos) return false;
    if(text.find("is")==string::npos) return false;
    if(text.find("in")==string::npos) return false;
    if(text.find("to")==string::npos) return false;
    if(text.find("it")==string::npos) return false;
    return true;
}
int main()
{
    freopen("p059_cipher.txt","r",stdin);
    while(cin>>data[cnt++]>>ch);
    chr[cnt]=key[3]='\0';
    for(key[0] = 'a'; key[0]<='z'; key[0]++)
        for(key[1] = 'a'; key[1]<='z'; key[1]++)
            for(key[2] = 'a'; key[2]<='z'; key[2]++) //31 ~126
            {
                for(i=0; i<cnt; i++)
                {
                    chr[i]=(char)(data[i]^(int)key[i%3]|32);
                    if(chr[i]<' '||chr[i]>'~') break;
                }
                if(i==cnt&&check())
                    cout<<key<<endl;
            }
    return 0;
}
