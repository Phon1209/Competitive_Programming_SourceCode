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
int a[1005];
int b[2000005];
int dis(int x,int y,int d,int r)
{
    return abs(x-d)+abs(y-r);
}
int main()
{
    sint2(n,m);
    vii v,v2;
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        v.pb(mkp(x,y));
    }
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        v2.pb(mkp(x,y));
        a[i]=inf;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int x,y,d,r;
            x=v[i].F;
            y=v[i].S;
            d=v2[j].F;
            r=v2[j].S;
            a[j]=min(a[j],dis(x,y,d,r));
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        b[a[i]]++;
        ans=max(ans,b[a[i]]);
//        printf("%d\n",a[i]);
    }
    printf("%d\n",ans);
}
