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
#define sss(a,b,c) stringstream a; a<<b; a>>c
#define rev(s) reverse(all(s));
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
vi v[300005],v2[300005];
int chk[300005];
set<int> s;
set<int>::iterator it;
vi e;
vi use;
vi a;
int rt;
void dfs2(int u)
{
 //   printf(">%d\n",u);
    chk[u]=1;
    a.pb(u);
    for(int i=0;i<v2[u].size();i++)
    {
        int y=v2[u][i];
        if(chk[y]==0)
            dfs2(y);
    }
 //   if(rt==u)return;

}
void dfs(int u)
{
    chk[u]=1;
    vi tmp;
    tmp=v[u];
    e.pb(u);
 //   printf("%d ",u);
    for(int i=0;i<tmp.size();i++)
    {
        int y=tmp[i];
        if(chk[y]==0)
            dfs(y);
    }

}

int main()
{
    sint(n);
    for(int i=0;i<n;i++)
    {
        sint2(x,y);
        v[y].pb(x);
    //    printf(">%d %d\n",y,x);
        v2[x].pb(y);
     //   printf(">%d %d\n",x,y);
        s.insert(x);
        s.insert(y);
    }
    for(int i=0;i<300005;i++)
        chk[i]=0;
    it=s.begin();
    while(it!=s.end())
    {
        int u=(*it);
        if(chk[u]==0)
        {
            dfs(u);
  //          endl;
        }
        it++;
    }
    for(int i=0;i<300005;i++)
        chk[i]=0;
 //       printf("B\n");
    for(int i=0;i<e.size();i++)
    {
 //       printf("%d\n",e[i]);
        if(chk[e[i]]==0)
        {
            rt=e[i];
            dfs2(rt);
 //           endl;
            if(a.size()!=1)
            {
                for(int j=0;j<a.size();j++)
                {
                    use.pb(a[j]);
                }
            }
            a.clear();
        }
    }
   // printf("A\n");
    for(int i=0;i<300005;i++)
        chk[i]=0;
    for(int i=0;i<use.size();i++)
    {
  //      printf("%d\n",use[i]);
        chk[use[i]]=1;
    }
 //   sort(all(use));
    for(int i=0;i<use.size();i++)
    {
        int u=use[i];
        queue<int> q;
        q.push(u);
        int cnt=-1;
        while(!q.empty())
        {
            int uu=q.front();
            q.pop();
            cnt++;
      //      printf(">%d\n",uu);
            for(int j=0;j<v[uu].size();j++)
            {
                int y=v[uu][j];
                if(chk[y]==0)
                {
                    chk[y]=1;
                    q.push(y);
                }
            }
        }
        printf("%d %d\n",u,cnt);
    }
 //   printf("%d\n",cnt);
}
