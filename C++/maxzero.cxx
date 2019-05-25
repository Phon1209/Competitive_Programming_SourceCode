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
int sq;
vii query[400];
int a[100005];
int ff[200005],lf[200005],tf[200005];
void _main()
{
    sint(n);
    sq=sqrt(n);
    memset(tf,-1,sizeof(tf));
    memset(ff,-1,sizeof(ff));
    memset(lf,-1,sizeof(lf));
    for(int i=1;i<=n;i++)
        int1(a[i]);
    sint(q);
    for(int i=0;i<q;i++)
    {
        sint2(x,y);
        query[(x+sq-1)/sq].pb(mkp(y,x));
    }
    debug(sq);
    ll fin=0;
    for(int i=1;i<=sq+1;i++)
    {
        if(query[i].empty())continue;
        sort(all(query[i]));
        int border=i*sq;
        int cnt=border;
        int sum=100001;
        lf[sum]=ff[sum]=border;
        debug(border);
        int mx=0,ans=0;
        for(int j=0;j<query[i].size();j++)
        {
            int x,y;
            x=query[i][j].S;
            y=query[i][j].F;
            debug(x);
            debug(y);
            while(cnt<y)
            {
                cnt++;
                sum+=a[cnt];
                debug(cnt);
                debug(sum);
                if(ff[sum]==-1)ff[sum]=cnt;
                lf[sum]=cnt;
                debug(ff[sum]);
                debug(lf[sum]);
                ans=max(ans,cnt-ff[sum]);
            }
            debug(ans);
            mx=0;
            int tmp=100001;
            for(int k=border;cnt>border && k>=x;k--)
            {
                tmp-=a[k];
                if(lf[tmp]!=-1)mx=max(mx,lf[tmp]-k+1);
            }
            debug((ans));
            tmp=100001;
            tf[tmp]=x-1;
            for(int k=x;k<=min(border,y);k++)
            {
                tmp+=a[k];
                debug(tmp);
                if(tf[tmp]!=-1)mx=max(mx,k-tf[tmp]);
                else tf[tmp]=k;
            }
            tmp=100001;
            tf[tmp]=-1;
            for(int k=x;k<=min(border,y);k++)
            {
                tmp+=a[k];
                tf[tmp]=-1;
            }
            debug(((ans)));
            // Wl(ans);
            fin+=max(mx,ans);
        }
        sum=100001;
        lf[sum]=ff[sum]=-1;
        while(border<cnt)
        {
            border++;
            sum+=a[border];
            lf[sum]=ff[sum]=-1;
        }
    }
    Wl(fin);
}
int main()
{
    sint(t);
    while(t--)_main();
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
