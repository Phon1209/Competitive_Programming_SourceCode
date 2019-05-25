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
int a[105][105];
int main()
{
//    freopen("test.txt","w",stdout);
    sint(t);
    while(t--)
    {
        sint(n);
        sint(m);
        memset(a,0,sizeof(a));
        while(m--)
        {
            sint2(x,y);
            sint2(d,r);
            a[x][y]++;
            a[x][r+1]--;
            a[d+1][y]--;
            a[d+1][r+1]++;
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",a[i][j]);
            }
            endl;
        }endl;
        //*/

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
        /*
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                printf("%d ",a[i][j]);
            }
            endl;
        }
        //*/
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int k=i;k<=n;k++)
                {
                    for(int l=j;l<=n;l++)
                    {
                        if(a[k][l]-a[i-1][l]-a[k][j-1]+a[i-1][j-1]==0)
                        {
                            ans=max(ans,(k-i+1)*(l-j+1));
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}
/*
3
10
3
2 2 5 3
8 3 9 7
3 6 3 8
20
1
1 1 1 1
10
2
5 1 5 10
1 5 10 5
*/
