/*
ID: abdulah2
PROG: holstein
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
int n,v,g;

struct data
{
    int vitamin[33], V;
    data(){
        V = 0;
        memset(vitamin,0,sizeof vitamin);
    }
};

data arr[32],sm[32];
data need;

bool ok(data chk)
{
    int ys = false;
    for(int i=1;i<=v;++i)
    {
        if(chk.vitamin[i] < need.vitamin[i]) return false;
    }
    return true;
}

void solve()
{
    cin>>v;
    need.V = v;
    for(int i=1;i<=v;++i)
    {
        cin>>n;
        need.vitamin[i] = n;
    }
    cin>>g;
    for(int i=0;i<g;++i)
    {
        for(int j=1;j<=v;++j)
        {
            cin>>n;
            arr[i].vitamin[j] = n;
            //sm[i].vitamin[j] = n + arr[i-1].vitamin[j];
        }
    }
    int ans = 111;
    int lmt = 1<<g,bt=0,bst;
    data vs;
    //dbg(lmt);
    for(int i=0; i<lmt ;++i)
    {
        bt=0;
        vs = data();
        for(int j=1;j<=v;++j) vs.vitamin[j]=0;
        //dbg(i);
        for(int j=0;j<g;++j)
        {

            int kk = 1<<j;
            if(i & kk)
            {
        //        dbg(j);
                bt++;
                for(int p = 1; p <= v ; ++p)
                {
        //            cerr<<arr[j].vitamin[p]<<" ";
                    vs.vitamin[p] += arr[j].vitamin[p];
                }
        //        cerr<<endl;
            }

        }
        //for(int p=0;p<v;++p) cerr<<vs.vitamin[p]<<" ";
        //cerr<<endl;
        bool f = ok(vs);
        if(f)
        {
            if( ans > bt)
            {
                ans = bt;
                bst = i;
            }
        }
    }
    dbg2(bst,ans);
    cout<<ans;
    for(int i=0;i<g;++i)
    {
        if(bst & (1<<i)) cout<<" "<<i+1;
    }
    cout<<endl;
}

int main()
{
    freopen("holstein.in","r",stdin);
    freopen("holstein.out","w",stdout);
    solve();
    return 0;
}
