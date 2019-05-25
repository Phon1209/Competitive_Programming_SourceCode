/*
LANG: C++
TASK:  o60_oct_c1_collecting
*/
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
int rk[50005];
vii v[50005];
ll gp[50005][50];
int main()
{
    sint3(n,m,l);
    sint2(s,t);
    for(int i=1;i<=n;i++)
    {
        int1(rk[i]);
    }
    for(int i=0;i<m;i++)
    {
        sint3(x,y,w);
        v[x].pb(mkp(y,w));
    }
    for(int i=0;i<=50000;i++)
    {
        for(int j=0;j<=50;j++)
        {
            gp[i][j]=inf;
        }
    }
    priority_queue<pair<ll,ii> > pq;
    // w u use
    pq.push(mkp(0,mkp(1,0)));
    while(!pq.empty())
    {
        int u=pq.top().S.F;
        int use=pq.top().S.S;
        ll w=-pq.top().F;
        pq.pop();
        if(gp[u][use]<w)continue;
        gp[u][use]=w;
//        printf("%d %d %lld\n",u,use,w);
        if(u==n && use==rk[n])
        {
            printf("%lld\n",w);
            break;
        }
        for(int i=0;i<v[u].size();i++)
        {
            int y=v[u][i].F;
            ll cost=v[u][i].S;
            if(rk[y]==use+1)
            {
                if(gp[y][use+1]>gp[u][use]+cost)
                {
                    gp[y][use+1]=gp[u][use]+cost;
                    pq.push(mkp(-gp[y][use+1],mkp(y,use+1)));
                }
            }
            else
            {
                if(gp[y][use]>gp[u][use]+cost)
                {
                    gp[y][use]=gp[u][use]+cost;
                    pq.push(mkp(-gp[y][use],mkp(y,use)));
                }
            }
        }
    }
}
/*

*/
