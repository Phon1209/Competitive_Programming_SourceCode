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
int a[205][205];
int b[205][205];
int main()
{
    sint3(n,m,k);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int1(a[i][j]);
        }
    }
    for(int j=1;j<=m;j++)
    {
        for(int i=1;i<=n+k;i++)
        {
            b[i][j]=b[i-1][j]+a[i][j];
        }
    }
    /*
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ",b[i][j]);
        }
        endl;
    }
//*/
    int ans=0;
    int ans2=0;
    for(int j=1;j<=m;j++)
    {
        int cnt=0;
        int cnt2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i][j]==1)
            {
                if(b[i+k-1][j]-b[i-1][j]>cnt)
                {
                    cnt2=b[i-1][j];
                    cnt=b[i+k-1][j]-b[i-1][j];
                }
            }
        }
        ans2+=cnt2;
        ans+=cnt;
    }
    printf("%d %d\n",ans,ans2);
}
