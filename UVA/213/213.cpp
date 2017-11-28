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

string keys[N];
string mk[11][266];

void gen()
{
    mk[1][0] = "0";
    mk[2][0] = "00";
    mk[2][1] = "01";
    mk[2][2] = "10";
    for(int i=3;i<=7;++i)
    {
        int lmt = 1 << i;
        for(int j=0;j<i;++j)
            mk[i][0] += "0";
        int thr = (lmt-1) >> 1;
        int id = 1;
        //dbg2(lmt,thr);
        for(int j=1;j<thr;++j)
        {
           // dbg2(j,id);
            mk[i][id] = "0" + mk[i-1][j];
            id++;
        }
        //dbg1(id);
        mk[i][id] = "0";
        for(int j=1;j<i;++j)
        {
            mk[i][id] += "1";
        }
        id++;
        for(int j=0;j<thr;++j)
        {
            mk[i][id] = "1" + mk[i-1][j];
            id++;
        }
        //dbg2(i,id);
    }
    //return;
    int id= 0;
    for(int i=1;i<=7;++i)
    {
        int j = 0;
        while(j < (1<<i)-1)
        {
            //dbg3(i,j,mk[i][j]);
            keys[id++] = mk[i][j];
            j++;
        }
        //dbg2(i,j);
    }
    //return;
    // dbg1(id);
    // for(int i=0;i<id;++i)
    // {
    //     dbg2(i,keys[i]);
    // }
}

void clear()
{
    for(int i=0;i<=7;++i)
    {
        for(int j=0;j<255;++j)
        {
            mk[i][j] = "";
        }
    }
    for(int i=0;i<1000;++i)
        keys[i] = "";
}
string p;

int process(int id)
{
    string th = p.substr(id,3);
    if(th=="000") return -1;
    if(th= "001") return 1;
    if(th= "010") return 2;
    if(th= "011") return 3;
    if(th= "100") return 4;
    if(th= "101") return 5;
    if(th= "110") return 6;
    if(th= "111") return 7;
}

void solve()
{
    clear();
    gen();
    string str = "",ans="";
    while(getline(cin,s))
    {
        str = "";
        bool got = false;
        int x;
        cin>>p;
        str = p;
        while(sz(str) < 3)
        {
            cin>>p;
            str += p;
        }
        x = process(0);
        
        cout<<s<<" "<<str<<endl;
    }
    //cout<<s<<" "<<str<<endl;
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
