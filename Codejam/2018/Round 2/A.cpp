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
int a[105];
char p[105][105];
int _main()
{
    sint(n);
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
        sum+=a[i];
    }
    if(sum!=n ||a[1]==0 || a[n]==0)
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    int want=0;
    int ans=1;
    vi v;
    vi pos;
    v.pb(0);
    pos.pb(0);
    queue<ii> q;
    ii now={0,0};
    ii lst;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=0)
        {
            q.push(mkp(i,a[i]));
        }
        if(now.F==0 && !q.empty())
        {
            // now=q.front();
            now.F=q.front().F;
            now.S+=q.front().S;
            lst=q.front();
            q.pop();
        }
        // debug(now.F);
        // debug(now.S);
        if(now.S<=0 && now.F!=0)
        {
            // debug(3);
            ans=max(ans,max(now.F-v.back()-1,i-1-now.F)+1);
            v.pb(v.back()+(lst.S));
            pos.pb(now.F);
            now.F=0;
        }
        now.S--;
        // ans=max(ans,abs(now.S)+1);
        if(now.S<=0 && now.F!=0)
        {
            // debug(1);
            ans=max(ans,max(now.F-v.back()-1,i-now.F)+1);
            v.pb(i);
            pos.pb(now.F);
            now.F=0;
        }
    }
    printf("%d\n",ans);
    for(int i=1;i<=ans;i++)
    {
        for(int j=1;j<=n;j++)
        {
            p[i][j]='.';
        }
    }
    // debug(pos.size());
    // debug(v.size());
    for(int i=1;i<v.size();i++)
    {
        int st,ed;
        st=v[i-1]+1;
        ed=v[i];
        // debug(st);
        // debug(ed);
        int go=pos[i];
        // debug(go);
        for(int j=st;j<go;j++)
        {
            int cnt=go-j;
            int x,y;
            x=1;
            y=j;
            while(cnt--)
            {
                p[x][y]='\\';
                x++;
                y++;
            }
        }
        for(int j=go+1;j<=ed;j++)
        {
            int cnt=j-go;
            int x,y;
            x=1;
            y=j;
            while(cnt--)
            {
                p[x][y]='/';
                x++;
                y--;
            }
        }
    }
    for(int i=1;i<=ans;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%c",p[i][j]);
        }
        endl;
    }
    return 0;
}
int main()
{
    // SEND;
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
    }
}
/*

*/
