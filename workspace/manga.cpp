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
vector<pair<int,ii> > v[50005];
int a[50005];
int main()
{
  sint3(n,m,k);
  for(int i=1;i<=m;i++)
  {
    sint3(x,y,w);
    v[x].pb(mkp(i,mkp(y,w)));
    v[y].pb(mkp(i,mkp(x,w)));
  }
  int mn=1,mx=m;
  int ans=m+1;
  while(mn<=mx)
  {
      int md=(mn+mx)/2;
      for(int i=0;i<=n;i++)
      {
          a[i]=inf;
      }
      a[1]=0;
      bool ok=false;
//      printf("%d\n",md);
      priority_queue<ii> pq;
      // t u
      pq.push(mkp(0,1));
      while (!pq.empty()) {
          int u=pq.top().S;
          int w=-pq.top().F;
          pq.pop();
          if(a[u]<w)continue;
          a[u]=w;
          if(u==n)
          {
              ok=true;
              break;
          }
          for(int i=0;i<v[u].size();i++)
          {
              int y=v[u][i].S.F;
              int cost=v[u][i].S.S;
              int date=v[u][i].F;
              if(date>md)continue;
    //          printf("%d %d %d\n",u,y,cost);
              if(a[y]>a[u]+cost && a[u]+cost<=k)
              {
                  a[y]=a[u]+cost;
                  pq.push(mkp(-a[y],y));
              }
          }
      }
      while(!pq.empty())pq.pop();
      if(ok)
      {
          ans=min(ans,md);
          mx=md-1;
      }
      else
      {
          mn=md+1;
      }
  }
  printf("%d\n",(ans==m+1)? -1:ans);
}
