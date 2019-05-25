#include<bits/stdc++.h>
char c[105],s[105];
int main()
{
	scanf("%s",c);
	scanf("%s",s);
	int cnt=0,chk=0;
	for(int i=0;c[i]!='\0';i++)
	{
		for(int j=0;s[j]!='\0';j++)
		{
			if(c[i]==s[j])
			{
				chk=0;
				for(int k=0;c[i+k]!='\0' && s[j+k]!='\0';k++)
				{
					if(c[i+k]==s[j+k])
					{
//						printf("%c",c[i+k]);
						chk++;
					}
					else
					{
						break;
					}
				}
//				printf("\n");
				if(chk>cnt)
					cnt=chk;
			}
		}
	}
	printf("%d\n",cnt);
}
