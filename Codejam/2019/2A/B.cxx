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
double mat[10][10];
int main()
{
    int t,w;
    scanf("%d %d",&t,&w);
    while(t--)
    {
        printf("214\n");
        fflush(stdout);
        ll d,e,f;
        ll ret=0;
        scanf("%lld",&ret);
        ret/=(1LL<<35);
        f=ret%128;
        ret/=(1LL<<7);
        e=ret%128;
        ret/=(1LL<<11);
        d=ret;

        printf("42\n");
        fflush(stdout);
        scanf("%lld",&ret);
        ret-=(1LL<<10)*d;
        ret-=(1LL<<8)*e;
        ret-=(1LL<<7)*f;
        ll a,b,c;
        ret/=(1LL<<14);
        c=ret%128;
        ret/=(1LL<<7);
        b=ret%128;
        ret/=(1LL<<21);
        a=ret%128;

        W(a),W(b),W(c),W(d),W(e),Wl(f);
        fflush(stdout);
        int vd;
        scanf("%d",&vd);
        assert(vd==1);
    }
}
/*
42  = 2^42 2^21 2^14  2^10  2^8  2^7
256 = 2^25 2^42  2^7  2^53 2^42 2^35
63
*/
