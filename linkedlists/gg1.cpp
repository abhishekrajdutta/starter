// A simple C program to introduce
// a linked list
#include<stdio.h>
#include<stdlib.h>
using namespace std;
 
struct Node 
{
  int data;
  struct Node *next;
};

void printList(struct Node *n)
{
  while (n != NULL)
  {
     printf(" %d ", n->data);
     n = n->next;
  }
}

void fInsert(struct Node** head_ref,int newdata)
{
  struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
   
  temp->data=newdata;
  temp->next=*head_ref;
  *head_ref=temp;

}
 
void pInsert(struct Node** head_ref, int newdata, int pos)
{ 
  struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
  struct Node *newnode=(struct Node*)malloc(sizeof(struct Node));
  
  temp->next=*head_ref;
  for (int tag=0;tag<pos;tag++)
    temp=temp->next;

  newnode->data=newdata;
  newnode->next=temp->next;
  temp->next=newnode;

}

void lInsert(struct Node** head_ref, int newdata)
{
  struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
  temp->data=newdata;
  temp->next=NULL;

  struct Node *last=*head_ref;
  
  while(last->next!=NULL)
    last=last->next;

  last->next=temp;

}

void numDeletion(struct Node **head_ref, int delData)
{
  struct Node *index=*head_ref,*prev;
  while (index!=NULL)
  {
    if (index->data==delData)
      break;
    prev=index;
    index=index->next;
  }

  prev->next=index->next;
  free(index);

}

void swap(struct Node** head_ref, int a, int b)
{
  struct Node *indexa=*head_ref,*indexb=*head_ref,*preva=NULL,*prevb=NULL,*temp=(struct Node*)malloc(sizeof(struct Node));
  int founda=0,foundb=0;

  
  while(indexa!=NULL && indexb!=NULL)
  {

    if (indexa->data!=a)
    {
      preva=indexa;
      indexa=indexa->next;
    }
    else 
      founda=1;


    if (indexb->data!=b)
    {
      prevb=indexb;
      indexb=indexb->next;
    }
    else 
      foundb=1;

    if (founda==1 && foundb==1)
      break;
  }

  if (preva==NULL)
    {
      *head_ref=indexb;
      prevb->next=indexa;
    }
  else if (prevb==NULL)
    {
      *head_ref=indexa;
      preva->next=indexb;
    }
  else
  {
    preva->next=indexb;
    prevb->next=indexa;
    
  }

  temp=indexb->next;
  indexb->next=indexa->next;
  indexa->next=temp;

}

void reverse(Node **head_ref)
{
  struct Node *prev=NULL,*temp=NULL,*current=*head_ref;
  while (current!=NULL)
  {
    temp=current->next;
    current->next=prev;
    prev=current;
    current=temp;
  }
  *head_ref=prev;
}


int main()
{
  

  struct Node *head = NULL;
  fInsert(&head,0);
  fInsert(&head,1);
  fInsert(&head,2);
  fInsert(&head,3);

  
  printf("\nnew array\n");  
  printList(head);
  printf("\ninsertion\n");
  pInsert(&head,100,2);
  printList(head);
  printf("\n endsertion\n");
  lInsert(&head,5);
  printList(head);
  printf("\n deletion\n");
  numDeletion(&head,100);
  printList(head);
  printf("\n swap\n");
  swap(&head,3,5);
  printList(head);
  printf("\n reverse\n");
  reverse(&head);
  printList(head);
  return 0;
}