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
bitset<1000005> bt;
vi v;
int rk[1000005];
int main()
{
    for(int i=2;i<=1000000;i++)
    {
        if(bt[i])continue;
        v.pb(i);
        rk[i]=1;
        for(int j=i+i;j<=1000000;j+=i) bt[j]=1;
    }
//       printf("a\n");
    for(int i=2;i<=1000000;i++)
    {
        if(rk[i]==0)
        {
            for(int j=0;j<v.size();j++)
            {
                if(i%v[j]==0)
                {
//                    printf("%d %d\n",i,i/v[j]);
                    rk[i]=rk[i/v[j]]+1;
                    break;
                }
            }
        }
//        if(i%10==0)pause;
    }
//    printf("A\n");
    sint2(a,b);
    sint2(c,d);
    int mx=0;
    int ans,ans2;
    for(int i=2;i<=max(b,d);i++)
    {
        int n,m;
        n=(b/i)*i;
        m=(d/i)*i;
        if(n>b || n<a)continue;
        if(m>d || m<c)continue;
//        printf("%d %d\n",i,rk[i]);
//        printf("%d %d %d\n",n,m,rk[i]);
        if(rk[i]>mx)
        {
            mx=rk[i];
            ans=n;
            ans2=m;
        }
        else if(rk[i]==mx)
        {
            if(n+m>ans+ans2)
            {
                ans=n;
                ans2=m;
            }
            else if(n+m==ans+ans2)
            {
                if(n>ans)
                {
                    ans=n;
                    ans2=m;
                }
            }
        }
    }
    printf("%d %d\n",ans,ans2);
}
/*

*/
