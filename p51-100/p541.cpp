#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<time.h>
using namespace std;
#define JoinValues(v,x)  ((v<<20)+(x[4]/10<<16)+(x[3]/10<<12)+(x[2]/10<<8)+(x[1]/10<<4)+x[0]/10)
int charValue[128]={0};
int inline getValue(char a,char b)
{
    return charValue[int(a)]*10+charValue[int(b)];
}
int A[5],B[5];
int getCardsValue(int C[])
{
    sort(C,C+5);
    bool flag=true; ///Royal Flush or Straight Flush
    for(int i=1;i<5;i++)
        if(C[i]-C[i-1]!=10) flag=false;
    if(flag)
        return JoinValues(10,C);
    if(C[3]/10==C[0]/10||C[4]/10==C[1]/10) ///Four of a kind
        return (8<<20)+C[2];
    if((C[0]/10==C[1]/10&&C[2]/10==C[4]/10)||(C[0]/10==C[2]/10&&C[3]/10==C[4]/10)) ///Full House
        return (7<<20)+C[2];
    flag=true;///Flush
    for(int i=1;i<5;i++)
        if(C[i]%10!=C[0]%10) flag=false;
    if(flag) return JoinValues(6,C);
    flag=true; ///Straight
    for(int i=1;i<5;i++)
        if(C[i]/10-C[i-1]/10!=1) flag=false;
    if(flag) return JoinValues(5,C);
    if(C[0]/10==C[2]/10||C[1]/10==C[3]/10||C[2]/10==C[4]/10)///three of a Kind
        return   (4<<20)+C[2];
    int cnt=0; ///Two Pairs
    for(int i=1;i<5;i++)
        if(C[i]/10==C[i-1]/10)
            cnt++;
    if(cnt==2)
    {
        if(C[4]/10!=C[3]/10) swap(C[4],C[2]);
        if(C[2]/10!=C[1]/10) swap(C[0],C[2]);
        return JoinValues(3,C);
    }
    if(cnt==1)    /// one Pair
    {
        cnt=0;
        int tmp[5];
        for(int i=0;i<4;i++)
            if(C[i]/10==C[i+1]/10) tmp[4]=tmp[3]=C[i];
        for(int i=0;i<5;i++)
            if(C[i]/10!=tmp[4]/10)
            tmp[cnt++]=C[i];
        return JoinValues(1,tmp);
    }
    ///HighCard
    return JoinValues(0,C);
}
int main()
{
    int start=clock();
    freopen("p054_poker.txt","r",stdin);
    for(int i='0';i<='9';i++)
        charValue[i]=i-int('0');
    charValue[int('T')]=10;
    charValue[int('J')]=11;
    charValue[int('Q')]=12;
    charValue[int('K')]=13;
    charValue[int('A')]=14;
    charValue[int('C')]=0;
    charValue[int('D')]=1;
    charValue[int('S')]=2;
    charValue[int('H')]=3;
    int ans=0;
    string str;
    while(cin>>str)
    {
        A[0]=getValue(str[0],str[1]);
        for(int i=1;i<5;i++)
        {
            cin>>str;
            A[i]=getValue(str[0],str[1]);
        }
        for(int i=0;i<5;i++)
        {
            cin>>str;
            B[i]=getValue(str[0],str[1]);
        }
        if(getCardsValue(A)>getCardsValue(B)) ans++;
    }
    cout<<ans<<endl;
   // cout<<clock()-start<<endl;
    return 0;
}
