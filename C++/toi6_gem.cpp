#include<bits/stdc++.h>
using namespace std;
/*
Learn : 2-SAT SCC
Problem Type : 2-SAT
Source : Proprog
*/
// #pragma GCC optimize ("Ofast")
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
vi v[200005];
vi vr[200005];
vii g;
int ban[200005];
int scc[200005];
bitset<200005> bt;
stack<int> st;
void dfs(int u)
{
    bt[u]=1;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(bt[y])continue;
        dfs(y);
    }
    st.push(u);
}
int cnt;
void dfs2(int u)
{
    bt[u]=1;
    for(int i=0;i<vr[u].size();i++)
    {
        int y=vr[u][i];
        if(bt[y])continue;
        dfs2(y);
    }
    scc[u]=cnt;
}
int main()
{
    int t=5;
    while(t--)
    {
        sint2(n,m);
        //clear
        bt.reset();
        for(int i=1;i<=m;i++)
        {
            v[i].clear();
            vr[i].clear();
            ban[i]=0;
            scc[i]=0;
        }
        g.clear();
        //
        for(int i=1;i<=n;i++)
        {
            sint2(x,y);
            g.pb(mkp(x,y));
        }
        for(int i=1;i<=(m/2);i++)
        {
            sint2(x,y);
            ban[x]=y;
            ban[y]=x;
        }
        for(int i=0;i<g.size();i++)
        {
            int x,y;
            x=g[i].F;
            y=g[i].S;
            v[ban[x]].pb(y);
            v[ban[y]].pb(x);
            vr[y].pb(ban[x]);
            vr[x].pb(ban[y]);
        }
        bt.reset();
        for(int i=1;i<=m;i++)
        {
            if(!bt[i])
            {
                dfs(i);
            }
        }
        bt.reset();
        cnt=1;
        while(!st.empty())
        {
            int u=st.top();
            st.pop();
            if(bt[u])continue;
            dfs2(u);
            cnt++;
        }
        bool ok=true;
        for(int i=1;i<=m;i++)
        {
            // printf("scc[%d] = %d\n",i,scc[i]);
            if(scc[i]==scc[ban[i]])ok=false;
        }
        printf("%c",ok? 'Y':'N');
    }
    endl;
}
/*

*/
