#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
// #include "appstyle.h"
#include<windows.h>

void menu();
void close();
void con();
int count(char *filename);
void printturnlist(int tid);
void printandwriteTurn(double *head);
double * load_turn_data();
double * load_train_data();
int searchTrain(int t , int tid);
int searchTurn(int t , int tid);
void writeReport(int id,char* name,char* type);
void readturn(int t);
void inserturnrear();
void inserturnfront();
void inserturnnext();
void updateturn();
void deleteturn();
const char turndataRef[20] ="turndata.txt";
// const char traindataRef[20] ="traindata.txt";


// struct nodeturn
// {
// 	int id;
// 	char name[25];

// 	struct nodeturn *next;
// };

struct nodeturn
{
	int id;
	char name[50];
	char starttime[20];
	char endtime[20];
	int trainid;
	struct nodeturn *next;
};

struct nodetrain
{
	int id;
	char name[25];

	struct nodetrain *next;
};





double * load_turn_data(){
  int s=count(turndataRef);// get count
  struct nodeturn *head=NULL;
  head=(struct nodeturn*)malloc(sizeof(struct nodeturn));
  head->next=NULL;

  struct nodeturn *go=head;
    FILE* file = fopen(turndataRef, "r");//open file
    if ( file == NULL ){ 
        printf( " file failed to open." ); 
    } 
    else{
       for(int i=1;i<=s;i++){// get data from file to link list
           
            fscanf(file,"%d %s %s %s %d\n",&go->id,go->name,go->starttime,go->endtime,&go->trainid);
           
           if (i!=s)
           {
            go->next=(struct nodeturn*)malloc(sizeof(struct nodeturn));
            go=go->next;
            go->next=NULL;
           }
           
           

        }
    }
   
    fclose(file);
    return head;

 }

int searchTurn(int t , int tid){
   
  system("color 0e");
  int f=0;
  if (count(turndataRef)==0)
  {
    if (t==0)
    {
      printf("\t\t\t\t\tEmpty data list\n");
    }
    
  }else
  {
    double *head=load_turn_data();
    struct nodeturn *go=head;
    int n; 
  if (t==0)
  {
  system("cls");
  printf("Enter Train ID , that you want to search ??...  ");
  scanf("%d",&n);
  }else{
    n=tid;
  }

   
    while (1)
    { 
     if (go->id==n)
     {
      if (t==0)
      {
          blue();
           printf("----------------Details------------------------\n\n");   
     printf("Turn ID -%d \nName - %s\nStrated Time - %s \nEnded Time - %s \nTrain ID - %d \n",go->id,go->name,go->starttime,go->endtime,go->trainid);
     resetcolor();
      }

      
        f=1;
        break;
     }
        
     if (go->next==NULL)
    {
        break;
    }
  go=go->next;
    
    //printf("\n");
    }
    if (f==0&&t==0)
    {
      system("color 0c");
       system("cls");
       red();
        printf("\t\t\t\t\t\tInvalid   ID\n");
        resetcolor();
    }

 resetcolor();
  }
   if(t==0){
     con();
  }
  

  return f;
 
}





 // train and trun deatails 
 void readturn(int t){
   int s=count(turndataRef);
  
    system("color 0e");// chanage color
    system("cls");//clear console
    blue();
    printf("\n-------------------------------------------------------------------------------------------------");
    printf("\n                                   Turn RECORDS  (CURRENT)                                   ");
    printf("\n---------------------------------------------------------------------------------------------");
    printf("\n     ID      |       NAME        |       Started Time      |        Ended Time     |  Train ID  ");
    printf("\n-------------------------------------------------------------------------------------------------\n");

  if (s==0)
  {
      red();
    printf("\n-----------------------------------------empty data list-----------------------------------------\n");
    resetcolor();
  }else
  {
    double *head=load_turn_data();
  struct nodeturn *go=head;
     
    yellow();
  while (1)
    { 
     
  printf(" %6d        %15s        %16s        %16s        %6d \n",go->id,go->name,go->starttime,go->endtime,go->trainid);
     if (go->next==NULL)
    {
        break;
    }
    go=go->next;
    
    
    printf("\n");
    }
  }
  
  
    resetcolor();
    //printf("****\n"); 
  if (t==0)
  {
    con();
  }else
  {
    printf("\n") ;
    //pass
  }
  
 
}

void printandwriteTurn(double *head){
   struct nodeturn *go=head;
     FILE *ptr_file1;
    ptr_file1 =fopen(turndataRef,"w"); 
    cyan();
    printf("\n-------------------------------------------------------------------------------------------------");
    printf("\n                                   Turn RECORDS  (New)                                           ");
    printf("\n-------------------------------------------------------------------------------------------------");
    printf("\n     ID      |       NAME        |       Started Time      |        Ended Time     |  Train ID  ");
    printf("\n-------------------------------------------------------------------------------------------------\n");
    int i=0;
    yellow();
    while (1)
    { 
	   //printf("\n No    |    ID      |       NAME        |      PRICE    |   QUANTITY  |   Type   ");    
	  printf(" %6d        %15s        %16s        %16s        %6d \n",go->id,go->name,go->starttime,go->endtime,go->trainid);
    fprintf(ptr_file1, "%6d  %15s %16s %16s %6d\n",go->id,go->name,go->starttime,go->endtime,go->trainid);
   if (go->next==NULL)
    {
        break;
    }
	go=go->next;
    
    i++;
    printf("\n");
    }

    resetcolor();
    fclose(ptr_file1);

}






//insert rear

void inserturnrear(){
    // read stock
    readturn(1);
    system("color 0e");

    struct nodeturn *newNode = malloc(sizeof(struct nodeturn));
    inputs :
        printf("Enter turn ID ");
        scanf("%d",&newNode->id);
         int f=searchTurn(1,newNode->id);
        if (f==1)
        {
          printf("\n\nEntered trun ID has given to another turn ,Try again!!!\n\n");
         goto inputs;
        }
        printf("Enter Turn name ");
        scanf("%s",newNode->name);
        printf("Enter Turn Started Time ");
        scanf("%s",newNode->starttime);
        printf("Enter Turn Ended Time ");
        scanf("%s",newNode->endtime);
        inputtrainid :
            printf("Enter Train ID  ");
            scanf("%d",&newNode->trainid);
               
            if (searchTrain(1,newNode->trainid)==0)
            {
                red();
                printf("\tInvalid Train Id !!!\n");
                resetcolor();
                goto inputtrainid;
            }
             
    char type[16]="ADD-Turn-Rear";
    writeReport(newNode->id,newNode->name,type);
     newNode->next = NULL; 
     if (count(turndataRef)==0)
     {
       printandwriteTurn(newNode);
     }else
     {
       double * head=load_turn_data();
    //newNode->next= head;
    ///head=newNode;
    struct nodeturn *tmp =head ;
    while(tmp->next != NULL)
            tmp = tmp->next;
    tmp->next = newNode;  //Links the address part
    // struct nodeturn *go =head ;
       printandwriteTurn(head);
     }
     
     
  
    con();

 }
//insert front
void inserturnfront(){
    // read 
    readturn(1);
    system("color 0e");

    struct nodeturn *newNode = malloc(sizeof(struct nodeturn));
    inputs :
        printf("Enter turn ID ");
        scanf("%d",&newNode->id);
         int f=searchTurn(1,newNode->id);
        if (f==1)
        {
          printf("\n\nEntered trun ID has given to another turn ,Try again!!!\n\n");
         goto inputs;
        }
        printf("Enter Turn name ");
        scanf("%s",newNode->name);
        printf("Enter Turn Started Time ");
        scanf("%s",newNode->starttime);
        printf("Enter Turn Ended Time ");
        scanf("%s",newNode->endtime);
        inputtrainid :
            printf("Enter Train ID  ");
            scanf("%d",&newNode->trainid);
               
            if (searchTrain(1,newNode->trainid)==0)
            {   red();
                printf("\tInvalid Train Id !!!\n");
                resetcolor();
                goto inputtrainid;
            }
             
    char type[16]="ADD-Turn-Front";
    writeReport(newNode->id,newNode->name,type);
     newNode->next = NULL; 
     if (count(turndataRef)==0)
     {
       printandwriteTurn(newNode);
     }else
     {
       double * head=load_turn_data();
    //newNode->next= head;
    ///head=newNode;
    struct nodeturn *temp =head ;
    newNode->next=temp;
    // while(tmp->next != NULL)
    //         tmp = tmp->next;
    // tmp->next = newNode;  //Links the address part
    // struct nodeturn *go =head ;
      printandwriteTurn(newNode);
     }
     resetcolor();
     con();

 }


 //insert next
void inserturnnext(){
    // read 
    readturn(1);
    system("color 0e");
    int pevturnid;
    previnputs:
        printf("Enter turn ID Which your want add next ");
        scanf("%d",&pevturnid);
        if (searchTurn(1,pevturnid)==0)
        {
        printf("\nInvalid Turn Id!!!\n");
          goto  previnputs;
        }
        

    struct nodeturn *newNode = malloc(sizeof(struct nodeturn));
    inputs :
        printf("Enter turn ID ");
        scanf("%d",&newNode->id);
         int f=searchTurn(1,newNode->id);
        if (f==1)
        {
            red();
          printf("\n\nEntered trun ID has given to another turn ,Try again!!!\n\n");
          resetcolor();
         goto inputs;
        }
        printf("Enter Turn name ");
        scanf("%s",newNode->name);
        printf("Enter Turn Started Time ");
        scanf("%s",newNode->starttime);
        printf("Enter Turn Ended Time ");
        scanf("%s",newNode->endtime);
        inputtrainid :
            printf("Enter Train ID  ");
            scanf("%d",&newNode->trainid);
               
            if (searchTrain(1,newNode->trainid)==0)
            {
                red();
                printf("\tInvalid Train Id !!!\n");
                resetcolor();
                goto inputtrainid;
            }
             

     newNode->next = NULL; 
     if (count(turndataRef)==0)
     {
       printandwriteTurn(newNode);
     }else
     {
       double * head=load_turn_data();
    //newNode->next= head;
    ///head=newNode;
    struct nodeturn *temp =head ;
    

    while (1)
    {
        // printf("*\n");
        if (temp->id==pevturnid)
        {
           struct nodeturn *tempnode=temp->next;
           temp->next=newNode;
           newNode->next=tempnode;
           break;
        }
        temp=temp->next; 
        
    }
       printandwriteTurn(head);
     }

     
         char type[16]="ADD-Turn-Next";
    writeReport(newNode->id,newNode->name,type);
     con();

 }

 //update turn
void updateturn(){
    // read 
    readturn(1);
    system("color 0e");
    int pevturnid;
    previnputs:
        printf("Enter turn ID Which your want to update ");
        scanf("%d",&pevturnid);
        if (searchTurn(1,pevturnid)==0)
        {
            red();
        printf("\nInvalid Turn Id!!!\n");
          goto  previnputs;
          resetcolor();
        }
        

    struct nodeturn *newNode = malloc(sizeof(struct nodeturn));
    inputs :
        printf("Enter turn ID ");
        scanf("%d",&newNode->id);
         int f=searchTurn(1,newNode->id);
        if (f==1)
        {
            red();
          printf("\n\nEntered trun ID has given to another turn ,Try again!!!\n\n");
             resetcolor();
         goto inputs;
        }
        printf("Enter Turn name ");
        scanf("%s",newNode->name);
        printf("Enter Turn Started Time ");
        scanf("%s",newNode->starttime);
        printf("Enter Turn Ended Time ");
        scanf("%s",newNode->endtime);
        inputtrainid :
            printf("Enter Train ID  ");
            scanf("%d",&newNode->trainid);
               
            if (searchTrain(1,newNode->trainid)==0)
            {
                red();
                printf("\tInvalid Train Id !!!\n");
                resetcolor();
                goto inputtrainid;
            }
             

     newNode->next = NULL; 
     if (count(turndataRef)==0)
     {
       printandwriteTurn(newNode);
     }else
     {
       double * head=load_turn_data();
    //newNode->next= head;
    ///head=newNode;
    struct nodeturn *temp =head ;
    

    while (1)
    {
        // printf("*\n");
        if (temp->id==pevturnid)
        {
           temp->id=newNode->id;
           strcpy(temp->name,newNode->name);
           strcpy( temp->starttime,newNode->starttime);
           strcpy( temp->endtime,newNode->endtime);
           temp->trainid=newNode->trainid;
           break;
        }
        temp=temp->next; 
        
    }
       printandwriteTurn(head);
     }

     resetcolor();
         char type[16]="ADD-Turn-Next";
    writeReport(newNode->id,newNode->name,type);
     con();

 }

//delete
void deleteturn(){
    readturn(1);
    system("color 0e");
    if (count(turndataRef)==0)
    {
       FILE *ptr_file1;
       ptr_file1 =fopen(turndataRef,"w"); 
       fprintf(ptr_file1,"");
       fclose(ptr_file1);
    }else
    {
      char type[16]="DELETE-Turn";
    double *head=load_turn_data();
    struct nodeturn *go=head;
    int p;
    
    inputs:
        printf("Enter train ID which you want to delete : ");
        scanf("%d",&p);
        int found=searchTurn(1,p);
        if (found==1)
        {
        //   printandwriteTurn(head);
        
              int c=1;
              while (1)
              { 
                  if (go->next==NULL)
                  {
                      break;
                  }
                  
                  if (go->id==p)
                  {
                    writeReport(go->id,go->name,type);
                  
                      break;
                  }
                  c++;
                  go=go->next; 
                
              }
              go=head;
              int position=c;//count
            //ok printf(" P-%d\n",position);
              int ph=go->id;
              struct nodeturn* temp = head;


              // If head needs to be removed 
              if (ph == p) 
              { 
                go=go->next;
                  printandwriteTurn(go);
              }else{

              
                      
                          // Find previous node of the node to be deletetraind 
                          for (int i=0; temp!=NULL && i<position-2; i++) 
                              temp = temp->next; 
                      
                          // If position is more than number of nodes 
                          if (temp == NULL || temp->next == NULL) 
                              return; 
                      
                          // Node temp->next is the node to be deletetraind 
                          // Store pointer to the next of node to be deletetraind 
                          struct nodeturn *next = temp->next->next; 
                      
                          // Unlink the node from linked list 
                          free(temp->next);  // Free memory 
                      
                          temp->next = next;  // Unlink the deletetraind node from list 
                          go=head;
                          printandwriteTurn(head);
              }
        }else{
            red();
          printf("\t\tInvalid Train Id!!!!\n");
             resetcolor();
          goto inputs;

        }
        resetcolor();
    }
    

  con();
}

void printturnlist(int tid){

    if (count(turndataRef)==0)
    {   
        purple();
        printf("\n-------------------------------------------------------------------------------------");
        printf("\n                             Turn RECORDS (Train ID - %d)                          ",tid);
        printf("\n------------------------------------------------------------------------------------");
        printf("\n     ID      |       NAME        |       Started Time      |        Ended Time     ");
        printf("\n-----------------------------------------------------------------------------------\n");
        red();
        printf("\n----------------------------  No turn Availabel ----------------------------------");
           resetcolor();
    }else{
        double *head=load_turn_data();
        struct nodeturn *go=head;
         purple();
        printf("\n-------------------------------------------------------------------------------------");
        printf("\n                             Turn RECORDS (Train ID - %d)                          ",tid);
        printf("\n------------------------------------------------------------------------------------");
        printf("\n     ID      |       NAME        |       Started Time      |        Ended Time     ");
        printf("\n-----------------------------------------------------------------------------------\n");

        yellow();
        int rowcount=0;
        while (1)
        {
           if (go->trainid==tid)
           {
               printf(" %6d        %15s        %16s        %16s         \n",go->id,go->name,go->starttime,go->endtime);
               rowcount++;
           }
           if (go->next==NULL)
           {
                break;
           }

           go=go->next;

        }
        if (rowcount==0)
        { 
            red();
           printf("\n----------------------------  No turn Availabel ----------------------------------");
           resetcolor();
        }
            
    resetcolor();
    }
    
}













