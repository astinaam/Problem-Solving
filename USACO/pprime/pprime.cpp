/*
ID: abdulah2
PROG: pprime
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
long long a,b;

vector<long long>pals;

bool isP(long long x)
{
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0) return false;
    }
    return true;
}
void solve()
{
    cin>>a>>b;
    //primes(a,b);
    //dbg2(a,b);
    long long num = 0;
    for(int i=1;i<=9;i++)
    {
        if(i>=a && i<= b) if (isP(i)) pals.pb(i);
        num = i*10 + i;
        if(num>=a && num<= b) if(isP(num)) pals.pb(num);
        for(int j=0;j<=9;++j)
        {
            num = 100*i + 10*j + i;
            if(num>=a && num<= b) if(isP(num))  pals.pb(num);
            num = 1000*i + 100*j + 10*j + i;
            if(num>=a && num<= b) if(isP(num))  pals.pb(num);
            for(int k=0;k<=9;++k)
            {
                num = 10000*i + 1000*j + 100*k + 10*j + i;
                if(num>=a && num<= b) if(isP(num))  pals.pb(num);
                num = 100000*i + 10000*j + 1000*k + 100*k + 10*j + i;
                if(num>=a && num<= b) if(isP(num))  pals.pb(num);
                for(int l=0;l<=9;++l)
                {
                    num = 1000000*i + 100000*j + 10000*k + 1000*l + 100*k + 10*j + i;
                    if(num>=a && num<= b) if(isP(num))  pals.pb(num);
                    num = 10000000*i + 1000000*j + 100000*k + 10000*l + 1000*l + 100*k + 10*j + i;
                    if(num>=a && num<= b) if(isP(num))  pals.pb(num);
                    for(int m=0;m<=9;++m)
                    {
                        num = 100000000*i + 10000000*j + 1000000*k + 100000*l + 10000*m + 1000*l + 100*k + 10*j + i;
                        if(num>=a && num<= b) if(isP(num))  pals.pb(num);
                    }
                }
            }
        }
    }
    sort(all(pals));
    for(auto m : pals)
    {
        cout<<m<<endl;
    }
}

int main()
{
    freopen("pprime.in","r",stdin);
    freopen("pprime.out","w",stdout);
    solve();
    return 0;
}
