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
struct interval
{
    int x,y;
    bool operator <(interval const &b)
    {
        if(x != b.x)return x > b.x;
        return y<b.y;
    }
    interval(int x,int y):x(x),y(y){}
};
int main()
{
    vector<interval> v;
    sint(n);
    FOR(i,0,n)
    {
        sint2(x,y);
        v.pb({x,y});
    }
    sort(all(v));
    vii lis;
    vi prev;
    prev.assign(n,-1);
    for(int i=0;i<v.size();i++)
    {//v[i].y; use upper
        int use=v[i].y;
        // debug(i);
        // debug(use);
        if(lis.empty()){
            lis.pb(mkp(use,i));
            prev[i]=-1;
        }
        else
        {
            auto it=upper_bound(all(lis),mkp(use,1000000));
            int idx=it-lis.begin();
            if(it==lis.end())
            {
                lis.pb(mkp(use,i));
                // debug(1);
            }
            else
                lis[idx]=mkp(use,i);
                // debug(idx);
            if(it==lis.begin())
            {
                prev[i]=-1;
                // debug(2);
            }
            else
                prev[i]=lis[idx-1].S;
            // debug(prev[i]);
        }
    }
    int iter=lis.back().S;
    wl(int(lis.size()));
    while(iter!=-1)
    {
        printf("%d %d\n",v[iter].x,v[iter].y);
        iter=prev[iter];
    }
}
/*

*/
