#include<bits/stdc++.h>
using namespace std;
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
bitset<2000010> bt;
int back[2000010];
ll cnt[2000010];
ll cnt2[2000010];
#define MAX_N 2000005
int main()
{
    vi v;
    back[0]=1;
    back[1]=1;
    back[2]=2;
    for(int i=4;i<=MAX_N;i+=2)
    {
        bt[i]=1;
        back[i]=2;
    }
    v.pb(2);
    for(int i=3;i<=MAX_N;i+=2)
    {
        if(bt[i])continue;
        back[i]=i;
        v.pb(i);
        for(int j=i+i;j<=MAX_N;j+=i)
        {
            bt[j]=1;
            back[j]=i;
        }
    }
    sint(n);
    slong(m);
    int r=n;
    n*=2;
    for(int i=r+1;i<=n;i++)cnt[i]=1;
    // debug(1);
    for(int i=n;i>=2;i--)
    {
        if(bt[i]==0)continue;
        int u=back[i];
        // debug(i);
        // debug(u);
        int tmp=i/u;
        int o=cnt[i];
        // debug(i);
        cnt[i]=0;
        cnt[u]+=o;
        cnt[tmp]+=o;
    }
    for(int i=1;i<=r;i++)cnt2[i]=1;
    for(int i=r;i>=1;i--)
    {
        if(bt[i]==0)continue;//1000000000
        int u=back[i];
        int tmp=i/u;
        int o=cnt2[i];
        // debug(i);
        cnt2[i]=0;
        cnt2[u]+=o;
        cnt2[tmp]+=o;
    }
    ll ans=1;
    for(int i=0;i<v.size();i++)
    {
        int u=cnt[v[i]]-cnt2[v[i]];
        while(u--)
        {
            ans*=v[i];
            ans%=m;
        }
    }
    ans*=ans;
    ans%=m;
    printf("%lld\n",ans);
}
/*

*/
