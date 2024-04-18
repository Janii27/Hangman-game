#include<stdio.h>
int length(char ch[])
{
	int i;
	for(i=0;ch[i]!='\0';i++);
	return i;
}

void str_copy(char ch[],char str[])
{
	int i;
	for(i=0;str[i]!='\0';i++)
	ch[i]=str[i];
	ch[i]='\0';
}

void str_rev(char ch[])
{
	int i;
	char str[50];
	for(i=0;ch[i]!='\0';i++)
	{
		str[length(ch)-1-i]=ch[i];
	}
	str[i]='\0';
	str_copy(ch,str);
}
void str_rev2(char ch[])
{
	int i;
	char temp;
	for(i=0;i<(length(ch)-1)/2;i++)
	{
		temp=ch[i];
		ch[i]=ch[length(ch)-1-i];
		ch[length(ch)-1-i]=temp;
	}
}


int str_cmp(char ch[],char str[])
{
	int i,l,n;
	l=length(ch);
	n=length(str);
	/*
	ch= rizwan
	str= rizwana
	*/
	for(i=0;i<l;i++)
	{
		if(str[i]=='\0')
			return 1;
		if(ch[i]>str[i])
			return 1;
		if(ch[i]<str[i])
			return -1;
	}
	if(n==l)
	return 0;

	return -1;
}


void str_cat(char ch[],char str[])
{
	int i,j=0;
	char temp;
	/*
	ch= rizwan
	str= rizwana
	*/
	for(i=length(ch);j<length(str);i++,j++)
	{
		ch[i]=str[j];
	}
	ch[i]='\0';
}

int search_char(char ch[],char c)
{
	int i;
	for(i=0;i<length(ch);i++)
	{
		if(ch[i]==c)
		return i;
	}
	return -1;
}



int search_word(char ch[],char str[],int i)
{
	int j=0,s=0;
	char temp[20];
	/* 	ch= Hello My World
		str= World
		temp=World\0
	*/
	for(;i<=length(ch);i++,s++)
	{
		if(ch[i]==' '||ch[i]=='\0')
		{
			temp[s]='\0';
			if(str_cmp(temp,str)==0)
			return j;
			s=(-1);
			j=i+1;
		}
		else
		{
			temp[s]=ch[i];
		}
	}
	return -1;
}


void shift_left(char ch[],int n,int i)
{
	int j=0;
	j=i-n;
	if(j<0)
	{
		j=0;
		i=i+n;
	}
	for(;j<length(ch)-n;j++,i++)
	{
		ch[j]=ch[i];
	}
	ch[j]='\0';
}

void shift_right(char ch[],int n,int i)
{
	int j=length(ch)-1,k,l;
	ch[j+1+n]='\0';
	for(;j>=i;j--)
	{
		ch[j+n]=ch[j];
	}
}

void deletew(char ch[],char str[])
{
	int i;
	for(i=0;i<length(ch);)
	{
		i=search_word(ch,str,0);
		if(i==-1)
		{
			break;
		}
		else
		{
			shift_left(ch,length(str)+1,i+length(str)+1);
		}
	}
}
void deletew2(char ch[],char str[])
{
	int i;
	for(i=0;i<length(ch);)
	{
		i=search_word(ch,str,0);
		if(i==-1)
		{
			break;
		}
		else
		{
			shift_left(ch,length(str)+1,i+length(str)+1);
			break;
		}
	}
}

void insertw(char ch[],char str[],int i)
{
	int j;
	shift_right(ch,length(str),i);
	for(j=0;j<length(str);j++,i++)
	ch[i]=str[j];
}

void find_replace(char ch[],char str[],char str2[])
{
	int j;
	for(j=0;j<length(ch);)
	{
		j=search_word(ch,str,j);
		if(j==-1)
		break;
		deletew2(ch,str);
		str_cat(str2," ");
		insertw(ch,str2,j);
		j+=length(str2);
	}
}
int length_int(int n)
{
	int i=0;
	while(n>0)
	{
		i++;
		n=n/10; //n/=10;
	}
	return i;
}

void inttoa(char ch[],int n)
{
	int i=length_int(n);
	ch[i]='\0';
	for(i=i-1;i>=0;i--)
	{
		ch[i]=(char)(n%10)+(char)48;
		n/=10;
	}
}

int frequency(char ch[],char c)
{
	int f=0,i;
	for(i=0;i<length(ch);i++)
	{
		if(ch[i]==c)
		f++;
	}
	return f;
}
