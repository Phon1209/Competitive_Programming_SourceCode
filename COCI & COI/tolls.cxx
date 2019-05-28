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
#define inf 4611686018427387904
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
vi a,b;
int perm[5];
ll dp[100005];
ll cal(int x,int y)
{
    if(x==y)return 1e18;
    return (x>y)? x-y:y-x;
}
int main()
{
    sint(n);
    a.pb(0);
    b.pb(0);
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        a.pb(x);
        b.pb(y);
    }
    sort(all(a));
    sort(all(b));
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=inf;
        for(int j=1;j<=3 && i-j>=0;j++)
        {
            for(int k=0;k<j;k++)perm[k]=k;
            int t=6;
            while(t--)
            {
                ll use=0;
                for(int k=0;k<j;k++)
                    use+=cal(a[i-k],b[i-perm[k]]);
                dp[i]=min(dp[i-j]+use,dp[i]);
                next_permutation(perm,perm+j);
            }
        }
    }
    printf("%lld\n",dp[n]);
}
/*

*/
