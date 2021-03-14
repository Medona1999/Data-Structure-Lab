#include <stdio.h>
#include <stdlib.h>
void push();
void pop();
void search();
void display();32
struct node
{
int val;
struct node *next;
};
struct node *head; void main ()
{
int choice=0; while(choice != 5)
{
printf("\n\nSINGLY LINKED LIST OPERATIONS");
printf("\n1.PUSH 2.POP 3.SEARCH 4.DISPLAY 5.EXIT");
printf("\n ENTER CHOICE : "); scanf("%d",&choice); switch(choice)
{
case 1:
{
push();
break;
}
case 2:
{
pop();
break;
}
case 3:
{
search();
break;
}
case 4:
{
display();
break;
}
case 5:
{
exit(0);
break;
}
default:
{
printf("INVALID CHOICE");
}
};33
}
}
void push ()
{
int val;
struct node *ptr = (struct node*)malloc(sizeof(struct node));
if(ptr == NULL)
{
printf("CANT PUSH ELEMENT");
}
else
{
printf("ENTER ELEMENT TO BE PUSHED: ");
scanf("%d",&val); .
if(head==NULL)
{
ptr->val = val;
ptr -> next = NULL;
head=ptr;
}
else
{
ptr->val = val;
ptr->next = head;
head=ptr;
}
printf("ELEMENT PUSHED");
}
}
void pop()
{
int item;
struct node *ptr; if (head == NULL)
{
printf("UNDERFLOW");
}
else
{
item = head->val;
ptr = head;
head = head->next;
free(ptr);34
printf("ELEMENT POPPED");
}
}
void search()
{
struct node *ptr;
int item,i=0,flag;
ptr = head;
if(ptr == NULL)
{
printf("\nEMPTY LIST\n");
}
else
{
printf("\nENTER ELEMENT TO BE SEARCHED : ");
scanf("%d",&item);
while (ptr!=NULL)
{
if(ptr->val == item)
{
printf("ELEMENT FOUND AT LOCATION: %d ",i+1);
flag=1;
}
i++;
ptr = ptr -> next;
}
if(flag==0)
{
printf("SUCH AN ELEMENT DOESNOT EXIST\n");
}
}
}
void display()
{
int i;
struct node *ptr;
ptr=head;
if(ptr == NULL)
{
printf("STACK IS EMPTY\n");
}
else
{35
printf("THE STACK ELEMENTS ARE:\n");
while(ptr!=NULL)
{
printf("%d\n",ptr->val);
ptr = ptr->next;
}
}
}