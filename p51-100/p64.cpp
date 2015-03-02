#include<iostream>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;

struct Num
{
    int rt,in,tim;/// = tim*sqrt(rt)+in
    Num(int r=0,int i=0,int t=0):rt(r),in(i),tim(t) {};
    double getValue()
    {
        return tim*sqrt(rt)+in;
    }
    Num operator /(const int & t)const
    {
        return Num(this->rt,this->in/t,this->tim/t).normal();
    }
    Num operator *(const Num & t)const
    {
        if(this->rt!=t.rt&&this->rt!=0&&t.rt!=0)
        {
            cout<<"Error"<<endl;
            return Num();
        }
        int r=this->rt;
        if(r==0) r=t.rt;
        return Num(r,this->in*t.in+this->tim*t.tim*this->rt,this->tim*t.in+t.tim*this->in).normal();
    }
    Num operator *(const int & t)const
    {
        return Num(this->rt,this->in*t,this->tim*t);
    }
    Num operator -(const int & t)const
    {
        return Num(this->rt,this->in-t,this->tim);
    }
    Num operator -(const Num & b)const
    {
        int tmp=this->rt;
        if(b.rt!=0) tmp=b.rt;
        return Num(tmp,this->in-b.in,this->tim-b.tim).normal();
    }
    Num normal()
    {
        if(this->tim==0||this->rt==0) this->rt=this->tim=0;
        return *this;
    }
    void output(char ch)
    {
        cout<<ch<<": "<<rt<<" "<<in<<" "<<tim<<endl;
    }
    bool operator<(const Num & n)const
    {
        if(this->tim==n.tim)
            return this->in<n.in;
        return this->tim<n.tim;
    }
    bool operator ==(const Num& n) const
    {
        return !(*this<n||n<*this);
    }
};

int gcd(int a,int b)
{
    if(a<0) a=-a;
    if(b<0) b=-b;
    if(a<b) swap(a,b);
    return b==0?a:gcd(b,a%b);
}

struct Fra
{
    Num a,b;///  a/b=numerator/denominator
    Fra(int _a=0,int _b=0):a(_a,0,1),b(0,_b,0){}
    int getValue()
    {
        int val=a.getValue()/b.getValue();
        a=a-b*val;
        swap(a,b);
        if(b.tim)
        {
            a=a*Num(b.rt,-b.in,b.tim);
            b=b*Num(b.rt,-b.in,b.tim);
        }
        int tmp=gcd(gcd(a.tim,a.in),gcd(b.tim,b.in));
        if(tmp==0) return -1;
        a=a/tmp;
        b=b/tmp;
        return val;
    }
    bool operator <(const Fra& f )const
    {
        if(this->a==f.a)
            return this->b<f.b;
        return this->a<f.a;
    }
};

int main()
{
    int ans=0;
    for(int i=1;i<=10000;i++)
    {
        map<Fra,int> mp;
        Fra n(i,1);
        for(int j=1;;j++)
        {
            int tmp=mp[n];
            if(tmp!=0)
            {
                if((j-tmp)&1) ans++;
                 break;
            }
            mp[n]=j;
            if(n.getValue()==-1) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
