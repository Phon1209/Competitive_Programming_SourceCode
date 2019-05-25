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
int a[3005];
int main()
{
    int t=10;
    while(t--)
    {
        int cnt=1;
        sint2(n,k);
//        printf("%d %d\n",n,k);
        for(int i=2;i<=n;i++)
        {
            cnt+=i;
            a[i]=0;
        }
//        printf("%d\n",cnt);
        for(int i=n;i>=2;i--)
        {
            if(cnt-(2*i)==k || cnt-(2*i)>k+2)
            {
                a[i]=1;
                cnt-=(2*i);
            }
        }
        if(cnt!=k)
        {
            printf("Impossible\n");;
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(i!=1)
                printf("%c",(a[i])? '-':'+');
            printf("%d",i);
        }
        endl;
    }
}
