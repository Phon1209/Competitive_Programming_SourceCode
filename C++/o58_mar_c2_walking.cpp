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
int a[6006];
int bt[6005];
int lv[6005];
vi v[6005];
bool chk[6005];
int main()
{
    sint2(n,k);
    for(int i=0;i<n;i++)
    {
        int1(a[i]);
    }
    for(int i=1;i<n;i++)
    {
        sint2(x,y);
        v[x].pb(y);
        v[y].pb(x);
    }
    int ans=inf;
    for(int i=0;i<n;i++)
    {
        queue<int> q;
        q.push(i);
        memset(chk,0,sizeof(chk));
        lv[i]=1;
        chk[i]=1;
        bt[i]=a[i];
        while(!q.empty())
        {
            bool ok=false;
            int u=q.front();
            q.pop();
            for(int j=0;j<v[u].size();j++)
            {
                int y=v[u][j];
                if(chk[y])continue;
                chk[y]=1;
                bt[y]=a[y]+bt[u];
                lv[y]=lv[u]+1;
                if(bt[y]>=k)
                {
                    ans=min(ans,lv[u]);
                    ok=true;
                    break;
                }
                q.push(y);
            }
            if(ok)break;
        }
    }
    if(ans==0)
    {
        printf("1\n");
        return 0;
    }
    printf("%d\n",ans==inf? -1:ans);
}
/*

*/
