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
char a[1005][1005];
int mu[]={1,0,0,-1};
int me[]={0,-1,1,0};
int main()
{
    sint2(n,m);
    for(int i=0;i<n;i++)
    {
        scanf("%s",a[i]);
    }
    bool ok=true;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]=='S')
                for(int k=0;k<4;k++)
                {
                    if(!ok)break;
                    if(i+mu[k]<0 || j+me[k]<0 || i+mu[k]>=n || j+me[k]>=m)continue;
                    if(a[i+mu[k]][j+me[k]]=='W')ok=false;
                    if(a[i+mu[k]][j+me[k]]=='.')a[i+mu[k]][j+me[k]]='D';
                }
        }
    }
    printf("%s\n",ok? "Yes":"No");
    if(!ok)return 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            printf("%c",a[i][j]);
        }
        endl;
    }
}
/*

*/
