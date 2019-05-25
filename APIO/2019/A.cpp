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
vector<pair<ll,ll> > v;
map<pair<ll,ll> , int> mp;
ll mx=(1000000000000000000LL);
int main()
{
    // IN("output.txt");
    // OUT("ANSWER.txt");
    //40 15 14
    sint(n);
    slong(a);
    slong(b);
    ll ans;
    bool ignore = false;
    if(mx/b < a){
        ignore=true;
        ans=mx;
    }
    else ans=a*b;
    ll Tmod=a*b;
    ll tod=(b+1)%a;
    if(tod==0)
    {
        Tmod=b;
    }
    else if(a%tod==0)
    {
        Tmod/=tod;
    }
    // if(b%4==1)
    // {
    //     if(a%2){Tmod=a*b;ans=Tmod;}
    //     else ans=Tmod=(a/2)*b;
    //     ignore=false;
    // }
    // else if(b%4==3)
    // {
    //     if(a%2){Tmod=a*b;ans=Tmod;}
    //     else ans=Tmod=(a/4)*b;
    //     ignore=false;
    // }
    // debug(ignore);
    // debug(Tmod);
    for(int i=0;i<n;i++)
    {
        slong(x);
        slong(y);
        // for(int j=x;j<=y;j++)
        // {
        //     mp[mkp((j+(j/b))%a,j%b)];
        // }
        if(ignore)
        {
            v.pb(x,y);
        }
        else
        {
            if(x/Tmod != y/Tmod)
            {
                v.pb(x%Tmod,Tmod-1);
                v.pb(0,y%Tmod);
            }
            else
            {
                v.pb(x%Tmod,y%Tmod);
            }
        }
    }
    sort(all(v));
    // endl;
    // for(int i=0;i<v.size();i++)
    // {
    //     printf("%lld %lld\n",v[i].F,v[i].S);
    // }
    int X=0,Y=-1;
    // debug(ans);
    for(int i=0;i<v.size();i++)
    {
        if(v[i].F<=Y)
        {
            if(v[i].S>Y)
                Y=v[i].S;
        }
        else
        {
            ans-=(v[i].F-Y-1);
            X=v[i].F;
            Y=v[i].S;
        }
        // debug(ans);
    }
    if(ignore)
    {
        ans-=(mx-Y);
    }
    else ans-=(Tmod-1-Y);
    Wl(ans);
    // Wl((ll)mp.size());
    // debug(mp.size());
    // assert(ans == mp.size());
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*
3 3 3
4 4
7 9
17 18

3 5 10
1 20
50 68
89 98


2 16 13
2 5
18 18


1 - /2
3 - /4
5 - /2
7 - /4
9 - /2
11 - /4
13 - /2
15 - /4
17 - /2
19 - /4
21 - /
*/
