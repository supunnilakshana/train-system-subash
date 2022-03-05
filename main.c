#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include<windows.h>
#include "appstyle.h"

void login();
void menu();
void con();
void close();
double * load_train_data();
int count();
void readtrain(int t);
void printandwriteTrain(double *head);
void writeReport(int id,char* name,char* type);
void insertrain();
void deletetrain();
void printturnlist(int tid);
void printandwriteTurn(double *head);
double * load_turn_data();
int searchTrain(int t , int tid);
int searchTurn(int t , int tid);
void writeReport(int id,char* name,char* type);
void readturn(int t);
void inserturnrear();
void inserturnfront();
void inserturnnext();
void updateturn();
void deleteturn();
void report();
void welcomeanimation();
void loadinganimation();
void print_progressbar(int percent);
int initialDatabase();



void login(){
  system("cls");// clear console
  system("color 0a");// change color in console
	char un[10];
	char pw[10];
	char unsave[10]="admin";
	char pwsave[10]="c1234";
    welcomeanimation();
    yellow();
	while(1){
		  printf("\n\t\t\t\t\tEnter User Name:");
	  	scanf("%s",un);
		  printf("\n\t\t\t\t\tEnter Password:");
      int p=0; 
      do{ 
        pw[p]=getch(); 
        if(pw[p]!='\r'){ 
          printf("*"); 
        } 
        p++; 
      }while(pw[p-1]!='\r'); 
      pw[p-1]='\0'; 
     // getch(); 
        loadinganimation();
       
		if((strcmp(un,unsave)==0)&&(strcmp(pw,pwsave)==0)){
                green();
				printf("\n\n\n  \t\t\t\t\t\t * Logging sucessfull *");
                resetcolor();
                if (initialDatabase()==1)
                {
                     initalanimation();
                }
                menu();
               
    //    break;
        
		}
     system("cls");
     red();
		printf("\n\n\n\n   \t\t\t\t\t\t  * invalid User name or password  *\n\n");
        resetcolor();
	}

    resetcolor();

}

void menu(){
  int choice;
  system("cls");
  menuerror:
      yellow();
      printf("\n\t\t\t\t\t\t\t--------MENU--------\n\n"); //show menu
      resetcolor();
      blue(); printf("\n\t\t\t\t01.Search Train   "); green();  printf("\t\t\t05.Search Turn");
      blue(); printf("\n\t\t\t\t02.Train Details  "); green();  printf("\t\t\t06.Turn Details ");
      blue(); printf("\n\t\t\t\t03.ADD a Train    "); green();   printf("\t\t\t07.ADD a Trun to Front");
      blue(); printf("\n\t\t\t\t04.Delete Train   "); green();   printf("\t\t\t08.ADD a Trun to Next");
      printf("\n\t\t\t\t                  "); green();   printf("\t\t\t09.ADD a Trun to Rear");
      printf("\n\t\t\t\t                  "); green();   printf("\t\t\t10.Update Turn details");
      printf("\n\t\t\t\t                  "); green();   printf("\t\t\t11.Delete Turn details");
      yellow(); printf("\n\t\t\t\t\t\t12.Activity Report \n");
      red(); printf("\n\t\t\t\t\t\t13.Exit "); resetcolor();
      printf("\n\n\t\t\t\t Enter your choice :");
      
      
      
       // get users choices
      scanf("%d",&choice);
      system("cls");

      switch(choice)
      {
      case 1:
        searchTrain(0,0);
        break;
      case 2:
        readtrain(0);// 0 value as an argument
        break;
      case 3:
        insertrain();
        break;
      case 4:
        deletetrain();
        break;
      case 5:
        searchTurn(0,0);
        break;
      case 6:
        readturn(0);
        break;
      case 7:
        inserturnfront();
        break;
      case 8:
        inserturnnext();
        break;
       case 9:
        inserturnrear();
        break;
      case 10:
        updateturn();
        break;
      case 11:
        deletetrain();
        break;
      case 12:
        report();
        break;  
      case 13:
         close();
        break;
      default:
        printf("Invalid Choice");
        goto menuerror;
      }
}



int main()
{
    
    login();
    
    return 0;
}
