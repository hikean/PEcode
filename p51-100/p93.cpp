#include<set>
#include<iostream>
#include<algorithm>
#define eps  0.0000000001
using namespace std;


int a,b,c,d,tmp;
set<int> st;
inline  double  operate(double a,double b,int opt) //opt 0~3 +-*/
{
    if(opt<2)//binary search, 2 comparsions on average,use case-switch or if-else 2.5 on average
        return opt==0?a+b:a-b;
    return opt==2?a*b:a/b;
}
void calcu(int n)
{
    int opt1=n&3,opt2=(n&12)>>2,opt3=(n&48)>>4;
    double ans[5];
    ans[0]=operate(operate(a,b,opt1),operate(c,d,opt3),opt2);
    ans[1]=operate(operate(operate(a,b,opt1),c,opt2),d,opt3);
    ans[2]=operate(operate(a,operate(b,c,opt2),opt1),d,opt3);
    ans[3]=operate(a,operate(operate(b,c,opt2),d,opt3),opt1);
    ans[4]=operate(a,operate(b,operate(c,d,opt3),opt2),opt1);
    for(int i=0; i<5; i++)
    {
        tmp=ans[i]+eps;
        if(tmp>0&& tmp-ans[i] < eps && tmp -ans[i]> -eps)
            st.insert(tmp);
    }
}

int main()
{
    int num[4],len=0,ans;
    for(int i=1; i<7; i++)
        for(int j=i+1; j<8; j++)
            for(int k=j+1; k<9; k++)
                for(int h=k+1; h<10; h++)
                {
                    num[0]=i,num[1]=j,num[2]=k,num[3]=h;
                    st.clear();
                    for(int f=0; f<24; f++)//24=4!
                    {
                        a=num[0],b=num[1],c=num[2],d=num[3];
                        for(int g=0;g<64;g++)//64=4*4*4
                            calcu(g);
                        next_permutation(num,num+4);
                    }
                    tmp=0;
                    for(set<int> ::const_iterator it=st.begin(); it!=st.end(); ++it)
                        if(*it!=++tmp) break;
                    if(tmp-1>len)
                    {
                        len=tmp-1;
                        ans=i*1000+j*100+k*10+h;
                    }
                }
    cout<<len<<" "<<ans<<endl;
    return 0;
}

/**a b c d

((a b) (c d))
(((a b) c) d)

((a(b c))d)
(a((b c)d))

(a(b(c d)))

***/

//24*64*5*C9,4
