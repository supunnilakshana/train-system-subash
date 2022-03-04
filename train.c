#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


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
void printtest();

const char traindataRef[20] ="traindata.txt";


struct nodetrain
{
	int id;
	char name[25];

	struct nodetrain *next;
};

struct nodeturn
{
	int id;
	char name[50];
	char starttime[20];
	char endtime[20];
	int trainid;
	struct nodeturn *next;
};


//menu
void menu(){
  int choice;
  system("cls");
  system("color 03");
  menuerror:
      printf("\n--------MENU--------"); //show menu
      printf("\n01.Search Train ");
      printf("\n02.Train Details ");
      printf("\n03.ADD a Train");
      printf("\n08.Delete Product");
      printf("\n09.Activity Report ");
      printf("\n10.Exit ");
      printf("\n\n Enter your choice :"); // get users choices
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
      
       case 8:
        deletetrain();
        
        break;
       case 9:
        // report();
        break;
      case 10:
         close();
        break;
      default:
        printf("Invalid Choice");
        goto menuerror;
      }
}



void close()
{
    printf("\t\t\t\t\tExiting from the system..... ");
    // animeE();
   system("cls");
   system("color 0a");
    printf("\n\n\n\n \t\t\t\t\t\t..............EXIT................");
     system("exit");
    
}


//con
void con(){
	char c;
	printf("\n Enter (Y or y)to go to the main menu otherwise enter(N or n) to exit.");
	scanf("%c",&c);
	while(1){
		if((c=='Y')||(c=='y')||(c=='N')||(c=='n')){// check validation
			break;
		}else{
			printf("Enter correct letter:");
			scanf(" %c",&c);	
		}
	}

	if((c=='Y')||(c=='y')){
		menu();// goto menu
	}else{
		close(); //
	}
}






int count(const char *filename){

    int s=0;
    FILE* file = fopen(filename, "r");// openfile
    char line[150];
    if ( file == NULL ){ 
        printf( " file failed to open." ) ; 
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

// return head 

double * load_train_data(){
  int s=count(traindataRef);// get count
  struct nodetrain *head=NULL;
  head=(struct nodetrain*)malloc(sizeof(struct nodetrain));
  head->next=NULL;

  struct nodetrain *go=head;
    FILE* file = fopen(traindataRef, "r");//open file
    if ( file == NULL ){ 
        printf( " file failed to open." ); 
    } 
    else{
       for(int i=1;i<=s;i++){// get data from file to link list
           
            fscanf(file,"%d %s\n",&go->id,go->name);
           // printf("%d  %d \n",go->pid,go->qty);
           if (i!=s)
           {
                go->next=(struct nodetrain*)malloc(sizeof(struct nodetrain));
            go=go->next;
            go->next=NULL;
           }
           
    

        }
    }
   //printf("****\n");
    fclose(file);
    return head;

 }

int searchTrain(int t , int tid){
   
  system("color 0e");
  int f=0;
  if (count(traindataRef)==0)
  {
    if (t==0)
    {
      printf("\t\t\t\t\tEmpty data list\n");
    }
    
  }else
  {
    double *head=load_train_data();
    struct nodetrain *go=head;
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
           printf("----------------Details------------------------\n\n");
        printf("Train ID -%d \nName - %s\n  ",go->id,go->name);
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
        printf("\t\t\t\t\t\tInvalid  P ID\n");
    }

 
  }
   if(t==0){
     con();
  }
  
  



  return f;
 
}

 // train and trun deatails 
 void readtrain(int t){
   int s=count(traindataRef);
  
    system("color 0e");// chanage color
    system("cls");//clear console
    
    printf("\n------------------------------------");
    printf("\n     Train RECORDS  (CURRENT)      ");
    printf("\n-----------------------------------");
    printf("\n     ID      |       NAME        ");
    printf("\n----------------------------------\n");

  if (s==0)
  {
    printf("\n---------empty data list----------\n");
  }else
  {
    double *head=load_train_data();
  struct nodetrain *go=head;
    

  while (1)
    { 
        
  printf(" %6d        %15s \n",go->id,go->name);
     if (go->next==NULL)
    {
        break;
    }
  go=go->next;
    
    
    printf("\n");
    }
  }
  
  

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

void printandwriteTrain(double *head){
   struct nodetrain *go=head;
     FILE *ptr_file1;
    ptr_file1 =fopen(traindataRef,"w"); 

    printf("\n------------------------------------");
    printf("\n     Train RECORDS  (New)      ");
    printf("\n-----------------------------------");
    printf("\n     ID      |       NAME        ");
    printf("\n----------------------------------\n");
    int i=0;
    
    while (1)
    { 
	   //printf("\n No    |    ID      |       NAME        |      PRICE    |   QUANTITY  |   Type   ");    
	  printf(" %6d        %15s      \n",go->id,go->name);
    fprintf(ptr_file1, "%6d  %15s  \n",go->id,go->name);
   if (go->next==NULL)
    {
        break;
    }
	go=go->next;
    
    i++;
    printf("\n");
    }


    fclose(ptr_file1);

}

void writeReport(int id,char* name,char* type){

  time_t t;
  time(&t);
  FILE *file;
  file =fopen("report.txt","a"); 
  fprintf(file, "   %6d             %15s       %16s      %s \n",id,name,type,ctime(&t));
  fclose(file);
}






//insert rear

void insertrain(){
    // read stock
    readtrain(1);
    system("color 0e");

    struct nodetrain *newNode = malloc(sizeof(struct nodetrain));
    inputs :
        printf("Enter train ID ");
        scanf("%d",&newNode->id);
         int f=searchTrain(1,newNode->id);
        if (f==1)
        {
          printf("\n\nEntered product ID has given to another product ,Try again!!!\n\n");
         goto inputs;
        }
        printf("Enter Train name ");
        scanf("%s",newNode->name);
       
    char type[16]="ADD-Train";
    writeReport(newNode->id,newNode->name,type);
     newNode->next = NULL; 
     if (count(traindataRef)==0)
     {
       printandwriteTrain(newNode);
     }else
     {
       double * head=load_train_data();
    //newNode->next= head;
    ///head=newNode;
    struct nodetrain *tmp =head ;
    while(tmp->next != NULL)
            tmp = tmp->next;
    tmp->next = newNode;  //Links the address part
    // struct nodetrain *go =head ;
      printandwriteTrain(head);
     }
     
     
   
  
    con();

 }

//delete
void deletetrain(){
    readtrain(1);
    system("color 0e");
    if (count(traindataRef)==0)
    {
       FILE *ptr_file1;
       ptr_file1 =fopen(traindataRef,"w"); 
       fprintf(ptr_file1,"");
       fclose(ptr_file1);
    }else
    {
      char type[16]="DELETE-Train";
    double *head=load_train_data();
    struct nodetrain *go=head;
    int p;
    
    inputs:
        printf("Enter train ID which you want to delete : ");
        scanf("%d",&p);
        int found=searchTrain(1,p);
        if (found==1)
        {
          // printandwriteTrain(head);
        
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
              struct nodetrain* temp = head;


              // If head needs to be removed 
              if (ph == p) 
              { 
                go=go->next;
                  printandwriteTrain(go);
              }else{

              
                      
                          // Find previous node of the node to be deletetraind 
                          for (int i=0; temp!=NULL && i<position-2; i++) 
                              temp = temp->next; 
                      
                          // If position is more than number of nodes 
                          if (temp == NULL || temp->next == NULL) 
                              return; 
                      
                          // Node temp->next is the node to be deletetraind 
                          // Store pointer to the next of node to be deletetraind 
                          struct nodetrain *next = temp->next->next; 
                      
                          // Unlink the node from linked list 
                          free(temp->next);  // Free memory 
                      
                          temp->next = next;  // Unlink the deletetraind node from list 
                          go=head;
                          printandwriteTrain(head);
              }
        }else{

          printf("\t\tInvalid Train Id!!!!\n");
          goto inputs;

        }
    }
    

  con();
}




int main()
{
	//  printf("%d",count(traindataRef));
	// readtrain(0);
  // insertrain();
  // searchTrain(0,1);
// deletetrain();
menu();
// printtest();
	return 0;
}







