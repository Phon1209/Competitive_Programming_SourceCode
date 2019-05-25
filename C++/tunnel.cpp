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
ll a[100005];
bitset<100005> bt;
void _main()
{
    bt.reset();
    sint(n);
    slong(k);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        if(tmp)bt[i]=1;
    }
    ll ans=0;
    if(bt[0]==0)ans++;
    if(bt[n-1]==0)ans++;
    bt[0]=1;
    bt[n-1]=1;
    ll sum=0;
    queue<ll> q;
    for(int i=0;i<n;i++)
    {
        if(bt[i])while(!q.empty())sum-=q.front(),q.pop();
        if(bt[i])continue;
        q.push(a[i]);
        sum+=a[i];
        if(sum>=k)
        {
            ans++;
            bt[i]=1;
            while(!q.empty())sum-=q.front(),q.pop();
        }
    }
    printf("%lld\n",ans);
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

*/
