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
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
ll a[65][65];
int main()
{
    sint(n);
    a[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
                a[i][j]=a[i-1][j];
            else
                a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
    }
    /*
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            printf("%d ",a[i][j]);
        }
        endl;
    }*/
    for(int i=0;i<=n;i++)
    {
        if(i)printf("+ ");
        printf("%lld ",a[n][i]);
        printf("x^%d ",i);
        printf("y^%d ",n-i);
    }
    endl;
}
