/*
ID: abdulah2
PROG: sort3
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
int arr[1111],prr[1111];

int find_previous_larger(int x,int idx)
{
    int ret = -1,mx = 0;
    for(int i=0;i<idx;++i)
    {
        if(arr[i] > x)
        {
            if(arr[i]>mx)
            {
                mx = arr[i];
                ret = i;
            }
        }
    }
    return ret;
}

void solve()
{
    cin>>n;
    int ones=0,twos=0,thrs=0;
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
        if(arr[i]==1) ones++;
        else if(arr[i]==2) twos++;
        else if(arr[i]==3) thrs++;
    }
    int ans=0;
    int on = 0, tw = 0, th = 0;
    //dbg2(twos,thrs);
    //dbg(ones);
    for(int i=0;i<ones;++i)
    {
        prr[i] = 1;
    }
    for(int i=ones;i < ones+twos;++i) prr[i] = 2;
    for(int i=ones+twos;i<ones+thrs+twos;++i) prr[i] = 3;
    //for(int i=0;i<n;++i) cerr<<prr[i];
    //cerr<<endl;

    for(int i=ones;i<n;++i)
    {
        if(arr[i]==1)
        {
            int k;
            for(int j=0;j<ones;++j)
            {
                if(arr[j]==2)
                {
                    k = j;
                    break;
                }
                else if(arr[j]==3)
                {
                    k = j;
                }
            }
            swap(arr[k],arr[i]);
            ans++;
        }
    }
    for(int i=ones+twos ; i<n;++i)
    {
        if(arr[i]==2)
        {
            ans++;
        }
    }

//    for(int i=0;i<n;++i) cerr<<arr[i]<<" ";
    cout<<ans<<endl;
}

int main()
{
    freopen("sort3.in","r",stdin);
    freopen("sort3.out","w",stdout);
    solve();
    return 0;
}
