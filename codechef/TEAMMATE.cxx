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
#define MOD 1000000007
ll a[1000005];
ll pre[100005];
void _main()
{
    // memset(a,0,sizeof(a));
    set<int> s;
    sint(n);
    for(int i=1;i<=n;i++)
    {
        sint(tmp);
        a[tmp]++;
        s.insert(tmp);
    }
    auto it=s.rbegin();
    bool spare=0;
    ll ans=1;
    ll rem=0;
    //remain u  = 1*3*5*...*u-1
    while(it!=s.rend())
    {
        int u=*it;
        // printf("%d %d %d %lld\n",u,a[u],spare? 1:0,rem);
        if(a[u]==1)
        {
            if(spare){
                ans*=(ll)(rem)*a[u];
                spare=0;
            }
            else
            {
                spare=1;
                rem=1;
            }
            it++;
            // debug((ans));
            a[u]=0;
            continue;
        }
        // debug(u);
        if(spare)
        {
            if(a[u]%2)
            {
                // debug(1);
                ans*=((ll)rem*a[u]);
                a[u]--;
                ans*=pre[a[u]];
                ans%=MOD;
                spare=0;
            }
            else
            {
                ans*=((ll)rem*(ll)a[u]);
                rem=--a[u];
                a[u]--;
                ans*=pre[a[u]];
                ans%=MOD;
            }
        }
        else
        {
            if(a[u]%2)
            {
                rem=a[u];
                a[u]--;
                spare=1;
                ans*=pre[a[u]];
                ans%=MOD;
            }
            else
            {
                ans*=pre[a[u]];
                ans%=MOD;
            }
        }
        a[u]=0;
        // debug(ans);
        it++;
    }
    printf("%lld\n",ans);
    return;
}
int main()
{
    pre[0]=1;
    pre[2]=1;
    for(int i=4;i<=100000;i+=2)
    {
        pre[i]=pre[i-2]*(i-1);
        pre[i]%=MOD;
    }
    sint(t);
    while(t--)_main();
}
/*

*/
