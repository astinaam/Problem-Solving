#include<bits/stdc++.h>
using namespace std;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9+21;
const long long LINF = (long long) 1e18;
const long double PI = 2 * acos((long double)0);
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define Mahmud main()
#define endl "\n"
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define alla(arr,n) arr,arr+n
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb push_back
///Debug
#define dbg1(x) std::cerr<<#x<<"="<<(x)<<endl;
#define dbg2(x,y) std::cerr<<#x<<"="<<(x)<<','<<#y<<"="<<(y)<<endl;
#define dbg3(x,y,z) std::cerr<<#x<<"="<<(x)<<','<<#y<<"="<<(y)<<','<<#z<<"="<<(z)<<endl;
#define dbgArr(arr,n) cerr<<#arr<<"=["; printArray(arr,n,0,93); cerr<<endl;
///traversing
#define rep(n) for(int i=0;i<n;++i)
#define trv(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();++i)
///necessary functions
inline ll Int()
{
    ll _x=0,_tmp=1;
    char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar(), _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
inline long double Double()
{
    long double d;
    scanf("%Lf",&d);
    return d;
}
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
int ton(string x)
{
    int y;
    std::istringstream ss(x);
    ss >> y;
    return y;
}
template<typename T>
string tostring(T x)
{
    ostringstream ss;
    ss << x ;
    return ss.str();
}

///Current Code vars
#define N 100010
long long n,k,c,d;
int arr[N+1],brr[N+1];
///Current Code functions

string s;
vector<int>g[N];
bool vis[N];
bool yes[N];
int cnt[3];
void clr()
{
    for(int i=0;i<22222;++i) 
    {
        g[i].clear();
        vis[i] = false;
        yes[i] = false;
    }
    cnt[1] = cnt[2] = 0;
}

void dfs(int node,int cs)
{
    //dbg2(node,cs);
    vis[node] = true;
    cnt[cs]++;
    for(int i = 0 ; i < g[node].size();++i)
    {
        int x = g[node][i];
        if(!vis[x])
        {
            if(cs == 1) dfs(x,2);
            else dfs(x,1);
        }
    }
}

void solve()
{
    int t = Int();
    for(int cs=1;cs<=t;++cs)
    {
        clr();
        n = Int();
        int st = 0, mn = 22222;
        for(int i=0;i<n;++i)
        {
            int u = Int();
            int v = Int();
            g[u].pb(v);
            g[v].pb(u);
            //dbg2(u,v);
            st = max(st,u);
            st = max(st,v);
            mn = min(mn,u);
            mn = min(mn,v);
            yes[u] = true;
            yes[v] = true;
        }
        //dbg2(mn,st);
        int ans = 0;
        for(int i=mn;i<=st;++i)
        {
            //dbg1(i);
            if(yes[i])
            {
                //dbg1(i);
                if(!vis[i])
                {
                    dfs(i,1);
                    ans += max(cnt[1],cnt[2]);
                    cnt[1] = cnt[2] = 0;
                }
            }
        }
        //ans = max(cnt[1],cnt[2]);
        printf("Case %d: %d\n",cs,ans);
    }
}

int Mahmud
{
    // ios_base::sync_with_stdio(0); //cin.tie(0);
  //#ifdef _LOCAL_
    //freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
  //while(1)
    solve();
  //#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
  //#endif
    return 0;
}
