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
#define fastio ios::sync_with_stdio(false);cin.tie(NULL);
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define ROF(a,b,c) for(int a=b;a>c;a--)
#define pause system("pause")
#define endl printf("\n")
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
enum color {
wht,blk
 };
struct cell
{
    int a;
    color use;
    string eq;
}*sheet;
int convertidx(int x,int y)
{
    return (x*20000)+y;
}
ii convert(string s)
{
    int ret=0;
    int ret2=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A' && s[i]<='Z')
        {
            ret*=26;
            ret+=(s[i]-'A'+1);
        }
        else if(s[i]>='0' && s[i]<='9')
        {
            ret2*=10;
            ret2+=(s[i]-'0');
        }
    }
    return mkp(ret,ret2);
}
int dfs(int x,int y)
{
    if(sheet[convertidx(x,y)].use==blk)return sheet[convertidx(x,y)].a;
    int ret=0;
    string tmp="";
    for(int i=0;i<sheet[convertidx(x,y)].eq.size();i++)
    {
        if(sheet[convertidx(x,y)].eq[i]=='=')continue;
        if(sheet[convertidx(x,y)].eq[i]=='+' || i==sheet[convertidx(x,y)].eq.size()-1)
        {
            ii u;
            if(i==sheet[convertidx(x,y)].eq.size()-1) tmp+=sheet[convertidx(x,y)].eq[i];
            u=convert(tmp);
        //    printf("%s %d %d\n",tmp.c_str(),u.S,u.F);
            int pos=dfs(u.S,u.F);
        //    printf("%d\n",pos);
            ret+=pos;
            tmp="";
            continue;
        }
        tmp+=sheet[convertidx(x,y)].eq[i];
    }
    sheet[convertidx(x,y)].a=ret;
    sheet[convertidx(x,y)].use=blk;
    return ret;
}
void _main()
{
    int n,m;
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            sheet[convertidx(i,j)].use=wht;
            string s;
            cin>>s;
            if(s[0]=='=')
            {
                sheet[convertidx(i,j)].eq=s;
            }
            else
            {
                int tmp=0;
                stringstream ss;
                ss<<s;
                ss>>tmp;
                sheet[convertidx(i,j)].a=tmp;
//                printf("%d %d %d\n",i,j,a[i][j]);
                sheet[convertidx(i,j)].use=blk;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j!=1)printf(" ");
            if(sheet[convertidx(i,j)].use==blk)
            {
                printf("%d",sheet[convertidx(i,j)].a);
            }
            else
            {
                dfs(i,j);
                printf("%d",sheet[convertidx(i,j)].a);
            }
        }
            endl;
    }
}
int main()
{
//    freopen("input.in.txt","r",stdin);
//     freopen("test.txt","w",stdout);
    fastio;
    int t;
    cin>>t;
    sheet = new cell[1005*20000];
    while(t--)_main();
}
