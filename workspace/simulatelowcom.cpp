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
stack<int> st;
void p(char a)
{
    printf("%c\n",a);
}
int main()
{
 //   freopen("OUT.txt","w",stdout);
 //   freopen("test.txt","r",stdin);
    int cnt=0;
    while(1)
    {
        int x;
        cnt++;
        printf("%d\n",cnt);
        if(cnt==41)
        {
            printf("OVERFLOW!!!\n");
        }
        string cmd;
        cin>>cmd;
        if(cmd=="PUH")
        {
  //          p('a');
            sstring(c,5);
            st.push(x);
        }
        if(cmd=="POP")
        {
 //           p('b');
            sstring(c,5);
            x=st.top();
            st.pop();
        }
        if(cmd=="ADD")
        {
 //           p('c');
            int t,t2;
            t=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            st.push(t+t2);
        }
        if(cmd=="ZER")
        {
 //           p('d');
            sstring(c,5);
            x=0;
        }
        if(cmd=="ONE")
        {
  //          p('e');
            sstring(c,5);
            x=1;
        }
        if(cmd=="PRN")
        {
 //           p('f');
            printf("%d\n",x);
            while(!st.empty())st.pop();
            x=0;
            cnt=0;
//            pause;
//            break;
        }
    }
}
