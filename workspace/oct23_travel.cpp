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
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
vi v[30005];
int d[5][30005];
int dist(int now ,int go)
{
    if(now==go)return 0;
    queue<pair<int,ii> > q;
    for(int i=0;i<=30000;i++)d[0][i]=d[1][i]=-1;
    q.push(mkp(now,mkp(0,0)));
    q.push(mkp(go,mkp(0,1)));
    d[0][now]=0;
    d[1][go]=0;
    while(!q.empty())
    {
        int u=q.front().F;
        int w=q.front().S.F;
        int code=q.front().S.S;
        q.pop();
        int other=code^(1^0);
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i];
            if(d[code][y]==-1)
            {
                d[code][y]=w+1;
                q.push(mkp(y,mkp(w+1,code)));
            }
            if(d[other][y]!=-1)
            {
                return w+1+d[other][y];
            }
        }
    }
}
int main()
{
    sint(n);
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    sint(m);
    int now=1;
    int go;
    int ans=0;
    while(m--)
    {
        int1(go);
        ans+=dist(now,go);
//        printf(">%d\n",ans);
        now=go;
    }
    printf("%d\n",ans);
}
/*

*/
