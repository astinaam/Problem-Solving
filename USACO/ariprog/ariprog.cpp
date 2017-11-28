/*
ID: abdulah2
PROG: ariprog
LANG: C++11
*/
#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) x.begin(),x.end()
#define X first
#define Y second
#define SQ(x) x*x
#define sz(x) (int)x.size()
#define dbg(n) cerr<<#n<<"="<<n<<endl;
#define dbg2(n,m) cerr<<#n<<"="<<n<<","<<#m<<"="<<m<<endl;
#define dbg3(n,m,k) cerr<<#n<<"="<<n<<","<<#m<<"="<<m<<","<<#k<<"="<<k<<endl;
#define err(s) cerr<<s<<":"<<endl;

vector<pair<int,int> > ans;

///vars
int n,m;
int sets[125010],vis[125010];



void gen()
{
    //set<int>st;
    for(int i=0;i<=m;++i)
    {
        for(int j=i;j<=m;++j)
        {
            int p = SQ(i)+SQ(j);
            //assert(p >=0 && p<=125000);
            sets[p]++;
            //st.insert(p);
            //cout<<p<<" ";
        }
    }
}

bool dfs(int u,int d,int c)
{
    //dbg3(u,d,c);
    //dbg(sets[u]);
    //cout<<u<<endl;
    //assert(u >=0 && u<=125010);
    if(u > SQ(m)+SQ(m)) return false;
    if (!sets[u]) return false;
    if(c>=n) return true;
    //dbg3(u,d,c);
    return dfs(u+d,d,c+1);
}

void solve()
{
    cin>>n>>m;
    gen();
    n--;
    int lm = SQ(m)+SQ(m);
    int an=0;
    for(int j=1;;++j) // length of progression
    {
        //dbg(j);
        if(j*n > lm) break;
        for(int i=0;i<=lm;++i)
        {
            if((i + (j*n)) > lm) break;
            assert(i>=0&&i<=125000);
            if(sets[i])
            {
                //cerr<<i<<" ";
                bool ok = dfs(i,j,0);
                if(ok)
                {
                    //cerr<<"ok on "<<i<<endl;
                    //ans.pb({i,j});
                    an++;
                    printf("%d %d\n",i,j);
                }
            }
        }
        //cerr<<endl;
    }
    if(an==0) puts("NONE");
    // if(sz(ans))
    // for(int i=0;i<ans.size();++i)
    // {
    //     //cout<<ans[i].first<<" "<<ans[i].second<<endl;
    //     printf("%d %d\n",ans[i].first,ans[i].second);
    // }
    // else cout<<"NONE"<<endl;
}

int main()
{
    freopen("ariprog.in","r",stdin);
    freopen("ariprog.out","w",stdout);
    solve();
    return 0;
}
