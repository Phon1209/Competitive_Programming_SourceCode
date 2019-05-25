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
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
//#pragma GCC optimize ("O3")
int a[100][100],b[100][100];
int main()
{
    int r,c,i,j,n,x,y;
    scanf("%d %d %d",&r,&c,&n);
    while(n--)
    {
        scanf("%d %d",&x,&y);
        b[y][x]=1;
    }
    a[1][0]=1;
    for(i=1;i<=c;i++)
    {
        for(j=1;j<=r;j++)
        {
            if(b[i][j]==1)
                a[i][j]=0;
            else a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    // /*
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=r;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    // */
    printf("%d\n",a[c][r]);
}
