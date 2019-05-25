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
ll sg[400005];
ll lz[400005];
bool is[400005];
void lzup(int idx,int l,int r,ll val)
{
  lz[idx]=val;
  is[idx]=1;
  sg[idx]=(val*(r-l+1));
}
void shift(int idx,int l,int r)
{
  if(!is[idx])return;
  int md=(l+r)/2;
  lzup(idx*2,l,md,lz[idx]);
  lzup(idx*2+1,md+1,r,lz[idx]);
  is[idx]=0;
  lz[idx]=0;
}
void sgup(int idx,int l,int r,int x,int y,ll val)
{
  if(y<l || x>r)return;
//  printf("%d %d %d %d %d\n",idx,l,r,x,y);
  if(x<=l && r<=y)
  {
//    printf("A\n");
    lzup(idx,l,r,val);
//    printf("%d %lld\n",idx,sg[idx]);
    return ;
  }
  shift(idx,l,r);
  int md=(l+r)/2;
  sgup(idx*2,l,md,x,y,val);
  sgup(idx*2+1,md+1,r,x,y,val);
//  printf(">>%d %d\n",idx*2,idx*2+1);
//  printf(">>%lld %lld\n",sg[idx*2],sg[idx*2+1]);
  sg[idx]=sg[idx*2]+sg[idx*2+1];
//  printf(">%d %lld\n",idx,sg[idx]);
}

ll sum(int idx,int l,int r,int x,int y)
{
  if(y<l || x>r)return 0;
  if(x<=l && r<=y)
  {
//    printf("%d %d %lld\n",l,r,sg[idx]);
    return sg[idx];
  }
  shift(idx,l,r);
  int md=(l+r)/2;
  return sum(idx*2,l,md,x,y)+sum(idx*2+1,md+1,r,x,y);
}
int main()
{
  sint2(n,m);
  while(m--)
  {
    sint(cm);
    if(cm==0)
    {
      sint2(x,y);
      slong(val);
      x++;
      sgup(1,1,n,x,y,val);
    }
    else if(cm==1)
    {
      sint2(x,y);
      x++;
      printf("%lld\n",sum(1,1,n,x,y));
    }
  }
}
