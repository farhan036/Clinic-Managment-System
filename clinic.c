#include"clinic.h"
#include <stdio.h>
#include <stdlib.h>
node *head=NULL;
void add_new_patient(node **head)
{
node *temp=NULL;
node *current=*head;
temp=(node *)malloc(sizeof(node));
if(temp==NULL)
    {
    printf("error create patient\n");
    }
else
    {
    printf("Enter Name of patient\n");
    fflush(stdin);
    gets(temp->name);
    fflush(stdin);
    printf("Enter age\n");
    scanf("%i",&temp->age);
    printf("Enter gender ============ 0 is female ===== 1 is male \n");
    scanf("%i",&temp->gender);
    while(temp->gender!=1 && temp->gender!=0)
        {
        printf("Enter 0 or 1 please\n");
        scanf("%i",&temp->gender);
        }

   while (1) { // Use an infinite loop and break when a unique ID is found
    node* current = *head;
    int flag = 0; // Reset flag for each new ID input attempt

    printf("Enter ID of patient: ");
    scanf("%i", &temp->id);

    // Check for duplicate ID in the list
    while (current != NULL) {
        if (temp->id == current->id) {
            printf("ID already exists. Enter another ID.\n");
            flag = 1; // Duplicate found
            break; // Exit the inner loop to prompt for a new ID
        }
        current = current->next; // Move to the next node
    }

    if (flag == 0) {
        // No duplicate found, break out of the infinite loop
        break;
    }
}

    fflush(stdin);
    if(*head==NULL)
        {
            *head=temp;
            temp->next=NULL;
        }
        else
        {

           current=*head;
        while(current->next!=NULL)
            {
                current=current->next;

            }
        current->next=temp;
        temp->next=NULL;
        }

    }

}
void print_patients(node *head)
{
node *current=head;



while(current!=NULL)
    {
    printf("Name of patient : %s\n Id : %i\n Age : %i\n",current->name,current->id,current->age);
    switch(current->slot){
    case 1:
    printf(" Time 2:00 -> 2:30\n");
    break;
    case 2:
    printf(" Time 2:30 -> 3\n");
    break;
    case 3:
    printf(" Time 3:00 -> 3:30\n");
    break;
    case 4:
    printf(" Time 4:00 -> 4:30\n");
    break;
    case 5:
    printf(" Time 4:30 -> 5\n");
    break;
    default:
    printf(" Haven't booked an appointment yet\n");
    break;
    }




    if(current->gender==1)
        {
        printf(" Gender : Male\n");
        }
    else {
        printf(" Gender : Female\n");

    }
    printf("==============================================================\n");
    current=current->next;
    }

}

void edit_information(node *head)
{
node *current=head;
int id=-1;
printf("Enter Id to edit information : ");
scanf("%i",&id);
while(current!=NULL&&current->id!=id)
    {
    current=current->next;
    }
if(current==NULL)
    {
    printf("Id not exist\n");
    }
else
{
  printf("Enter Name of patient\n");
    fflush(stdin);
    gets(current->name);
    fflush(stdin);
    printf("Enter age\n");
    scanf("%i",&current->age);
    printf("Enter gender ============ 0 is female ===== 1 is male \n");
    scanf("%i",&current->gender);
    while(current->gender!=1 && current->gender!=0)
        {
        printf("Enter 0 or 1 please\n");
        scanf("%i",&current->gender);
        }
}
}

void reserve_slot(node *head)
{
node *current=head;
node *compared=head;
int id=-1;
printf("Enter Id to reserve slot : ");
scanf("%i",&id);
while(current!=NULL&&current->id!=id)
    {
    current=current->next;
    }
if(current==NULL)
    {
    printf("Id not exist\n");
    }
else
{ printf(" (1) -> 2 to 2:30\n (2) -> 2:30 to 3\n (3) -> 3 to 3:30\n (4) -> 4 to 4:30\n (5) -> 4:30 to 5\n");

  while (1) { // Use an infinite loop and break when a unique ID is found
    compared=head;
    int flag = 0; // Reset flag for each new ID input attempt
     printf("Enter slots of patient: ");
    scanf("%i", &current->slot);
while(current->slot<1 ||current->slot>5)
        {
       printf("Enter slots from 1 to 5 : ");
    scanf("%i", &current->slot);
        }


    while (compared != NULL) {
        if (compared != current && compared->slot == current->slot) {
            printf("slot not avilable. Enter another slot.\n");
            flag = 1;
            break;
        }
        compared = compared->next;
    }

    if (flag == 0) {

        break;
    }
}
}
}
void cancel(node *head)
{
node *current=head;
int id=-1;
printf("Enter Id to cancel reservation : ");
scanf("%i",&id);
while(current!=NULL&&current->id!=id)
    {
    current=current->next;
    }
if(current==NULL)
    {
    printf("Id not exist\n");
    }
else
{
current->slot=0;
}
}
