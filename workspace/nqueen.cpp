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
bitset<100> r,l;
bitset<100> row,col;
int a[100];
int n,cnt=0;
int ok;
void place(int rw,int ld,int rd)
{
  if(rw==ok)
  {
    cnt++;
    return;
  }
  int pos = ok & (~(rw | ld | rd));
  while(pos)
  {
    int p=pos&-pos;
    pos-=p;
    place(rw|p,(ld|p)<<1,(rd|p)>>1);
  }
}
int chk=0;
void place2(int u)
{
  if(chk==3)return;
  if(u==n)
  {
    if(chk<3)
    {
      for(int i=0;i<n;i++)
      {
        printf("%d ",a[i]);
      }
      endl;
    }
    chk++;
    return;
  }
  for(int i=1;i<=n;i++)
  {
    if(!l[u+i] && !r[u-i+20] && !row[i] && !col[u])
    {
      row[i]=col[u]=r[u-i+20]=l[u+i]=1;
      a[u]=i;
      place2(u+1);
      row[i]=col[u]=r[u-i+20]=l[u+i]=0;
    }
  }
}
int main()
{
  int1(n);
  ok=(1<<n)-1;
  place2(0);
  place(0,0,0);
  printf("%d\n",cnt);
}
