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
vector<string> v;
struct attrib
{
    char l,r;
    int ll=0,rr=0;
    int mx=0;
    bool full=0;
    void copy(attrib a)
    {
        l=a.l;
        r=a.r;
        ll=a.ll;
        rr=a.rr;
        full=a.full;
        mx=a.mx;
    }
    void reset()
    {
        l=r=ll=rr=full=mx=0;
    }
    void print()
    {
        printf("%d\n",max(mx,max(ll,rr)));
    }
    void bug()
    {
        debug(l);
        debug(r);
        debug(ll);
        debug(rr);
        debug(mx);
        printf("full = %d\n",(full)? 1:0);
    }
    void ensure()
    {
        assert(ll<=1000000000);
        assert(rr<=1000000000);
        assert(mx<=1000000000);
    }
};
int main()
{
    sint(n);
    attrib ans,New;
    for(int i=0;i<n;i++)
    {
        sstring(s);
        v.pb(s);
    }
    for(int i=n-1;i>=0;i--)
    {
        New.reset();
        if(i==n-1)
        {
            ans.l=v[i][0];
            ans.r=v[i][v[i].size()-1];
            for(int j=0;j<v[i].size();j++)
            {
                if(v[i][j]==ans.l)ans.ll++;
                else break;
            }
            for(int j=v[i].size()-1;j>=0;j--)
            {
                if(v[i][j]==ans.r)ans.rr++;
                else break;
            }
            char tmp='A';
            int now=0;
            for(int j=0;j<v[i].size();j++)
            {
                now=(v[i][j]==tmp)? now+1:1;
                tmp=v[i][j];
                ans.mx=max(ans.mx,now);
            }
            if(ans.mx==v[i].size())ans.full=1;
        }
        else
        {
            if(ans.full)
            {
                char want=ans.l;
                New.l=ans.l;
                New.ll=ans.ll;
                New.r=ans.r;
                New.rr=ans.rr;
                for(int j=0;j<v[i].size();j++)
                {
                    if(v[i][j]==want)
                    {
                        New.ll+=(1+ans.ll);
                        if(j==v[i].size()-1)New.full=1;
                    }
                    else break;
                }
                for(int j=v[i].size()-1;j>=0;j--)
                {
                    if(v[i][j]==want)New.rr+=(1+ans.rr);
                    else break;
                }
                int now=0;
                int mx=0;
                for(int j=0;j<v[i].size();j++)
                {
                    if(v[i][j]==want) now++;
                    else now=0;
                    mx=max(mx,now);
                }
                now=((mx+1)*ans.ll)+mx;
                New.mx=max(max(ans.mx,now),max(New.ll,New.rr));
            }
            else
            {
                New.l=ans.l;
                New.ll=ans.ll;
                New.r=ans.r;
                New.rr=ans.rr;
                New.full=0;
                int now=1;
                for(int j=0;j<v[i].size();j++)
                {
                    if(v[i][j]==ans.l && v[i][j]==ans.r)
                        now=max(now,1+ans.ll+ans.rr);
                    else if(v[i][j]==ans.l)
                        now=max(now,1+ans.ll);
                    else if(v[i][j]==ans.r)
                        now=max(now,1+ans.rr);
                    else
                        now=max(now,1);
                }
                New.mx=max(max(ans.mx,now),max(New.ll,New.rr));
            }
            ans.copy(New);
        }
    }
    ans.print();
}
/*
llbnlllbnhllbnlllbnpllbnlllbn
*/
