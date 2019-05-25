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
int a[100005];
int up[100005];
int down[100005];
void add(int idx,int val,int lim)
{
    while(idx<=lim)
    {
        a[idx]+=val;
        idx+=(idx&-idx);
    }
}
void addup(int idx,int val,int lim)
{
    while(idx<=lim)
    {
        up[idx]+=val;
        idx+=(idx&-idx);
    }
}
void adddown(int idx,int val,int lim)
{
    while(idx<=lim)
    {
        down[idx]+=val;
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
int sumup(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=up[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
int sumdw(int idx)
{
    int ret=0;
    while(idx>0)
    {
        ret+=down[idx];
        idx-=(idx&-idx);
    }
    return ret;
}
int main()
{
    sint2(n,m);
    while(m--)
    {
        sint(cm);
        if(cm==1)
        {
            sint2(x,y);
            if(x!=1)
            {
                if(sum(x-1)-1==sum(x))
                {
                    adddown(x,-1,n);
        //            printf("A\n");
                }
                if(sum(x-1)==sum(x))
                {
                    addup(x-1,1,n);
        //            printf("B\n");
                }
            }
//            if(y!=n)
            {
                if(sum(y)==sum(y+1)-1)
                {
                    addup(y,-1,n);
        //            printf("C\n");
                }
                if(sum(y)==sum(y+1))
                {
                    adddown(y+1,1,n);
        //            printf("D\n");
                }
            }
            add(x,1,n);
            add(y+1,-1,n);
        }
        if(cm==2)
        {
            sint2(x,y);
            printf("%d %d\n",sum(x),sum(y));
        }
        if(cm==3)
        {
            sint2(x,y);
            printf("%d %d ",sum(x),sum(y));
            printf("%d %d\n",sumup(y-1)-sumup(x-1),sumdw(y)-sumdw(x));
        }
    }
}
/*
10 10
1 2 5
2 1 10
3 1 10
1 4 5
2 1 10
3 3 6
1 8 8
3 5 8
1 5 10
2 5 6

*/
