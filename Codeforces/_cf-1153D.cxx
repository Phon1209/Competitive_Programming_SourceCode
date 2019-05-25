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

ll fw[100005];
void add(int idx,int val)
{
    for(int i=idx;i<100005;i+=(i&-i))fw[i]+=val;
}
ll sum(int idx)
{
    ll ret=0;
    while(idx>0)
    {
        ret+=fw[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    slong(n);
    slong(k);
    ll mn=(k*(k+1))/2,mx;
    if(k>63)mx=LLONG_MAX;
    else mx=(1LL<<k)-1;
    if(k==1)
    {
        if(n==1)printf("YES\n1\n");
        else printf("NO\n");
        return 0;
    }
    if(k==2)
    {
        if(n==3)printf("YES\n1 2");
        else printf("NO\n");
        return 0;
    }
    if(n>=mn && n<=mx)
    {
        Wl("YES");
        for(int i=1;i<=k;i++){
            add(i,1);
        }
        ll now=mn;
        int idx=3;
        while(1)
        {
            // for(int i=1;i<=k;i++)
            // {
            //     printf("%lld ",sum(i));
            // }
            // endl;

            ll spare=((1LL<<(idx-1))-sum(idx))*(k-idx+1);
            debug(spare);
            debug(now);
            if(now+spare<=n)
            {
                add(idx,((1LL<<(idx-1))-sum(idx)));
                now+=spare;
                if(now==n)break;
                idx++;
            }
            else
            {
                ll okay=(k-idx+1);
                ll use = ((n-now)/okay)*okay;
                ll rem = n-now-use;
                add(idx,use);
                add(k-rem+1,1);
                break;
            }
        }
        for(int i=1;i<=k;i++)
        {
            printf("%lld ",sum(i));
        }
    }
    else
    {
        Wl("NO");
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*
min = triangle - number
max = 2^k -1
*/
