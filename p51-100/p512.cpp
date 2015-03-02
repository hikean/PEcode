#include<iostream>

using namespace std;
const int limit=1000005;
bool bprime[limit]= {0};

int dif[]= {1 , 10 , 11 , 100 , 101 , 110 , 111 , 1000 , 1001 , 1010 , 1011 , 1100 , 1101 , 1110 ,1111 , 10000 , 10001 , 10010 , 10011 , 10100 , 10101 , 10110 , 10111 , 11000 , 11001 , 11010 ,11011 , 11100 , 11101 , 11110 , 11111 , 100000 , 100001 , 100010 , 100011 , 100100 , 100101 ,100110 , 100111 , 101000 , 101001 , 101010 , 101011 , 101100 , 101101 , 101110 , 101111 ,110000 , 110001 , 110010 , 110011 , 110100 , 110101 , 110110 , 110111 , 111000 , 111001 ,111010 , 111011 , 111100 , 111101 , 111110 , 111111 ,};
bool may(int n)
{
    while(n)
    {
        if(n%10<=2)
            return true;
        n/=10;
    }
    return false;
}

bool can(int a,int b)// a is a prime number, b is the difference
{
    if(a<b) return false;
    int cnt=0,n=a,m=b,t=-1;
    while(t==-1)
    {
        if(b%10)
        {
            t=a%10;
            break;
        }
        a/=10,b/=10;
    }
    while(b)
    {
        if(b%10&&a%10!=t) return false;
        a/=10,b/=10;
    }
    for(int i=t; i<10; i++)
    {
        if(n<limit&&!bprime[n]) ++cnt;
        n+=m;
    }
    return cnt>=8;
}

int main()
{
    bprime[0]=bprime[1]=true;
    for(int i=2; i<2001; i++)
        if(!bprime[i])
            for(int j=i<<1; j<limit; j+=i)
                bprime[j]=true;
    for(int i=2; i<limit; i++)
        if(!bprime[i]&&may(i))
            for(int j=0; j<0x3f; j++)
                if(can(i,dif[j]))
                {
                    cout<<i<<" "<<dif[j]<<endl;
                    return 0;
                }
    return 0;
}
