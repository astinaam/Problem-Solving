/*
ID: abdulah2
PROG: nocows
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
int n,k;

int tstore[201][101];

int tree(int a,int b){
    int i,j,sum=0,temp1,temp2;
    if (a==0 || b==0) return 0;
    if (a==1) return 1;
    if (tstore[a][b]!=-1) return tstore[a][b];
    else 
    for (i=1;i<a-1;i++)
        sum=(sum+tree(i,b-1)*tree(a-i-1,b-1))%9901;
    tstore[a][b]=sum;
    return sum;
}

int main(){
    FILE *in,*out;
    in=fopen("nocows.in","r");
    out=fopen("nocows.out","w");
    int N,K,i,j;
    for (i=0;i<=200;i++) for (j=0;j<=100;j++) tstore[i][j]=-1;
    fscanf(in,"%d %d",&N,&K);
    fprintf(out,"%d\n",(9901+tree(N,K)-tree(N,K-1))%9901);
    return 0;
}
