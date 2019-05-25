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
int chk1[45],chk0[45];
int ok1[45],ok0[45];
void _main()
{
    sint2(n,m);
    for(int i=0;i<=m;i++)
        chk0[i]=chk1[i]=ok0[i]=ok1[i]=0;
    for(int i=0;i<n;i++)
    {
        sstring(a,m+5);
        for(int j=0;a[j];j++)
        {
            if(a[j]=='1')chk1[j]++;
            if(a[j]=='0')chk0[j]++;
        }
    }
    for(int i=0;i<n;i++)
    {
        sstring(a,m+5);
        for(int j=0;a[j];j++)
        {
            if(a[j]=='1')ok1[j]++;
            if(a[j]=='0')ok0[j]++;
        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(ok0[i]==chk0[i] && ok1[i]==chk1[i])continue;
        if(ok0[i]==chk1[i] && ok1[i]==chk0[i])ans++;
        else
        {
            printf("NO\n");
            return;
        }
    }
    printf("%d\n",ans);
}
int main()
{
    sint(t);
    while(t--) _main();
}
