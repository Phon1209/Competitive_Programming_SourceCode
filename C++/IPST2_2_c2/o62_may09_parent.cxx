#include<bits/stdc++.h>
using namespace std;
#define DEBUG
// #define TIME
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; qread(a);
#define sint2(a,b) int a,b; qread(a),qread(b);
#define sint3(a,b,c) int a,b,c; qread(a),qread(b),qread(c);
#define int1(a) qread(a);
#define int2(a,b) qread(a),qread(b);
#define int3(a,b,c) qread(a),qread(b),qread(c);
#define mkp make_pair
#define mkt make_tuple
#define pb emplace_back
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
#ifdef DEBUG
#define debug(x) cout<< #x << " = " << x;endl;
#else
#define debug(x)
#endif
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#ifdef COM
#define IN(x)
#define OUT(x)
#else
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);
#endif
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
void qread(int &x){
	int neg=1;x=0;
	register char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}
void Wl(int x)
{
    printf("%d\n",x);
}
void Wl(double x)
{
    printf("%lf\n",x);
}
void Wl(string x)
{
    printf("%s\n",x.c_str());
}
void Wl(ll x)
{
    printf("%lld\n",x);
}
void W(int x)
{
    printf("%d ",x);
}
void W(double x)
{
    printf("%lf ",x);
}
void W(string x)
{
    printf("%s ",x.c_str());
}
void W(ll x)
{
    printf("%lld ",x);
}
class UnionFind
{
private:
    vi p;
public:
    UnionFind(int n)
    {
        p.assign(n+5,0);
        for(int i=0;i<=n;i++)p[i]=i;
    }
    int fs(int i)
    {
        return (p[i]==i)? i:p[i]=fs(p[i]);
    }
    bool iss(int i,int j)
    {
        return fs(i)==fs(j);
    }
    void us(int i,int j) //use to find master
    {
        p[fs(i)]=fs(j);
    }
    void change(int i)
    {
        int y=fs(i);
        p[y]=i;
        p[i]=i;
    }
};
int depth[100005];
int p[20][100005];
int LCA(int x,int y)
{
    while(x!=y)
    {
        if(depth[x]<depth[y])swap(x,y);
        if(depth[x]==depth[y])
        {
            for(int i=18;i>=0;i--)
            {
                if(p[i][x]!=p[i][y])
                {
                    x=p[i][x];
                    y=p[i][y];
                }
            }
            if(p[0][x]==p[0][y])return p[0][x];
        }
        x=p[(int)log2(depth[x]-depth[y])][x];
    }
    return x;
}
vi v[100005];
void dfs(int u)
{
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        // debug(y);
        if(depth[y])continue;
        p[0][y]=u;
        depth[y]=depth[u]+1;
        dfs(y);
    }
}
bitset<1005> bt;
int main()
{
    sint2(n,m);
    UnionFind uf(n);
    if(n<=1000 && m<=3000)
    {
        while(m--){ // handle only when T=3 there are no T=1 anymore
            /*
            T = 1 Connect Graph
            T = 2 Change Root
            T = 3 Query
            */
            sint(t);
            if(t==1)
            {
                sint2(x,y);
                if(uf.iss(x,y))assert(false);
                uf.us(x,y);
                v[x].pb(y);
                v[y].pb(x);
            }
            if(t==2)
            {
                sint(x);
                uf.change(x);
            }
            if(t==3)
            {
                sint2(x,y);
                int root=uf.fs(x);
                queue<int> q;
                bt.reset();
                q.emplace(root);
                bt[root]=1;
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    if(u==x || u==y)
                    {
                        printf("%d\n",u);
                        break;
                    }
                    for(int i=0;i<v[u].size();i++)
                    {
                        int to=v[u][i];
                        if(!bt[to])
                        {
                            bt[to]=1;
                            q.emplace(to);
                        }
                    }
                }
            }
        }
        exit(0);
    }
    bool okay=1;
    while(m--){ // handle only when T=3 there are no T=1 anymore
        /*
        T = 1 Connect Graph
        T = 2 Change Root
        T = 3 Query
        */
        sint(t);
        if(t==1)
        {
            sint2(x,y);
            if(uf.iss(x,y))assert(false);
            uf.us(x,y);
            v[x].pb(y);
            v[y].pb(x);
        }
        if(t==2)
        {
            sint(x);
            uf.change(x);
        }
        if(t==3)
        {
            sint2(x,y);
            if(okay)
            {
                memset(depth,0,sizeof(depth));
                memset(p,0,sizeof(p));
                for(int i=1;i<=n;i++)
                {
                    if(depth[i]==0)
                    {
                        depth[i]=1;
                        p[0][i]=0;
                        dfs(i);
                    }
                }
                // debug(1);
                for(int i=1;(1<<i)<=n;i++)
                    for(int j=1;j<=n;j++)
                        p[i][j]=p[i-1][p[i-1][j]];
                okay=0;
            }
            // debug(6);
            int root=uf.fs(x);
            // debug(root);
            int X,Y;
            int lca=LCA(root,x);
            X=depth[x]-(2*depth[lca]);
            // debug(7);
            lca=LCA(root,y);
            // debug(19);
            Y=depth[y]-(2*depth[lca]);
            // debug(8);
            printf("%d\n",(X<Y)? x:y);
            // debug(9);
        }
        // endl;
        // for(int i=1;i<=n;i++)
        // {
        //     W(i);
        //     W("=");
        //     Wl(uf.fs(i));
        // }
        // endl;
    }
    #ifdef TIME
    	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
    #endif
}
/*
10 1000000
1 1 2
1 3 4
1 2 4
2 2
1 5 6
1 5 7
1 7 1
2 5
1 10 3
1 8 9
2 8
2 4
2 1
2 9
1 8 1
3 8 9
*/
