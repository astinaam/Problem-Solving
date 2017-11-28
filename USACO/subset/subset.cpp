/*
ID: abdulah2
PROG: subset
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

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

ll dp[1111][41];

ll sol(int w,int k)
{
    if(w < 0 || k < 0) return 0;
    if(dp[w][k]!=-1) return dp[w][k];
    if(w==0 && k==0) return dp[w][k] = 1;
    return dp[w][k] =  sol(w,k-1) + sol(w-k,k-1);
}


void solve()
{
    cin>>n;
    memset(dp,-1,sizeof dp);
    ll ans = 0;
    int lmt = (n*(n+1)) / 2;

    if(lmt & 1) puts("0");
    else
    {
        //dbg("here");
    //    for(int i=0;i<=lmt;++i) for(int j=0;j<=n;++j) dp[i][j]=-1;
        ans = sol(lmt/2,n);
        cout<<ans/2<<endl;
    }
}

int main()
{
    freopen("subset.in","r",stdin);
    freopen("subset.out","w",stdout);
    solve();
    return 0;
}
