#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
char choice3;
char choise;
int score1=0;
int score=0;
int prev[4][4]={0};
int arr[4][4]={0};
void Generate_number();
int check();
int pert=1;
void move();
void display();
int precheck();
void loadingBar(int temp);
void previous(int val);
void menu();


int main()
{

 int x,y,temp,val=1;



 temp=1;
 loadingBar(temp);
 system("cls");

 
printf("\n\t\t\t\t\t===============2048==============\n");

printf("\t\t\t\t\t --> PRESS  O  TO GO TO OPTIONS \t\t\t\t\t\n");

printf("\n\n\t\t\t\t\t--> PRESS ANY KEY TO START THE GAME....\n\t\t\t\t\t");

choice3=getch();
 if(choice3=='o' || choice3=='O')
 {
  	 menu();
 }

 

 while(check())
 {
 	val++;
  previous(val); 
  Generate_number();
  display();


  
  fflush(stdin);
  move(choise);
 

  
 if(choise=='x' || choise=='X')
 {
 	system("cls") ;
 	temp=0;
 	loadingBar(temp);
 	
    return 0;
}
 else if(choise=='r' || choise=='R')
 {
 	score1=0;
 	system("cls");
 	temp=2;
 	loadingBar(temp);
 for(x=0;x<=3;x++)
 {
  for(y=0;y<=4;y++)
  {
   arr[x][y]=0;
  }
 } 

}
 else if(choise=='h' || choise=='H')
 {
 	printf("\n\n\n\n\t\t\t\t\tTHE HIGHSCORE IS %d\n\n\n",score1);
    printf("\t\t\t\t\t --> PRESS  ANY KEY TO GO BACK \t\t\t\t\t\n");
    getch();
 	
 }
 
  for(x=0;x<=3;x++)
 {
  for(y=0;y<=3;y++)
  {
   if (arr[x][y]==2048)
   {
   	   system("cls");
   	printf("\n\n\n\t\t\t\t\t CONGRATULATION YOU WON \t\t\t\t\t\n");
   	return 0;
   }
  }
 } 


  


 }
    system("cls");
printf("\n\n\n\n\t\t\t\t\t The Game ENDED AS NO MORE MOVES POSSIABLE");
 printf("\n\n\n\n\t\t\t\t\t\tThe final score is = %d",score1);
 getch();
   
}
void Generate_number()
{
 int location;
 int x,y;
 int no;
 do
 {
  no=rand()%5;
 }while(no==1||no==0||no==3);
 if(pert==1)
 {
  score=0;
  pert=0;
 }

 do
 {
  x=rand()%4;
  y=rand()%4;
  
 }while(arr[x][y]!=0);
 arr[x][y]=no;
 
}

void move()
{
choise=getch();
 int i,j;
 int k=0;
 int max;
 int x,y;

    while (choise!='d' && choise!='D' && choise!='a' && choise!='A' && choise!='w' && choise!='W' && choise!='s' && choise!='S' && choise!='x' && choise!='X' && choise!='r' && choise!='R' && choise!='P' && choise!='p'  && choise!='h' && choise!='H')
  {
  	printf("\n\n\t\t\t\t\t--> INVALID INPUT....\n\t\t\t\t\t");
  	choise=getch();
  }

 if(choise=='d' || choise=='D')
 {

  for(i=0;i<=3;i++)
  {
   max=arr[i][3];
   for(j=2;j>=0;j--)
   {
    if(arr[i][j]==max)
    {
       arr[i][j+1]=2*max;
       score1=arr[i][j+1]+score1;
       arr[i][j]=0;
       
    }
   
     max=arr[i][j];
    
   }
   for(j=2;j>=0;j--)
   {
    k=j;
    while(precheck(i,k+1)&&(k+1)<=3)
    {
     arr[i][k+1]=arr[i][k];
     arr[i][k]=0;
     k++;
    }
   }
  }
    
 }
 else if(choise=='a' || choise=='A')
 {
 
  for(i=0;i<=3;i++)
  {
   max=arr[i][0];
   for(j=1;j<=3;j++)
   {
    if(arr[i][j]==max)
    {
     arr[i][j-1]=2*max;
     score1=arr[i][j+1]+score1;
     arr[i][j]=0;
           
    }
    max=arr[i][j];
    
   }
   for(j=1;j<=3;j++)
   {
    k=j;
    while(precheck(i,k-1)&&(k-1)>=0)
    {
     arr[i][k-1]=arr[i][k];
     arr[i][k]=0;
     k--;
    }
   }
  }
 }
 else if(choise=='w' || choise=='W')
 {
 
  for(j=0;j<=3;j++)
  {
   max=arr[0][j];
   for(i=1;i<=3;i++)
   {
    if(arr[i][j]==max)
    {
     arr[i-1][j]=2*max;
     score1=arr[i][j+1]+score1;
     arr[i][j]=0;
        
    }
   max=arr[i][j];
   }
   for(i=1;i<=3;i++)
   {
    k=i;
    while(precheck(k-1,j)&&(k-1)>=0)
    {
     arr[k-1][j]=arr[k][j];
     
     arr[k][j]=0;
     k--;
    }
   }
   
  }
 }
 else if(choise=='s' || choise=='S')
 {

   for(j=0;j<=3;j++)
  {
   max=arr[3][j];
   for(i=2;i>=0;i--)
   {
    if(arr[i][j]==max)
    {
     arr[i+1][j]=2*max;
     score1=arr[i][j+1]+score1;
     arr[i][j]=0;
      
    }
   
     max=arr[i][j];
    
   }
   for(i=2;i>=0;i--)
   {
    k=i;
    while(precheck(k+1,j)&&(k+1)<=3)
    {
     arr[k+1][j]=arr[k][j];
     arr[k][j]=0;
     k++;
    }
   }
   
  }
  
 }
   else if(choise=='p' || choise=='P')
  {
  	  	 	for (x=0;x<4;x++)
	{
		for (y=0;y<4;y++)
		{
			arr[x][y]=0;
		}
	}
  	 	for (x=0;x<4;x++)
	{
		for (y=0;y<4;y++)
		{
			arr[x][y]=prev[x][y];
		}
	}

  	 score1=score1-2;

  }


}

int precheck(int q,int w)
{
 if(arr[q][w]==0)
 {
  return 1;
 }
 else return 0;
}


int check()
{
 int i,j,m;
 int flag=1;
 for(i=0;i<=3;i++)
 {
  for(j=0;j<=3;j++)
  {
   if(arr[i][j]==0)
   {
    flag=0;
   }
  }
 }
 if(flag==0)
 {
  return 1;
 }
 else 
 return 0;
}



// displays all main game and its frame and also displays the score 

void display()
{
	system("cls") ;
 printf("\n\t\t\t\t\t--> PRESS  W  TO MOVE UPWARDS");
 printf("\n\t\t\t\t\t--> PRESS  S  TO MOVE DOWNWARDS");
 printf("\n\t\t\t\t\t--> PRESS  D  TO MOVE RIGHTWARDS");
 printf("\n\t\t\t\t\t--> PRESS  A  TO MOVE LEFTWARDS\n ");
 printf("\n\t\t\t\t\t--> PRESS  H  TO SHOW HIGH SCORE\n ");
  printf("\n\t\t--> PRESS  P  TO GO BACK *warning u can only back once per 2 move and ur score will be deducted*\n ");
printf("\t\t\t\t\t --> PRESS  R  TO RESET\t\t\t\t\t\n");
printf("\t\t\t\t\t --> PRESS  X  TO END\t\t\t\t\t\n");

 int k=0;
 int i,j,len;
 printf("\t\t\tScore=%d\n",score1);
   printf("\t\t\t\t\t---------------------------------");
 
 for(i=0;i<=3;i++)
 {
 

  printf("\n\t\t\t\t\t|");
  for(j=0;j<=3;j++)
  {
   if(arr[i][j]==0)
   {
    printf("      |");
    
   }
  
   else printf("%d     |",arr[i][j]);
   
   printf(" ");
   
  }
  if(i<=2)
  {
  
  printf("\n");
  printf("\t\t\t\t\t---------------------------------");
 }
 
  
 }
   printf("\n\t\t\t\t\t---------------------------------");
 
}



// Function to creating loading bar
void loadingBar(int temp)
{
	int x;
    // 0 - black background,
    // A - Green Foreground
    system("color 06");
  
    // Initialize char for printing
    // loading bar
    char before_loading = 177, after_loading = 219;
  
    printf("\n\n\n\n");
    if (temp==1){
	
    printf("\n\n\n\n\t\t\t\t\t\t" "LOADING....\n\n");
	}
    else  if (temp==0)
    {
    	printf("\n\n\n\n\t\t\t\t\t\t" "EXITING....\n\n");
    	
	}
	else  if (temp==2)
    {
    	printf("\n\n\n\n\t\t\t\t\t\t" "RESTARTING....\n\n");
    	
	}
	printf("\t\t\t\t\t");
    
  
    // Print initial loading bar
    for ( x = 0; x < 26; x++)
        printf("%c", before_loading);
  
    // Set the cursor again starting
    // point of loading bar
    printf("\r");
    printf("\t\t\t\t\t");
  
    // Print loading bar progress
    for ( x = 0; x < 26; x++) {
        printf("%c", after_loading);
  
        // Sleep for .1 second
        Sleep(100);
    }
    printf("\n\n\n\n\n\n\n\n");

     
}



void previous (int val)
{
	int i,j;
	if (val%2==0){
	
	for (i=0;i<4;i++)
	{
		for (j=0;j<4;j++)
		{
			prev[i][j]=arr[i][j];
		}
	}
	}


}



// using recurrsion here 
void menu()
{
		system("cls") ;
char choise2;
printf("\t\t\t\t\t --> PRESS  C  TO GO TO CREDITS \t\t\t\t\t\n");
printf("\t\t\t\t\t --> PRESS  H  TO GO TO HIGHSCORE FOR THE SESSION \t\t\t\t\t");
printf("\t\t\t\t\t --> PRESS  ANY KEY TO START THE GAME\t\t\t\t\t\n");


	choise2=getch();
	if(choise2=='c' || choise2=='C')
	{
	int x;
  
    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t\t" "CREATED BY ... \n\n");
	printf("\t\t\t\t\t\t");
	
    printf("\r");
    printf("\t\t\t\t\t\t");
    printf("K");Sleep(150);printf("A");Sleep(150);printf("S");Sleep(150);printf("H");Sleep(150);printf("A");Sleep(150); printf("A");Sleep(150);printf("F");Sleep(150);
    printf("-");Sleep(150);printf("3");Sleep(150);printf("3");Sleep(150);printf("8");Sleep(150);printf("0");Sleep(150);
    printf("\n");
   
    printf("\r");
    printf("\t\t\t\t\t\t");
    printf("S");Sleep(150);printf("U");Sleep(150);printf("L");Sleep(150);printf("E");Sleep(150);printf("M");Sleep(150); printf("A");Sleep(150);printf("N");Sleep(150);
    printf("-");Sleep(150);printf("3");Sleep(150);printf("8");Sleep(150);printf("8");Sleep(150);printf("7");Sleep(150);
    printf("\n");
    
    printf("\r");
    printf("\t\t\t\t\t\t");
    printf("H");Sleep(150);printf("A");Sleep(150);printf("R");Sleep(150);printf("O");Sleep(150);printf("O");Sleep(150);printf("N");Sleep(150);printf(" ");Sleep(150);
    printf("-");Sleep(150);printf("3");Sleep(150);printf("8");Sleep(150);printf("2");Sleep(150);printf("1");Sleep(150);
    printf("\n\n\n");
    printf("\t\t\t\t\t --> PRESS  ANY KEY TO GO BACK \t\t\t\t\t\n");	
		getch();    menu();
    	
    }

   if(choise2=='h' || choise2=='H')
    {
    printf("\n\n\n\n\t\t\t\t\tTHE HIGHSCORE IS %d\n\n\n",score1);
    printf("\t\t\t\t\t --> PRESS  ANY KEY TO GO BACK \t\t\t\t\t\n");
    getch();
    menu();
	}

	
		

}
	
	
