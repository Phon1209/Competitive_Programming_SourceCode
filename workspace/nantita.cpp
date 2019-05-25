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
int a[1005];
int b[1005];
int c[1005];
int d[1005];
int main()
{
    sint2(n,m);
    for(int i=0;i<n;i++)
    {
        sint(tmp);
        a[i]=tmp;
        d[i]=tmp;
    }
    sort(a,a+n);
    int cnt=1;
    int now=a[0];
    int p=0;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]==a[i])
        {
            cnt++;
        }
        else
        {
            b[p]=now;
            c[p]=cnt;
            cnt=1;
            now=a[i];
            p++;
        }
    }
    b[p]=now;
    c[p]=cnt;
    p++;
    for(int i=0;i<p;i++)
    {
        printf("%d %d\n",b[i],c[i]);
    }
}
/*

*/
