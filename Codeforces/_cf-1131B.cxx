#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
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
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void wl(int x)
{
    printf("%d\n",x);
}
void wl(double x)
{
    printf("%lf\n",x);
}
void wl(string x)
{
    printf("%s\n",x.c_str());
}
void wl(ll x)
{
    printf("%lld\n",x);
}
void w(int x)
{
    printf("%d ",x);
}
void w(double x)
{
    printf("%lf ",x);
}
void w(string x)
{
    printf("%s ",x.c_str());
}
void w(ll x)
{
    printf("%lld ",x);
}
void Dbug(ii a)
{
    cout<< "First : " << a.F << "  Second : " << a.S;endl;
}
int main()
{
    // OPEN;
    // SEND;
    sint(n);
    vii v;
    v.pb(mkp(0,0));
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        v.pb(mkp(x,y));
    }
    ii curr;
    int ans=1;
    for(int i=1;i<v.size();i++)
    {
        int a,b;
        curr=v[i-1];
        a=v[i].F-v[i-1].F;
        b=v[i].S-v[i-1].S;
        // debug(a);
        // debug(b);
        // printf("curr :");
        // Dbug(curr);
        if(curr.F==curr.S)
        {
            ans+=min(a,b);
        }
        else if(curr.F<curr.S)
        {
            int diff=curr.S-curr.F;
            a-=diff;
            if(a>=0)ans++;
            ans+=max(0,min(a,b));
        }
        else if(curr.F>curr.S)
        {
            int diff=curr.F-curr.S;
            b-=diff;
            if(b>=0)ans++;
            ans+=max(0,min(a,b));

        }
    }
    w(ans);
}
/*

*/
