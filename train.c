#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>



double * load_train_data();
int count();
void readtrain(int t);
void insertrain();
void delete();


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

// //con
// void con(){
// 	char c;
// 	printf("\n Enter (Y or y)to go to the main menu otherwise enter(N or n) to exit.");
// 	scanf("%c",&c);
// 	while(1){
// 		if((c=='Y')||(c=='y')||(c=='N')||(c=='n')){// check validation
// 			break;
// 		}else{
// 			printf("Enter correct letter:");
// 			scanf(" %c",&c);	
// 		}
// 	}

// 	if((c=='Y')||(c=='y')){
// 		menu();// goto menu
// 	}else{
// 		close(); //
// 	}
// }






int count(char *filename){

    int s=0;
    FILE* file = fopen(filename, "r");// openfile
    char line[150];
    if ( file == NULL ){ 
        printf( " file failed to open." ) ; 
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
  int s=count("traindata.txt");// get count
  struct nodetrain *head=NULL;
  head=(struct nodetrain*)malloc(sizeof(struct nodetrain));
  head->next=NULL;

  struct nodetrain *go=head;
    FILE* file = fopen("traindata.txt", "r");//open file
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
    double *head=load_train_data();
    struct nodetrain *go=head;
    int n;
    system("color 0e");
    if (t==0)
    {
  
    } 
  if (t==0)
  {
    system("cls");
   printf("Enter Train ID , that you want to search ??...  ");
   scanf("%d",&n);
  }else{
    n=tid;
  }

    int f=0;
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

  if(t==0){
    //  con();
  }
  return f;
 
}

 // train and trun deatails 
 void readtrain(int t){
    double *head=load_train_data();
    system("color 0e");// chanage color
    system("cls");//clear console
    
    printf("\n------------------------------------");
    printf("\n     Train RECORDS  (CURRENT)      ");
    printf("\n-----------------------------------");
    printf("\n     ID      |       NAME        ");
    printf("\n----------------------------------\n");
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

    //printf("****\n"); 
  if (t==0)
  {
    // con();
  }else
  {
    printf("\n") ;
    //pass
  }
  
 
}


//insert rear

void insertrain(){
    // read stock
    readtrain(1);
    ////////////////////////
    system("color 0e");
    time_t t;
    time(&t);
    FILE *ptr_file1;
    FILE *ptr_file2;
    ptr_file2 =fopen("report.txt","a");
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
     fprintf(ptr_file2, "   %6d             %15s                %16s             %s \n",newNode->id,newNode->name,type,ctime(&t));
     newNode->next = NULL; 
    double * head=load_train_data();
    //newNode->next= head;
    ///head=newNode;
    struct nodetrain *tmp =head ;
    while(tmp->next != NULL)
            tmp = tmp->next;
    tmp->next = newNode;  //Links the address part
    struct nodetrain *go =head ;
    ptr_file1 =fopen("traindata.txt","w");  
    printf("\n------------------------------------");
    printf("\n     Train RECORDS  (CURRENT)      ");
    printf("\n-----------------------------------");
    printf("\n     ID      |       NAME        ");
    printf("\n----------------------------------\n");
    
    int i=0;
   
  while (1)
    { 
                 //printf("\n No    |    ID      |       NAME        |      PRICE    |   QUANTITY  |   Type   ");    
  printf(" %6d        %15s    \n",go->id,go->name);
    fprintf(ptr_file1, "%6d  %15s \n",go->id,go->name);
     if (go->next==NULL)
    {
        break;
    }
  go=go->next;
    
    i++;
    printf("\n");
    }
    fclose(ptr_file1);
    fclose(ptr_file2);
    // con();

 }

void printandwriteTrain(double *head){
   struct nodetrain *go=head;
     FILE *ptr_file1;
    ptr_file1 =fopen("traindata.txt","w"); 

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






void delete(){
    readtrain(1);
    system("color 0e");
    time_t t;
    time(&t);
   
    FILE *ptr_file2;
    ptr_file2 =fopen("report.txt","a"); 
     char type[16]="DELETE";
    double *head=load_train_data();
    struct nodetrain *go=head;
    int p;
    printf("Enter train ID which you want to delete : ");
	scanf("%d",&p);
    int c=1;
    while (1)
    { 
        if (go->next==NULL)
        {
            break;
        }
         
         if (go->id==p)
        {
            fprintf(ptr_file2, "   %6d             %15s             %s \n",go->id,go->name,type,ctime(&t));
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
    }else{

    
            
                // Find previous node of the node to be deleted 
                for (int i=0; temp!=NULL && i<position-2; i++) 
                    temp = temp->next; 
            
                // If position is more than number of nodes 
                if (temp == NULL || temp->next == NULL) 
                    return; 
            
                // Node temp->next is the node to be deleted 
                // Store pointer to the next of node to be deleted 
                struct nodetrain *next = temp->next->next; 
            
                // Unlink the node from linked list 
                free(temp->next);  // Free memory 
            
                temp->next = next;  // Unlink the deleted node from list 
                go=head;
                printandwriteTrain(head);
    }


    fclose(ptr_file2);

  // con();
}







int main()
{
	// printf("%d",count("traindata.txt"));
	// readtrain(0);
    //  insertrain();
//    searchTrain(0,1);
delete();
	return 0;
}







