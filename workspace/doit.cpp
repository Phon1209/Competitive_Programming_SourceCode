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
char a[150];
queue<char> q;
stack<char> st;
stack<int> ans;
string post="";
int prior(char c)
{
    if(c=='+')return 1;
    if(c=='-')return 1;
    if(c=='*')return 2;
    if(c=='/')return 2;
    return 0;
}
void inpost()
{
    post="";
    for(int i=0;a[i];i++)
    {
        if(a[i]<='9' && a[i]>='0')
        {
            q.push(a[i]);
            post+=a[i];
        }
        if(a[i]=='(')
        {
            st.push(a[i]);
        }
        if(a[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                q.push(st.top());
                post+=st.top();
                st.pop();
            }
            st.pop();
        }
        if(prior(a[i]))
        {
            while(!st.empty() && prior(st.top())>=prior(a[i]) && st.top()!='(')
            {
                q.push(st.top());
                post+=st.top();
                st.pop();
            }
            st.push(a[i]);
        }
    }
    while(!st.empty())
    {
        post+=st.top();
        q.push(st.top());
        st.pop();
    }
}
void toans()
{
    while(!q.empty())
    {
        if(q.front()<='9' && q.front()>='0')
        {
            ans.push(q.front()-'0');
        }
        if(prior(q.front()))
        {
            int x,y;
            x=ans.top();
            ans.pop();
            y=ans.top();
            ans.pop();
            if(q.front()=='+')y+=x;
            if(q.front()=='-')y-=x;
            if(q.front()=='*')y*=x;
            if(q.front()=='/')y/=x;
            ans.push(y);
        }
        q.pop();
    }
    if(ans.size()==1)
    {
        printf("%d\n",ans.top());
    }
}
int main()
{
    scanf("%s",a);
    inpost();
    printf("%s\n",post.c_str());
    toans();
}
