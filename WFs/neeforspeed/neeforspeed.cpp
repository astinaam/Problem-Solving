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
long long n,k,c,d;
int arr[N+1],brr[N+1];
///Current Code functions

string s;
vector<pair<int,int> > v;

double chk(double m)
{
    double ss = 0;
    double tim = 0,tv=0;
    for(auto x: v)
    {
        if(x.second + m == 0 ) continue;
        ss = (double) x.first / (double) (x.second + m);
        tim += ss;
        ss = (double) x.first / (double) (x.second - m);
        tv += ss;
    }
    double tt = (double) k;
    return tim;
}

void solve()
{
    n = Int();
    k = Int();
    ll sm = 0;
    double p=0,xy = 0,zx=0;
    for(int i=0;i<n;++i)
    {
        c = Int(); d = Int();
        v.pb({c,d});
        sm += c;
        if( c && d)
        {
            p = (double)c / (double)d;
            xy += p;
        }
    }
    double tt = (double) k;
    int pos = 1,ok =0;
    cout<<xy <<" "<<tt<<endl;
    if(xy > tt) pos = 0;
    double low = 0, high = 10000;
    for(int i=0;i<100;++i)
    {
        double mid = (low+high) / 2.0;
        double ch = chk(mid);
        cerr<<fixed<<setprecision(6)<<"low="<<low<<" high="<<high<<" mid="<<mid<<" ch = "<<ch<<" tt="<<tt<<endl;
        if(ch > tt)
        {
            low = mid;
        }
        else if(ch < tt)
            high = mid;
        else
        {
            ok = 1;
            break;
        }
    }
    double ans = (low+high)/2.0;
    double bt = chk(ans);
    dbg2(bt,tt);
    if(abs(bt - tt) <= 1e-6)
    {
        cout<<fixed<<setprecision(10)<<ans<<endl;
        return;

    }
    int pp=0;
    low = 0, high = 10000;
    for(int i=0;i<100;++i)
    {
        double mid = (low+high) / 2.0;
        double ch = chk(-1*mid);
        cerr<<fixed<<setprecision(6)<<"low="<<low<<" high="<<high<<" mid=-"<<mid<<" ch = "<<ch<<" tt="<<tt<<endl;
        ch = abs(ch);
        if(ch < tt)
        {
            if(pp==1) {
                low = mid;;}
            else high = mid;
        }
        else if(ch > tt)
        {
            if(ch < tt+tt && pp==0)
            {
                high = mid;
                pp=1;
            }
            else low = mid;
        }
        else
        {
            ok = 1;
            break;}
    }
    cout<<fixed<<setprecision(10)<<"nn = "<<ans<<endl;
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
