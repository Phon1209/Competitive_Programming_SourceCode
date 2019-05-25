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
#define inf 1e9
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
#define PER(a) int _a=a; while(_a--)
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
int n,m;
queue<pair<ii,pair<ii,int> > > q;
char a[105][105];
int b[105][105];
void eq(int x,int y,int px,int py,int sp)
{
	if(x>0 && x<=n && y>0 && y<=m)
	{
		q.push(mkp(mkp(x,y),mkp(mkp(px,py),sp+1)));
	}
}
int main()
{
	int2(n,m);
	char s[5];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%s",s);
			a[i][j]=s[0];
		}
	}
	q.push(mkp(mkp(1,1),mkp(mkp(0,0),1)));
	while(!q.empty())
	{
		int x,y;
		x=q.front().F.F;
		y=q.front().F.S;
		int px,py,sp;
		px=q.front().S.F.F;
		py=q.front().S.F.S;
		sp=q.front().S.S;
		q.pop();
//		printf("%d %d %d %d\n",px,py,x,y);
		if(b[x][y]==sp)
		{
			printf("%d\n%d %d\n",sp,x,y);
			break;
		}
		b[x][y]=sp;
		if(a[x][y]=='B')
		{
			if(x+1!=px || y!=py)
				eq(x+1,y,x,y,sp);
			if(x!=px || y+1!=py)
				eq(x,y+1,x,y,sp);
		}
		else if(a[x][y]=='D')
		{
			if(x+1!=px || y!=py)
				eq(x+1,y,x,y,sp);
		}
		else if(a[x][y]=='R')
		{
			if(x!=px || y+1!=py)
				eq(x,y+1,x,y,sp);
		}
		if((x-1!=px || y!=py) && a[x-1][y]!='R'  && a[x-1][y]!='N')
			eq(x-1,y,x,y,sp);
		if((x!=px || y-1!=py) && a[x][y-1]!='D'  && a[x][y-1]!='N')
			eq(x,y-1,x,y,sp);
//		system("pause");
	}
}


