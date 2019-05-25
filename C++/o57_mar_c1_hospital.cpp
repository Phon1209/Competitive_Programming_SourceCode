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
int in[100005];
bitset<100005> de;
vi v[100005];
ll ans=0;
int dis[100005];
void dfs(int u)
{
    ans+=dis[u];
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
        if(dis[y]!=-1)continue;
        dis[y]=dis[u]+1;
        dfs(y);
    }
}
int main()
{
    // OPEN;
    // SEND;
    sint(n);
    int num=n;
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        in[x]++;
        in[y]++;
        v[x].pb(y);
        v[y].pb(x);
    }
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==1)
        {
            q.push(i);
        }
    }
    ll ta=LLONG_MAX;
    int f;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        de[u]=1;
        num--;
        if(num==75)
        {
            de[u]=0;
            for(int i=1;i<=n;i++)
            {
                if(de[i]==0)
                {
                    ans=0;
                    memset(dis,-1,sizeof(dis));
                    dis[i]=0;
                    dfs(i);
                    ta=min(ta,ans);
                }
            }
            break;
        }
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i];
            if(de[y])continue;
            in[y]--;
            if(in[y]==1)
            {
                q.push(y);
            }
        }
    }
    printf("%lld\n",ta);
}
/*

*/
