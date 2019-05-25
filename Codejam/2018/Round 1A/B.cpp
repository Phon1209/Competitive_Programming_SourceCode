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
vector<pair<ll,pair<ll,ll> > > v;
void _main()
{
    v.clear();
    ll r,b,c,m,s,p,mn=1,mx=0;
    scanf("%lld %lld %lld",&r,&b,&c);//robot bit cashier
    ll ans=LLONG_MAX;
    for(ll i=1;i<=c;i++)
    {
        scanf("%lld %lld %lld",&m,&s,&p);// max per/item pack
        v.pb(mkp(m,mkp(s,p)));
        mx=max(b*s+p,mx);
    }
    while(mn<=mx)
    {
        ll md=(mn+mx)/2;
        vector<ll> chk;
        // debug(md);
        for(int i=0;i<v.size();i++)
        {
            ll tim=md-v[i].S.S;//p
            ll amount=tim/v[i].S.F;//s
            amount=min(amount,v[i].F);//m
            amount=max(amount,0LL);
            chk.pb(amount);
        }
        sort(all(chk),greater<ll>());
        ll ok=0;
        for(ll i=0;i<r;i++)
        {
            ok+=chk[i];
        }
        // debug(ok);
        if(ok>=b)
        {
            ans=min(ans,md);
            mx=md-1;
        }
        else
        {
            mn=md+1;
        }
    }
    printf("%lld",ans);
}
int main()
{
    // SEND;
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
        if(i!=t)endl;
    }
}
/*

*/
