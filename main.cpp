#include <stdio.h>
#include<graphics.h>
#include <stdlib.h>
#include<conio.h>
//We are going to make a linked list with menu to add at the beginning , in the middle and at the end! also we will implement deleting a node
//The user can choose to view the list!

void begining(int data);
void enddata(int data);
void anywhere(int data,int position);
bool deleteAnywhere(int position);
void printlist();
void callPattern(int patNum);
void wishToContinue(char decision);//a simple logic to ask a user to continue or not
void loopChoices(int choice);//repeats choices to user
//we need to form a custom data type so that we can store two info at a location
//first being the data and the second being the address
struct Node{
int data;
struct Node* next;
};

struct Node *head;//here we declared a global variable called head which is the starting address of our linked list.

int main()
{   //here is a pyramid out of no reason! Lol
    head=NULL;
    int patNum;
    patNum=10; //We need a 10 line pattern
    callPattern(patNum);

    int choice;



    printf("\n\t\t\t\t\t\tWelcome to Ankush's code!\n\n");
    printf("Choose your option from the menu\n");

    printf("1)Add a node at the beginning of the linked list\n");
    printf("2)Add a node at the End of the linked list\n");
    printf("3)Add a node anywhere in the linked list\n");
    printf("4)Delete a node at a specific position\n");
    printf("5)Print your created list\n\n\n");
    scanf("%d",&choice);

    loopChoices(choice);

    return 0;
}

void callPattern(int patNum){
int i,j,k,temp;
temp=patNum;//add the value to the temporary assignment

for(i=1;i<=patNum;i++){
    for(j=1;j<temp;j++){
        printf("      ");
    }
    temp--;
    for(k=1;k<=2*i-1;k++){

        printf("*O*O*O");
    }
    printf("\n");
}

}


void begining(int data){

    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));//create a Temporary variable to store the New node in heap memory
                        //we use typecasting here as malloc returns void type and we need struct pointer type
    temp->data=data;//adds data
    temp->next=head;//this works even when list is empty,the new node's address is now the head's address
    head=temp;//the head's value is temp's value
}

void enddata(int data){

    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    struct Node* temp1=head;

    if(temp1!=NULL){//Check if list empty!
        while(temp1->next!=NULL){//if the list is not empty go forward, temp->Next moves the address pointer from one node to next
            temp1=temp1->next;//the current temp1 points to the nth position
        }
        temp1->next=temp;//the last position now must point to the new node being added
        temp->next=NULL;//the last node must point to NULL
    }
    else{
    temp->next=head;
    head=temp;

    }
}

void anywhere(int data,int position){
    int i;
    struct Node* temp =(struct Node*)malloc(sizeof(struct Node));
    temp->data=data;
    struct Node* temp1= head;

    if(position==1){ //if head is being added
        temp->next=head;
        head=temp;
        return;
    }
    else{
        for(i=1;i<position-1;i++){
            temp1=temp1->next;
        }
        temp->next=temp1->next;//dekho bhai baat aesi hai ki ham ek position phle aaye, uska pointer kiskhaya ,new node now points to the previous node and replaces its position
        temp1->next=temp;//ye same hai jese begining mein head =temp kiya tha, vese hi, reference complete, pichla node attached
}
}

void printlist(){
struct Node* temp=head;

if(head!=NULL){
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
        }
    }
else{
    printf("\nNo list to show! Enter data to show a list!\n");
}
}

bool deleteAnywhere(int position){
struct Node* temp=head;

if(position==1){
    if(head==NULL){
    printf("Nothing to delete! List is Empty!");
    return false;
    }
    else{
        head=temp->next;
        free(temp);
        return true;
    }
}

if(position!=1){
        int i;
        for(i=1;i<position-1;i++){
            temp=temp->next;
        }
        struct Node* temp1=temp->next;
        temp=temp1->next;
        free(temp1);
        return true;
    }


}


void wishToContinue(char decision){
        int choice;
    if(decision=='y'||decision=='Y'){

         printf("\nChoose your option from the menu\n");

    printf("1)Add a node at the beginning of the linked list\n");
    printf("2)Add a node at the End of the linked list\n");
    printf("3)Add a node anywhere in the linked list\n");
    printf("4)Delete a node at a specific position\n");
    printf("5)Print your created list\n\n\n");
    scanf("%d",&choice);

    loopChoices(choice);
    }

    else{

        printf("Thank you for using the linked list generator from AINC.\nYour Program will now be terminated.");
        exit(0);
    }


}
void loopChoices(int choice){

switch(choice){
        case 1: {int i,n,data;
                char decision;
                printf("How many numbers you wish to add!\n");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("Enter the number to add at the beginning \n");
                    scanf("%d",&data);
                    begining(data);
                    printf("Data entered successfully\n\n");
                }

                printf("Do you wish to continue?\n");
                scanf(" %c",&decision);
               wishToContinue(decision);
        }
        case 2: {int i,n,data;
                char decision;
                printf("How many numbers you wish to add!\n");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("Enter the number to add at the End \n");
                    scanf("%d",&data);
                    enddata(data);
                    printf("Data entered successfully\n\n");
                }

                printf("Do you wish to continue?\n");
                scanf(" %c",&decision);
                wishToContinue(decision);
        }

        case 3: {int i,n,data,position;
                char decision;
                printf("How many numbers you wish to add!\n");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("Enter the number to add anywhere \n");
                    scanf("%d",&data);
                    printf("Enter the Position \n");
                    scanf("%d",&position);
                    anywhere(data,position);
                    printf("Data entered successfully\n\n");
                }

                printf("Do you wish to continue?\n");
                scanf(" %c",&decision);
                wishToContinue(decision);
        }

             case 4: {int i,n,position;
                char decision;
                printf("How many nodes you wish to delete!\n");
                scanf("%d",&n);
                for(i=0;i<n;i++){
                    printf("Enter the position to delete \n");
                    scanf("%d",&position);
                    if(deleteAnywhere(position)==true)
                        printf("Data deleted successfully\n\n");
                }

                printf("\nDo you wish to continue?\n");
                scanf(" %c",&decision);
                wishToContinue(decision);
        }
           case 5: {
                char decision;
                printf("Your list is printed as----\n");
                printlist();

                printf("Do you wish to continue?\n");
                scanf(" %c",&decision);
                wishToContinue(decision);
        }
        default: printf("It seems like you entered the wrong Input!\n");
                char decision;
                printf("Do you wish to continue?\n");
                scanf(" %c",&decision);
                wishToContinue(decision);

    }

}
