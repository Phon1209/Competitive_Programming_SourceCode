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

char a[2005][2005];
int b[2005][2005];
int mu[]={1,0,0,-1};
int me[]={0,1,-1,0};
int main()
{
    memset(b,0,sizeof(b));
    sint2(n,m);
    sint2(sx,sy);
    sx--;
    sy--;
    sint2(l,r);
    FOR(i,0,n)
    {
        scanf("%s",a[i]);
        FOR(j,0,m)
        {
            if(a[i][j]=='*')b[i][j]=1;
        }
    }
    queue<tuple<int,int,int,int> > q;
    q.push(mkt(sx,sy,0,0));
    int x,y,ul,ur;
    int cnt=0;
    while(!q.empty())
    {
        tie(x,y,ul,ur)=q.front();
        q.pop();
        // printf("%d %d %d %d\n",x,y,ul,ur);
        if(ul>l || ur>r)continue;
        if(b[x][y])continue;
        b[x][y]=1;
        cnt++;
        // debug(1);
        a[x][y]='+';
        FOR(i,0,4)
        {
            int nx,ny;
            nx=x+mu[i];
            ny=y+me[i];
            // debug(b[nx][ny]);
            if(b[nx][ny]!=0)continue;
            if(nx>=n || nx<0)continue;
            if(ny>=m || ny<0)continue;
            if(a[nx][ny]=='*')continue;
            // b[nx][ny]=b[x][y]+1;
            // printf(">>%d %d %d %d\n",nx,ny,ul,ur);
            //2=r 3=l
            q.push(mkt(nx,ny,ul+((i==2)? 1:0),ur+((i==1)? 1:0)));
        }
    }
    printf("%d\n",cnt);
}
/*

*/
