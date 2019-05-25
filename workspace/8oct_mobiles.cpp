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
int n;
ll a[1050][1050];
void upt(int idx,int idy,int val)
{
    int u=idy;
    while(idx<=n)
    {
        idy=u;
        while(idy<=n)
        {
            a[idx][idy]+=val;
            idy+=(idy&-idy);
        }
        idx+=(idx&-idx);
    }
}
ll sum(int idx,int idy)
{
    int u=idy;
    ll ret=0;
    while(idx>0)
    {
        idy=u;
        while(idy>0)
        {
            ret+=a[idx][idy];
            idy-=(idy&-idy);
        }
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    int1(n);
    int1(n);
    while(1)
    {
        sint(cm);
        if(cm==1)
        {
            sint3(x,y,val);
            x++;
            y++;
            upt(x,y,val);
        }
        if(cm==2)
        {
            sint2(x,y);
            sint2(d,r);
            x++;
            y++;
            d++;
            r++;
            printf("%lld\n",sum(d,r)+sum(x-1,y-1)-sum(x-1,r)-sum(d,y-1));
        }
        if(cm==3)break;
    }
}
