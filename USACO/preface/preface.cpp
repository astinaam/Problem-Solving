/*
ID: abdulah2
PROG: preface
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
int val[8];
int pval[8];
string roman[4444];
string sym[8];
string pres[8];
int ans[8];
map<char,int> cnt;

void count(string str)
{
    for(int i=0;i<sz(str);++i)
    {
        cnt[str[i]]++;
    }
}

void out()
{
    for(int i=1;i<=n;++i)
    {
        count(roman[i]);
    }
    int k = 0;
    if(cnt.count('I'))
    {
        cout<<"I "<<cnt['I']<<endl;
        ans[k++] = cnt['I'];
    }
    if(cnt.count('V')) cout<<"V "<<cnt['V']<<endl;
    if(cnt.count('X')) cout<<"X "<<cnt['X']<<endl;
    if(cnt.count('L')) cout<<"L "<<cnt['L']<<endl;
    if(cnt.count('C')) cout<<"C "<<cnt['C']<<endl;
    if(cnt.count('D')) cout<<"D "<<cnt['D']<<endl;
    if(cnt.count('M')) cout<<"M "<<cnt['M']<<endl;
}

void solve()
{
    cin>>n;
    sym[0] = "I";
    val[0] = 1;

    sym[1] = "V";
    val[1] = 5;
    pval[1] = 0;
    pres[1] = "I";

    sym[2] = "X";
    val[2] = 10;
    pres[2] = "I";
    pval[2] = 1;

    sym[3] = "L";
    val[3] = 50;
    pres[3] = "X";
    pval[3] = 2;

    sym[4] = "C";
    val[4] = 100;
    pres[4] = "X";
    pval[4] = 2;

    sym[5] = "D";
    val[5] = 500;
    pres[5] = "C";
    pval[5] = 4;

    sym[6] = "M";
    val[6] = 1000;
    pres[6] = "C";
    pval[6] = 4;

    roman[0] = "";
    roman[1] = "I";
    roman[2] = "II";
    roman[3] = "III";
    roman[4] = "IV";
    roman[5] = "V";
    roman[6] = "VI";
    roman[7] = "VII";
    roman[8] = "VIII";
    roman[9] = "IX";
    roman[10] = "X";
    roman[40] = "XL";
    roman[50] = "L";
    roman[100] = "C";
    roman[500] = "D";
    roman[1000] = "M";

    int lmt=11111;
    int now = 2,in = 0, kk=0;
    int pk = 0;
    for(int i=11;i<=n;++i)
    {
        if(i >= val[now+1] - val[pval[now+1]] && pk < val[pval[now+1]] && i<=1000)
        {
            pk++;
            if(in==0)
            {
                in = 1;
            }
            int k = i - val[now+1] + val[pval[now+1]];
            roman[i] = pres[now+1] + sym[now+1] + roman[k];
        }
        else
        {
            //dbg(i);
            pk=0;
            if(in==1)
            {
                now++;
                in = 0;
            }
            int k = i - val[now];
    //        if(i==51)
    //        {
    //            dbg2(k,val[now]);
    //        }
            roman[i] = sym[now] + roman[k];
        }
    //    dbg(roman[51]);
        kk++;
        //cout<<"["<<i<<"]"<< roman[i]<<"===";
        if(kk==6)
        {
            //cout<<endl;
            kk = 0;
        }
    }
    out();
}

int main()
{
    freopen("preface.in","r",stdin);
    freopen("preface.out","w",stdout);
    solve();
    return 0;
}
