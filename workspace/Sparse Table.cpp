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
#define MAX_N 1000
#define LOG_TWO 10
int a[MAX_N];
class RMQ
{
private:
    int _a[MAX_N],spt[MAX_N][LOG_TWO];
public:
    RMQ(int n)
    {
        for(int i=0;i<n;i++)
        {
            _a[i]=a[i];
            spt[i][0]=i;
        }
        for(int j=1;(1<<(j-1))<=n;j++)
        {
            for(int i=0;i+(1<<(j))-1<n;i++)
            {
                if(_a[spt[i][j-1]]<_a[spt[i+(1<<(j-1))][j-1]])
                {
                    spt[i][j]=spt[i][j-1];
                }
                else
                {
                    spt[i][j]=spt[i+(1<<(j-1))][j-1];
                }
            }
        }
    }
    void pt(int n)
    {
        for(int j=0;(1<<(j-1))<=n;j++)
        {
            for(int i=0;i<n;i++)
            {
                printf("%d ",spt[i][j]);
            }
            endl;
        }
    }
    int query(int i,int j)
    {
        int k=(int)log2((double)j-i+1);
        if(_a[spt[i][k]]<=_a[spt[j-(1<<k)+1][k]]) return spt[i][k];
        return spt[j-(1<<k)+1][k];
    }
};
int main()
{
    sint(n);
    for(int i=0;i<n;i++)
    {
        int1(a[i]);
    }
    RMQ rmq(n);
//    rmq.pt(n);
    sint(m);
    while(m--)
    {
        sint(x);
 //       if(!x)break;
        sint(y);
        int u=rmq.query(x,y);
        printf("%d\n",a[u]);
    }
}
