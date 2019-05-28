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
ii lca(ii a,ii b)
{
    while(1)
    {
        int A,B;
        A=__builtin_popcount(a.F)+__builtin_popcount(a.S);
        B=__builtin_popcount(b.F)+__builtin_popcount(b.S);
        printf("a :");
        Dbug(a);
        printf("b :");
        Dbug(b);
        pause;

        ii tmpa=a,tmpb=b;
        int l,r;
        bool shifta,shiftb;
        //assign a
        l=(a.F)? (a.F&(-a.F)):inf;
        r=(a.S)? (a.S&(-a.S)):inf;
        if(l<r)tmpa.F-=l,shifta=0;
        else   tmpa.S-=r,shifta=1;
        //assign b
        l=(b.F)? (b.F&(-b.F)):inf;
        r=(b.S)? (b.S&(-b.S)):inf;
        if(l<r)tmpb.F-=l,shiftb=0;
        else   tmpb.S-=r,shiftb=1;
        printf("tmpa :");
        Dbug(tmpa);
        printf("tmpb :");
        Dbug(tmpb);
        pause;
        if(A>B)a=tmpa;
        else if(A<B)b=tmpb;
        else if(A==B)
        {
            if(tmpa!=tmpb)
            {
                a=tmpa;
                b=tmpb;
                continue;
            }
            if(shifta ^ shiftb)return tmpa;
            else
            {
                if(shiftb)
            }
        }
    }
}
ll dist(ii a,ii b)
{

}
int main()
{
    sint(n);
    vii v;
    ii p={-1,-1};
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        if(p==mkp(-1,-1))p=mkp(x,y);
        else p=lca(p,{x,y});
        Dbug(p);
        v.pb(mkp(x,y));
    }
}
/*
0010
0001

0100
0010

0 0101
1 0000



2 1
0010
0001

4 3

0100
0010

4 1
0100
0001
4 2
0100
0010


0 8
0000 0000
0000 1000
16 0
0001 0000
0000 0000
*/
