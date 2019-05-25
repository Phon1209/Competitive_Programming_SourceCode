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
ll a[50005];
ll dpa[50005];
ll dpb[50005];
ll qs[50005];
int main()
{
    sint3(n,k,m);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        ans+=a[i];
        qs[i]=ans;
    }
    dpa[m-1]=(1LL<<60);
    dpb[m-1]=dpa[m-1];
    for(int i=m;i<=n;i++)
    {
        dpa[i]=min(dpa[i-1]+a[i],qs[i]-qs[i-m]);
        dpb[i]=min(dpb[i-1],dpa[i]);
    }
    for(int i=1;i<k;i++)
    {
        int st=((i+1)*m+i);
        dpa[st-1]=(1LL<<60);
        for(int j=st;j<=n;j++)
            dpa[j]=min(dpa[j-1]+a[j],dpb[j-m-1]+(qs[j]-qs[j-m]));
        dpb[st]=dpa[st];
        for(int j=st+1;j<=n;j++)
            dpb[j]=min(dpb[j-1],dpa[j]);
    }
    printf("%lld\n",ans-dpb[n]);
    return 0;
}
/*

*/
