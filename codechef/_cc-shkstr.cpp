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
vector<string> v;
vector<pair<int,pair<string,int> > > ans;
struct Node
{
	Node *child[30];
	char c;
	bool en;
	Node(char c):c(c){
		for(int i=0;i<=26;i++)child[i]=0;
		en=0;
	}
};

void insert(Node *now,string s)
{
	Node *tmp=now;
	for(int i=0;i<s.size();i++)
	{
		int idx=s[i]-'a'+1;
		// debug(idx);
		if(!tmp->child[idx])
			tmp->child[idx]=new Node(s[i]);
		tmp = tmp->child[idx];
	}
	tmp->en=1;
}
bool found(Node *root,string s)
{
	Node *now=root;
	for(int i=0;i<s.size();i++)
	{
		int idx=s[i]-'a'+1;
		if(now->child[idx])
			now=now->child[idx];
		else return 0;
	}
	return (now->en)? 1:0;
}
string st;
void search(Node *root,string s)
{
	Node *now=root;
	for(int i=0;i<s.size();i++)
	{
		int idx=s[i]-'a'+1;
		if(now->child[idx])
		{
			now=now->child[idx];
			// printf("%c",'a'+idx-1);
			char f='a'+idx-1;
			st=st+f;
		}
		else
		{
			while(!now->en)
			{
				for(int j=1;j<=26;j++)
					if(now->child[j])
					{
						now=now->child[j];
						// printf("%c",'a'+j-1);
						char f='a'+j-1;
						st=st+f;
						break;
					}
			}
			return;
		}
	}
	// debug(1);
	while(!now->en)
	{
		// debug(now->en);
		for(int j=1;j<=26;j++)
			if(now->child[j])
			{
				now=now->child[j];
				// printf("%c",'a'+j-1);
				char f='a'+j-1;
				st=st+f;
				break;
			}
	}
	return;
}
int main()
{
	sint(n);
	Node *root=new Node(96);
	for(int i=0;i<n;i++)
	{
		sstring(tmp);
		v.pb(tmp);
		// insert(root,tmp);
	}
	/*
	while(1)
	{
		sstring(tmp);
		printf("%s = %s\n",tmp.c_str(),found(root,tmp)? "Found":"Not Found");
		search(root,tmp);
		endl;
	}
	// */
	// /*
	sint(q);
	for(int i=1;i<=q;i++)
	{
		sint(r);
		sstring(tmp);
		ans.pb(mkp(r,mkp(tmp,i)));
	}
	sort(all(ans));
	int cnt=0;
	vector<pair<int,string> > P;
	for(int i=1;i<=n;i++)
	{
		insert(root,v[i-1]);
		// debug(v[i-1]);
		while(ans[cnt].F==i)
		{
			// debug(ans[cnt].S);
			st="";
			search(root,ans[cnt].S.F);
			P.pb(mkp(ans[cnt].S.S,st));
			// endl;
			cnt++;
		}
	}
	sort(all(P));
	for(int i=0;i<q;i++)
	{
		printf("%s\n",P[i].S.c_str());
	}
//	*/
}
