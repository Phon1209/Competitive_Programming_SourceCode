#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define pb push_back
#define endl printf("\n")
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
        return (p[i]==i)? i:(p[i]=fs(p[i]));
    }
    bool iss(int i,int j)
    {
        return fs(i)==fs(j);
    }
    void us(int i,int j)
    {
        int x,y;
        x=fs(i);
        y=fs(j);
        if(y>x)p[x]=y;
        else p[y]=x;
    }
};
char a[1005][1005];
vi v[2005];
enum color
{
    progress,okay,blank
};
color node[2005];
int depth[2005];
bool ok=1;
void dfs(int u)
{
    if(v[u].size()==0)
    {
        node[u]=okay;
        depth[u]=1;
        return;
    }
    int mx=0;
    node[u]=progress;
    for(int i=0;i<v[u].size();i++)
    {
        if(!ok)return;
        int y=v[u][i];
        if(node[y]==progress)ok=0;
        if(node[y]!=okay)dfs(y);
        mx=max(mx,depth[y]+1);
    }
    depth[u]=mx;
    node[u]=okay;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    UnionFind uf(n+m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]=='=')uf.us(i,n+j);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='>')
                v[uf.fs(i)].pb(uf.fs(n+j));
            if(a[i][j]=='<')
                v[uf.fs(n+j)].pb(uf.fs(i));
        }
    for(int i=0;i<=2000;i++)node[i]=blank;
    for(int i=0;i<n+m;i++)
    {
        int tmp=uf.fs(i);
        if(node[tmp]==blank)
            dfs(tmp);
    }
    if(!ok)
    {
        wl("No");
        return 0;
    }
    wl("Yes");
    for(int i=0;i<n;i++)
        w(depth[uf.fs(i)]);
    endl;
    for(int j=0;j<m;j++)
        w(depth[uf.fs(n+j)]);
    endl;
}
/*

*/
