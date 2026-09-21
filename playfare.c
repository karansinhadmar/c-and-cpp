#include<stdio.h>
#include<string.h>
#include<ctype.h>
int m[5][5];
char t[100];
char c[100];
char p[100];
char d[100];
char key[100];
int alph[26];
int lm,lk;
int rx,ry,cx,cy;
int mo(int n)
{
	int num=(n-1)%5;
	if(num>=0)
	{
		return num;
	}
	else
	{
		return num+5;	
	}
}
int is(char x)
{
	x-=65;
	if(alph[x]==0)
	{
		alph[x]=1;
		return 1;
	}
	else
	{
		return 0;
	}
}
void rc(char x,char y)
{
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(m[i][j]==x)
			{
				rx=i;
				cx=j;
			}
			if(m[i][j]==y)
			{
				ry=i;
				cy=j;
			}
		}
	}
}
void encryption()
{
	int ce=0,i;
	for(i=0;i<lm;i+=2)
	{
		rc(t[i],t[i+1]);
		if(rx==ry)
		{
			c[ce]=m[rx][(cx+1)%5];
			c[ce+1]=m[rx][(cy+1)%5];
		}
		else if(cx==cy)
		{
			c[ce]=m[(rx+1)%5][cx];
			c[ce+1]=m[(ry+1)%5][cx];
		}
		else
		{
			c[ce]=m[rx][cy];
			c[ce+1]=m[ry][cx];
		}
		ce+=2;
	}
	printf("Encrypted text:");
	puts(c);
}
void decryption()
{
	int	ce=0,i;
	for(i=0;i<lm;i+=2)
	{
		rc(c[i],c[i+1]);
		if(rx==ry)
		{
			d[ce]=m[rx][mo(cx)];
			d[ce+1]=m[rx][mo(cy)];
		}
		else if(cx==cy)
		{
			d[ce]=m[mo(rx)][cx];
			d[ce+1]=m[mo(ry)][cx];
		}
		else
		{
			d[ce]=m[rx][cy];
			d[ce+1]=m[ry][cx];
		}
		ce+=2;
	}
	printf("decrypted text:");
	puts(d);
}
void makem()
{
	lk=strlen(key);
	int ce=0,i,j,te=65;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			if(ce<lk)
			{
				while(!is(key[ce]))
				{
					ce++;
				}
				m[i][j]=key[ce++];
			}
			else
			{
				while(!is(te) || te=='J')
				{
					te++;
				}
				m[i][j]=te;
				te++;
			}
			
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ",m[i][j]);
		}
		printf("\n");
	}
}
void main()
{
	int i,j,lk,ce=0;
	printf("Enter the plain text:");
	gets(p);
	printf("Enter the key:");
	gets(key);
	for(i=0;i<26;i++)
	{
		alph[i]=0;
	}
	lm=strlen(p);
	for(i=0;i<lm;i++)
	{
		p[i]=toupper(p[i]);
	}
	for(i=0;i<lm;i+=2)
	{
		if(p[i]==p[i+1])
		{
			t[ce]=p[i];
			t[ce+1]='X';
			t[ce+2]=p[i+1];
			ce+=3;
		}
		else if(p[i]==32 && p[i+1]!=32)
		{
			t[ce++]=p[i+1];
		}
		else if(p[i+1]==32 && p[i]!=32)
		{
			t[ce++]=p[i];
			continue;
		}
		else
		{
			t[ce]=p[i];
			t[ce+1]=p[i+1];
			ce+=2;
		}
	}
	lm=strlen(t);
	if(lm%2!=0)
	{
		strcat(t,"X");
	}
	puts(t);
	makem();
	encryption();
	decryption();
}
