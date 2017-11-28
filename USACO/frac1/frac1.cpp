/*
ID: abdulah2
PROG: frac1
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

typedef pair<int,int> pi;

///vars
int n;

pi reduce(pi x)
{
    int gcd = __gcd(x.first,x.second);
    int nm = x.first/gcd;
    int dn = x.second/gcd;
    return make_pair(nm,dn);
}

set< pair<double,pi> > ans;
vector<pi> ag;

bool cmp(pi a,pi b)
{
    double val1  = (double) a.first / (double) a.second;
    double val2  = (double) b.first / (double) b.second;
    return val1 < val2;
}

void solve()
{
    cin>>n;
    for(int i=1;i<n;++i)
    {
        for(int j = i+1 ; j<= n;++j)
        {
            pi red = reduce(make_pair(i,j));
            if(find(all(ag),red)==ag.end()) ag.pb(red);
            //double val = (double)red.first / (double)red.second;
            //ans.insert(make_pair(val,make_pair(red.first,red.second)));
        }
    }
    sort(all(ag),cmp);
    cout<<0<<'/'<<1<<endl;
    for(auto x : ag)
    {
        cout<<x.first<<"/"<<x.second<<endl;
        //cout<<x.second.first<<'/'<<x.second.second<<endl;
    }
    cout<<1<<'/'<<1<<endl;
}

int main()
{
    freopen("frac1.in","r",stdin);
    freopen("frac1.out","w",stdout);
    solve();
    return 0;
}
