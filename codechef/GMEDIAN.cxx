#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
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
ll cmb[1005][1005];
#define MOD 1000000007
void _main()
{
  sint(n);
  vi v;
  for(int i=0;i<n;i++)
  {
    sint(tmp);
    v.pb(tmp);
  }
  sort(all(v));
  ll ans=0;
  for(int i=1;i<=n;i+=2)
  {
    ans+=cmb[n][i];
    ans%=MOD;
  }
  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(v[i]==v[j])
      {
        int x,y;
        x=min(i,n-j-1);
        y=max(i,n-j-1);
        ans+=cmb[x+y][x];
        ans%=MOD;
      }
    }
  }
  printf("%lld\n",ans);
}
int main()
{
    cmb[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
      for(int j=0;j<=i;j++)
      {
        if(j==0)cmb[i][j]=cmb[i-1][j];
        else cmb[i][j]=cmb[i-1][j]+cmb[i-1][j-1];
        cmb[i][j]%=MOD;
      }
    }
    sint(t);
    while(t--)
    {
      _main();
    }
}
