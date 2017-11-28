#include<bits/stdc++.h>

using namespace std;

int n;

int arr[11111];

int sz(int x)
{
    int len=0;
    while(x)
    {
        x/= 10;
        len++;
    }
    return len;
}

int main()
{
    cin>>n;
    int cnt=0;
    for(int i=1;;++i)
    {
        int p = sz(i);
        if(cnt + p >= n)
        {
            int rest = n - cnt;

            vector<int>v;
            int x=i;
            cerr<<x<<" "<<rest<<endl;;
            while(x)
            {
               //cerr<<(x%10)<<endl;
                v.push_back(x%10);
                x/=10;
            }
            reverse(v.begin(),v.end());
            //for(int j=0;j<v.size();++j) cerr<<v[j]<<" ";
            //cerr<<endl;
            cout<<v[rest-1]<<endl;
            return 0;
        }
        else cnt +=p;
    }
}
