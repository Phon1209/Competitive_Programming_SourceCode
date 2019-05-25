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
int a[40005][40005];
int n;
void add(int idx,int idy,int val)
{
    while(idx<=n)
    {
        int tmp=idy;
        while(tmp<=n)
        {
            a[idx][tmp]+=val;
            tmp+=(tmp&-tmp);
        }
        idx+=(idx&-idx);
    }
}
int sum(int idx,int idy)
{
    int ret=0;
    while(idx>0)
    {
        int tmp=idy;
        while(tmp>0)
        {
            ret+=a[idx][tmp];
            tmp-=(tmp&-tmp);
        }
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    int1(n);
    sint2(m,k);
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        sint2(d,r);
        add(x,y,1);
        add(x,r+1,-1);
        add(d+1,y,-1);
        add(d+1,r+1,1);
    }
    while(m--)
    {
        sint2(x,y);
        printf("%d\n",sum(x,y));
    }
}
/*

*/
