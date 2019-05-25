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
int a[100005],n;
ll qs[100005];
int fw[100005];
void add(int idx,int val)
{
    while(idx<=n)
    {
        fw[idx]+=val;
        idx+=(idx&-idx);
    }
}
int sum(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=fw[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
int _main()
{
    int1(n);
    memset(qs,0,sizeof(qs));
    memset(fw,0,sizeof(fw));
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int now=a[i];
        int l=1,r=i-1;
        int L=i,R=i;
        while(l<=r)
        {
            int md=(l+r)/2;
            // debug(md);
            // printf(">%d %lld\n",now,qs[i-1]-qs[md-1]);
            if(qs[i-1]-qs[md]<=now)L=min(md,L),r=md-1;
            else l=md+1;
        }
        l=i+1;
        r=n;
        while(l<=r)
        {
            int md=(l+r)/2;
            // debug((md));
            // printf(">%d %lld\n",now,qs[md-1]-qs[i]);
            if(qs[md-1]-qs[i]<=now)R=max(R,md),l=md+1;
            else r=md-1;
        }
        add(L,1);
        add(R+1,-1);
        add(i,-1);
        add(i+1,1);
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",sum(i));
    }
    endl;
    return 0;
}
int main()
{
    sint(t);
    while(t--)_main();
}
/*

*/
