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
int a[100005];
int red[100005];
set<int> s[100005];
void _main()
{
    memset(a,0,sizeof(a));
    memset(red,0,sizeof(red));
    for(int i=0;i<=100000;i++)s[i].clear();
    sint(n);
    for(int i=1;i<=n;i++)
    {
        int1(a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        red[i]=a[a[i]];
        s[red[i]].insert(a[i]);
        // debug(i);
        // debug(red[i]);
        // debug(a[i]);
        if(s[red[i]].size()>=2)
        {
            printf("Truly Happy\n");
            return;
        }
    }
    printf("Poor Chef\n");
}
int main()
{
    sint(t);
    while(t--)_main();
}
/*

*/