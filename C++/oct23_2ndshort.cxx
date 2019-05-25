#include<bits/stdc++.h>
using namespace std;
/*
Learn : 2nd Shortest Path
Problem Type : Shortest Path + DP
Source : evaluator
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
vector<ii> v[10005],vr[10005];
int d1[10005],d2[10005];
void dijk(int *d,vector<ii> *V,int st)
{
    priority_queue<ii> pq;
    pq.push(mkp(0,st));
    while(!pq.empty())
    {
        int u=pq.top().S;
        int w=-pq.top().F;
        pq.pop();
        if(w>d[u])continue;
        d[u]=w;
        for(int i=0;i<V[u].size();i++)
        {
            int y=V[u][i].F;
            int cost=V[u][i].S;
            if(d[y]>d[u]+cost)
            {
                d[y]=d[u]+cost;
                pq.push(mkp(-d[y],y));
            }
        }
    }
}
vector<pair<ii,int> > edge;
int main()
{
    sint2(n,m);
    sint2(st,ed);
    for(int i=0;i<=n;i++)d1[i]=d2[i]=2e9;
    FOR(i,0,m)
    {
        sint3(x,y,w);
        v[x].pb(mkp(y,w));
        vr[y].pb(mkp(x,w));
        edge.emplace_back(mkp(mkp(x,y),w));
    }
    dijk(d1,v,st);
    dijk(d2,vr,ed);
    int ans1=inf,ans2=inf;
    for(int i=0;i<edge.size();i++)
    {
        int x,y,w;
        x=edge[i].F.F;
        y=edge[i].F.S;
        w=edge[i].S;
        int a=d1[x]+w+d2[y];
        if(a<ans1)
        {
            ans2=ans1;
            ans1=a;
        }
        else if(a>ans1 && a<ans2) ans2=a;
    }
    printf("%d\n",ans2);
}
/*

*/
