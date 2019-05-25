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
#define MOD 100000
int a[100005];
int main()
{
    vector<ll> v;
    slong(m);
    slong(k);
    sint(n);
    for(int i=0;i<n;i++)
    {
        slong(tmp);
        v.pb(tmp);
    }
    for(int i=0;i<=100000;i++)
        a[i]=inf;
    queue<pair<ll,ll> > q;
    a[m]=0;
    q.push(mkp(m,0));
    while(!q.empty())
    {
        ll u=q.front().F;
        ll r=q.front().S;
        q.pop();
 ///       printf("%d\n",u);
        if(a[u]<r) continue;
        a[u]=r;
///        printf("%d\n",u);
        if(u==k)
        {
            printf("%d\n",r);
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            ll tmp=(u*v[i]);
            if(tmp>MOD)
            {
                tmp%=MOD;
            }
            if(a[tmp]>r+1)
            {
                a[tmp]=r+1;
                q.push(mkp(tmp,r+1));
            }
        }
    }
    printf("-1\n");
}
