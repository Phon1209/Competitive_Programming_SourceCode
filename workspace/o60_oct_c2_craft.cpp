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
int a[50];
//#pragma GCC optimize ("O3")
ll find(int n,int w)
{
    // printf(">%d %d\n",n,w);
    if(n==1)
    {
        w-=a[n];
        if(w==0)throw 1;
        return w;
    }
    int tmp;
    tmp=w*2+1;
    tmp-=a[n];
    if(tmp<=0)throw 1;
    int o=tmp-tmp/2;
    // printf(">>%d\n",tmp);
    // printf(">>%d %d\n",tmp/2,o);
    if(tmp/2==0 || o==0)throw 1;
    return find(n-1,tmp/2)+find(n-1,o);
}
int main()
{
    sint2(n,w);
    for(int i=2;i<1+n;i++)
    {
        int1(a[i]);
    }
    try
    {
        printf("%lld\n",find(n,w));
    }
    catch(...)
    {
        printf("-1\n");
    }
}
/*

*/
