#include<bits/stdc++.h>
using namespace std;
#define sint(a) int a; scanf("%d",&a);
#define sint2(a,b) int a,b; scanf("%d %d",&a,&b);
#define sint3(a,b,c) int a,b,c; scanf("%d %d %d",&a,&b,&c);
#define mkp make_pair
#define pb push_back
#define inf 1e9
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
#define sdouble(a) double a; scanf("%lf",&a);
#define slong(a) long long a; scanf("%lld",&a);
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
char a[400],b[400];
int main()
{
	string s1,s2;
	scanf("%s %s",a,b);
	int cnt=0;
	int a1=strlen(a),b1=strlen(b);
	while(cnt+a1<400)
	{
		s1+='0';
		cnt++;
	}
	s1+=a;
	cnt=0;
	while(cnt+b1<400)
	{
		s2+='0';
		cnt++;
	}
	s2+=b;
	int mk=0;
	for(int i=s1.size()-1;i>=0;i--)
	{
		char tmp=s1[i]-'0'+s2[i]+mk;
		mk=0;
		if(tmp>'9')
		{
			tmp-=10;
			mk++;
		}
		s1[i]=tmp;
	}
	bool chk=false;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]!='0' || chk)
		{
			chk=true;
			printf("%c",s1[i]);
		}
	}
}

