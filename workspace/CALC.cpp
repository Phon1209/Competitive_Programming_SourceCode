#include<bits/stdc++.h>
using namespace std;
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
#define sstring(a,x) char a[x]; scanf("%s",a);
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

int main()
{
    sint(t);
    while(t--)
    {
        int ans=0;
        sint2(n,m);
        int tmp=n/2;
        int p1,p2;
        p1=ceil((double)tmp/m);
        p2=floor((double)tmp/m);
        int c1,c2;
        c1=p1*m;
        c2=p2*m;
        int ls=0,rs=0;
        ls=n-c1;
        rs=ls*p1;
        ans=max(ans,rs);
        ls=n-c2;
        rs=ls*p2;
        ans=max(ans,rs);
        printf("%d\n",ans);
    }
}
/*

*/
