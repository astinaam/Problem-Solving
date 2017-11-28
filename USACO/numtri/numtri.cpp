/*
ID: abdulah2
PROG: numtri
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
int n;
//int arr[1010][1010];
int ans[1010][1010];
//vector<int>v[1010];

void solve()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int t = i;
        for(int j=0;j<i;++j)
        {
            int mp;
            cin>>mp;
    //        arr[i][j] = mp;
            if(j==0)
            {
                int sma = ans[i-1][j] + mp;
                ans[i][j] = sma;
            }
            else if(j==i-1)
            {
                int smb = ans[i-1][j-1] + mp;
                ans[i][j] = smb;
            }
            else
            {
                int sma = ans[i-1][j] + mp;
                int smb = ans[i-1][j-1] + mp;
                ans[i][j] = max(sma,smb);
            }
        }
    }
    int fans = 0;
    for(int i=0;i<n;++i)
    {
    //    cerr<<ans[n][i]<<" ";
        fans = max(fans,ans[n][i]);
    }
    //cerr<<endl;
    cout<<fans<<endl;
}

int main()
{
    freopen("numtri.in","r",stdin);
    freopen("numtri.out","w",stdout);
    solve();
    return 0;
}
