#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
vector<long long>::iterator it;
void gen(string,int);
int t; 
//Time = 6.xx s
int main()
{
	gen("",0);
	scanf("%d",&t);
	for(int l=1;l<=t;l++)
	{
		long long n;
		scanf("%lld",&n);
		it=upper_bound(v.begin(),v.end(),n);
		printf("Case #%d: ",l);
		it--;
		printf("%lld\n",(*it));
	}
}
void gen(string tmp,int lv)
{
	if(lv==18)
	{
		stringstream ss;
		ss<<tmp;
		long long q;
		ss>>q;
		v.push_back(q);
		return;
	}
	int st;
	if(tmp.size()==0)
		st='0';
	else
		st=tmp[tmp.size()-1];
	for(int i=st;i<='9';i++)
	{
		char c=i;
		gen(tmp+c,lv+1);
	}
}
