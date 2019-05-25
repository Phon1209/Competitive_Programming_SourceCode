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
int mu[]={1,-1,0,0,0},me[]={0,0,1,-1,0};
int a[105][105];
char cs[105][105];
int b[105][105];
void bfs(int x,int y,int T,int r,int c)
{
    queue<pair<int,ii> > q;
    q.push(mkp(0,mkp(x,y)));
    b[x][y]=0;
    if(a[x][y]==0)
    {
        printf("NO\n");
        return;
    }
    while(!q.empty())
    {
        int t=q.front().F;
        int x=q.front().S.F;
        int y=q.front().S.S;
        q.pop();
        if(t==T)
        {
            printf("YES\n");
            return;
        }
//        printf("%d %d %d\n",x,y,t);
        bool nk=0;
        for(int i=0;i<5;i++)
        {
            int X,Y;
            X=x+mu[i];
            Y=y+me[i];
            if(X>=r || X<0)continue;
            if(Y>=c || Y<0)continue;
            if(t+1>=a[X][Y] && a[X][Y]!=-1)continue;
            if(t+1>T)continue;
            if(cs[X][Y]=='#')continue;
//            b[X][Y]=b[x][y]+1;
            q.push(mkp(t+1,mkp(X,Y)));
            nk=1;
        }
        if(!nk)
        {
            printf("NO\n");
            return;
        }
    }
}
void _main()
{
    sint2(r,c);
    sint(n);
    sint3(T,xx,yy);
    vector<pair<int,ii> > v;
    while(n--)
    {
        sint3(t,q,w);
        v.pb(mkp(t,mkp(q,w)));
    }
    for(int i=0;i<r;i++)
    {
        scanf("%s",cs[i]);
        for(int j=0;j<c;j++)b[i][j]=a[i][j]=-1;
    }
    sort(all(v));
    int cnt=0;
    queue<pair<int,ii> > q;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].F==v[0].F)
        {
            q.push(mkp(v[i].F,mkp(v[i].S.F,v[i].S.S)));
            a[v[i].S.F][v[i].S.S]=v[i].F;
            cnt++;
        }
        else break;
    }
    while(!q.empty())
    {
        int t=q.front().F;
        int x=q.front().S.F;
        int y=q.front().S.S;
        q.pop();
        for(int i=cnt;i<v.size();i++)
        {
            if(v[i].F==t+1 && t+1<=T)
            {
                q.push(mkp(v[i].F,mkp(v[i].S.F,v[i].S.S)));
                a[v[i].S.F][v[i].S.S]=v[i].F;
                cnt++;
            }
            else break;
        }
        for(int i=0;i<4;i++)
        {
            int X,Y;
            X=x+mu[i];
            Y=y+me[i];
            if(t+1>T)continue;
            if(X<0 || X>=r)continue;
            if(Y<0 || Y>=c)continue;
            if(cs[X][Y]=='#')continue;
            if(a[X][Y]==-1)
            {
                a[X][Y]=a[x][y]+1;
                q.push(mkp(t+1,mkp(X,Y)));
            }
        }
    }
    /*
    printf("%d %d\n",r,c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        endl;
    }
    //*/
    bfs(xx,yy,T,r,c);
}
int main()
{
    sint(t);
    while(t--)_main();
}
/*

*/
