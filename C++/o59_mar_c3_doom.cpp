#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize ("Ofast")
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a);
#define int2(a,b) scanf("%d %d",&a,&b);
#define int3(a,b,c) scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
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
char c[105][105];
ii pos[35];
int ret(char c,int k)
{
    if(c>='a' && c<='z')
    {
        if(c=='z')return 1;
        return 3+c-'a';
    }
    else if(c>='A' && c<='Z')
    {
        if(c=='Z')return 2;
        return 3+c-'A'+k;
    }
    return -1;
}
bool DOOR(char c)
{
    if(c<='Y' && c>='A')return true;
    return false;
}
int g[35][35];
int b[105][105];
int mu[]={1,0,0,-1};
int me[]={0,-1,1,0};
int main()
{
    sint3(n,m,k);
    for(int i=0;i<=34;i++)pos[i]={-1,-1};
    for(int i=0;i<=34;i++)
    {
        for(int j=0;j<=34;j++)
        {
            g[i][j]=inf;
        }
    }
    //start = 1;
    //end = 2;
    //Door i = 3+i; i-base 0
    //Key i = 3+k+i;
    //conclusion - Node 1-2(k+1)
    for(int i=0;i<n;i++)
    {
        scanf("%s",c[i]);
        for(int j=0;j<m;j++)
        {
            int u=ret(c[i][j],k);
            if(u!=-1)
            {
                pos[u]={i,j};
                g[u][u]=0;
            }
        }
    }
    for(int i=1;i<=32;i++)
    {
        if(pos[i]==mkp(-1,-1))continue;
        queue<ii> q;
        q.push(pos[i]);
        memset(b,-1,sizeof(b));
        b[pos[i].F][pos[i].S]=0;
        while(!q.empty())
        {
            int x,y;
            x=q.front().F;
            y=q.front().S;
            q.pop();
            for(int j=0;j<4;j++)
            {
                int xx,yy;
                xx=x+mu[j];
                yy=y+me[j];
                if(xx<0)continue;
                if(xx>=n)continue;
                if(yy<0)continue;
                if(yy>=m)continue;
                if(c[xx][yy]=='#')continue;
                if(b[xx][yy]!=-1)continue;
                b[xx][yy]=b[x][y]+1;
                // debug(xx);
                // debug(yy);
                if(ret(c[xx][yy],k)!=-1)
                {
                    int r=ret(c[xx][yy],k);
                    g[i][r]=b[xx][yy];
                }
                if(DOOR(c[xx][yy]))continue;
                q.push(mkp(xx,yy));
            }
        }
        /*
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                printf("%d ",b[i][j]);
            }
            endl;
        }
        */
    }
    Not Complete
    /*
    printf("Complete\n");
    for(int i=1;i<=2*k+2;i++)
    {
        for(int j=1;j<=2*k+2;j++)
        {
            printf("g[%d][%d] = %d\n",i,j,g[i][j]);
        }
    }
    */
}
/*

*/
