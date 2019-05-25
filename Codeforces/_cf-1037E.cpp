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

vi v[200005];
int deg[200005];
vii edge;
set<ii> s;
bitset<200005> chk;
int ans[200005];
int n,m,k;
map<int,bool> mp[200005];

void reduce(int u,int y)
{
    if(mp[u][y]==0)return;
    s.erase(mkp(deg[u],u));
    deg[u]--;
    s.insert(mkp(deg[u],u));
}
bool ok(int a,int b,int x,int y)
{
    if(a>b)swap(a,b);
    if(x>y)swap(x,y);
    if(a==x && b==y)return true;
    else return false;
}
void DEL(int a,int b)
{
    while(!s.empty() && s.begin()->F<k)
    {
        int u=s.begin()->S;
        s.erase(s.begin());
        // printf("Selected : %d\n",u);
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i];
            if(ok(u,y,a,b))continue;
            if(chk[y] && mp[u][y])
            {
                // printf(">Reduce : %d\n",y);
                reduce(y,u);
                mp[u][y]=0;
                mp[y][u]=0;
            }
        }
        chk[u]=0;
    }
}
void BUG()
{
    for(int i=1;i<=n;i++)
    {
        printf("%d = %d %s\n",i,deg[i],(chk[i])? "Yes":"No");
    }
    endl;
}
int main()
{
    int3(n,m,k);
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        v[x].pb(y);
        v[y].pb(x);
        edge.pb(mkp(x,y));
        deg[x]++;
        deg[y]++;
        mp[x][y]=1;
        mp[y][x]=1;
    }
    for(int i=1;i<=n;i++)
    {
        if(!v[i].empty())
        {
            s.insert(mkp(v[i].size(),i));
            chk[i]=1;
        }
    }
    DEL(0,0);
    for(int i=m-1;i>=0;i--)
    {
        // BUG();
        ans[i]=s.size();
        int u=edge[i].F;
        int y=edge[i].S;
        // debug(u);
        // debug(y);
        if(chk[u] && chk[y])
        {
            reduce(u,y);
            reduce(y,u);
            mp[u][y]=0;
            mp[y][u]=0;
            if(u>y)swap(u,y);
            DEL(u,y);
        }
    }
    for(int i=0;i<m;i++)
    {
        printf("%d\n",ans[i]);
    }
}
/*

*/
