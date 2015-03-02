#include<set>
#include<iostream>


using namespace std;

int fac[]={1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
set<int> st;
bool have[10000001]={0};
int data[100],num=0,sum,cnt;
/***int check(int n)
{
    st.clear();
    int sum=0;
    int cnt=0;
    while(st.size() >=cnt&&cnt<60)
    {
        st.insert(n);
        while(n)
        {
            sum+=fac[n%10];
            n/=10;
        }
        n=sum;
        sum=0;
        cnt++;
    }
    return cnt;

}***/
int check(int n)
{
    num=sum=cnt=0;
    while(!have[n])
    {
        have[n]=true;
        data[num++]=n;
        while(n)
        {
            sum+=fac[n%10];
            n/=10;
        }
        n=sum;
        sum=0;
        cnt++;
    }
    for(int i=0;i<num;i++)
        have[data[i]]=false;
    return cnt;
}

int main()
{
    int ans=0;
    for(int i=1;i<1000000;i++)
        if(check(i)>=60)
            ans++;
    cout<<ans<<endl;//402
    return 0;
}
/**
lst=[1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880]
def cal(n):
	cnt=0
	st=set([])
	tmp=0
	while n not in st and cnt<60:
		st.add(n)
		for x in str(n):
			tmp+=lst[int(x)]
		cnt+=1
		n=tmp
		tmp=0
	if cnt >= 60:
		return 1
	else:
		return 0
ans=0
for x in xrange(1,1000000):
    ans+=cal(x)

***/
