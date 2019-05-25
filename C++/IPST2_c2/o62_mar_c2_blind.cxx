#include<bits/stdc++.h>
using namespace std;
#define DEBUG
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
    void us(int i,int j)
    {
        p[fs(i)]=fs(j);
    }
    int fs(int i)
    {
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j)
    {
        return fs(i)==fs(j);
    }
};
vi T[20005];
vi v[20005];
int in[20005];
int rnk[20005];
vi g[20005];
int main()
{
    sint2(n,m);
    UnionFind uf(n);
    int cnt=n;
    for(int i=0;i<m;i++){
        sint(cmd);
        sint3(a,b,c);
        if(cmd==1) //a>b a>c
        {
            if(b!=a)T[b].pb(a);
            if(c!=a)T[c].pb(a);
        }
        if(cmd==2) //a<b a<c
        {
            if(b!=a)T[a].pb(b);
            if(c!=a)T[a].pb(c);
        }
        if(cmd==3) // equal
        {
            if(!uf.iss(a,b))uf.us(a,b),cnt--;
            if(!uf.iss(a,c))uf.us(a,c),cnt--;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int u=uf.fs(i);
        g[u].pb(i);
        for(int j=0;j<T[i].size();j++)
        {
            int y=T[i][j];
            y=uf.fs(y);
            if(y!=u)
            {
                v[u].pb(y);
                in[y]++;
            }
        }
    }
    Wl(cnt);
    for(int i=1;i<=n;i++)
    {
        int u=uf.fs(i);
        if(in[u]==0)
        {
            queue<int> q;
            q.emplace(u);
            while(!q.empty())
            {
                int p=q.front();
                q.pop();
                W((int)g[p].size());
                for(int j=0;j<g[p].size();j++)
                {
                    W(g[p][j]);
                }
                endl;
                for(int j=0;j<v[p].size();j++)
                {
                    int y=v[p][j];
                    in[y]--;
                    if(in[y]==0)
                    {
                        q.emplace(y);
                    }
                }
            }
            break;
        }
    }
}
/*

*/
