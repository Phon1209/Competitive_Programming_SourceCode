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

int conv(char c)
{
    if('A'<= c && c <='Z')return c-'A';
    if('a'<= c && c<='y')return c-'a'+26;
}
vector<pair<int,ll> >  v[60];
ll g[60];
int main()
{
    for(int i=0;i<60;i++)g[i]=LLONG_MAX;
    sint(n);
    char a[5];
    char b[5];
    for(int i=1;i<=n;i++)
    {
        ll w;
        scanf("%s %s %lld",a,b,&w);
        int x,y;
        // debug(1);
        x=conv(a[0]);
        y=conv(b[0]);
        // debug(x);
        // debug(y);
        v[x].pb(mkp(y,w));
        v[y].pb(mkp(x,w));
    }
    priority_queue<ii> pq;
    pq.push(mkp(0,25));
    while(!pq.empty())
    {
        int u=pq.top().S;
        ll w=-pq.top().F;
        pq.pop();
        if(g[u]<w)continue;
        g[u]=w;
        if(0<=u && u<=24)
        {
            printf("%c %lld\n",'A'+u,w);
            return 0;
        }
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i].F;
            ll cost=v[u][i].S;
            if(g[y]>g[u]+cost)
            {
                g[y]=g[u]+cost;
                pq.push(mkp(-g[y],y));
            }
        }
    }
}
/*

*/
