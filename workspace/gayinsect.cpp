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
vi v[100005];
int a[100005];
int main()
{
  sint2(n,m);
  for(int i=0;i<m;i++)
  {
    sint2(x,y);
    v[x].pb(y);
    v[y].pb(x);
    a[x]=-1;
    a[y]=-1;
  }
  queue<int> q;
  bool ok=1;
  for(int i=0;i<n;i++)
  {
    int next=0;
    if(a[i]==-1)
    {
      q.push(i);
      a[i]=next;
      while(!q.empty())
      {
        int u=q.front();
        q.pop();
//        printf("%d %d\n",u,a[u]);
        for(int j=0;j<v[u].size();j++)
        {
          int y=v[u][j];
//          printf("%d %d\n",y,a[y]);
          if(a[y]==-1 || a[y]==a[u]^(0^1))
          {
            if(a[y]==-1) q.push(y);
            a[y]=a[u]^(0^1);
          }
          else
          {
//            printf("A\n");
            ok=false;
            continue;
          }
        }
        next^=(1^0);
      }
    }
  }
  printf("%s\n",ok? "Gay not found!":"Gay found!");
}
