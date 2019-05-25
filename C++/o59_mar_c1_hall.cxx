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
vector<tuple<ii,int> > v[2]; //rank 1, rank 2, index
int s[100005];
int rnk[100005];
int usable;
void suffix_array(int n)
{
    for(int i=0;i<n;i++)
    {
        v[0].pb(mkp(0,s[i]),i);
    }
    sort(all(v[0]));
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int u=get<1>(v[0][i]);
        cnt = (i!=0 && get<0>(v[0][i]) == get<0>(v[0][i-1]))? cnt:cnt+1;
        rnk[u]=cnt;
    }
    int now=0;
    for(int t=1;(1<<t)<=n;t<<=1)
    {
        now^=1;
        v[now].clear();
        for(int i=0;i<n;i++)
        {
            int u=get<1>(v[now^1][i]);
            v[now].pb(mkp(rnk[u],rnk[(u+t)%n]),u); //mod n for making circular
        }
        sort(all(v[now]));
        cnt=0;
        for(int i=0;i<n;i++){
            int u=get<1>(v[now][i]);
            cnt = (i!=0 && get<0>(v[now][i]) == get<0>(v[now][i-1]))? cnt:cnt+1;
            rnk[u]=cnt;
        }
        usable=now;
        if(cnt==n)break;
    }
}
int prv[100005];
int main()
{
    sint(n);
    for(int i=0;i<n;i++)int1(s[i]);
    suffix_array(n);

    prv[get<1>(v[usable][0])]=-1;
    for(int i=1;i<n;i++)prv[get<1>(v[usable][i])]=get<1>(v[usable][i-1]);
    int ans=0,l=0;
    for(int i=0;i<n;i++)
    {
        if(prv[i]==-1)continue;
        while(l<n && s[(i+l)%n]==s[(prv[i]+l)%n])l++; // mod n for cicular
        ans=max(ans,l);
        l=max(0,l-1);
    }
    Wl(ans==n? -1:ans);
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*

*/
