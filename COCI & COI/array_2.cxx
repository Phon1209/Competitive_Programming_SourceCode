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
    printf("%s",x.c_str());
}
void w(ll x)
{
    printf("%lld ",x);
}
void space(int x)
{
    for(int i=0;i<x;i++)w(" ");
}
int indent=0;
void arr(string s)
{
    int w;
    w(w);
    stack<char> brack;
    string t="";
    string word="";
    int cnt=0;
    // debug(s);
    // debug(1);
    for(int i=1;i<s.size()-1;i++)
    {
        if(s[i]=='{')
        {
            brack.push('{');
        }
        else if(s[i]==',')
        {
            if(brack.empty())cnt++;
        }
        else if(s[i]=='}')
        {
            brack.pop();
        }
    }
    cnt++;
    bool sub=0;
    bool last=0;
    // debug(s);
    // debug(cnt);
    space(indent);
    w("{");
    endl;
    indent+=2;
    for(int i=1;i<s.size()-1;i++)
    {
        // debug(i);
        // debug(s[i]);
        if(sub)
        {
            t+=s[i];
            if(s[i]=='{')
            {
                brack.push('{');
            }
            else if(s[i]=='}')
            {
                brack.pop();
                if(brack.empty())
                {
                    sub=0;
                    arr(t);
                    last=1;
                    t="";
                }
            }
            continue;
        }
        if(s[i]=='{')
        {
            brack.push('{');
            t+=s[i];
            sub=1;
        }
        else if(s[i]==',')
        {
            if(last)
            {
                if(--cnt)w(",");
                endl;
                continue;
            }
            space(indent);
            w(word);
            word="";
            if(--cnt)w(",");
            endl;
        }
        else
        {
            last=0;
            word+=s[i];
        }
    }
    if(word.size() || last)
    {
        space(indent);
        w(word);
        word="";
        endl;
    }
    indent-=2;
    space(indent);
    w("}");
    // printf("end of the line %s \n",s.c_str());
}
int main()
{
    sstring(s);
    arr(s);
}
/*
{
    54,75,436}
// */
