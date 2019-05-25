#include<stdio.h>

char a[10005];
int main()
{
    int n;
    char s[15];
    scanf("%s\n",s);
    scanf("%d\n",&n);
    gets(a);
    /*
    for(int i=0;a[i]!='\0';i++)
	{
		printf("%c %d\n",a[i],a[i]);
	}
	*/
    for(int i=0;a[i]!='\0';i++)
    {
        if((a[i]>='A' && a[i]<='Z'))
        {
            if(s[0]=='s')
            {
                a[i]+=n;
                if(a[i]>'Z')
                {
                    a[i]-=26;
                }
            }
            else if(s[0]=='o')
            {
                a[i]-=n;
                if(a[i]<'A')
                {
                    a[i]+=26;
                }
            }
        }
        else if((a[i]>='a' && a[i]<='z'))
        {
            if(s[0]=='s')
            {
                a[i]-=(26-n);
                if(a[i]<'a')
                {
//                	printf("A\n");
                    a[i]+=26;
                }
            }
            else if(s[0]=='o')
            {
                a[i]-=n;
                if(a[i]<'a')
                {
                    a[i]+=26;
                }
            }
        }
    }
    printf("%s\n",a);
    /*
	for(int i=0;a[i]!='\0';i++)
	{
		printf("%c %d\n",a[i],a[i]);
	}*/
}
