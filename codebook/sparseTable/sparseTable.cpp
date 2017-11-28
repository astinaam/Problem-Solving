#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define here cerr<<"Here"<<endl
typedef long long ll;
#define Int(x) scanf("%lld",&x)
#define N 100010
int n,q,arr[N],NL;
string s;

int st[N][20];

void preprocess()
{
	//RMQ
	//initialize
	for(int i=0;i<n;++i)
		st[i][0] = i;

	for(int j = 1; (1<<j) <= n ;++j)
	{
		for(int i=0 ; i + (1<<(j)) -1 < n ;++i)
		{
			if(arr[st[i][j-1]] < arr[st[i+(1<<(j-1))][j-1]]) 
				st[i][j] = st[i][j-1];
			else 
				st[i][j] = st[i+(1<<(j-1))][j-1];
			cerr<<"st["<<i<<"]["<<j<<"] = "<<st[i][j]<<endl;
		}
	}
}

int query(int l,int r)
{
	if(r < l) swap(l,r);
	int len = r - l + 1;
	int k = log2(len);
	cerr<<len <<" "<<k<<endl;
	int ans = min(arr[st[l][k]],arr[st[r - (1<<k) + 1][k]]);
	return ans;
}

int main()
{
	//NL = log2(N)+1;
	//cout<<NL<<endl;
	cin>>n;
	for(int i=0;i<n;++i) cin>>arr[i];
	preprocess();
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<"Query of "<<"{"<<l<<","<<r<<"} = "<<query(l,r)<<endl;
	}
}
