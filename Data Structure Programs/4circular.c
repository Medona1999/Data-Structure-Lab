#include<stdio.h>
#define maxsize 25
void insert();
void search();
void delete();
void display();
int front=-1,rear=-1;
int q[maxsize];
void main()
{
int ch,n;
while(ch!=5)
{
printf("\nCIRCULAR QUEUE OPERATIONS ");
printf("\n1.INSERT 2.SEARCH
3.DELETE 4.DISPLAY 5.EXIT");
printf("\nENTER THE CHOICE: ");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert();
break;
case 2:
search();
break;
case 3:
delete();
break;
case 4:
display();
break;27
case 5:
exit(0);
break;
default:
printf("\nINVALID CHOICE");
}
}
}
void insert()
{
int item;
printf("ENTER ELEMENT TO BE INSERTED:");
scanf("%d",&item);
if(front==0 && rear==(maxsize-1))
{
printf("\nOVERFLOW");
return;
}
else
{
rear=(rear+1) % maxsize;
q[rear]=item;
}
if(front==-1) front=0;
printf("Element inserted\n");
}
void search()
{
int item,i,flag=0;
printf("ENTER THE ELEMENT TO BE SEARCHED: ");
scanf("%d",&item);
for(i=front;i<=rear;i++)
{
if(item==q[i])
{
printf("THE ELEMENT WAS FOUND AT : %d ",i+1);
printf("\n");
flag++;
}
}
if(flag==0)
{28
printf("SUCH AN ELEMENT DOESNOT EXIT");
printf("\n");
}
}
void delete()
{
int item; if(front==-1)
{
printf("\nUNDERFLOW");
return;
}
else
{
item=q[front];
if(front==rear)
{
front=-1; rear=-1;
}
else
front=(front+1) % maxsize;
}
printf("ELEMENT DELETED IS %d",item);
printf("\n");
}
void display()
{
int i;
if(rear==-1)
printf("\nEMPTY QUEUE");
else
{
printf("THE QUEUE ELEMENTS ARE : ");
for(i=front;i<=rear;i++)
{
printf("%d\t",q[i]);
}
}
printf("\n");
}