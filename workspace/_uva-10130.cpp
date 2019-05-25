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
vii v;
int a[30005];
int main()
{
    sint(t);
    while(t--)
    {
        v.clear();
        sint(n);
        int sum=0;
        for(int i=0;i<=30000;i++)a[i]=0;
        for(int i=0;i<n;i++)
        {
            sint2(x,y);
            sum+=y;
            for(int j=sum;j-y>=0;j--)
            {
                a[j]=max(a[j],a[j-y]+x);
            }
        }
        sint(m);
        int p=0;
        while(m--)
        {
            sint(tmp);
            int ans=0;
            for(int i=0;i<=tmp;i++)
            {
                ans=max(ans,a[i]);
            }
            p+=ans;
        }
        printf("%d\n",p);
    }
}
/*

*/
