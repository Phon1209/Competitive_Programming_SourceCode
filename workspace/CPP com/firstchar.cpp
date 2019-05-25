#include<bits/stdc++.h>
using namespace std;
map<char,int> m;
priority_queue<char> pq;
stack<char> st;
char a[32];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",a);
		m[a[0]]++;
	}
	char d='a';
	for(int i=0;i<26;i++)
	{
		if(m[d+i]>=5)
		{
//			printf("%c %d\n",d+i,m[d+i]);
			pq.push(d+i);
		}
	}
	while(!pq.empty())
	{
		d=pq.top();
		st.push(d);
		pq.pop();
	}
	bool chk=true;
	while(!st.empty())
	{
		printf("%c",st.top());
		st.pop();
		chk=false;
	}
	if(chk)
	{
		printf("PREDAJA\n");
	}
}
