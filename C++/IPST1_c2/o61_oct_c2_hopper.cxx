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
int n,m;
vi edge[3005];
int a[6005];
int d[3005];
int chk[3005][3005];
bool dijkstra()
{
    priority_queue<ii> pq;
    for(int i=0;i<n;i++)pq.push(mkp(0,i));
    while(!pq.empty())
    {
        int w=-pq.top().F;
        int u=pq.top().S;
        pq.pop();
        // printf("%d %d\n",w,u);
        if(d[u]<w)continue;
        d[u]=w;
        if(d[u]<=-m)
        {
            // printf("OK\n");
            return true;
        }
        for(int i=0;i<edge[u].size();i++)
        {
            int y=edge[u][i];
            if(d[y]>d[u]-1)
            {
                d[y]=d[u]-1;
                pq.push(mkp(-d[y],y));
            }
        }
    }
    return false;
}
int main()
{
    int2(n,m);
    for(int i=0;i<n;i++)
    {
        int1(a[i]);
        a[i+n]=a[i];
    }
    int l=1,r=n;
    int ans=n;
    int x,y;
    while(l<=r)
    {
        int md=(l+r)/2;
        for(int i=0;i<n;i++)edge[i].clear();
        memset(chk,0,sizeof(chk));
        // debug(md);
        for(int i=0;i<2*n;i++)
        {
            for(int j=1;j<=md;j++)
            {
                if(i-j<0)continue;
                if(a[i]>a[i-j])
                {
                    x=(i-j)%n;
                    y=(i%n);
                    if(chk[x][y])continue;
                    edge[x].pb(y);
                    chk[x][y]=1;
                    // debug(x);
                    // debug(y);
                    // endl;
                }
            }
        }
        bool ok=false;
        for(int i=0;i<n;i++)d[i]=0;
        if(dijkstra())
        {
            r=md-1;
            ans=min(ans,md);
        }
        else
            l=md+1;
        // debug(ans);
        // pause;
    }
    printf("%d\n",ans);
}
/*

*/
