#include<bits/stdc++.h>

using namespace std;

void parray(int _a[],int _n)
{
    cerr<<"---->Printing array<--"<<endl;
    int _k=1;
    for(int i=0;i<_n;++i)
    {
        cerr<<"("<<setw(2)<<i<<")="<<setw(6)<<_a[i]<<", ";
        if(_k%5==0) cout<<endl;
        _k++;
    }
    cerr<<"\nDone Printing array-->"<<endl;
}

int n,m;
int chk[1010];
int idx;
int arr[10000];

int main()
{
    scanf("%d%d",&n,&m);
    bitset<2001>A,B;
    if(n >= m)
    {
        puts("YES");
        return 0;
    }
    while(n--)
    {
        int k;
        scanf("%d",&k);
        B = A << k;
       // cerr<<endl<<"A<<k = "<<B<<endl;
        A |= B;
       // cerr<<"A|=B = "<<A<<endl;
        B = A >> m;
      //  cerr<<"A>>m = "<<B<<endl;
        A |= B;
      //  cerr<<"A|=B = "<<A<<endl;
        A.set(k%m);
      //  cerr<<"SET  = "<<A<<endl;
    }
    if(A[0]) puts("YES");
    else puts("NO");
}

int mainn()
{
    cin>>n>>m;
    for(int i=0;i<n;++i)
    {
        int t;
        cin>>t;
        int sz = idx;
        for(int j=0;j<sz;++j)
        {
            int k = (arr[j]+t)%m;
            if(!chk[k])
            {
                arr[idx++] = k;
                chk[k]=1;
            }
        }
        int  k = t%m;
        if(!chk[k])
        {
            arr[idx++] = k;
            chk[k]=1;
        }
        if(chk[0])
        {
            puts("YES");
            return 0;
        }
    }
    cout<<"NO"<<endl;
}
