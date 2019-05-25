#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define mkt make_tuple
#define pb push_back
#define inf INT_MAX
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
#define cstring(a,x) char a[x]; scanf("%s",a);
#define sstring(a) string a;cin>>a;
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
#define fastio {ios::sync_with_stdio(false);cin.tie(NULL);}
#define null NULL
#define debug(x) cout<< #x << " = " << x;endl;
#define OPEN freopen("input.txt","r",stdin)
#define SEND freopen("output.txt","w",stdout)
#define IN(x) freopen(x,"r",stdin);
#define OUT(x) freopen(x,"w",stdout);

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;

int n,m;
char a[100][100];
int mp[5][100][100];
int mu[]={1,0,0,-1};
int me[]={0,-1,1,0};
void dfs(int x,int y,char mask)
{
    a[x][y]=mask;
    for(int i=0;i<4;i++)
    {
        if(x+mu[i]>=n || x+mu[i]<0)continue;
        if(y+me[i]>=m || y+me[i]<0)continue;
        if(a[x+mu[i]][y+me[i]]!='X')continue;
        dfs(x+mu[i],y+me[i],mask);
    }
}
int bfs(int x,int y,char st,char mark,int cnt)
{
    int ret=-1;
    // printf("%d %d %c %c %d\n",x,y,st,mark,cnt);
    priority_queue<pair<int,ii> > q;
    q.push(mkp(0,mkp(x,y)));
    while(!q.empty())
    {
        x=q.top().S.F;
        y=q.top().S.S;
        int walk=-q.top().F;
        q.pop();
        mp[cnt][x][y]=walk;
        // printf("%d %d %d\n",x,y,walk);
        if(ret==-1 && a[x][y]==mark)
        {
            // // printf("FOUND\n");
            // pause;
            ret=walk-1;
        }
        for(int i=0;i<4;i++)
        {
            int nx,ny,nw;
            nx=x+mu[i];
            ny=y+me[i];
            nw=walk;
            if(a[nx][ny]!=st)
            {
                // debug(1);
                nw++;
            }
            if(x+mu[i]>=n || x+mu[i]<0)continue;
            if(y+me[i]>=m || y+me[i]<0)continue;
            if(mp[cnt][nx][ny]==-1)
            {
                mp[cnt][nx][ny]=nw;
                q.push(mkp(-nw,mkp(nx,ny)));
            }
        }
    }
    return ret;
}
int pos[5][2];
int main()
{
    memset(mp,-1,sizeof(mp));
    int2(n,m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='X')
            {
                pos[cnt][0]=i;
                pos[cnt][1]=j;
                dfs(i,j,'0'+cnt++);
            }
        }
    }
    /*
    endl;
    for(int i=0;i<n;i++)
    {
        printf("%s\n",a[i]);
    }
    */
    int dis12=bfs(pos[0][0],pos[0][1],'0','1',0);
    // debug(dis12);
    // Debug(0);
    int dis31=bfs(pos[2][0],pos[2][1],'2','0',1);
    // debug(dis31);
    // Debug(1);
    int dis23=bfs(pos[1][0],pos[1][1],'1','2',2);
    // debug(dis23);
    // Debug(2);
    int ans=inf;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            ans=min(ans,mp[0][i][j]+mp[1][i][j]+mp[2][i][j]-2);
        }
    }
    ans=min(ans,min(dis12+dis31,min(dis12+dis23,dis31+dis23)));
    printf("%d\n",ans);
}
/*

*/
