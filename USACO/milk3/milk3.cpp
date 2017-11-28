/*
ID: abdulah2
PROG: milk3
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
int a,b,c,x,y,z;
std::vector<int>ans;
bool isOk(int p,int q,int r)
{

    if(p >=0 && q>=0 && r>=0 && p<=a && q<=b && r<=c)
    {
        if(p==0)
        {
            ans.pb(r);
        }
        return true;
    }
    return false;
}

int vis[22][22];

void possiblity(int x,int y,int z)
{
    if(vis[x][y]) return;
    vis[x][y]=1;
    bool ok = isOk(x,y,z);
    if(ok)
    {
        if (x>0 && y<b)
            possiblity(max(0,x+y-b),min(b,x+y),z);
        if (x>0 && z<c)
            possiblity(max(0,x+z-c),y,min(c,x+z));
        if (y>0 && x<a)
            possiblity(min(a,y+x),max(0,y+x-a),z);
        if (y>0 && z<c)
            possiblity(x,max(0,y+z-c), min(c,y+z));
        if (z>0 && x<a)
            possiblity(min(a,z+x),y,max(0,z+x-a));
        if (z>0 && y<b)
            possiblity(x,min(b,z+y),max(0,z+y-b));
    }
    return;
}



void solve()
{
    cin>>a>>b>>c;
    possiblity(0,0,c);
    sort(all(ans));
    for(int i=0;i<sz(ans);++i)
    {
        printf("%d%c",ans[i]," \n"[i==sz(ans)-1]);
    }
}

int main()
{
    freopen("milk3.in","r",stdin);
    freopen("milk3.out","w",stdout);
    solve();
    return 0;
}
