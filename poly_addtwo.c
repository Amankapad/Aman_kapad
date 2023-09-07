//add of two polynomial
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    int power;
    struct node*next;
};

struct node*start1=NULL,*start2=NULL,*start3=NULL;

struct node*insertion(struct node*start)
{
    int a,c,p,i;
    struct node *ptr;
    printf("Give no of terms\n");
    scanf("%d",&a);
    //printf("Hello");
    for(i=0;i<a;i++)
    {
        printf("Give cofficient then power\n");
        struct node newnode=(struct node)malloc(sizeof(struct node));
        scanf("%d %d",&newnode->data,&newnode->power);
        newnode->next=NULL;   
        if(start==NULL)
        {
            start=ptr=newnode;
        }
        else{
            ptr->next=newnode;
            ptr=ptr->next;
        }
    }
    return start;
}

void display(struct node*start)
{
    struct node *ptr=start;
    while(ptr!=NULL)
    {
        if(ptr->power==1)
        {
            printf("%dx",ptr->data);
        }
        else if(ptr->power!=0)
        {
            printf("%dx^%d",ptr->data,ptr->power);
        }
        else{
            printf("%d",ptr->data);
        }
        if(ptr->next!=NULL)
        {
            printf(" + ");
        }
        ptr=ptr->next;
    }
    printf("\n");
}
struct node*result(struct node*start1,struct node*start2)
{
    struct node *ptr1=start1, *ptr2=start2 ,*ptr3=start3;
    while( ptr1!=NULL && ptr2!=NULL )
    {
      struct node*new_node=(struct node*)malloc(sizeof(struct node));
      new_node->next=NULL;
      if((ptr1->power)>(ptr2->power))
      {
         new_node->data=ptr1->data;
         new_node->power=ptr1->power;
         if(start3==NULL)
         {
            start3=ptr3=new_node;
         }
         else
         {
            ptr3->next=new_node;
            ptr3=ptr3->next;
         }
        ptr1=ptr1->next;
      }
      else if((ptr2->power)>(ptr1->power))
      {
        new_node->data=ptr2->data;
        new_node->power=ptr2->power;
        if(start3==NULL)
      {
        start3=ptr3=new_node;
      }
      else
      {
        ptr3->next=new_node;
        ptr3=ptr3->next;
      }
      ptr2=ptr2->next;
      }
      else
      {
        new_node->data=(ptr1->data+ptr2->data);
        new_node->power=(ptr1->power+ptr2->power);
        if(start3==NULL)
        {
            start3=ptr3=new_node;
        }
        else
        {
            ptr3->next=new_node;
            ptr3=ptr3->next;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
      }
    }
    return start3;
}

int main()
{
    printf("Give equation\n");
    start1=insertion(start1);
    printf("Give equation\n");
    start2=insertion(start2);
    printf("The result is:\n");
    start3=result(start1,start2);
    display(start1);
    display(start2);
    display(start3);
    return 0;
}
