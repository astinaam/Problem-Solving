/*
ID: abdulah2
PROG: sprime
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define X first
#define Y second
#define sz(x) (int)x.size()
#define dbg(n) cerr<<#n<<"="<<n<<endl;
#define dbg2(n,m) cerr<<#n<<"="<<n<<","<<#m<<"="<<m<<endl;
#define err(s) cerr<<s<<":"<<endl;

///vars
int n;

bool isPrime(int x)
{
    if(x%2==0) return false;
    for(int i=3;i*i<=x;i+=2)
    {
        if(x%i==0) return false;
    }
    return true;
}
vector<int>v;
void solve()
{
    cin>>n;
    v.pb(2);
    v.pb(3);
    v.pb(5);
    v.pb(7);
    int num = 0;
    if(n==1)
    {
        for(int i=1;i<=9;++i)
        {
            if(isPrime(i)) cout<<i<<endl;
        }
    }
    else if(n==2)
    {
        for(auto x : v)
        {
            for(int i=1;i<=9;i+=2)
            {
                num = x*10 + i;
                if(isPrime(num)) cout<<num<<endl;
            }
        }
    }
    else if(n==3)
    {
        for(auto x : v)
        {
            for(int i=1;i<=9;i+=2)
            {
                num = x*10 + i;
                if(isPrime(num))
                {
                    for(int j=1;j<=9;j+=2)
                    {
                        num = x*100 + i*10 + j;
                        if(isPrime(num)) cout<<num<<endl;

                    }
                }
            }
        }
    }
    else if(n==4)
    {
    //    dbg(n);
        for(auto x : v)
        {
            for(int i=1;i<=9;i+=2)
            {
                num = x*10 + i;
                if(isPrime(num))
                {
                    for(int j=1;j<=9;j+=2)
                    {
                        num = x*100 + i*10 + j;
                        if(isPrime(num))
                        {
                            for(int k=1;k<=9;k+=2)
                            {
                                num = x*1000 + i* 100 + j*10 + k;
                                if(isPrime(num)) cout<<num<<endl;
                        //        dbg2(k,num);
                            }
                        }
                        //dbg2(n,num);
                    }
                }
                //dbg(num);
            }
            //dbg(x);
        }
    }
    else if(n==5)
    {
        for(auto x : v)
        {
            for(int i=1;i<=9;i+=2)
            {
                num = x*10 + i;
                if(isPrime(num))
                {
                    for(int j=1;j<=9;j+=2)
                    {
                        num = x*100 + i*10 + j;
                        if(isPrime(num))
                        {
                            for(int k=1;k<=9;k+=2)
                            {
                                num = x*1000 + i* 100 + j*10 + k;
                                if(isPrime(num))
                                {
                                    for(int l=1;l<=9;l+=2)
                                    {
                                        num = x*10000+ i * 1000 + j * 100+ k*10 + l;
                                        if(isPrime(num)) cout<<num<<endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==6)
    {
        for(auto x : v)
        {
            for(int i=1;i<=9;i+=2)
            {
                num = x*10 + i;
                if(isPrime(num))
                {
                    for(int j=1;j<=9;j+=2)
                    {
                        num = x*100 + i*10 + j;
                        if(isPrime(num))
                        {
                            for(int k=1;k<=9;k+=2)
                            {
                                num = x*1000 + i* 100 + j*10 + k;
                                if(isPrime(num))
                                {
                                    for(int l=1;l<=9;l+=2)
                                    {
                                        num = x*10000+ i * 1000 + j * 100+ k*10 + l;
                                        if(isPrime(num))
                                        {
                                            for(int m=1;m<=9;m+=2)
                                            {
                                                num = x*100000 + i*10000 + j*1000 + k*100 + l*10 + m;
                                                if(isPrime(num)) cout<<num<<endl;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==7)
    {
        for(auto x : v)
        {
            for(int i=1;i<=9;i+=2)
            {
                num = x*10 + i;
                if(isPrime(num))
                {
                    for(int j=1;j<=9;j+=2)
                    {
                        num = x*100 + i*10 + j;
                        {
                        if(isPrime(num))
                        {
                            for(int k=1;k<=9;k+=2)
                            {
                                num = x*1000 + i* 100 + j*10 + k;
                                if(isPrime(num))
                                {
                                    for(int l=1;l<=9;l+=2)
                                    {
                                        num = x*10000+ i * 1000 + j * 100+ k*10 + l;
                                        if(isPrime(num))
                                            for(int m=1;m<=9;m+=2)
                                            {
                                                num = x*100000 + i*10000 + j*1000 + k*100 + l*10 + m;
                                                if(isPrime(num))
                                                {
                                                    for(int o=1;o<=9;o+=2)
                                                    {
                                                        num = x*1000000 + i*100000 + j*10000 + k*1000 + l*100 + m*10 + o;
                                                        if(isPrime(num)) cout<<num<<endl;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if(n==8)
    {
        for(auto x : v)
        {
            for(int i=1;i<=9;i+=2)
            {
                num = x*10 + i;
                if(isPrime(num))
                {
                    for(int j=1;j<=9;j+=2)
                    {
                        num = x*100 + i*10 + j;
                        if(isPrime(num))
                        {
                            for(int k=1;k<=9;k+=2)
                            {
                                num = x*1000 + i* 100 + j*10 + k;
                                if(isPrime(num))
                                {
                                    for(int l=1;l<=9;l+=2)
                                    {
                                        num = x*10000+ i * 1000 + j * 100+ k*10 + l;
                                        if(isPrime(num))
                                        {
                                            for(int m=1;m<=9;m+=2)
                                            {
                                                num = x*100000 + i*10000 + j*1000 + k*100 + l*10 + m;
                                                if(isPrime(num))
                                                {
                                                    for(int o=1;o<=9;o+=2)
                                                    {
                                                        num = x*1000000 + i*100000 + j*10000 + k*1000 + l*100 + m*10 + o;
                                                        if(isPrime(num))
                                                        {
                                                            for(int p=1;p<=9 ;p+=2)
                                                            {
                                                                num = x*10000000 + i*1000000 + j*100000 + k*10000 + l*1000 + m*100 + o*10 + p;
                                                                if(isPrime(num)) cout<<num<<endl;
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    freopen("sprime.in","r",stdin);
    freopen("sprime.out","w",stdout);
    solve();
    return 0;
}
