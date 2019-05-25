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
map<string,int> mp;
int remap[80005];
vector<ii> v[80005];
ll g[80005];
int dijk(int x,int y)
{
    // printf("Find %d -> %d\n",x,y);
    for(int i=0;i<=80000;i++)g[i]=INT_MAX;
    priority_queue<ii> pq;
    pq.push(mkp(0,x));
    while(!pq.empty())
    {
        int u=pq.top().S;
        int w=-pq.top().F;
        pq.pop();
        if(w>g[u])continue;
        g[u]=w;
        if(u==y)
        {
            return w;
        }
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i].F;
            int cost=v[u][i].S;
            // printf("%d with cost %d\n",y,g[u]+cost);
            if(g[y]>g[u]+cost)
            {
                g[y]=g[u]+cost;
                pq.push(mkp(-g[y],y));
            }
        }
    }
    return -1;
}
int main()
{
    sint(n);
    char s[5];
    string tmp;
    for(int i=1;i<=n;i++)
    {
        remap[i]=i;
        scanf("%s",s);
        tmp=s;
        if(mp.find(tmp)==mp.end())
            mp[tmp]=i;
        else remap[i]=mp[tmp];
    }
    /*
    for(int i=1;i<=n;i++)
    {
        printf("remap[%d] = %d\n",i,remap[i]);
    }
    */
    sint(m);
    while(m--)
    {
        sint2(x,y);
        sint(w);
        x=remap[x];
        y=remap[y];
        if(x==y)continue;
        // printf("Push %d -> %d = %d\n",x,y,w);
        v[x].pb(mkp(y,w));
    }
    sint(l);
    while(l--)
    {
        sint2(x,y);
        x=remap[x];
        y=remap[y];
        if(x==y)
        {
            printf("0\n");
            continue;
        }
        printf("%d\n",dijk(x,y));
    }
}
/*

*/
