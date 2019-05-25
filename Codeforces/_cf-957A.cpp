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
char s[105];
char r[105];
int n;
int chk=0;
char g(int i)
{
    if(i==0)return 'C';
    if(i==1)return 'Y';
    if(i==2)return 'M';
}
void f(int idx)
{
    if(idx==n)
    {
        chk++;
        if(chk==2)
        {
            printf("Yes\n");
            exit(0);
        }
    }
    r[idx]=s[idx];
    if(idx!=0)
    {
        if(r[idx]=='?')
        {
            for(int i=0;i<3;i++)
            {
                r[idx]=g(i);
                if(r[idx]==r[idx-1])continue;
                f(idx+1);
            }
        }
        else
        {
            if(r[idx]==r[idx-1])return;
            f(idx+1);
        }
    }
    else
    {
        if(r[idx]=='?')
        {
            for(int i=0;i<3;i++)
            {
                r[idx]=g(i);
                f(idx+1);
            }
        }
        else
        {
            f(idx+1);
        }
    }
}
int main()
{
    int1(n);
    scanf("%s",s);
    f(0);
    printf("No\n");
}
/*

*/
