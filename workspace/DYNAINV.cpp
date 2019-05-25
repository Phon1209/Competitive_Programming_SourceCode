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
int a[10005];
void add(int idx,int lim)
{
    while(idx<lim)
    {
        a[idx]+=1;
        a[idx]%=2;
        idx+=(idx&-idx);
    }
}
int sum(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=a[idx];
        ret%=2;
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    int ans=0;
    sint2(n,m);
    vi v;
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        v.pb(tmp);
    }
    for(int i=n-1;i>=0;i--)
    {
        int tmp=v[i];
        ans+=sum(tmp-1);
        add(tmp,n);
    }
    ans%=2;
    for(int i=0;i<m;i++)
    {
        sint2(x,y);
        printf("%d\n",ans++);
        ans%=2;
    }

}
/*

*/
