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
int checkQ(ll x,ll y,int k)
{
    if(x<(1ll<<(k-1)))
    {
        if(y<(1ll<<(k-1)))return 1;
        else return 2;
    }
    else
    {
        if(y<(1ll<<(k-1)))return 4;
        else return 3;
    }
}
typedef pair<ll,ll> pll;
tuple<pll,pll,pll,pll> getAround(ll x,ll y,int k)
{
    ll p=(1ll<<k);
    pll a[5];
    a[1]=mkp(x/p,y/p);
    a[2]=mkp(x/p,ceil((double)(y+1)/p));
    a[3]=mkp(ceil((double)(x+1)/p),y/p);
    a[4]=mkp(ceil((double)(x+1)/p),ceil((double)(y+1)/p));
    for(int i=1;i<=4;i++)a[i].F*=p,a[i].S*=p;
    a[2].S--;
    a[3].F--;
    a[4].F--;
    a[4].S--;
    return mkt(a[1],a[2],a[3],a[4]);
}
pll jump[55][5],jump2[55][5];
map<pll,bool> ext[2];
map<pll,ll> dp[2];
ll cost(pll x,pll y,int lv)
{
    bool pass=false;
    if(x.F%(1ll<<lv)==0 || x.S%(1ll<<lv)==0)pass=true;
    if(((x.F+1)%(1ll<<lv))==0 || ((x.S+1)%(1ll<<lv))==0)pass=true;
    if(!pass)return LLONG_MAX/2ll;
    // debug(llabs(x.F-y.F) + llabs(x.S-y.S));
    return llabs(x.F-y.F) + llabs(x.S-y.S);
}
ll cost2(pll x,pll y,int lv)
{
    bool pass=false;
    if(x.F%(1ll<<lv)==0 || x.S%(1ll<<lv)==0)pass=true;
    if(((x.F+1)%(1ll<<lv))==0 || ((x.S+1)%(1ll<<lv))==0)pass=true;
    if(!pass)return LLONG_MAX/2ll;

    bool pass2=false;
    if(y.F%(1ll<<lv)==0 || y.S%(1ll<<lv)==0)pass2=true;
    if(((y.F+1)%(1ll<<lv))==0 || ((y.S+1)%(1ll<<lv))==0)pass2=true;
    if(!pass2)return LLONG_MAX/2ll;

    return llabs(x.F-y.F) + llabs(x.S-y.S);
}
int main()
{
    sint(k);
    ll x1,y1,x2,y2;
    scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
    while(1)
    {
        int Q=checkQ(x1,y1,k);
        if(Q==checkQ(x2,y2,k))
        {
            if(Q==2)
            {
                y1-=((1ll<<(k-1)));
                y2-=((1ll<<(k-1)));
            }
            if(Q==3)
            {
                x1-=((1ll<<(k-1)));
                x2-=((1ll<<(k-1)));
                y1-=((1ll<<(k-1)));
                y2-=((1ll<<(k-1)));
            }
            if(Q==4)
            {
                x1-=((1ll<<(k-1)));
                x2-=((1ll<<(k-1)));
            }
            k--;
        }
        else break;
    }
    for(int i=1;i<=k;i++)
    {
        tie(jump[i][1],jump[i][2],jump[i][3],jump[i][4])=getAround(x1,y1,i);
    }
    for(int i=1;i<=4;i++)jump[0][i]=mkp(x1,y1);
    ext[0][mkp(x1,y1)]=true;
    dp[0][mkp(x1,y1)]=0;
    for(int i=1;i<=k;i++)
    {
        debug(i);
        for(int j=1;j<=4;j++)
        {
            if(!ext[0][jump[i][j]])
            {
                ext[0][jump[i][j]]=1;
                dp[0][jump[i][j]]=LLONG_MAX/2ll;
            }
            for(int l=1;l<=4;l++)
            {
                // printf("%d %d\n",jump[j][i].F,jump[j][i].S);
                dp[0][jump[i][j]]=min(dp[0][jump[i][j]],dp[0][jump[i-1][l]]+cost(jump[i-1][l],jump[i][j],i));
                // printf("%lld %lld = %lld\n",jump[i][j].F,jump[i][j].S,dp[0][jump[i][j]]);
            }
        }
    }
    //
    // endl;
    // endl;
    // endl;

    for(int i=1;i<=k;i++)
    {
        tie(jump2[i][1],jump2[i][2],jump2[i][3],jump2[i][4])=getAround(x2,y2,i);
    }
    for(int i=1;i<=4;i++)jump2[0][i]=mkp(x2,y2);
    ext[1][mkp(x2,y2)]=true;
    dp[1][mkp(x2,y2)]=0;
    for(int i=1;i<=k;i++)
    {
        debug(i);
        for(int j=1;j<=4;j++)
        {
            if(!ext[1][jump2[i][j]])
            {
                ext[1][jump2[i][j]]=1;
                dp[1][jump2[i][j]]=LLONG_MAX/2ll;
            }
            for(int l=1;l<=4;l++)
            {
                // printf("%d %d\n",jump[j][i].F,jump[j][i].S);
                dp[1][jump2[i][j]]=min(dp[1][jump2[i][j]],dp[1][jump2[i-1][l]]+cost(jump2[i-1][l],jump2[i][j],i));
                // printf("%lld %lld = %lld\n",jump2[i][j].F,jump2[i][j].S,dp[1][jump2[i][j]]);

            }
        }
    }

    debug(k);
    ll ans=LLONG_MAX;
    if(checkQ(x1,y1,k)==1 && checkQ(x2,y2,k)==2)
    {
        ans=min(ans,dp[0][jump[k-1][2]]+dp[1][jump2[k-1][1]]+cost(jump[k-1][2],jump2[k-1][1],k));
    }
    if(checkQ(x1,y1,k)==1 && checkQ(x2,y2,k)==3)
    {
        ans=min(ans,dp[0][jump[k-1][2]]+dp[1][jump2[k-1][2]]+cost(jump[k-1][2],jump2[k-1][2],k));
        ans=min(ans,dp[0][jump[k-1][3]]+dp[1][jump2[k-1][3]]+cost(jump[k-1][3],jump2[k-1][3],k));
    }
    if(checkQ(x1,y1,k)==1 && checkQ(x2,y2,k)==4)
    {
        ans=min(ans,dp[0][jump[k-1][3]]+dp[1][jump2[k-1][1]]+cost(jump[k-1][3],jump2[k-1][1],k));
    }
    if(checkQ(x1,y1,k)==2 && checkQ(x2,y2,k)==1)
    {
        ans=min(ans,dp[0][jump[k-1][1]]+dp[1][jump2[k-1][2]]+cost(jump[k-1][1],jump2[k-1][2],k));

    }
    if(checkQ(x1,y1,k)==2 && checkQ(x2,y2,k)==3)
    {
        ans=min(ans,dp[0][jump[k-1][4]]+dp[1][jump2[k-1][2]]+cost(jump[k-1][4],jump2[k-1][2],k));

    }
    if(checkQ(x1,y1,k)==2 && checkQ(x2,y2,k)==4)
    {
        ans=min(ans,dp[0][jump[k-1][1]]+dp[1][jump2[k-1][1]]+cost(jump[k-1][1],jump2[k-1][1],k));
        ans=min(ans,dp[0][jump[k-1][4]]+dp[1][jump2[k-1][4]]+cost(jump[k-1][4],jump2[k-1][4],k));

    }
    if(checkQ(x1,y1,k)==3 && checkQ(x2,y2,k)==1)
    {
        ans=min(ans,dp[0][jump[k-1][2]]+dp[1][jump2[k-1][2]]+cost(jump[k-1][2],jump2[k-1][2],k));
        ans=min(ans,dp[0][jump[k-1][3]]+dp[1][jump2[k-1][3]]+cost(jump[k-1][3],jump2[k-1][3],k));

    }
    if(checkQ(x1,y1,k)==3 && checkQ(x2,y2,k)==2)
    {
        ans=min(ans,dp[0][jump[k-1][2]]+dp[1][jump2[k-1][4]]+cost(jump[k-1][2],jump2[k-1][4],k));

    }
    if(checkQ(x1,y1,k)==3 && checkQ(x2,y2,k)==4)
    {
        ans=min(ans,dp[0][jump[k-1][3]]+dp[1][jump2[k-1][4]]+cost(jump[k-1][3],jump2[k-1][4],k));

    }
    if(checkQ(x1,y1,k)==4 && checkQ(x2,y2,k)==1)
    {
        ans=min(ans,dp[0][jump[k-1][1]]+dp[1][jump2[k-1][3]]+cost(jump[k-1][1],jump2[k-1][3],k));

    }
    if(checkQ(x1,y1,k)==4 && checkQ(x2,y2,k)==2)
    {
        ans=min(ans,dp[0][jump[k-1][1]]+dp[1][jump2[k-1][1]]+cost(jump[k-1][1],jump2[k-1][1],k));
        ans=min(ans,dp[0][jump[k-1][4]]+dp[1][jump2[k-1][4]]+cost(jump[k-1][4],jump2[k-1][4],k));

    }
    if(checkQ(x1,y1,k)==4 && checkQ(x2,y2,k)==3)
    {
        ans=min(ans,dp[0][jump[k-1][4]]+dp[1][jump2[k-1][3]]+cost(jump[k-1][4],jump2[k-1][3],k));

    }
    Wl(ans);

    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
