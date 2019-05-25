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

int mem[105][105];
void _main()
{
    memset(mem,0,sizeof(mem));
    vector<string> v;
    sint(n);
    string ok="";
    for(int i=0;i<n;i++)
    {
        sstring(tmp);
        v.pb(tmp);
    }
    char last='A';
    for(int i=0;i<v[0].size();i++)
    {
        if(v[0][i]!=last)
        {
            last=v[0][i];
            ok+=v[0][i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(ok[0]!=v[i][0])
        {
            printf("NO\n");
            return;
        }
        else mem[i][0]++;
        int cnt=0;
        for(int j=1;j<v[i].size();j++)
        {
            if(v[i][j]==ok[cnt])
            {
                mem[i][cnt]++;
            }
            else
            {
                if(ok[cnt+1]==v[i][j])
                {
                    cnt++;
                    mem[i][cnt]++;
                }
                else
                {
                    printf("NO\n");
                    return;
                }
            }
        }
    }
    // debug(ok);
    int ans=0;
    // /*
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<ok.size();j++)
        {
            printf("%d ",mem[i][j]);
        }
        endl;
    }
    // */
    // /*
    // int ans=0;
    for(int i=0;i<ok.size();i++)
    {
        int mn=INT_MAX;
        for(int k=1;k<=100;k++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                sum+=abs(k-mem[j][i]);
            }
            mn=min(mn,sum);
        }
        debug(mn);
        ans+=mn;
    }
    // */
    printf("%d\n",ans);
    return ;
}
int main()
{
    sint(t);
    while(t--)_main();
}
/*
5
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb
2
abc
abc
3
aabc
abbc
abcc
*/
