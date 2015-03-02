#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<math.h>
using namespace std;
char chr[20];
struct Word
{
    string str,val;
    Word(string s="",string v=""):str(s),val(v) {}
    bool operator < (Word const & w) const
    {
        if(this->val!=w.val)
        {
            if(this->val.length()==w.val.length())
                return this->val<w.val;
            return this->val.length()>w.val.length();
        }
        return this->str<w.str;
    }
    bool operator ==(Word const &w) const
    {
        return this->val==w.val;
    }
    void output()
    {
        cout<<str<<" "<<val<<endl;
    }
} words[2000];
int cnt=0;

bool getWord()
{
    char tmp=0;
    while(tmp!='"'&&tmp!=EOF)
        tmp=getchar();
    if(tmp==EOF) return false;
    int n=0;
    do
    {
        tmp=getchar();
        chr[n++]=tmp;
    }
    while(tmp!='"');
    chr[n-1]='\0';
    string str(chr);
    sort(chr,chr+n-1);
    string val(chr);
    words[cnt++]=Word(str,val);
    return true;
}
int charValue[128]= {0},chars[20],nchar,ans=0, strValue[10],nstr;
string strs[10];
bool used[10]= {0};
void dfs(int lv=0)
{
    if(lv==nchar)
    {
        int nsquare=0;
        for(int i=0; i<nstr; i++)
        {
            if(charValue[int(strs[i][0])]==0)
                continue;
            strValue[i]=0;
            for(int j=0; j<strs[i].length(); j++)
                strValue[i]=strValue[i]*10+charValue[int(strs[i][j])];
            int tmp=sqrt(strValue[i])+0.5;
            if(tmp*tmp==strValue[i])
                strValue[nsquare++]=strValue[i];
        }
        if(nsquare>1)
            for(int i=0; i<nsquare; i++)
            {
                cout<<strValue[i]<<" ";
                if(ans<strValue[i])
                    ans=strValue[i];
            }
    }
    for(int i=0; i<10; i++)
        if(!used[i])
        {
            used[i]=true;
            charValue[chars[lv]]=i;
            dfs(lv+1);
            used[i]=false;
        }
}

int main()
{
    freopen("p098_words.txt","r",stdin);
    while(getWord());///Read all
    cout<<cnt<<endl;
    sort(words,words+cnt);
    int lenstr=0;
    for(int i=1; i<cnt; i++)
    {
        if(words[i-1]==words[i])
        {
            if(ans!=0&&lenstr>words[i].str.length())
                break;
            lenstr=words[i].str.length();
            nchar=nstr=0;
            chars[nchar++]=words[i].val[0];
            for(int j=1; j<words[i].val.length(); j++)
                if(words[i].val[j]!=words[i].val[j-1])
                    chars[nchar++]=words[i].val[j];
            strs[nstr++]=words[i-1].str;
            while(words[i-1]==words[i])
                strs[nstr++]=words[i++].str;
            for(int i=0; i<10; i++)
                used[i]=false;
            dfs();
            cout<<nstr<<" ";
            words[i].output();
        }
    }
    cout<<"Answer : "<<ans<<endl;
    return 0;
}

/***
18769
***/
