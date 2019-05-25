#include<bits/stdc++.h>
using namespace std;
stack<int> st;
char a[100005];
int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",a);
		int h;
		for(int i=0;a[i]!='\0';i++)
		{
			if(a[i]=='A')
				h=1;	
			else if(a[i]=='B')
				h=2;
			if(!st.empty())
				if(st.top()==h)
					st.pop();
				else
					st.push(h);
			else
				st.push(h);
		}
		if(!st.empty())
			while(!st.empty())
				st.pop();
		else
			cnt++;
	}
	printf("%d\n",cnt);
}
