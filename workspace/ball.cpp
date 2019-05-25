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
vi v;
int main()
{
  sint(n);
  for(int i=0;i<n;i++)
  {
    sint(tmp);
    int last=tmp;
    if(v.size()==0)
    {
      v.pb(tmp);
      continue;
    }
    if(v[v.size()-1]==0)
    {
      v.pb(tmp);
      for(int j=v.size()-2;j>=0;j--)
      {
        if(v[j]<=v[j+1])
        {
          v[j]=v[j+1]+1;
        }
      }
      continue;
    }
    v.pb(0);
    for(int j=v.size()-1;j>=0;j--)
    {
//      printf("%d %d\n",j,last);
      if(j==0 || v[j]+last<v[j-1])
      {
        v[j]+=last;
        break;
      }
      else if(v[j]+last>=v[j-1])
      {
        last-=(v[j-1]-v[j]+1);
        v[j]=v[j-1]-1;
//        printf(">>%d\n",last);
        if(last<=0)break;
      }
    }
    /*
    printf(">");
    for(int j=0;j<v.size();j++)
    {
      printf("%d ",v[j]);
    }
    endl;
    */
  }
  for(int i=0;i<v.size();i++)
  {
    printf("%d\n",v[i]);
  }

}
