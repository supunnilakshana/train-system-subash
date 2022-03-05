#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include<windows.h>
// #include "appstyle.h"

void close();
void con();
int count(const char *filename);
void report();
void writeReport(int id,char* name,char* type);
void welcomeanimation();
void loadinganimation();
void print_progressbar(int percent);
void initalanimation();
void print_progressbarinit(int percent);
int initialDatabase();


void close()
{
    printf("\t\t\t\t\tExiting from the system..... ");
    // animeE();
   system("cls");
   system("color 0a");
    printf("\n\n\n\n \t\t\t\t\t\t..............EXIT................");
     system("exit");
    
}

void welcomeanimation(){
     int x; double y;
   
   char text1[]=    "\n  \t\t\t\t\t\t   *********************************";
   char text2[]=    "\n   \t\t\t\t\t\t  * Welcome to Train Mannagement System *";
   char text3[]=    "\n  \t\t\t\t\t\t   *********************************\n\n\n";
    printf("\n");
     green();
    for(x=0; text1[x]!=NULL; x++)
   {
     printf("%c",text1[x]);
      for(y=0; y<=8888888; y++)
      {
      }
   }
   printf("\n");
   yellow();
    for(x=0; text2[x]!=NULL; x++)
   {
     printf("%c",text2[x]);
      for(y=0; y<=8888888; y++)
      {
      }
   }
   green();
   printf("\n");
    for(x=0; text3[x]!=NULL; x++)
   {
     printf("%c",text3[x]);
      for(y=0; y<=8888888; y++)
      {
      }
   }
   resetcolor();

//    getch();
}



//animation

void print_progressbar(int percent)
{
  const int mul = 2; // width factor
  percent = min(100, percent);

  // spinning animation
  static int spin_index = 0;
  char spinning[] = "_-\\|/-";

  // bar filler
  int len = (percent * mul / 10) + 1;
  char *bar = malloc(len);
  memset(bar, '|', len - 1);
  bar[len - 1] = 0;

  // write display
  printf("\t\t\t\t\t\t%c Verifying: [%*s] %*d%%\r",
         percent == 100 ? ' ' : spinning[spin_index],
         mul * 10, bar,
         3, percent
        );
  spin_index = (spin_index + 1) % strlen(spinning);

  free(bar);
}


void print_progressbarinit(int percent)
{
  const int mul = 2; // width factor
  percent = min(100, percent);

  // spinning animation
  static int spin_index = 0;
  char spinning[] = "_-\\|/-";

  // bar filler
  int len = (percent * mul / 10) + 1;
  char *bar = malloc(len);
  memset(bar, '<', len - 1);
  bar[len - 1] = 0;

  // write display
  printf("\t\t\t\t\t\t%c Initializing Database: [%*s] %*d%%\r",
         percent == 100 ? ' ' : spinning[spin_index],
         mul * 10, bar,
         3, percent
        );
  spin_index = (spin_index + 1) % strlen(spinning);

  free(bar);
}


void loadinganimation(){
     printf("\n\n");
     white();
  for (int i = 0; i <= 100; i += 1)
  {
     
    if (i%5==0)
    {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
    }else if (i%4==0)
    {
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    }else  if (i%3==0)
    {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);
    }else  if (i%2==0)
    {
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE);
    }else{
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    }
   
      
    print_progressbar(i);
    Sleep(50);
  }

   resetcolor();
}

void initalanimation(){
     printf("\n\n");
     white();
  for (int i = 0; i <= 100; i += 1)
  {
    if (i%5==0)
    {
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN|BACKGROUND_INTENSITY);
    }else if (i%4==0)
    {
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE|BACKGROUND_INTENSITY);
    }else  if (i%3==0)
    {
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE);
    }else  if (i%2==0)
    {
           SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_RED|BACKGROUND_INTENSITY);
    }else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
    }
   
      
    print_progressbarinit(i);
    Sleep(40);
  }

   resetcolor();
}

//con
void con(){

	char c;
    yellow();
	printf("\n Enter (Y or y)to go to the main menu otherwise enter(N or n) to exit. ");
	scanf(" %c",&c);
	while(1){
		if((c=='Y')||(c=='y')||(c=='N')||(c=='n')){// check validation
			break;
		}else{
            red();
			printf("Enter correct letter:");
            resetcolor();
			scanf(" %c",&c);

		}
	}

	if((c=='Y')||(c=='y')){
		menu();// goto menu
	}else{
		close(); //
	}
    resetcolor();
}

int count(const char *filename){

    int s=0;
    FILE* file = fopen(filename, "r");// openfile
    char line[150];
    if ( file == NULL ){ 
        
        s=0;
    } 
    else{
        while (fgets(line, sizeof(line), file)) {
            //printf("%s", line);
            s++;

        }
    }
    fclose(file);
	
    return s;
}

void report(){
  system("cls");
  system("color 0e");
  blue();
  printf("\n------------------------------------------------------------------------------------------------");
  printf("\n                                        Activity REPORT                                          ");
  printf("\n------------------------------------------------------------------------------------------------");
  printf("\n         ID   |             NAME           |          Type        |     Time                     " );
  printf("\n-----------------------------------------------------------------------------------------------\n");

    FILE* file = fopen("report.txt", "r");
    char line[500];
    if ( file == NULL ){ 
        red();
        printf( "--------------------------------- NO activities -----------------------------------" ) ; 
        resetcolor();
    } 
    else{
        yellow();
        while (fgets(line, sizeof(line), file)) {// read report.txt

            printf("%s", line); 
        }
    }
    fclose(file);

  resetcolor();  
  con();
}

void writeReport(int id,char* name,char* type){

  time_t t;
  time(&t);
  FILE *file;
  file =fopen("report.txt","a"); 
  fprintf(file, "   %6d             %15s       %16s      %s \n",id,name,type,ctime(&t));
  fclose(file);
}


int initialDatabase(){
    int s=0;
    FILE* file;
    file = fopen("report.txt", "r");
    if ( file == NULL ){ 
          s=1;
        FILE* file3=fopen("report.txt", "w");
        // fprintf(file3," ");
        fclose(file3);
    } 
   
    fclose(file);
    file = fopen("traindata.txt", "r");
    
    if ( file == NULL ){ 
        s=1;
        FILE* file1=fopen("traindata.txt", "w");
        // fprintf(file1," ");
        fclose(file1);
      
  
      
    } 
    
    fclose(file);

    file = fopen("turndata.txt", "r");
    
    if ( file == NULL ){ 
        s=1;
        FILE* file2=fopen("turndata.txt", "w");
        // fprintf(file2," ");
        fclose(file2);
      
    }
    fclose(file);
    return s;

}
