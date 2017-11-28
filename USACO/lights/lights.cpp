/*
ID: abdulah2
PROG: test
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
int n,m;

ll toggle[40];
map<ll,int>dp;
vector<int>g[40];

void solve()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int u,v; cin>>u>>v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
//    cerr<<"toggling..."<<endl;
    for(int i=0;i<n;++i)
    {
        toggle[i] = 1LL << i;
//        dbg2(i,toggle[i]);
//        bitset<64> b (toggle[i]);
//        cerr<<"toggle["<<i<<"] = "<<b<<endl;
//        cerr<<"for vertexes..."<<endl;
        for(auto x : g[i])
        {
///            cerr<<"Vertex : "<<x<<endl;
            toggle[i] = toggle[i] ^ (1LL << x);
    //        bitset<64> c(toggle[i]);
    //        cerr<<"toggle["<<i<<"] = "<<c<<endl;
        }
    //    bitset<64> c(toggle[i]);
    //    cerr<<"lastly toggle["<<i<<"] = "<<c<<endl;
    }

    int mid = n/2;
    ll  lmt = (1LL << mid+1);
    //dbg(lmt);
    for(int i=0;i<lmt;++i)
    {
        ll x = 0;
        //dbg(i);
        for(int j=0;j<mid+1;++j)
        {
            if(i & (1LL<<j) )
            {
                x = x ^ toggle[j];
            }
        }
    //    bitset<64> b ( x);
        //dbg(x);
        //dbg(b);
        if(dp[x]) dp[x] = min(dp[x],__builtin_popcount(i));
        else dp[x] = __builtin_popcount(i);
        //dbg(dp[x]);
    }
    //for(auto d : dp)
    {
    //    dbg(d.first);
    }
    int ans = dp[(1LL<<n)-1] ? dp[(1LL<<n)-1] : 999;
    //dbg(ans);
    lmt = n - mid - 1;
    //dbg(lmt);
    for(int i=0;i< (1LL<<(n-mid-1));++i)
    {
    //    dbg(i);
        ll x = 0;
        for(int j=0;j < n-mid-1;++j)
        {
            if(i & (1LL<<j)) x  = x ^ toggle[mid+j+1];
        }
    //    dbg(x);
    //    bitset<64> b(x);
    //    dbg(b);
        ll cmp = ((1LL<<n)-1)^x;
    //    dbg(cmp);
    //    bitset<64> c(cmp);
    //    dbg(c);
        int add = dp[cmp] ? dp[cmp] : 999;
    //    dbg(add);
        ans = min(ans, __builtin_popcount(i)+add);
    }
    cout<<ans<<endl;
}

int main()
{
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
    solve();
    return 0;
}
