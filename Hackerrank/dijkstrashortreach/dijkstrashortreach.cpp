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
#define FOR(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=n,i>=0;--i)
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
long long n,m;
int arr[N+1],brr[N+1];
///Current Code functions

string s;
int graph[3010][3010];
int dist[3001];
void clear()
{
    FOR(i,3001)
    {
        FOR(j,3001)
        {
            graph[i][j] = INF;
        }
    }
    FOR(i,3001) dist[i]=INF;
}



void fw()
{
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
}

void djk(int src)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    pq.push(src);
    while(!pq.empty())
    {
        int x = pq.top();
        pq.pop();
        for(int i=1;i<=n;++i)
        {
            if(dist[i] > dist[x] + graph[x][i])
            {
                dist[i] = dist[x]+graph[x][i];
                pq.push(i);
            }
        }
    }
}

void solve()
{
    int tc = Int();
    while(tc--)
    {
        clear();
        cin>>n>>m;
        while(m--)
        {
            int x,y,w;
            x = Int();
            y = Int();
            w = Int();
            graph[x][y] = min(graph[x][y],w);
            graph[y][x] = min(graph[y][x],w);
        }
        int s = Int();
        dist[s] = 0;
        // FOR(step,n-1)
        // {
        //     for(int i=1;i<=n;++i)
        //     {
        //         for(int j=1;j<=n;++j)
        //         {
        //             dist[j] = min(dist[j],dist[i]+graph[i][j]);
        //         }
        //     }
        // }
        djk(s);
        for(int i=1;i<=n;++i)
        {
            if(i!=s)
            {
                if(dist[i]==INF) cout<<"-1 ";
                else cout<<dist[i]<<" ";
            }
        }
        cout<<endl;
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
