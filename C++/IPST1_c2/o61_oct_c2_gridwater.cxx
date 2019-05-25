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
vii v[160005];
int n,m;
int conv(int x,int y)
{
    return ((x-1)*m)+y;
}
int p[20][160005];
int mx[20][160005];
bitset<160005> chk;
int lv[160005];
void dfs(int u,int w)
{
    chk[u]=1;
    lv[u]=w;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i].F;
        int cost=v[u][i].S;
        if(chk[y])continue;
        p[0][y]=u;
        mx[0][y]=cost;
        dfs(y,w+1);
    }
}
int lca(int x,int y)
{
    int ret=0;
    while(x!=y)
    {
        if(lv[x]<lv[y])swap(x,y);
        if(lv[x]==lv[y])
        {
            for(int i=18;i>=0;i--)
            {
                if(p[i][x]!=p[i][y])
                {
                    ret=max(ret,max(mx[i][x],mx[i][y]));
                    x=p[i][x];
                    y=p[i][y];
                }
            }
            if(p[0][x]==p[0][y])
            {
                ret=max(ret,max(mx[0][x],mx[0][y]));
                return ret;
            }
        }
        else
        {
            int u=log2(lv[x]-lv[y]);
            ret=max(ret,mx[u][x]);
            x=p[u][x];
        }
    }
    return ret;
}
class UnionFind
{
private:
    vi q;
public:
    UnionFind(int n)
    {
        q.assign(n+5,0);
        for(int i=0;i<=n;i++)q[i]=i;
    }
    int fs(int i)
    {
        return (q[i]==i)? i:(q[i]=fs(q[i]));
    }
    bool iss(int i,int j)
    {
        return (fs(i)==fs(j));
    }
    void us(int i,int j)
    {
        q[fs(i)]=fs(j);
    }
};
vector<tuple<int,int,int> > edge,other;
int main()
{
    int2(n,m);
    for(int i=1;i<m;i++)
    {
        sint(tmp);
        int x,y;
        x=conv(1,i);
        y=conv(1,i+1);
        edge.pb(mkt(tmp,x,y));
    }
    // pause;
    for(int i=1;i<n;i++)
    {
        int x,y;
        for(int j=0;j<m;j++)
        {
            sint(tmp);
            x=conv(i,j+1);
            y=conv(i+1,j+1);
            edge.pb(mkt(tmp,x,y));
        }
        for(int j=1;j<m;j++)
        {
            sint(tmp);
            x=conv(i+1,j);
            y=conv(i+1,j+1);
            edge.pb(mkt(tmp,x,y));
        }
    }
    sort(all(edge));
    UnionFind uf((n*m)+5);
    int x,y,w;
    for(int i=0;i<edge.size();i++)
    {
        tie(w,x,y)=edge[i];
        if(!uf.iss(x,y))
        {
            uf.us(x,y);
            v[x].pb(mkp(y,w));
            v[y].pb(mkp(x,w));
            // printf("!\n");
            // debug(x);
            // debug(y);
            // endl;
        }
        else
            other.pb(edge[i]);
    }
    dfs(1,1);
    for(int i=1;i<=log2(n*m);i++)
    {
        for(int j=1;j<=n*m;j++)
        {
            p[i][j]=p[i-1][p[i-1][j]];
            mx[i][j]=max(mx[i-1][j],mx[i-1][p[i-1][j]]);
            // printf("p[%d][%d] = %d\n",i,j,p[i][j]);
            // printf("mx = %d\n",mx[i][j]);
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<other.size();i++)
    {
        tie(w,x,y)=other[i];
        /*
        debug(x);
        debug(y);
        debug(lca(x,y));
        debug(w);
        endl;
        // */
        ans=min(ans,w-lca(x,y));
    }
    printf("%d\n",ans);
}
/*

*/
