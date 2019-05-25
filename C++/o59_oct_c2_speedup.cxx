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
#define eb emplace_back
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
ll g[80005][10];
bitset<80005> spec;
vii v[80005];
int main()
{
    sint2(n,m);
    sint2(sp,q);
    for(int i=0;i<m;i++)
    {
        sint3(x,y,w);
        v[x].pb(mkp(y,w));
    }
    for(int i=0;i<sp;i++)
    {
        sint(tmp);
        spec[tmp]=1;
    }
    for(int i=1;i<=n;i++)
        for(int j=0;j<=8;j++)
            g[i][j]=LLONG_MAX;
    priority_queue<tuple<ll,int,int,int> > pq;
    pq.push(mkt(0,1,0,-1));
    ll w;
    int u,bt,last;
    while(!pq.empty())
    {
        tie(w,u,bt,last)=pq.top();
        w=-w;
        // printf("%lld %d %d %d\n",w,u,bt,last);
        pq.pop();
        if(g[u][bt]<w)continue;
        g[u][bt]=w;
        if(u==n)
        {
            printf("%lld\n",w);
            break;
        }
        if(spec[u] && u!=last && bt<q && g[u][bt+1]>g[u][bt])
        {
            g[u][bt+1]=g[u][bt];
            pq.push(mkt(-g[u][bt+1],u,bt+1,u));
        }
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i].F;
            int cost=v[u][i].S;
            cost/=(1<<bt);
            if(g[y][bt]>g[u][bt]+cost)
            {
                g[y][bt]=g[u][bt]+cost;
                pq.push(mkt(-g[y][bt],y,bt,last));
            }
            if(spec[y] && g[y][bt+1]>g[u][bt]+cost && y!=last && bt<q)
            {
                g[y][bt+1]=g[u][bt]+cost;
                pq.push(mkt(-g[y][bt+1],y,bt+1,y));
            }
        }
    }
}
/*

*/
