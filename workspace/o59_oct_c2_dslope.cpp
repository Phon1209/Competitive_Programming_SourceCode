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
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
#define MOD 999999999
//#pragma GCC optimize ("O3")
ll a[45][80005];
int n,k;
void add(int idx,int k,int val)
{
    while(idx<=n)
    {
        a[k][idx]+=val;
        a[k][idx]%=MOD;
        idx+=(idx&-idx);
    }
}
ll sum(int idx,int k)
{
    ll ret=0;
    while(idx>0)
    {
        ret+=a[k][idx];
        ret%=MOD;
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    int2(n,k);
    vi v;
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        tmp=n-tmp+1;
        v.pb(tmp);
    }
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int val=v[i];
        add(val,1,1);
        ll tmp;
        for(int j=2;j<=k;j++)
        {
            tmp=sum(val-1,j-1);
            tmp%=MOD;
            add(val,j,tmp);
        }
        ans+=tmp;
        ans%=MOD;
    }
    printf("%lld\n",ans);
}
/*

*/
