/*
ID: abdulah2
PROG: castle
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
int m,n,tmp;
int arr[55][55];


struct adir
{
    char dir;
    int x,y;
    adir(){}
    adir(int a,int b,char e)
    {
        dir = e;
        x = a;
        y = b;
    }
};

struct dir
{
    int n,s,w,e;
    dir(){}
    dir(int a,int b,int c,int d)
    {
        n = a;
        s = b;
        e = c;
        w = d;
    }
};



bool cmp(adir a,adir b)
{
    if(a.y == b.y)
    {
        if(a.x == b.x)
        {
            return a.dir > b.dir;
        }
        return a.x > b.x;
    }
    return a.y < b.y;
}

dir getDirections(int x)
{
    dir ret(0,0,0,0);
    if(x == 1 || x== 3 || x== 11 || x==5 || x==9 || x==7 || x==13 || x==15) ret.w = 1;
    if(x==2 || x==3 || x==6 || x==14 || x==10 || x==7 || x==11 || x==15) ret.n = 1;
    if(x==4 || x==6 || x==5 || x==12 || x==14 || x==13 || x==7 || x==15) ret.e = 1;
    if(x==8 || x==12 || x==9 || x==10 || x==13 || x==14 || x==11 || x==15) ret.s = 1;
    return ret;
}



int vis[55][55];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int roomid[55][55];
dir direction[55][55];
map<int,int> idsize;
map<int,vector<adir> > Ref;

void dfs(int id,int i,int j)
{
    //cout<<i<<" "<<j<<endl;
    roomid[i][j] = id;
    vis[i][j] = 1;
    for(int p=0;p<4;++p)
    {
        if(p==0) if(direction[i][j].n == 1) continue;
        if(p==1) if(direction[i][j].s == 1) continue;
        if(p==2) if(direction[i][j].e == 1) continue;
        if(p==3) if(direction[i][j].w == 1) continue;
        int ddx = dx[p] + i;
        int ddy = dy[p] + j;
        if(ddx >= 0 && ddy >=0 && ddx <n && ddy < m)
        {
            if(roomid[ddx][ddy]==-1)
            {
    //            cerr<<p<<" "<<ddx<<" "<<ddy<<endl;
                dfs(id,ddx,ddy);
            }
        }
    }
}

int dfs2(int cnt,int id,int i,int j)
{
    vis[i][j] = 1;
    cnt++;
    int ret = cnt;
    for(int p=0;p<4;++p)
    {
        int ddx = dx[p] + i;
        int ddy = dy[p] + j;
        if(ddx >=0 && ddy >=0 && ddx < n && ddy < m)
        {
            if(!vis[ddx][ddy] && roomid[ddx][ddy]==id)
            {
                ret += dfs2(0,id,ddx,ddy);
            }
        }
    }
    return ret;
}

int getSizeOfTheBiggestRoom()
{
    int mx = 0;
    //RESET(vis,0);
    for(int i=0;i<n;++i ) for(int j=0;j<m;++j) vis[i][j]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(vis[i][j]==0)
            {
                int gt = dfs2(0,roomid[i][j],i,j);
                idsize[roomid[i][j]] = gt;
                mx = max(mx,gt);
            }
        }
    }
    return mx;
}
vector<adir> vag;
int getSizeofTheLargestRoomCreateable()
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m-1;++j)
        {
            assert(j+1 < m);
             int p = roomid[i][j];
             int q = roomid[i][j+1];
             int ps = idsize[p];
             int qs = idsize[q];
             dbg2(ps,qs);
             if(p==q) continue;
             adir rt(i+1,j+1,'E');
             Ref[ps+qs].pb(rt);
        }
    }

    for(int i=0;i<m;++i)
    {
        for(int j=n-1;j> 0 ;--j)
        {
            assert(j-1 >= 0);
             int p = roomid[j][i];
             int q = roomid[j-1][i];
             int ps = idsize[p];
             int qs = idsize[q];
             if(p==q) continue;
             adir rt(j+1,i+1,'N');
             Ref[ps+qs].pb(rt);
        }
    }
    assert(Ref.size());
    auto it = Ref.end();
    it--;
    int ret = it->first;
    vag = it->second;
    sort(all(vag),cmp);
    //  for(auto xx : vag)
    //  {
    //      cerr<<xx.x<<" "<<xx.y<<" "<<xx.dir<<endl;
    //  }
     return ret;
}

void solve()
{
    cin>>m>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>tmp;
            arr[i][j] = tmp;
            roomid[i][j] = -1;
            dir walls = getDirections(tmp);
            direction[i][j] = walls;
        }
    }
    int mxsz = 0, cnt = 0, rmxsz = 0, torm = 0;
    //dbg2(n,m);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(roomid[i][j] == -1)
            {
                dfs(cnt,i,j);
                cnt++;
            }
        }
    }
    // cerr<<"directions : "<<endl;
    // for(int i=0;i<n;++i)
    // {
    //     for(int j=0;j<m;++j)
    //     {
    //         cerr<<'['<<direction[i][j].n<<",";
    //         cerr<<direction[i][j].s<<",";
    //         cerr<<direction[i][j].e<<",";
    //         cerr<<direction[i][j].w<<"]";
    //         cerr<<"  ";
    //     }
    //     cerr<<endl;
    // }
    // cerr<<"Visulaization : "<<endl;
    // for(int i=0;i<n;++i)
    // {
    //     assert(i<n);
    //     for(int j=0;j<m;++j)
    //     {
    //         assert(j<m);
    //         cerr<<roomid[i][j]<<" ";
    //     }
    //     cerr<<endl;
    // }
    //cout<<"maximum rooms : "<<cnt<<endl;
    cout<<cnt<<endl;
    int szofbig = getSizeOfTheBiggestRoom();
    cout<<szofbig<<endl;
    int szlarge = getSizeofTheLargestRoomCreateable();
    cout<<szlarge<<endl;
    cout<<vag[0].x<<" "<<vag[0].y<<" "<<vag[0].dir<<endl;
}

int main()
{
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    solve();
    return 0;
}
