#include<bits/stdc++.h>
using namespace std;
// #define DEBUG
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
#define MOD 1000000007
vi v;
vi l[4];
int n,k;
ll sub2(int u)
{
    if(u==v.size())
    {
        return 1;
    }
    ll ret=0;
    for(int i=1;i<=3;i++)
    {
        if(l[i].empty() || abs(l[i].back()-v[u])<=k)
        {
            l[i].emplace_back(v[u]);
            ret+=sub2(u+1);
            ret%=MOD;
            l[i].pop_back();
        }
    }
    return ret;
}
tuple<int,int,int> mm(tuple<int,int,int> x){
    int a,b,c;
    tie(a,b,c)=x;
    if(a>b)swap(a,b);
    if(b>c)swap(a,c);
    if(a>b)swap(a,b);
    return mkt(a,b,c);
}
map<tuple<int,int,int>,ll> dp;
int main()
{
    int2(n,k);
    int e;
    bool sub1=true;
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb(tmp);
        if(i==0)e=tmp;
        else if(e!=tmp)sub1=false;
    }
    if(sub1) //sub1 = 2 pts
    {
        ll ans=1;
        for(int i=0;i<n;i++)
        {
            ans*=3;
            ans%=MOD;
        }
        Wl(ans);
        return 0;
    }
    if(n<=10) //sub2 = 3 pts
    {
        Wl(sub2(0));
        return 0;
    }
    if(n<=100) //sub3 = 15pts
    {
        ll ans=0;
        vector<tuple<int,int,int> > q[2];
        dp[mkt(0,0,0)]=1;
        q[0].emplace_back(0,0,0);
        int idx=0;
        for(int i=1;i<=n;i++)
        {
            int y=v[i-1];
            q[1-idx].clear();
            for(int j=0;j<q[idx].size();j++)
            {
                tuple<int,int,int> bef,aft;
                bef=q[idx][j];
                int o=get<0>(bef);
                int o2=get<1>(bef);
                int o3=get<2>(bef);
                if(o==0 || abs(v[o-1]-y)<=k)
                {
                    aft=mkt(i,o2,o3);
                    aft=mm(aft);
                    if(i==n)ans+=dp[bef];
                    ans%=MOD;
                    if(dp.find(aft)==dp.end())
                    {
                        q[1-idx].pb(aft);
                    }
                    dp[aft]+=dp[bef];
                    dp[aft]%=MOD;
                }
                if(o2==0 || abs(v[o2-1]-y)<=k)
                {
                    aft=mkt(o,i,o3);
                    aft=mm(aft);
                    if(i==n)ans+=dp[bef];
                    ans%=MOD;
                    if(dp.find(aft)==dp.end())
                    {
                        q[1-idx].pb(aft);
                    }
                    dp[aft]+=dp[bef];
                    dp[aft]%=MOD;
                }
                if(o3==0 || abs(v[o3-1]-y)<=k)
                {
                    aft=mkt(o,o2,i);
                    aft=mm(aft);
                    if(i==n)ans+=dp[bef];
                    ans%=MOD;
                    if(dp.find(aft)==dp.end())
                    {
                        q[1-idx].pb(aft);
                    }
                    dp[aft]+=dp[bef];
                    dp[aft]%=MOD;
                }
            }
            idx = 1-idx;
        }
        Wl(ans);
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
