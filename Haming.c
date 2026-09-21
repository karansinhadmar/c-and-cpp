#include<stdio.h>
#include<string.h>
#include<math.h>
char m[100];
char ans[100];
char ham[100];
char ans1[100];
int hm,lm,n;
int ind[100];
void findhm()
{
	int i=1;
	while(1)
	{
		if(pow(2,i)>=lm+i+1)
		{
			hm=i;
			break;
		}
		i++;
	}
}
void setH()
{
	int i;
	int in[hm];
	for(i=0;i<hm;i++)
	{
		in[i]=pow(2,i);
	}
	int z=lm-1;
	int j=0;
	for(i=0;i<lm+hm;i++)
	{
		if(i+1==in[j])
		{
			j++;
			ans[i]='H';
		}
		else
		{
			ans[i]=m[z--];
		}
	}
}
void findind()
{
	int i;
	int j=0;
	for(i=0;i<lm+hm;i++)
	{
		if(ans[i]=='1')
		{
			ind[j++]=i+1;
		}
	}
	n=j;
}
void decitobin(int n,int f)
{
	if(f==0)
	{
		int a,i=0;
		while(n!=0)
		{
			a=n%2;
			if(a==1)
			{
				ans1[i++]='1';
			}
			else
			{
				ans1[i++]='0';
			}
			n/=2;
		}
		while(strlen(ans1)<hm)
		{
			ans1[i++]='0';
		}
	}
	else
	{
		int a,i=0;
		while(n!=0)
		{
			a=n%2;
			if(a==1)
			{
				ham[i++]='1';
			}
			else
			{
				ham[i++]='0';
			}
			n/=2;
		}
		while(strlen(ham)<hm)
		{
			ham[i++]='0';
		}
	}
}
int xoor(char x,char y)
{
	if((x=='1'&&y=='0')||(x=='0'&&y=='1'))
	{
		return 49;
	}
	else
	{
		return 48;
	}
}
void findhem()
{
	decitobin(ind[0],1);
	if(n>1)
	{
		int i,j;
		decitobin(ind[1],0);
		for(j=0;j<hm;j++)
		{
			ham[j]=xoor(ham[j],ans1[j]);
		}
		for(i=2;i<n;i++)
		{
			decitobin(ind[i],0);
			for(j=0;j<hm;j++)
			{
				ham[j]=xoor(ham[j],ans1[j]);
			}
		}
	}
	
}
void setham()
{
	int i,j=0;
	for(i=0;i<lm+hm;i++)
	{
		if(ans[i]=='H')
		{
			ans[i]=ham[j++];
		}
	}
}
void checker()
{
	
}
void main()
{
	int i;
	printf("Enter the meassage:");
	gets(m);
	lm=strlen(m);
	findhm();
	printf("%d",hm);
	setH();
	findind();
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("%d",ind[i]);
	}
	printf("\n");
	for(i=lm+hm-1;i>=0;i--)
	{
		printf("%c",ans[i]);
	}
	findhem();
	//printf("\n");
	/*for(i=hm-1;i>=0;i--)
	{
		printf("%c",ans1[i]);
	}*/
	printf("\nHaming code:");
	for(i=hm-1;i>=0;i--)
	{
		printf("%c",ham[i]);
	}
	setham();
	printf("\nMeassage is:");
	for(i=lm+hm-1;i>=0;i--)
	{
		printf("%c",ans[i]);
	}
	checker();
}
