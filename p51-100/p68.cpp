#include<iostream>
#include<algorithm>
#include<time.h>
using namespace std;

int num[10]= {1,2,3,4,5,6,7,8,9,10},tmp;
int seq[]= {0,5,6,1,6,7,2,7,8,3,8,9,4,9,5};
long long ans=0,temp;
void deal()//get the string
{
    temp=0;
    for(int i=1; i<5; i++)
        if(num[i]<num[0]) return ;
    for(int i=0; i<15; i++)
    {
        if(num[seq[i]]==10) temp*=10;
        temp=temp*10+num[seq[i]];
    }
    if(temp>ans&&temp<9999999999999999L) ans=temp;
}
int main()
{
    int start=clock();
    for(int i=0; i<3628800; i++)
    {
        tmp=num[0]+num[5]+num[6];
        if(tmp==num[1]+num[6]+num[7]&&
                tmp==num[2]+num[7]+num[8]&&
                tmp==num[3]+num[8]+num[9]&&
                tmp==num[4]+num[9]+num[5])
            deal();
        next_permutation(num,num+10);
    }
    cout<<ans<<endl;
    cout<<clock()-start<<endl;
    return 0;
}
/***
      0
        \         1
         5 ___  /
        /       6
      9         |
     /  \      /
    /    8____7____2
  4        \
            \
             3
the positions' number in my code

***/
