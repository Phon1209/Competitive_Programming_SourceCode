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
struct Job
{
    int a,b;
    int idx;
    bool operator < (const Job &A)
    {
        if(b==A.b)return a<A.a;
        return b>A.b;
    }
    Job(int a,int b,int idx):a(a),b(b),idx(idx){}
};
vector<Job> v;








ll tod[100005];
ll ans[100005];
void updateTOD(int idx,int val)
{
    while(idx<=100000)
    {
        tod[idx]+=val;
        idx+=(idx&-idx);
    }
}
ll sumtod(int idx){
    ll ret=0;
    while(idx)
    {
        ret+=tod[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
void updateANS(int idx,int val)
{
    while(idx<=100000)
    {
        ans[idx]=max(ans[idx],sumtod(idx)+val);
        idx+=(idx&-idx);
    }
}
ll sumANS(int idx)
{
    ll ret=0;
    while(idx>0)
    {
        ret=max(ret,ans[idx]);
        idx-=(idx&-idx);
    }
    return ret;
}



int main()
{
    sint2(n,t);
    sint2(m1,m2);
    for(int i=1;i<=n;i++)
    {
        sint2(x,y);
        v.pb(x,y,i);
    }
    sort(all(v));
    for(int i=0;i<v.size();i++)
    {
        int idx=v[i].idx;
        endl;
        for(int i=1;i<=n;i++){
            W(sumtod(i));
        }
        endl;
        updateANS(idx,v[i].a+v[i].b);
        updateTOD(idx,v[i].a);
        for(int i=1;i<=n;i++){
            W(sumANS(i));
        }
        endl;
    }
    for(int i=1;i<=n;i++){
        Wl(sumANS(i));
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*
4 1 1 1
1 4
5 3
4 3
5 2
*/
