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
vector<pair<ii,int> >  v;
int dp[200];
int main()
{
//    freopen("test.txt","w",stdout);
    int t=0;
    while(++t)
    {
        v.clear();
        sint(n);
        if(!n)break;
        for(int i=0;i<n;i++)
        {
            sint3(x,y,z);
            v.pb(mkp(mkp(x,y),z));
            v.pb(mkp(mkp(y,x),z));
            v.pb(mkp(mkp(x,z),y));
            v.pb(mkp(mkp(z,x),y));
            v.pb(mkp(mkp(z,y),x));
            v.pb(mkp(mkp(y,z),x));
        }
        sort(all(v));
        int ans=0;
        for(int i=0;i<6*n;i++)
        {
            dp[i]=v[i].S;
            for(int j=i-1;j>=0;j--)
            {
                if(v[i].F.F>v[j].F.F && v[i].F.S>v[j].F.S)
                    dp[i]=max(dp[i],dp[j]+v[i].S);
            }
            ans=max(dp[i],ans);
        }
        printf("Case %d: maximum height = %d\n",t,ans);
    }
}
/*

*/
