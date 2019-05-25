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
int a[200005];
void add(int idx,int val,int lim)
{
    while(idx<=lim)
    {
        a[idx]+=val;
        idx+=(idx&-idx);
    }
}
int sum(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=a[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    sint2(n,m);
    while(m--)
    {
        sint(tmp);
        if(tmp==1)
        {
            sint3(x,y,val);
            add(x,val,n);
            add(y+1,-val,n);
//            FOR(i,1,n+1)printf("%d ",a[i]);endl;
        }
        else if(tmp==2)
        {
            sint(x);
            printf("%d\n",sum(x));
        }
    }
}
