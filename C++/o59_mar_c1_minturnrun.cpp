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
vector<string> a;
vector<vi> b;
int main()
{
    sint3(n,m,k);
    for(int i=0;i<n;i++)
    {
        sstring(s);
        char c=(i==k-1)? '.':'#';
        a.pb(c+s);
    }
    b.resize(n);
    for(int i=0;i<n;i++)
    {
        b[i].resize(m+1);
    }
    /*
    for(int i=0;i<n;i++)
    {
        cout<< a[i];
        endl;
    }
    endl;
    return 0;
    */
    queue<ii> q;
    q.push(mkp(k-1,0));
    b[k-1][0]=1;
    bool ok=false;
    while(!q.empty())
    {
        ii pos;
        pos=q.front();
        q.pop();
        int x,y;
        x=pos.F;
        y=pos.S;
        if(y==m)
        {
            printf("%d\n",b[x][y]-2);
            ok=true;
            return 0;
        }
        for(int i=1;;i++)
        {
            if(x-i<0 || a[x-i][y]=='#')break;
            if(b[x-i][y]!=0)break;
            b[x-i][y]=b[x][y]+1;
            q.push(mkp(x-i,y));
        }
        for(int i=1;;i++)
        {
            if(x+i>=n || a[x+i][y]=='#')break;
            if(b[x+i][y]!=0)break;
            b[x+i][y]=b[x][y]+1;
            q.push(mkp(x+i,y));
        }
        for(int i=1;;i++)
        {
            if(y+i>m || a[x][y+i]=='#')break;
            if(b[x][y+i]!=0)break;
            b[x][y+i]=b[x][y]+1;
            q.push(mkp(x,y+i));
        }
    }
    if(!ok)
    {
        printf("-1\n");
    }
    /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(a[i][j]=='#')printf("#");
            else printf("%d",b[i][j]);
        }
        endl;
    }
    // */
}
/*

*/
