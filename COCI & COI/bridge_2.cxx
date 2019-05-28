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
void wl(int x)
{
    printf("%d\n",x);
}
void wl(double x)
{
    printf("%lf\n",x);
}
void wl(string x)
{
    printf("%s\n",x.c_str());
}
void wl(ll x)
{
    printf("%lld\n",x);
}
void w(int x)
{
    printf("%d ",x);
}
void w(double x)
{
    printf("%lf ",x);
}
void w(string x)
{
    printf("%s ",x.c_str());
}
void w(ll x)
{
    printf("%lld ",x);
}
int n,m;
void renode(int *x)
{
    if(*x>n)*x=(3*n)-*x+1;
}
set<int> bridge[2],cut;
unordered_map<int,int> other;
int main()
{
    // OPEN;
    // SEND;
    int2(n,m);
    int x,y;
    char cmd[5];
    while(m--)
    {
        scanf("%s %d %d",cmd,&x,&y);
        renode(&x);
        renode(&y);
        if(cmd[0]=='A') //construct
        {
            bridge[x>n].insert(x);
            bridge[y>n].insert(y);
            other[x]=y;
            other[y]=x;
        }
        if(cmd[0]=='B') // destroy
        {
            if(x>y)swap(x,y);
            cut.insert(x);
        }
        if(cmd[0]=='Q') // query
        {
            if((x>n) ^ (y>n)) // on other side
            {
                bool ok=false;
                if(bridge[x>n].lower_bound(x)!=bridge[x>n].end()) //check bridge x
                {
                    int bx=*bridge[x>n].lower_bound(x);
                    if(cut.lower_bound(bx)==cut.lower_bound(x))
                    {
                        bx=other[bx];
                        if(cut.lower_bound(bx)==cut.lower_bound(y) && y>=bx)
                        {
                            ok=true;
                        }
                    }
                }
                if(bridge[y>n].upper_bound(y)!=bridge[y>n].begin())// check bridge y
                {
                    int by=*(--bridge[y>n].upper_bound(y));
                    if(cut.lower_bound(by)==cut.lower_bound(y))
                    {
                        by=other[by];
                        if(cut.lower_bound(by)==cut.lower_bound(x) && by>=x)
                        {
                            ok=true;
                        }
                    }
                }
                printf("%s\n",(ok)? "DA":"NE");
            }
            else //on same side // bug
            {
                if(y>=x)
                {
                    if((*cut.lower_bound(y))==(*cut.lower_bound(x)))printf("DA\n");
                    else printf("NE\n");
                }
                else
                {
                    if(bridge[x>n].lower_bound(x)!=bridge[x>n].end())
                    {
                        int nx=*(bridge[x>n].lower_bound(x));
                        if(cut.lower_bound(nx)!=cut.lower_bound(x))
                        {
                            printf("NE\n");
                            continue;
                        }
                        x=other[nx];
                        bool ok=false;
                        if(bridge[x>n].lower_bound(x)!=bridge[x>n].end()) //check bridge x
                        {
                            int bx=*bridge[x>n].lower_bound(x);
                            if(cut.lower_bound(bx)==cut.lower_bound(x))
                            {
                                bx=other[bx];
                                if(cut.lower_bound(bx)==cut.lower_bound(y) && y>=bx)ok=true;
                            }
                        }
                        if(bridge[y>n].upper_bound(y)!=bridge[y>n].begin())// check bridge y
                        {
                            int by=*(--bridge[y>n].upper_bound(y));
                            if(cut.lower_bound(by)==cut.lower_bound(y))
                            {
                                by=other[by];
                                if(cut.lower_bound(by)==cut.lower_bound(x) && by>=x)ok=true;
                            }
                        }
                        printf("%s\n",(ok)? "DA":"NE");
                    }
                    else printf("NE\n");
                }
            }
        }
    }
}
/*

*/
