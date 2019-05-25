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
bool a[10][10][10];
int main()
{
    int cnt=0;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=8;j++)
        {
            if(j==i)continue;
            for(int k=1;k<=8;k++)
            {
                if(k==i || k==j)continue;
                if(a[i][j][k])continue;
                printf("%d.%d %d %d\n",++cnt,i,j,k);
                a[i][j][k]=1;
                a[i][k][j]=1;
                a[j][k][i]=1;
                a[j][i][k]=1;
                a[k][i][j]=1;
                a[k][j][i]=1;
            }
        }
    }
}
