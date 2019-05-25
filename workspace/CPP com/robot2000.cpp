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
char a[105];
char dir;
int main()
{
	//N=0 E=1 S=2 W=3
	scanf("%s",a);
	dir='N';
	for(int i=0;a[i]!='\0';i++)
	{
		if(a[i]=='Z')
		{
			dir='N';
			printf("Z");
			continue;
		}
		while(1)
		{
			if(a[i]==dir)
				break;
			switch(dir)
			{
				case 'N':
					dir='E';
					printf("R");
					break;
				case 'E':
					dir='S';
					printf("R");
					break;
				case 'S':
					dir='W';
					printf("R");
					break;
				case 'W':
					dir='N';
					printf("R");
					break;
			}
		}
		printf("F");
//		system("pause");
	}
}

