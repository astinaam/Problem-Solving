#include<bits/stdc++.h>
using namespace std;
const int MOD = (int) 1e9 + 7;
const int INF = (int) 1e9+21;
const long long LINF = (long long) 1e18;
const long double PI = 2 * acos((long double)0);
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
#define Mahmud main()
#define endl "\n"
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define alla(arr,n) arr,arr+n
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define pb push_back
#define FOR(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=n,i>=0;--i)
///Debug
#define dbg1(x) std::cerr<<#x<<"="<<(x)<<endl;
#define dbg2(x,y) std::cerr<<#x<<"="<<(x)<<','<<#y<<"="<<(y)<<endl;
#define dbg3(x,y,z) std::cerr<<#x<<"="<<(x)<<','<<#y<<"="<<(y)<<','<<#z<<"="<<(z)<<endl;
#define dbgArr(arr,n) cerr<<#arr<<"=["; printArray(arr,n,0,93); cerr<<endl;
///traversing
#define rep(n) for(int i=0;i<n;++i)
#define trv(i,t) for(__typeof(t.begin()) i=t.begin();i!=t.end();++i)
///necessary functions
inline ll Int()
{
    ll _x=0,_tmp=1;
    char _tc=getchar();
    while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
    if( _tc == '-' ) _tc=getchar(), _tmp = -1;
    while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
    return _x*_tmp;
}
inline long double Double()
{
    long double d;
    scanf("%Lf",&d);
    return d;
}
ll lcm(ll a,ll b)
{
    return a/__gcd(a,b)*b;
}
int ton(string x)
{
    int y;
    std::istringstream ss(x);
    ss >> y;
    return y;
}
template<typename T>
string tostring(T x)
{
    ostringstream ss;
    ss << x ;
    return ss.str();
}

///Current Code vars
#define N 100010

int frames;
int pages[N],page;
int fifo_queue[N];
int second_chance_queue[N];
int clock_queue[N];
int nru_queue[N];
int page_faults;
int rbit[N];
int mbit[N];
map<long long, int> exists;


void fifo()
{
    page_faults = 0;
    int front = 0, rear = 0,cnt = 0;
    //exists.clear();
    for(int i=0;i<page;++i)
    {
        if(exists[pages[i]] == 0)
        {
            // dbg3(i,pages[i],exists[pages[i]]);
            exists[pages[i]] = 1;
            page_faults++;
            if(cnt < frames)
            {
                fifo_queue[rear] = pages[i];
                rear++;
                cnt++;
            }
            else
            {
                front++;
                exists[fifo_queue[front-1]] = 0;
                fifo_queue[rear] = pages[i];
                rear++;
            }
        }
        cerr<<"for reference "<<pages[i]<<" page_faults = "<<page_faults<<endl;
        cerr<<"in frame = ";
        for(int j = front;j<rear;++j)
        {
            cerr<<fifo_queue[j]<<" ";
        }
        cerr<<endl;
    }
}

void Clock()
{
    RESET(rbit,0);
    // cout<<"Enter Reference Bits : "<<endl;
    // for(int i=0;i<page;++i)
    // {
    //     cin>>rbit[pages[i]];
    // }
    page_faults = 0;
    int front = 0, rear = 0, cnt = 0;
    //exists.clear();
    int hand = 0;
    for(int i=0;i<page;++i)
    {
        //dbg1(i);
        if(exists[pages[i]] == 0)
        {
            // dbg3(i,pages[i],"here");
            exists[pages[i]] = 1;
            page_faults++;
            if(cnt < frames)
            {
                second_chance_queue[rear] = pages[i];
                rear++;
                cnt++;
            }
            else
            {
                 //dbg2(front,rear);
                cerr<<"Enter Rbits : ";
                for(int x=0;x<frames;++x)
                {
                    cin>>rbit[x];
                }
                bool found = false;
                for(int x=hand;x<frames;++x)
                {
                    //dbg2(x,found);
                    if(rbit[x] == 0)
                    {
                        found = true;
                        exists[second_chance_queue[x]] = 0;
                        second_chance_queue[x] = pages[i];
                        //rear++;
                        
                        //front++;
                        hand = x + 1;
                        if(hand == frames - 1)
                        {
                            hand = 0;
                        }
                        break;
                    }
                    else
                    {
                        rbit[x] = 0;
                        //second_chance_queue[rear] = second_chance_queue[front];
                        //front++;
                        //rear++;
                    }
                    if(x == frames - 1 && !found)
                    {
                        x = -1;
                    }
                }
            }
        }
        else
        {
             //rbit[second_chance_queue[pages[i]]] = 1;
        }
        cerr<<"for reference "<<pages[i]<<" page_faults = "<<page_faults<<endl;
        cerr<<"in frame = ";
         //dbg2(front,rear);
        for(int j = front;j<rear;++j)
        {
            cerr<<second_chance_queue[j]<<" ";
        }
        cerr<<endl;
    }
}

int make_bin(int x, int y)
{
    if(x==0 && y==0) return 0;
    if(x==0 && y==1) return 1;
    if(x==1 && y==0) return 2;
    if(x==1 && y==1) return 3;
}

void nru()
{
    RESET(rbit,0);
    // cout<<"Enter Reference Bits : "<<endl;
    // for(int i=0;i<page;++i)
    // {
    //     cin>>rbit[pages[i]];
    // }
    RESET(mbit,0);
    // cout<<"Enter Modified Bits : "<<endl;
    // for(int i=0;i<page;++i)
    // {
    //     cin>>mbit[pages[i]];
    // }
    page_faults = 0;
    int front = 0, rear = 0, cnt = 0;
    //exists.clear();
    for(int i=0;i<page;++i)
    {
        if(exists[pages[i]] == 0)
        {
            exists[pages[i]] = 1;
            page_faults++;
            int rb,mb;
            
            rbit[pages[i]] = rb;
            mbit[pages[i]] = mb;
            if(cnt < frames)
            {
                nru_queue[rear] = pages[i];
                rear++;
                cnt++;
            }
            else
            {
                cerr<<"Enter Rbits : ";
                for(int x=0;x<frames;++x)
                {
                    cin>>rbit[x];
                }
                cerr<<"Enter Mbits : ";
                for(int x=0;x<frames;++x)
                {
                    cin>>mbit[x];
                }
                int find_min = 10, idx = 0;
                for(int j=0;j<frames;++j)
                {
                    int _bin = make_bin(rbit[j],mbit[j]);
                    //dbg2(_bin,find_min);
                    if(_bin < find_min) //finds the first one that is minimum 
                    {
                        idx = j;
                        find_min = _bin;
                    }
                }
                exists[nru_queue[idx]] = 0;
                nru_queue[idx] = pages[i];
            }
        }
        else
        {
             //rbit[nru_queue[pages[i]]] = 1;
        }
        cout<<"for reference "<<pages[i]<<" page_faults = "<<page_faults<<endl;
        cout<<"in frame = ";
        for(int j = front;j<rear;++j)
        {
            cout<<nru_queue[j]<<" ";
        }
        cout<<endl;
    }
}

void second_chance()
{
    RESET(rbit,0);
    // cout<<"Enter Reference Bits : "<<endl;
    // for(int i=0;i<page;++i)
    // {
    //     cin>>rbit[pages[i]];
    // }
    page_faults = 0;
    int front = 0, rear = 0, cnt = 0;
    //exists.clear();
    for(int i=0;i<page;++i)
    {
        //dbg1(i);
        if(exists[pages[i]] == 0)
        {
            // dbg3(i,pages[i],"here");
            exists[pages[i]] = 1;
            page_faults++;
            if(cnt < frames)
            {
                second_chance_queue[rear] = pages[i];
                rear++;
                cnt++;
            }
            else
            {
                 //dbg2(front,rear);
                cerr<<"Enter Rbits : ";
                for(int x=0;x<frames;++x)
                {
                    cin>>rbit[x];
                }
                bool found = false;
                for(int x=0;x<frames;++x)
                {
                    //dbg2(x,found);
                    if(rbit[x] == 0)
                    {
                        found = true;
                        second_chance_queue[rear] = pages[i];
                        rear++;
                        exists[second_chance_queue[front]] = 0;
                        front++;
                        break;
                    }
                    else
                    {
                        rbit[x] = 0;
                        second_chance_queue[rear] = second_chance_queue[front];
                        front++;
                        rear++;
                    }
                    if(x == frames - 1 && !found)
                    {
                        x = -1;
                    }
                }
            }
        }
        else
        {
             //rbit[second_chance_queue[pages[i]]] = 1;
        }
        cerr<<"for reference "<<pages[i]<<" page_faults = "<<page_faults<<endl;
        cerr<<"in frame = ";
         //dbg2(front,rear);
        for(int j = front;j<rear;++j)
        {
            cerr<<second_chance_queue[j]<<" ";
        }
        cerr<<endl;
    }
}

void solve()
{
    cout<<"No of Frames : ";
    cin>>frames;
    cout<<"No of pages : ";
    cin>>page;
    cout<<"Pages : ";
    for(int i=0;i<page;++i)
    {
        cin>>pages[i];
        exists[pages[i]] = 0;
    }
    cout<<"1.FiFo 2.Second Chance 3.Clock 4.NRU\n";
    int choice;
    cin>>choice;
    switch(choice)
    {
        case 1:
            fifo();
            break;
        case 2:
            second_chance();
            break;
        case 3:
            Clock();
            break;
        case 4:
            nru();
            break;
        default:
            fifo();
            break;
    }
}

int Mahmud
{
    // ios_base::sync_with_stdio(0); //cin.tie(0);
  //#ifdef _LOCAL_
    //freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
  //while(1)
    solve();
  //#ifdef _LOCAL_
    //printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
  //#endif
    return 0;
}
