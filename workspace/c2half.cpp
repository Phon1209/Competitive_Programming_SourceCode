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
int a[55][50005];
int main()
{
    sint(n);
    int cnt=0;
    a[0][0]=1;
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        tmp+=101;
        cnt+=tmp;
        for(int j=n/2;j>=1;j--)
        {
            for(int k=cnt;k>=tmp;k--)
            {
//                printf("%d %d %d\n",j,k,tmp);
                if(a[j-1][k-tmp])
                {
//                    printf("%d %d\n",j,k);
                    a[j][k]+=a[j-1][k-tmp];
                }
            }
        }
    }
    int t=cnt;
    cnt=(cnt+1)/2;
    int ans=inf;
//    printf("%d %d\n",n/2,cnt);
    for(int i=0;i<cnt;i++)
    {
        if(a[n/2][i]!=0)
        {
//            printf("%d\n",i);
            ans=min(ans,(t-i)-i);
        }
    }
    printf("%d\n",ans);
}
