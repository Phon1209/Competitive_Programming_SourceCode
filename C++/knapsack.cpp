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

vii v[2005];
ll dp[2005];
int main()
{
    sint2(s,n);
    for(int i=0;i<n;i++)
    {
        sint3(val,w,k);
        v[w].pb(mkp(val,k));
    }
    // debug(2);
    for(int i=1;i<=2000;i++)
    {
        sort(all(v[i]),greater<ii>());
        int num=s/i;
        int cnt=0;
        // debug(3);
        while(num--)
        {
            if(cnt==v[i].size())break;
            for(int j=2000;j>=i;j--)
            {
                dp[j]=max(dp[j],dp[j-i]+v[i][cnt].F);
            }
            v[i][cnt].S--;
            if(v[i][cnt].S==0)cnt++;
        }
    }
    // debug(1);
    printf("%lld\n",dp[s]);
}
/*

*/
