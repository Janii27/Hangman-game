#include<iostream>
#include<fstream>
#include<conio.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int fetch_word(char str[20])
{
	int i,n,range=30,choice;
	char ch;
	srand(time(0));
	choice=rand()%range;
	cout<<choice<<endl;
	fstream file;
  	file.open("d:/Hangman_Words.txt",ios::in);
  	if(!file)
  	{
  		cout<<"\nError in opening file:\t"<<"Hangman_Words.txt";
  		getch();
  	}	
  	//1.Get the word from the file according to the random no.(choice)generated
  	i=0;
  	while(1)
  	{               // function get() reads a single character from the associated stream.
  		file.get(ch);         // or  ch=file.get();
  		if(ch=='\n')
  		{	
  		choice--;
  		if(choice==0)
  			break;
  		i=0;
	}
	str[i]=ch;
	i++;
  	}
  	str[i]='\0';
  	file.close();
  	return i+1;//returning length of word
}
void print_used(char str[20],int l)//for printing the alphabets already used
{
	int i=0;
	for(i=0;i<l;i++)
	{
		cout<<str[i]<<" ";
	}cout<<endl;
}
int main()
{
	int i,l,attempt=6,found=0,count=0;
  	char ch,c,str[20],arr[15],str1[20];
	printf("HANGMAN GAME\n");
	printf("	START	\n");
	l=fetch_word(str);
	cout<<str<<endl;;
  	//system("CLS");
//Make an array for showing the player's progress
  	for(i=0;i<l-1;i++)
  	{
  		arr[i]='_';
  		str1[i]=' ';
 	}
  	for(i=0;i<l;i++)
  		cout<<arr[i];
  	cout<<endl;
//The game continues till the player doesn't lose chance
	while(attempt>0)
	{
  		cout<<"Enter your choice: ";
  		cin>>c;
  		str1[attempt]=c;
  		found=0;
  		for(i=0;i<l;i++)
  		{
  			if(str[i]==c)
  			{
				arr[i]=c;//change space in array with the found character
				++found;
				++count;
			}
 	 	}
 	 	if(found==0)//
 	 	{
  			cout<<"\nWrong choice\n";
  			--attempt;
 	 	}
  		for(i=0;i<l;i++)
  			cout<<arr[i];
  		cout<<endl;
  		cout<<"Use characters: ";
  		print_used(str1,l-attempt);
//  		for(i=0;i<l;i++)
//  		{
//  			if(arr[i]==str[i])
//  			{
//  				++count;
//			}	
//  		}
		 if(count==l)
  		 {
  			cout<<"You win!"<<endl;
  			break;
 		 }
	}if(attempt==0)
		cout<<"You are hanged!"<<endl;
 return 0;	
}
