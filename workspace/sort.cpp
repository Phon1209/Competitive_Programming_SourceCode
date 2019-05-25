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
int a[1005];
int tmp[1005];
void mergesort(int st,int ed)
{
    if(st>=ed)return;
    int md=(st+ed)/2;
    mergesort(st,md);
    mergesort(md+1,ed);
    int i,j;
    i=st;
    j=md+1;
    int cnt=st;
    while(i<=md && j<=ed)
    {
        if(a[i]<a[j])
        {
            tmp[cnt]=a[i];
            i++;
        }
        else
        {
            tmp[cnt]=a[j];
            j++;
        }
        cnt++;
    }
    while(i<=md)
    {
        tmp[cnt]=a[i];
        i++;
        cnt++;
    }
    while(j<=ed)
    {
        tmp[cnt]=a[j];
        j++;
        cnt++;
    }
    for(int i=st;i<=ed;i++)
    {
        a[i]=tmp[i];
    }
}
int main()
{
    sint(n);
    for(int i=0;i<n;i++)
    {
        int1(a[i]);
    }
    mergesort(0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
/*

*/
