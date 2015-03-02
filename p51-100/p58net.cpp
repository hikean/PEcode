
#include<stdio.h>
#include<iostream>

using namespace std;

const double THRESHOLD = 0.1;


const int limit=10000000;

bool bprime[limit]={0};

bool isprime(long long  n)
{
    if(n<limit) return !bprime[n];
    for(long long i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

void Problem_58()
{

    int firstNum = 0;
    int lastNum = 1;
    int layer = 0;

    double ratio = 1;
    int whole = 1;
    int prime = 0;
    while(ratio >= THRESHOLD)
    {
        layer++;
        int increment = layer * 2;
        int firstNum = lastNum + increment;
        lastNum = firstNum;
        if(isprime(lastNum))
        {
            prime++;
        }
        for(int i=0; i<3; i++)
        {
            lastNum += increment;
            if(isprime(lastNum))
            {
                prime++;
            }
        }
        whole += 4;
        ratio = ((double)prime) / whole;
        printf("%d/%d, %f,%d\n", prime, whole, ratio, increment + 1);
    }
        printf("%f,%d\n", ratio, 2 * layer + 1);
}

int main()
{
     for(int i=2;i<2000;i++)
        if(!bprime[i])
            for(int j=i<<1;j<limit;j+=i)
                bprime[j]=true;
    Problem_58();

    return 0;
}
