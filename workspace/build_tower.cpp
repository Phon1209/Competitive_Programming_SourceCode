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
vii a;
int sc[205];
int main()
{
    sint(t);
    while(t--)
    {
        sint(n);
        a.resize(n+5);
        for(int i=0;i<n;i++)
        {
            sint2(x,y);
            a[i]=mkp(x,y);
        }
        int ans=0;
        sort(all(a),greater<ii>());
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                sc[i]=a[i].S;
                continue;
            }
            for(int j=i-1;j>=0;j--)
            {
                printf("%d %d %d %d\n",a[i].F,a[i].S,a[j].F,a[j].S);
                if(a[i].F<=a[j].F && a[i].S<=a[j].S)
                {
                    sc[i]=max(sc[i],sc[j])+a[j].S;
                    ans=max(ans,sc[i]);
                }
            }
        }
        printf("%d\n",ans);
    }
}
