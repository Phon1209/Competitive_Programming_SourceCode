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
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int in[5005];
vi v[5005];
vi v2[5005];
bool chk[5005];
stack<int> st;
queue<int> q;
int ret[5005];
vi nw[5005];
int order[5005];
int rk[5005];
void dfs(int u)
{
    chk[u]=1;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(!chk[y])
        {
            dfs(y);
        }
    }
    st.push(u);
}
void dfs2(int u)
{
    chk[u]=1;
    q.push(u);
    for(int i=0;i<v2[u].size();i++)
    {
        int y=v2[u][i];
        if(!chk[y])
        {
            dfs2(y);
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
        v2[y].pb(x);
    }
    for(int i=0;i<n;i++)chk[i]=0;
    for(int i=0;i<n;i++)
    {
        if(!chk[i])
        {
            dfs(i);
        }
    }
    for(int i=0;i<n;i++)chk[i]=0;
    int cnt=-1;
    while(!st.empty())
    {
        if(!chk[st.top()])
        {
            cnt++;
            dfs2(st.top());
        }
        while(!q.empty())
        {
            ret[q.front()]=cnt;
            q.pop();
        }
        st.pop();
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            int y=v[i][j];
            if(ret[i]!=ret[y])
            {
                nw[ret[i]].pb(ret[y]);
                in[ret[y]]++;
            }
        }
    }
    queue<int> topo;
    for(int i=0;i<=cnt;i++)
    {
        if(in[i]==0)
        {
            order[i]=0;
            topo.push(i);
        }
    }
    while(!topo.empty())
    {
        int u=topo.front();
        topo.pop();
        for(int i=0;i<nw[u].size();i++)
        {
            int y=nw[u][i];
            in[y]--;
            if(in[y]==0)
            {
                topo.push(y);
                order[y]=order[u]+1;
            }
        }
    }
    int mx=0;
    for(int i=0;i<n;i++)
    {
        int u=ret[i];
        int y=order[u];
        rk[y]++;
        mx=max(mx,y);
    }
    for(int i=0;i<=mx;i++)
    {
        printf("%d ",rk[i]);
    }
}
/*

*/
