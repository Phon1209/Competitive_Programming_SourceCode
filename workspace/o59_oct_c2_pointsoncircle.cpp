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
//#pragma GCC optimize ("O3")
int a[1005][1005],n,k;
int path[1005];
bool got=0;
void find(int lv)
{
    if(got)return;
    // printf(">%d\n",lv);
    if(lv==k)
    {
        // printf("A\n");
        got=1;
        for(int i=0;i<k;i++)
        {
            printf("%d\n",path[i]);
        }
        return;
    }
    int tmp;
    bool ok;
    tmp=path[lv-1]+a[lv-1][lv];
    if(tmp>=n)tmp=tmp-n;
    ok=true;
    // printf(">>%d %d %d %d\n",lv,tmp,path[lv-1],a[lv-1][lv]);
    for(int i=lv-1;i>=0;i--)
    {
        if(abs(tmp-path[i])!=(a[lv][i]) && (n-abs(tmp-path[i])!=(a[lv][i])))
        {
            ok=false;
        }
    }
    if(ok)
    {
        path[lv]=tmp;
        find(lv+1);
    }
    tmp=path[lv-1]-a[lv-1][lv];
    if(tmp<0)tmp=n+tmp;
    ok=true;
    // printf(">>%d %d %d %d\n",lv,tmp,path[lv-1],a[lv-1][lv]);
    for(int i=lv-1;i>=0;i--)
    {
        if(abs(tmp-path[i])!=(a[lv][i]) && (n-abs(tmp-path[i])!=(a[lv][i])))
        {
            ok=false;
        }
    }
    if(ok)
    {
        path[lv]=tmp;
        find(lv+1);
    }
}
int main()
{
    int2(n,k);
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<k;j++)
        {
            int1(a[i][j]);
        }
    }
    path[0]=0;
    find(1);
}
/*

*/
