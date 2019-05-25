#include<bits/stdc++.h>
using namespace std;
/*
Learn : -
Problem Type : -
Source : -
*/
#pragma GCC optimize ("O3")
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
char c[105][105];
int sumx[105],sumy[105];
void _main()
{
    memset(sumx,0,sizeof(sumx));
    memset(sumy,0,sizeof(sumy));
    memset(c,0,sizeof(c));
    sint2(n,m);
    sint2(h,w);
    vi flag;
    int all=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",c[i]);
        for(int j=0;c[i][j];j++)
        {
            if(c[i][j]=='@')
            {
                sumx[i]++;
                all++;
            }
        }
    }
    // debug(all);
    if(all%((h+1)*(w+1))!=0)
    {
        printf("IMPOSSIBLE");
        return;
    }
    int want=all/((h+1)*(w+1));
    if(want==0)
    {
        printf("POSSIBLE");
        return;
    }
    int chk=0;
    for(int i=0;i<n;i++)
    {
        // debug(chk);
        chk+=sumx[i];
        // debug(((chk)));
        if(chk==(all/(h+1)))
        {
            chk=0;
            flag.pb(i);
        }
        else if(chk>(all/(h+1)))
        {
            printf("IMPOSSIBLE");
            return;
        }
    }
    // printf("b\n");
    if(flag.size()!=(h+1))
    {
        printf("IMPOSSIBLE");
        return;
    }
    // printf("a\n");
    for(int i=0;i<m;i++)
    {
        int cnt=0;
        for(int j=0;j<n;j++)
        {
            sumy[cnt]+=(c[j][i]=='@')? 1:0;
            if(flag[cnt]==j)cnt++;
        }
        bool allok=1,lim=0;
        for(int j=0;j<cnt;j++)
        {
            if(sumy[j]!=want)allok=0;
            if(sumy[j]>want)lim=1;
        }
        if(allok)
        {
            memset(sumy,0,sizeof(sumy));
        }
        if(lim)
        {
            printf("IMPOSSIBLE");
            return;
        }
    }
    printf("POSSIBLE");
}
int main()
{
    // SEND;
    sint(t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        _main();
        if(i!=t)endl;
    }
}
/*

*/
