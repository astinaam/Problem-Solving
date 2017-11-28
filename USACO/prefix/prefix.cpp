/*
ID: abdulah2
PROG: prefix
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
string s,str;
map<string,int>P;
int arr[300010];
bool isOn[200100];
void split(string tos)
{
    string sk;
    stringstream ss(tos);
    while(getline(ss,sk,' '))
    {
        P[sk] = 1;
   //     dbg(sk);
        n = max(n,sz(sk));
    }

}

void solve()
{
    while(getline(cin,s))
    {
        if(s==".") break;
        split(s);
    }
    str = "";
    while(getline(cin,s))
    {
        str += s;
    }
 //   dbg(str);
    //dbg(sz(str));
    int ans = -1;
    isOn[0]=1;
    for(int i=0;i<sz(str);++i)
    {
        if(isOn[i] )
        {
            for(auto x : P)
            {
                int xsz = sz(x.first);
                s = str.substr(i,xsz);
                if(x.first==s)
                {
                    isOn[i+xsz] = 1;
                    ans = max(ans,i+xsz);
                }
            }
        }
    }
    if(ans==-1) ans=0;
    cout<<ans<<endl;
}

int main()
{
    freopen("prefix.in","r",stdin);
    freopen("prefix.out","w",stdout);
    solve();
    return 0;
}
