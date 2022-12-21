#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char* data;
    struct node* link;
}node;

node* front = NULL;
node* rear = NULL;

// NULL checking for dynamic memory allocation of node pointers

void null_check(node* ptr)
{
    if(ptr==NULL)
    {
        printf("DYNAMIC MEMORY NOT ALLOCATED!!!\n");
        exit(0);
    }
    return;
}

// NULL checking for dynamic memory allocation of char pointers

void null_check_char(char* ptr)
{
    if(ptr==NULL)
    {
        printf("DYNAMIC MEMORY NOT ALLOCATED!!!\n");
        exit(0);
    }
    return;
}

// Creation of new node

node* new_node(char* data)
{
    node* temp = malloc(sizeof(node));
    null_check(temp);
    temp->data = data;
    temp->link = NULL;

    return temp;
}

// Enqueuing the passwords

void enq(char* data)
{
    node* temp = new_node(data);

    if(front==NULL && rear==NULL)
    {
        front=rear=temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
    return;
}

// Dequeuing the password

char* deq()
{
    if(front==NULL)
    {
        printf("UNDERFLOW!!!\n");
        exit(0);
    }
    else
    {
        node* temp = front;
        char* p = front->data;
        front=front->link;
        free(temp);
        temp=NULL;
        return p;
    }

}

// Printing the passwords stored in the queue

void print(node* front)
{
    node* ptr= front;
    while(ptr)
    {
        printf("%s ", ptr->data);
        ptr=ptr->link;
    }
    return;
}

// Checking whether the password entered is same as that of last three passwords or not

node* check(char* data)
{
    node* ptr = front;
    int k=0;
    node* temp=malloc(sizeof(node));
    null_check(temp);
    temp->link=NULL;
    while(ptr)
    {
        k=k+1;
        if(strcmp(ptr->data,data)==0)
        {
       {
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("The entered password is matching with the password-%d\n",k);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
            printf("Please enter a different password: ");
            scanf("%s", data);
            node* temp1=check(data);
            temp->data="2";
        }
        ptr=ptr->link;
        }
        else {
            temp->data="1";
            ptr=ptr->link;
        }
    }
    return temp;
}

// Function to change password

int change_pass(int count)
{
    if(count<3)
    {
        char* data1=malloc(50*sizeof(char));
        null_check_char(data1);
        printf("Enter new password: ");
        scanf("%s",data1);
        check(data1);
        enq(data1);
        count++;
    }
    else if(count>=3)
    {
        char* data1=malloc(50*sizeof(char));
        null_check_char(data1);
        printf("Enter new password: ");
        scanf("%s", data1);
        node* c=check(data1);

        enq(data1);
        deq();
        count++;
    }

    return count;
}

// Function to check the security pin

void check_pin(int sp)
{
    int pin = 6069;
    if(sp!=pin)
    {
        printf("Enter the correct pin: ");
        scanf("%d",&sp);
        check_pin(sp);
    }
    return;
}

int main()
{
    int sp,count = 0;
    char* data=malloc(50*sizeof(char));
    null_check_char(data);

    printf("\t----------------------------------------------------------\n");
    printf("\t\t  ***WELCOME TO THE NET-BANKING PORTAL***\n");
    printf("\t----------------------------------------------------------\n\n");
    printf("Enter your security pin to create password: ");
    scanf("%d",&sp);
    check_pin(sp);
    printf("Please create a password for your bank account: ");
    scanf("%s",data);
    printf("----------------------------------------------------------");
    printf("\nPassword successfully updated!!!");
    enq(data);

    while(1)
    {
        printf("\n----------------------------------------------------------");
        printf("\nEnter 1 to change password\nEnter any number to logout of the portal\n\n");
        int choice;
        printf("Please enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
        case 1:
            {
                count=count+1;
                {
                    int c= change_pass(count);
                    printf("----------------------------------------------------------");
                    printf("\nPassword successfully updated!!!");
                    break;
                }
            }

        default:
            {
                printf("\n\n\t\t\t      ***LOGGED OUT***\n\n");
                printf("\t\t   -----------SESSION EXPIRED-----------\n");
                exit(0);

            }
        }
    }

 return 0;
}