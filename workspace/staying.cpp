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
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define MOD 1000000007
int a[5];
ll dp[1005][1005][5][10];
vi v[5];
int n;
ll find(int day,int stay,int town,int ok)
{
//    printf("%d %d %d %d\n",day,stay,town,ok);
    if(day==n && ok==7)return 1;
    if(day==n)return 0;
    if(dp[day][stay][town][ok])return dp[day][stay][town][ok];
    ll ret=0;
    for(int i=0;i<v[town].size();i++)
    {
        int y=v[town][i];
        ret+=find(day+1,1,y,ok|(1<<y));
        ret%=MOD;
    }
    if(stay<a[town])
    {
        ret+=find(day+1,stay+1,town,ok);
    }
    ret%=MOD;
    dp[day][stay][town][ok]=ret;
    return ret;
}
int main()
{
    int1(n);
    int3(a[0],a[1],a[2]);
    v[0].pb(1);
    v[1].pb(2);
    v[2].pb(0);
    v[0].pb(2);
    printf("%lld\n",find(1,1,0,1)%MOD);
}
/*

*/
