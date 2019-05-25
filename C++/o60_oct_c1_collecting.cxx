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
ll g[50005][35];
vii v[50005];
int rk[50005];
int main()
{
    sint3(n,m,l);
    sint2(s,t);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=30;j++)
        {
            g[i][j]=LLONG_MAX;
        }
    }
    for(int i=1;i<=n;i++)
        int1(rk[i]);
    for(int i=0;i<m;i++)
    {
        sint3(a,b,c);
        v[a].pb(mkp(b,c));
    }
    priority_queue<pair<ll,ii> > pq;
    pq.push(mkp(0,mkp(s,0)));
    while(!pq.empty())
    {
        ll w=-pq.top().F;
        int u=pq.top().S.F;
        int rnk=pq.top().S.S;
        pq.pop();
        if(g[u][rnk]<w)continue;
        g[u][rnk]=w;
        if(u==t && rnk==rk[t])
        {
            printf("%lld\n",w);
            return 0;
        }
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i].F;
            int cost=v[u][i].S;
            int want=rk[y];
            if(want==rnk+1)
            {
                if(g[y][rnk+1]>g[u][rnk]+cost)
                {
                    g[y][rnk+1]=g[u][rnk]+cost;
                    pq.push(mkp(-g[y][rnk+1],mkp(y,rnk+1)));
                }
            }
            else
            {
                if(g[y][rnk]>g[u][rnk]+cost)
                {
                    g[y][rnk]=g[u][rnk]+cost;
                    pq.push(mkp(-g[y][rnk],mkp(y,rnk)));
                }
            }
        }
    }
    printf("-1\n");
}
/*

*/
