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
vi v,v2;
vi::iterator it,it2;
int main()
{
    sint2(n,m);
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        x++;
        y--;
        v.pb(x);
        v2.pb(y);
    }
    sort(all(v));
    sort(all(v2));
    int ans=0;
    while(m--)
    {
        sint(tmp);
        it=lower_bound(all(v2),tmp);
        it2=upper_bound(all(v),tmp);
        int cntf,cnts;
        cntf=(int)(it-v2.begin());
        cnts=(int)(v.end()-it2);
        ans+=(n-cntf-cnts);
        ans%=2007;
        printf("%d\n",ans);
    }
    printf("%d\n",ans);
}
