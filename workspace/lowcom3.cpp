#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define int1(a) scanf("%d",&a)
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
vector<string> v;
bool lowcom(int n,int k)
{
    v.pb("ONE X");
    int cnt=0;
    stack<int> st;
    while(n!=0)
        {
            int tmp=n%k;
            while(tmp--)
            {
                v.pb("PUH X");
                cnt++;
                n--;
                st.push(1);
            }
            if(n==0)break;
            for(int i=0;i<k;i++)
                v.pb("PUH X");
            cnt+=k;
            for(int i=1;i<k;i++)
                v.pb("ADD");
            cnt+=k-1;
            st.push(1);
            n/=k;
            if(n==0 || n==1)break;
            v.pb("POP X");
            cnt++;
            st.pop();
        }
        st.pop();
        while(!st.empty())
        {
            st.pop();
            cnt++;
            v.pb("ADD");
        }
        v.pb("POP X");
        v.pb("PRN X");
        cnt+=2;
        if(cnt<=40)
        {
            return false;
        }
        else return true;
}
int main()
{
    int n;
 //   freopen("test.txt","w",stdout);
//    freopen("IN.txt","r",stdin);
    while(int1(n)!=EOF)
    {
        if(n==0)
        {
            printf("ZER X\n");
            printf("PRN X\n");
            continue;
        }
        if(n==1)
        {
            printf("ONE X\n");
            printf("PRN X\n");
            continue;
        }
        for(int i=2;i<=30;i++)
        {
            v.clear();
            if(lowcom(n,i))break;
        }
        for(int i=0;i<v.size();i++)
        {
            printf("%s\n",v[i].c_str());
        }
    }
}
