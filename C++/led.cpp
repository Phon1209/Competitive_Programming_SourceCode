#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
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

void Debug(ll mask,int m)
{
    printf("Debug mask %lld = ",mask);
    for(int i=m-1;i>=0;i--)
    {
        if((1ll<<i)&mask)printf("1");
        else printf("0");
    }
    printf(" = %d\n",__builtin_popcountll(mask));
    endl;
}
char s[50];
ll conv()
{
    ll ret=0;
    for(int i=0;s[i];i++)
    {
        ret*=2;
        ret+=(s[i]=='1')? 1:0;
    }
    // debug(ret);
    return ret;
}
void _main()
{
    vector<ll> v,chk;
    sint2(n,m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        v.pb(conv());
    }
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        chk.pb(conv());
    }
    sort(all(chk));
    ll mask;
    ll res=v[0];
    ll ans=inf;
    bool ok=0;
    for(int i=0;i<n;i++)
    {
        // debug(res);
        // debug(chk[i]);
        mask=res^chk[i];
        // debug(mask);
        vector<ll> test;
        for(int j=0;j<n;j++)
        {
            test.pb(v[j]^mask);
        }
        sort(all(test));
        if(test==chk)
        {
            // Debug(mask,m);
            ans=min(ans,(ll)__builtin_popcountll(mask));
            ok=1;
        }
    }
    if(ok)printf("%lld\n",ans);
    else printf("NO\n");
    return;
}
int main()
{
    sint(t);
    while(t--)
    {
        _main();
    }
}
/*
2 2
10 11
01 00

2 2
01 00
10 11

2 2
01 00
11 10
*/
