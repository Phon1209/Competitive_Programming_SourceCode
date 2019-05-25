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
void _main()
{
    vi v,v2;
    sint2(n,m);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb(tmp);
    }
    for(int i=0;i<m;i++)
    {
        sint(tmp);
        v2.pb(tmp);
    }
    sort(all(v),greater<int>());
    sort(all(v2),greater<int>());
    int cnt=0;
    int ok=0;
    for(int i=0;i<n;)
    {
        if(cnt==v2.size())break;
  //      printf("%d %d %d %d\n",i,cnt,v[i],v2[cnt]);
        if(v[i]>v2[cnt])
        {
            i++;
            ok++;
        }
        cnt++;
    }
    printf("%s\n",(ok==n)? "YES":"NO");
}
int main()
{
    sint(t);
    while(t--)_main();
}
