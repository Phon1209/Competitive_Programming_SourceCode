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
int lps[100];
int main()
{
    //*BUG*//
    cstring(a,100005);
    string b="codecube";
    int c1=1,c2=0;
    lps[0]=0;
    while(c1<b.size())
    {
        if(b[c1]==b[c2])lps[c1++]=++c2;
        else if(c2!=0)c2=lps[c2-1];
        else lps[c1++]=0;
    }
    c1=0;
    ii ans={0,inf};
    int prev=0;
    for(int i=0;a[i];)
    {
        printf(">%d %d\n",i,c1);
        if(c1==0 && b[c1]=='c')prev=i;
        if(a[i]==b[c1])
        {
            c1++;
            if(c1==8)
            {
                if(i-prev<(ans.S-ans.F))
                {
                    ans={prev,i};
                }
            }
            i++;
        }
        else if(a[i]!='\0' && a[i]!=b[c1])
        {
            if(c1!=0)c1=lps[c1];
            else i++;
        }
    }
    printf("%d %d\n",ans.F,ans.S);
}
/*

*/
