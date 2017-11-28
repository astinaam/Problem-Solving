/*
ID: abdulah2
PROG: lamps
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
int n,c;

struct state{
    int lamps[110];
    state(int ar[])
    {
        for(int i=0;i<101;++i) lamps[i] = ar[i];
    }

};

struct mission
{
    vector<state>lamp;
};

state op(int id,int x,state ret)
{
    if(id==1) for(int i=1;i<=x;++i) if(ret.lamps[i]==1) ret.lamps[i] = 0; else ret.lamps[i] = 1;
    else if(id==2) for(int i=1;i<=x;i+=2) if(ret.lamps[i]==1) ret.lamps[i] = 0; else ret.lamps[i] = 1;
    else if(id==3) for(int i=2;i<=x;i+=2) if(ret.lamps[i]==1) ret.lamps[i] = 0; else ret.lamps[i] = 1;
    else if(id==4) for(int i=1;i<=x;i+=3) if(ret.lamps[i]==1) ret.lamps[i] = 0; else ret.lamps[i] = 1;
    return ret;
}

mission arr[10010];
int on[110],off[110];
int faka[110];
int idx,idx2;

void printstate(state x)
{
    for(int i=1;i<n;++i) cerr<<x.lamps[i];
    cerr<<x.lamps[n]<<endl;
}

bool repited(state x,state y)
{
    for(int i=1;i<=n;++i)
    {
        if(x.lamps[i] != y.lamps[i]) return false;
    }
    return true;
}

bool okay(state st)
{
    for(int i=0;i<idx;++i)
    {
        int tx = on[i];
        if(st.lamps[tx] != 1) return false;
    }
    for(int i=0;i<idx2;++i)
    {
        int tx = off[i];
        if(st.lamps[tx] != 0) return false;
    }
    return true;
}

bool cmp(state a,state b)
{
    for(int i = 1; i<=n;++i)
    {
        if(a.lamps[i] != b.lamps[i])
        {
            int x = a.lamps[i], y = b.lamps[i];
            if(x==1 && y==0) return 0;
            if(x==0 && y==1) return 1;
        }
    }
    return 1;
}

bool nothere(state st,int it)
{
    for(auto x : arr[it].lamp)
    {
        int same = 0;
        for(int i=1;i<=n;++i)
        {
            if(st.lamps[i]!=x.lamps[i])
            {
                same = 1;
                break;
            }
        }
        if(same==0) return false;
    }
    return true;
}

void solve()
{
    cin>>n>>c;
    //int idx=0;
    while(1)
    {
        int tmp; cin>>tmp;
        if(tmp != -1) on[idx++] = tmp;
        else break;
    }
    //int idx2 = 0;
    while(1)
    {
        int tmp; cin>>tmp;
        if(tmp != -1) off[idx2++] = tmp;
        else break;
    }
    if(c==0)
    {
        bool ok = true;
        if(idx2 != 0) cout<<"IMPOSSIBLE"<<endl;
        else {for(int i=0;i<n-1;++i) cout<<1;
        cout<<1<<endl;}
        return;
    }
    if(c>4) c=4;
    //memset(faka,1,sizeof(faka));
    for(int i=0;i<=n;++i) faka[i]=1;
    arr[0].lamp.pb(state(faka));

    for(int step = 1; step <= c; ++step)
    {
        //dbg(step);
        for(auto x : arr[step-1].lamp)
        {
            //printstate(x);
            for(int i=1;i<=4 ;++i)
            {
                state ret = op(i,n,x);
                //dbg(i);
            //    printstate(ret);
                if(step == c && okay(ret) && nothere(ret,step))
                {
                //    dbg("addednext");
                    arr[step].lamp.pb(ret);
                }
                else if(step != c) arr[step].lamp.pb(ret);
            }
        }
    }
    vector<state> ans = arr[c].lamp;
    if(!sz(ans))
    {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    sort(all(ans),cmp);
    //for(int i=1;i<=c;++i)
//    {
//        cout<<"step = "<<i<<endl;
        for(auto x : ans)
        {
            for(int i=1;i<n;++i) cout<<x.lamps[i];
            cout<<x.lamps[n]<<endl;
        }
//    }

}

int main()
{
    freopen("lamps.in","r",stdin);
    freopen("lamps.out","w",stdout);
    solve();
    return 0;
}
