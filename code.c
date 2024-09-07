#include<stdio.h>
#include<stdlib.h>
struct node
{
    char name[50];
    int svcno;
    int read;
    struct node*next;
};
struct node*head=NULL;
void insert();
void display();
void main()
{
    int opt;
    int ch=1;
    while(ch)
    {
        printf("MENU");
        printf("\n 1.Insert the details");
        printf("\n 2.display the current bill");
        printf("\n choose any option");
        scanf("%d",&opt);
         switch(opt)
         {
             case 1:insert();
             break;
             case 2:display();
             break;
             default:printf("\n wrong option");
         }
         printf("\n do u want to continue");
         scanf("%d",&ch);
    }
}
void insert()
{
    struct node*newnode;
    int val;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\n enter user details");
    scanf("%d",&val);
    newnode->svcno=val;
    newnode->read=0;
    scanf("%s",newnode->name);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    printf("\n node inserted successfully");
}
void display()
{
    struct node*temp;
    int n,reads,amt,t;
    if(head==NULL)
    {
        printf("\n list is empty");
    }
    else
    {
        temp=head;
        printf("enter service no:");
        scanf("%d",&n);
        while(temp!=NULL)
        {
            if(temp->svcno==n)
            break;
            temp=temp->next;
        }
        if(temp==NULL)
         printf("service number not found");
        else{
         printf("%d\n %s\n",temp->svcno,temp->name);
         printf("enter the reading:");
         scanf("%d",&t);
          if(temp->read<t){
            reads=t-temp->read;
           if (reads<=100)
           {
            amt=reads*1.5;
            }
          else if (reads>100 && reads<=200)
            {
            amt=150+(reads-100)*2;
              }
           else if (reads>200)
            {
            amt=350+(reads-200)*3;
                }

         printf("svc no \t name \t previous_read \t current_read \t amount\n");
         printf("%d \t %s \t %d \t \t %d \t \t %d\n",temp->svcno,temp->name,temp->read,t,amt);
          temp->read=t;
       }
       else
        printf("\nenter correct readings\n");
     }
  }
}
