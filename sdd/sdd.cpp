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
long long n,m,c,d;
int arr[N+1],brr[N+1];
///Current Code functions

int masks,parent[N];
bool visited[N];
vector<int>graph[N];
map<string,int>mp;
string str[N];
map<vector<int>,bool>find_duplicate;
set<vector<int> >deadlocks;

void clear()
{
    masks = 0;
    mp.clear();
    find_duplicate.clear();
    deadlocks.clear();
    for(int i = 0; i < n; ++i)
    {
        graph[i].clear();
        str[i].clear();
    }
}

void solve()
{
    //number of nodes = n
    //number of edges = m
    cin >> n >> m;
    clear();
    for(int i = 0; i < m; ++i)
    {
        string x, y;
        cin>>x>>y;
        if(!mp.count(x))
        {
            str[masks] = x;
            mp[x] = masks++;
        }
        if(!mp.count(y))
        {
            str[masks] = y;
            mp[y] = masks++;
        }
        graph[mp[x]].pb(mp[y]);
    }
    for(int i = 0; i < masks; ++i)
    {
        bool cycle_found = false;
        queue<int>Q;
        Q.push(i);
        RESET(visited,false);
        RESET(parent,-1);
        visited[i] = true;
        int node = -1;
        while(!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            for(auto y : graph[x])
            {
                if(!visited[y])
                {
                    visited[y] = true;
                    Q.push(y);
                    parent[y] = x;
                }
                else if(y == i)
                {
                    cycle_found = true;
                    node = x;
                    break;
                }
            }
            if(cycle_found)
            {
                break;
            }
        }
        if(cycle_found)
        {
            vector<int>cycle_nodes;
            while(parent[node] != -1)
            {
                cycle_nodes.pb(node);
                node = parent[node];
            }
            cycle_nodes.pb(i);
            if(sz(cycle_nodes) < 3)
                continue;
            vector<int>cv;
            cv = cycle_nodes;
            sort(all(cv));
            if(!find_duplicate[cv])
            {
                find_duplicate[cv] = true;
                reverse(cycle_nodes.begin(), cycle_nodes.end());
                deadlocks.insert(cycle_nodes);
            }
        }
    }
    cout<<"Result : "<<endl;
    if(sz(deadlocks) == 0)
    {
        cout<<"No DeadLock"<<endl;
        return;
    }
    cout<<sz(deadlocks)<<" Deadlock(s) found "<<endl;
    for(auto it : deadlocks)
    {
        for(auto i : it)
        {
            cout<<str[i]<<" ";
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
