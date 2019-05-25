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
enum color
{
    wht,gry,blk
}a[100005];
vi v[100005];
bool ok=true;
void dfs(int u)
{
    if(!ok)return;
    a[u]=gry;
    for(int i=0;i<v[u].size();i++)
    {
        int y=v[u][i];
//        printf("%d %d\n",u,y);
        if(a[y]==gry)
        {
//            printf("A\n");
            ok=false;
            return;
        }//printf("%d %d\n",u,y);
        if(a[y]==wht)
        {
            dfs(y);
        }
    }
    a[u]=blk;
}
int b[100005];
void _main()
{
  sint(n);
  ok=true;
  for(int i=0;i<=n;i++)
  {
      a[i]=wht;
      v[i].clear();
      b[i]=0;
  }
  for(int i=0;i<n;i++)
  {
      sint(tmp);
      if(!tmp)continue;
      b[tmp]=i;
  }
  for(int i=0;i<n;i++)
  {
     sint(tmp);
      if(!tmp)continue;
      int u=b[tmp];
//      printf(">%d %d\n",u,i);
      if(u==i)continue;
      v[u].pb(i);
  }
  for(int i=0;i<=n;i++)
  {
      if(a[i]==wht)
        dfs(i);
  }
  printf("%s\n",ok? "Yes":"No");
}
int main()
{
  sint(t);
  while(t--)
  {
    _main();
  }
}
