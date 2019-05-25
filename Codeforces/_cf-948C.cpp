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

ll a[100005];
ll t[100005];
ll tod[100005];
ll ok[100005];
int main()
{
    sint(n);
    for(int i=1;i<=n;i++)
    {
        slong(tmp);
        a[i]=tmp;
    }
    for(int i=1;i<=n;i++)
    {
        slong(tmp);
        t[i]=tmp;
        t[i]+=t[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        int l=i,r=n;
        while(l<r)
        {
            int md=(l+r+1)/2;
            // debug(md);
            if(t[md]-t[i-1]<=a[i])
            {
                l=md;
            }
            else r=md-1;
        }
        if(t[l]-t[i-1]>a[i])l--;
        ok[i]++;
        ok[l+1]--;
        tod[l+1]+=a[i]-(t[l]-t[i-1]);
    }
    for(int i=1;i<=n;i++)
    {
        ok[i]+=ok[i-1];
        printf("%lld ",tod[i]+(ok[i]*(t[i]-t[i-1])));
    }
    endl;
}
/*

*/
