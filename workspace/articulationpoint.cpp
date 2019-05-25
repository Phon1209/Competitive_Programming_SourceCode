#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define sstring(a,x) char a[x]; scanf("%s",a);
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
vi num,low,p,vertex;
int cnt=0;
vi v[10005];
int root,child;
void find(int u)
{
    low[u]=num[u]=cnt++;
    printf(">%d\n",u);
    for(int j=0;j<v[u].size();j++)
    {
        int y=v[u][j];
        if(num[y]==-1)
        {
            p[y]=u;
            if(u==root)child++;
            find(y);
            printf("%d %d %d %d\n",u,y,low[y],num[u]);
            if(low[y]>=num[u])
                vertex[u]=1;
            if(low[y]>num[u])
                printf("Edge %d <-> %d is a bridge\n",u,y);
            low[u]=min(low[u],low[y]);
        }
        else if(y!=p[u])
        {
            low[u]=min(low[u],num[y]);
        }
    }
}
int main()
{
    sint2(n,m);
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    cnt=0;
    num.assign(n,-1);
    low.assign(n,-1);
    p.assign(n,0);
    vertex.assign(n,0 );
    printf("Bridge :\n");
    for(int i=0;i<n;i++)
    {
        if(num[i]==-1)
        {
            root=i;
            child=0;
            find(i);
            vertex[root]=(child>1);
        }
    }
    printf("Point :\n");
    for(int i=0;i<n;i++)
    {
        if(vertex[i])
        {
            printf("%d ",i);
        }
    }
    endl;
}
