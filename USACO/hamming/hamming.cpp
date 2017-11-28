/*
ID: abdulah2
PROG: hamming
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
int n,b,d;

int hamming_distance(int x,int y)
{
    int xr = x xor y;
    int cnt = 0;
    while(xr)
    {
        xr = xr & (xr-1);
        cnt++;
    }
    return cnt;
}
vector<int>ans;
void solve()
{
    cin>>n>>b>>d;
    ans.pb(0);
    //dbg(n);
    for(int i=1;i<(1<<b);++i)
    {
        bool ok = true;
        for(auto x : ans)
        {
    //        dbg2(x,i);
            int hmd = hamming_distance(x, i);
        //    dbg(hmd);
        //    dbg2(hmd,d);
        //    dbg(sz(ans));
            if(hmd < d)
            {
                ok = false;
                break;
            }
        }
        if(ok) ans.pb(i);
        if(sz(ans) >= n) break;
    }
        //dbg(hamming_distance(25, 7));
        int i = 1,p=0;
        for(auto x : ans)
        {
            cout<<x;
            if(i==10 || p+1==sz(ans))
            {
                i = 0;
                cout<<endl;
            }
            else cout<<" ";
            i++;
            p++;
        }

        // cerr<<"each other : "<<endl;
        // for(int i=0;i<sz(ans);++i)
        // {
        //     for(int j=i+1;j<sz(ans);++j)
        //     {
        //         int hm = hamming_distance(ans[i],ans[j]);
        //         cerr<<ans[i]<<"   "<<ans[j]<<" = "<<hm<<endl;
        //     }
        // }
}

int main()
{
    freopen("hamming.in","r",stdin);
    freopen("hamming.out","w",stdout);
    solve();
    return 0;
}
