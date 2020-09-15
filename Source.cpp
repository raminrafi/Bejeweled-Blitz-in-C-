#include<iostream>
#include<conio.h>
#include<time.h>
#include"help.h"
#include<fstream>
#include<windows.h>
using namespace std;
bool verticalpossible(int val[][8])
{
	int flag=0;
for (int i= 0; i < 6 && flag==0; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if (val[i][j] == val[i + 1][j] && val[i][j] == val[i + 2][j] )
			{
				val[i][j]=(rand()%5+1);
				val[i + 1][j]=(rand()%5+1);
				val[i + 2][j]=(rand()%5+1);
					flag=1;
			}
		}
	}
if(flag==1)
	return true;
else
	return false;
}
bool horizontalpossible(int val[][8])
{
	int flag=0;
for (int i= 0; i < 8 && flag==0; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if (val[i][j] == val[i ][j+1] && val[i][j] == val[i][j+ 2] && j<=6)
			{
				
				val[i][j]=(rand()%5+1);
				val[i][j + 1]=(rand()%5+1);
				val[i][j + 2]=(rand()%5+1);		
			    flag=1;
			}
		}
	}
if(flag==1)
	return true;
else
	return false;
}
bool  possible (int arr[][8])
{
	if(horizontalpossible(arr)==true)
	{
		
		return true;
	}
	if(verticalpossible(arr)==true)
	{
		
		return true;
	}
	return false;
}

void printboard(int  val[][8],int r)
{
	myLine(0,0,315,0,255);
	myLine(0,0,0,315,255);
	myLine(315,0,315,315,255);
	myLine(0,315,315,315,255);
	for(int i=0; i<8;i++)
	{
		myLine(0,0+i*40,315,0+i*40,255);
		myLine(0+i*40,0,0+i*40,315,255);	
	}
	for(int i=0;i<r;i++)
	{
		for(int l=0;l<8;l=l+1)
			{
			if(val[i][l]==1)
				myEllipse(5+l*40,10 + i*40,25+l*40,30+ i*40,255,0,0,255,0,0);
			else if(val[i][l]==3)
				myRect(5+l*40,10+i*40,25+l*40,30+i*40,0,255,0,0,255,0);
			else if(val[i][l]==2)
			{
			        myLine(15+l*40,5+i*40,5+l*40,15+i*40,255);
	                myLine(15+l*40,5+i*40,25+l*40,15+i*40,255);
					myLine(5+l*40,15+i*40,15+l*40,25+i*40,255);
					myLine(25+l*40,15+i*40,15+l*40,25+i*40,255);	
	        }
			else if(val[i][l]==4)
			{
				myEllipse(7+l*40,10 + i*40,25+l*40,30+ i*40,255,0,0,255,255,0);
				myRect(4+l*40,20+i*40,30+l*40,30+i*40,0,0,255,0,255,255);
			}
			   
			else 
				mytriangle(5+l*40,10+i*40,25+l*40,30+i*40,0,0,255,0,0,0);
		}
	}
}
void swap(int  row,int  col,int whichKey,int val[][8])
{
	int score=0;
	    Sleep(990);
	  if( isCursorKeyPressed(whichKey)==true)
	  {
	 		if(whichKey==1)
				{
					swap(val[row][col],val[row][col-1]);
					myRect(0,0,315,315,0,0,0,0,0,0);
					 printboard(val,8);
			}
			else if(whichKey==2)
				{
					swap(val[row][col],val[row-1][col]);
					 myRect(0,0,315,315,0,0,0,0,0,0);
					 printboard(val,8);
			}
			else if(whichKey==3)
			{				
				swap(val[row][col],val[row][col+1]);
				myRect(0,0,315,315,0,0,0,0,0,0);
				printboard(val,8);
			}
			else if(whichKey==4)
				{					
					swap(val[row][col],val[row+1][col]);					
					myRect(0,0,315,315,0,0,0,0,0,0);
					printboard(val,8);			
			}
	}
}
void marker(int & x1,int& x2,int& y1,int& y2,int arr[][8])
{
	int row,col;
	int sq=40;
	int whichKey;
	if( isCursorKeyPressed(whichKey)==true)
				{
							myLine(0+x1*sq,33+y1*sq,30+x2*sq,33+y2*sq,0);	   
					if(whichKey==1 && x1>0)
					{
							x1=x1--;
							x2=x2--;
							myLine(0+x1*sq,33+y1*sq,30+x2*sq,33+y2*sq,255);
								
     				}
					else if(whichKey==2 && y1>0)
					{
							y1=y1--;
							y2=y2--;
							myLine(0+x1*sq,33+y1*sq,30+x2*sq,33+y2*sq,255);
									
					}
					else if(whichKey==3 && x1<7)
					{
							x1=x1++;
							x2=x2++;
							myLine(0+x1*sq,33+y1*sq,30+x2*sq,33+y2*sq,255);	
					 }
					 else if(whichKey==4  && y1<7)
						{
							y1=y1++;
							y2=y2++;
							myLine(0+x1*sq,33+y1*sq,30+x2*sq,33+y2*sq,255);							
					 } 
					 else if(whichKey==13)
					 {
                      row=y1;
					  col=x1;
					  swap(row,col,whichKey,arr);
					 }
					 else if(whichKey=='S')
					 {
						 ofstream fout("save.txt");
						 for (int i = 0; i < 3; i++)
								for (int j = 0; j < 3; j++)
									fout<<arr[i][j]<<" ";
					 }
					  else if(whichKey=='L')
					 {
						 ifstream fin("save.txt");
						  for (int i = 0; i < 3; i++)
								for (int j = 0; j < 3; j++)
									fin>>arr[i][j];
					 }
		}			 
}
void timer(int & sec,int arr[][8])
{
	int score=0;
	int x1=0,y1=0,y2=0,x2=0;
	sec=0;int sq=40;
	int min=0;        
	gotoxy(50,0);
	for(;min!=1;)
	{
			int whichKey;          
			sec++; 
			marker(x1,x2,y1,y2,arr);
			if(possible(arr)==true)
			{
				score++;
				gotoxy(65,0);
				cout<<"score:"<<score;
				 myRect(0,0,315,315,0,0,0,0,0,0);
				printboard(arr,8);
			}
			if(sec==61)
			{
			   min++;
			   sec=0;
			}
			gotoxy(50,0);
			cout<<min<<":"<<sec;
			Sleep(550);
		}
	}
int main()
{
	srand(time(0));
	int whichKey;
	int x1=0,y1=0,sq=40;
	int arr[8][8];
	for(int i=0;i<8;i++)
		{
		 for(int l=0;l<8;l=l+1)
			{
				arr[i][l]=(rand()%5+1);
			}
		}
	for (int i= 0; i < 16; i++)
	{
	for (int i= 0; i < 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			if (arr[i][j] == arr[i ][j+1] && arr[i][j] == arr[i][j+ 2] && j<=6)
			{
				
				arr[i][j]=(rand()%5+1);
				arr[i][j + 1]=(rand()%5+1);
				arr[i][j + 2]=(rand()%5+1);	
			}
			if (arr[i][j] == arr[i+1][j] && arr[i][j] == arr[i+ 2][j] && j<=6)
			{
				
				arr[i][j]=(rand()%5+1);
				arr[i + 1 ][j]=(rand()%5+1);
				arr[i + 2][j]=(rand()%5+1);	
			}
		}
	}
	}
	int score=0;
	printboard(arr,8);
	gotoxy(65,0);
	cout<<"score:"<<score;
	int sec=0;
	int x2=0,y2=0;
	timer(sec,arr);
	_getch();
	
}

 
