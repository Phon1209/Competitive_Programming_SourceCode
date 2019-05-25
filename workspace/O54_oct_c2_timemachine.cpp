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
#define fastio ios::sync_with_stdio(false);cin.tie(NULL)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
vector<pair<ii,int> > node;
int v[20][20];
int t[15];
int a[15][1050];
int k;
int path[20];
int ANS=inf;
void toans(int lv)
{
    int ans=0;
    for(int i=0;i<lv;i++)
    {
//        printf("%d ",path[i]);
        if(i==0)
        {
            ans+=v[0][path[i]];
        }
        else
        {
            ans+=v[path[i-1]][path[i]];
        }
        ans-=t[path[i]];
//        printf(">%d\n",ans);
    }
//    endl;
    ANS=min(ans,ANS);
}
void find(int bit)
{
    int lv=__builtin_popcount(bit);
    if(bit & (1<<1))
    {
        toans(lv);
        return;
    }

    for(int i=1;i<k+2;i++)
    {
        if(!(bit&(1<<i)))
        {
            path[lv]=i;
            find(bit|(1<<i));
        }
    }
}
int main()
{
    sint2(n,m);
    int1(k);
    node.pb(mkp(mkp(0,0),0));
    node.pb(mkp(mkp(n-1,m-1),1));
    for(int i=2;i<k+2;i++)
    {
        sint3(x,y,w);
        t[i]=w;
        node.pb(mkp(mkp(x,y),i));
    }
    for(int i=0;i<k+2;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            int x,y;
            x=node[i].S;
            y=node[j].S;
            int w=(abs(node[i].F.F-node[j].F.F)*abs(node[i].F.F-node[j].F.F)+abs(node[i].F.S-node[j].F.S)*abs(node[i].F.S-node[j].F.S));
            int W=sqrt(w);
            if(W*W<w) W++;
//            printf("%d %d %d\n",x,y,W);
            v[x][y]=W;
            v[y][x]=W;
        }
    }
    find(0);
    printf("%d\n",ANS);
    pause;
}
/*

*/
