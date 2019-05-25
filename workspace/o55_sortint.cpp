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
void sot(int st,int ed)
{
    if(ed<=st)  return;
    int pivot;
    pivot=rand()%(ed-st+1);
    pivot=pivot+st;
    swap(a[pivot],a[st]);
    int cnt=st+1;
    pivot=a[st].F;
    int pivot2=a[st].S;
    for(int i=st+1;i<=ed;i++)
    {
        if(a[i].F<pivot)
        {
            swap(a[cnt],a[i]);
            cnt++;
        }
        else if(a[i].F==pivot)
        {
            if(a[i].S<=pivot2)
            {
                swap(a[cnt],a[i]);
                cnt++;
            }
        }
    }
    /*
    printf("%d\n",cnt-1);
    for(int i=st;i<=ed;i++)
    {
        printf("%d ",a[i]);
    }
    endl;
    */
    swap(a[st],a[cnt-1]);
    sot(st,cnt-2);
    sot(cnt,ed);
}
int main()
{
    srand(time(0));
    sint(n);
    FOR(i,0,n)
    {
        sint2(tmp,p);
        a.pb(mkp(tmp,p));
    }
    sot(0,n-1);
    FOR(i,0,n)
    {
        printf("%d %d\n",a[i].F,a[i].S);
    }
}
