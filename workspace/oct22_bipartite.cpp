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
enum color
{
    unvisit,blue,red
};
color gp[100005];
vi v[100005];
int main()
{
    sint(k);
    while (k--)
    {
        sint2(n,m);
        for(int i=0;i<n;i++)
        {
            v[i].clear();
        }
        while(m--)
        {
            sint2(x,y);
            v[x].pb(y);
            v[y].pb(x);
        }
        for(int i=0;i<n;i++)
        {
            gp[i]=unvisit;
        }
        bool ok=true;
        for(int i=0;i<n;i++)
        {
            if(gp[i]==unvisit)
            {
                try
                {
                    gp[i]=blue;
                    queue<int> q;
                    q.push(i);
                    while(!q.empty())
                    {
                        int u=q.front();
                        q.pop();
                        for(int j=0;j<v[u].size();j++)
                        {
                            int y=v[u][j];
                            if(gp[y]==unvisit)
                            {
                                if(gp[u]==blue)gp[y]=red;
                                else gp[y]=blue;
                                q.push(y);
                            }
                            else if(gp[u]==gp[y])
                            {
                                throw 0;
                            }
                        }
                    }
                }
                catch(...)
                {
                    ok=false;
                }
            }
        }
        printf("%s\n",ok? "yes":"no");
    }
}
/*

*/
