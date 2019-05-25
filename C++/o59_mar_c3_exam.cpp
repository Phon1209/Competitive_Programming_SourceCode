#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
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
int fw[100005];
void add(int idx,int val)
{
    while(idx>0){
        fw[idx]+=val;
        idx-=idx&-idx;
    }
}
int sum(int idx)
{
    int ret=0;
    while(idx<100000)
    {
        ret+=fw[idx];
        idx+=idx&-idx;
    }
    return ret;
}
map<int,int> mp;
int ans[500005];
int main()
{
    vi v;
    sint(n);
    v.pb(0);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb(tmp);
    }
    sint(m);
    queue<ii> q[50005];
    for(int i=1;i<=m;i++)
    {
        sint2(x,y);
        q[y+1].push(mkp(x+1,i));
    }
    for(int i=1;i<=n;i++)
    {
        int u=v[i];
        // debug(u);
        if(mp.find(u)!=mp.end()){
            // printf("Bomb\n");
            add(mp[u],-1);
        }
        mp[u]=i;
        add(i,1);
        // debug(i);
        while(!q[i].empty())
        {
            ii y=q[i].front();
            q[i].pop();
            // printf(">%d %d\n",y.F,i);
            // debug(sum(y.F));
            ans[y.S]=(i-y.F+1)-( sum(y.F));
        }
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d\n",ans[i]);
    }
}
/*

*/
