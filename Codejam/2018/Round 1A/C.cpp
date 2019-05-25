#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("O3")
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

void _main()
{
    sint2(n,p);
    double goal=(double)p;
    vector<pair<double,double> > v;
    double ans=0;
    for(int i=0;i<n;i++)
    {
        sint2(w,h);
        ans+=(w+h)*2;
        v.pb(mkp(2*((double)min(w,h)),2*(sqrt(w*w+h*h))));
    }
    sort(all(v),greater<pair<ll,ll> > ());
    double addon=0;
    for(int i=0;i<n;i++)
    {
        // printf(">%lf %lf\n",ans,v[i].F);
        if(ans+v[i].F>goal)
        {
            printf("%lf\n",min(ans+addon,goal));
            return;
        }
        else
        {
            ans+=v[i].F;
            addon+=(v[i].S-v[i].F);
        }
    }
    printf("%lf\n",min(ans+addon,goal));
}
int main()
{
    // SEND;
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
    }
}
/*

*/
