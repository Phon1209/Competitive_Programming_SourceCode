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
#define inf LLONG_MAX
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
vector<pair<int,ll> > v[80005];
int po[80005];
ll gp[80005][15];
int main()
{
    sint2(n,m);
    sint2(rm,lim);
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=lim;j++)
        {
            gp[i][j]=inf;
        }
    }
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        slong(w);
        v[x].pb(mkp(y,w));
    }
    for(int i=0;i<rm;i++)
    {
        sint(tmp);
        po[tmp]=1;
    }
    gp[1][0]=0;
    priority_queue<pair<ll,pair<int,ii> > > pq;
    pq.push(mkp(0,mkp(1,mkp(0,-1))));
    while(!pq.empty())
    {
        int u=pq.top().S.F;
        int dk=pq.top().S.S.F;
        int lt=pq.top().S.S.S;
        ll w=-pq.top().F;
        pq.pop();
        if(gp[u][dk]<w)continue;
        gp[u][dk]=w;
    //    printf("%lld %d %d %d\n",w,u,dk,lt);
        if(u==n)
        {
            printf("%lld\n",w);
            break;
        }

        for(int i=0;i<v[u].size();i++)
        {
            int go=dk;
            int tmplt=lt;
            if(po[u] && dk+1<=lim && lt!=u)
            {
                tmplt=u;
                go=dk+1;
            }
            int y=v[u][i].F;
            ll run=v[u][i].S;
            run/=(1<<go);
    //        printf("> %d %lld %lld\n",y,gp[u][dk],run);
            if(gp[y][go]>gp[u][dk]+run)
            {
                gp[y][go]=gp[u][dk]+run;
                pq.push(mkp(-gp[y][go],mkp(y,mkp(go,tmplt))));
            }
        }
    }
}
