#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
struct Work
{
    int st,ed,w;
    Work(int st,int ed,int w):st(st),ed(ed),w(w){}
    bool operator < (const Work &b)
    {
        if(ed==b.ed)return st<b.st;
        return ed>b.ed;
    }
};
ll dp[250005];
int chose[250005];
bitset<250005> did;
int nxt[250005];
int main()
{
    sint(n);
    vector<Work> v,tmp;
    for(int i=0;i<n;i++)
    {
        sint3(x,y,w);
        v.pb(x,y,w);
    }
    sort(all(v));
    // for(Work x : v)
    // {
    //     printf("%d %d %d\n",x.st,x.ed,x.w);
    // }
    if(n<=2000)
    {
        ll fuck=0;
        tmp=v;
        for(int i=0;i<n;i++)
        {
            memset(dp,0,sizeof(dp));
            int ban=i;
            v=tmp;
            v.erase(v.begin()+ban);
            for(int j=0;j<v.size();j++)
            {
                nxt[j]=v.size();
                int l=j+1,r=v.size()-1;
                while(l<=r)
                {
                    int md=(l+r)/2;
                    if(v[md].ed<v[j].st)
                    {
                        r=md-1;
                        nxt[j]=md;
                    }
                    else l=md+1;
                }
            }
            dp[n-1]=0;
            for(int j=n-2;j>=0;j--)
            {
                if(dp[j+1]>dp[nxt[j]]+v[j].w)
                    dp[j]=dp[j+1];
                else
                    dp[j]=dp[nxt[j]]+v[j].w;
            }
            fuck=max(fuck,dp[0]+tmp[i].w);
        }
        Wl(fuck);
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        nxt[i]=n;
        int l=i+1,r=n-1;
        while(l<=r)
        {
            int md=(l+r)/2;
            if(v[md].ed<v[i].st)
            {
                r=md-1;
                nxt[i]=md;
            }
            else l=md+1;
        }
    }
    dp[n]=0;
    chose[n]=-1;
    for(int i=n-1;i>=0;i--)
    {
        if(dp[i+1]>dp[nxt[i]]+v[i].w)
        {
            dp[i]=dp[i+1];
            chose[i]=i+1;
            did[i]=0;
        }
        else
        {
            dp[i]=dp[nxt[i]]+v[i].w;
            chose[i]=nxt[i];
            did[i]=1;
        }
    }
    vi use;
    int idx=0;
    while(chose[idx]!=-1)
    {
        if(did[idx])
            use.pb(idx);
        idx=chose[idx];
    }
    sort(all(use));
    int q=0;
    ll mx=0;
    for(int i=0;i<v.size();i++)
    {
        if(i==use[q])
        {
            q++;
            continue;
        }
        mx=max(mx,(ll)v[i].w);
    }
    Wl(dp[0]+mx);
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
