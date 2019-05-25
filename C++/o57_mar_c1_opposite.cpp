#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : BFS
Source : Evaluator
*/
#pragma GCC optimize ("Ofast")
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
char a[50][50];
int mu[]={-1,1,0,0},rmu[]={1,-1,0,0};
int me[]={0,0,-1,1},rme[]={0,0,1,-1};
int b[50][50];
int mp[50][50][50][50];
int n,m;
bool crash(ii x){
    if(a[x.F][x.S]=='#')return true;
    if(x.F<0 || x.F>=n)return true;
    if(x.S<0 || x.S>=m)return true;
    return false;
}
int d[50][50][50][50];
int dis(ii x,ii y)
{
    return d[x.F][x.S][y.F][y.S];
}
void gendis()
{
    memset(d,-1,sizeof(d));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            queue<ii> q;
            if(a[i][j]=='#')continue;
            q.push(mkp(i,j));
            d[i][j][i][j]=0;
            while(!q.empty())
            {
                int x,y;
                x=q.front().F;
                y=q.front().S;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx=x+mu[k];
                    int ny=y+me[k];
                    if(crash(mkp(nx,ny)))continue;
                    if(d[i][j][nx][ny]!=-1)continue;
                    d[i][j][nx][ny]=d[i][j][x][y]+1;
                    q.push(mkp(nx,ny));
                }
            }
        }
    }
}
int main()
{
    OPEN;
    SEND;
    int2(m,n);
    ii st,ed;
    for(int i=0;i<n;i++){
        scanf("%s",a+i);
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='A')st={i,j};
            if(a[i][j]=='B')ed={i,j};
        }
    }
    gendis();
    if(dis(st,ed)==-1){
        printf("-1 0\n");
        return 0;
    }
    queue<pair<ii,ii> > q;
    q.push(mkp(st,ed));
    // debug(1);
    memset(mp,-1,sizeof(mp));
    mp[st.F][st.S][ed.F][ed.S]=0;
    int ans=inf;
    int ans2=inf;
    while(!q.empty())
    {
        ii x,y;
        x=q.front().F;
        y=q.front().S;
        q.pop();
        printf("%d %d %d %d\n",x.F,x.S,y.F,y.S);
        for(int i=0;i<4;i++)
        {
            ii nst,ned;
            nst={x.F+mu[i],x.S+me[i]};
            ned={y.F+rmu[i],y.S+rme[i]};
            if(crash(nst))nst=x;
            if(crash(ned))ned=y;
            printf(">>%d %d %d %d\n",nst.F,nst.S,ned.F,ned.S);
            if(mp[nst.F][nst.S][ned.F][ned.S]!=-1)continue;
            printf("Okay\n");
            mp[nst.F][nst.S][ned.F][ned.S]=mp[x.F][x.S][y.F][y.S]+1;
                q.push(mkp(nst,ned));
                int u=dis(nst,ned);
                debug(u);
                debug(mp[nst.F][nst.S][ned.F][ned.S]);
                if(u==ans)
                {
                    ans2=min(ans2,mp[nst.F][nst.S][ned.F][ned.S]);
                }
                if(u<ans)
                {
                    ans=u;
                    ans2=mp[nst.F][nst.S][ned.F][ned.S];
                }
        }
        // pause;
    }
    printf("%d %d\n",ans,ans2);
    assert(ans!=-1);
}
/*
5 1
A.#.B

*/
