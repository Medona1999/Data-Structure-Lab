#include<stdio.h>
struct node
{
struct node *left,*right;
int data;
};
void main()
{
struct node *first;
int n,pos,item,ch;
INITIALIZE(&first);
printf("\nCREATING DOUBLY LINKED LIST");
printf("\n ENTER NO.OF NODES : ");
scanf("%d",&n);
CREATE(&first,n);
while(1)
{
printf("\nIMPLEMENTATION OF DOUBLY LINKED LIST");
printf("\n1.INSERTING FIRST NODE 2.INSERTING LAST NODE 3.
INSERTING A NODE AT ANY POSITION 4.DELETING FIRST NODE
5.DELETING LAST NODE 6.DELETING ANY NODE 7.DISPLAY");
printf("\n8.SEARCHING AN ELEMENT 9.EXIT ");
printf("\nENTER CHOICE : ");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\nENTER THE ITEM TO BE INSERTED : ");
scanf("%d",&item);
INSERTFIRST(&first,item);
break;
case 2:
printf("\nENTER THE ITEM TO BE INSERTED : ");
scanf("%d",&item);
INSERTLAST(&first,item);
break;
case 3:
printf("\nENTER THE ITEM TO BE INSERTED : ");
scanf("%d",&item);
printf("\nENTER POSITION OF ITEM : ");40
scanf("%d",&pos);
INSERTATANY(&first,pos,item);
break;
case 4:
DELETEFIRST(&first);
break;
case 5:
DELETELAST(&first);
break;
case 6:
printf("\nENTER NODE NUMBER TO BE DELETED : ");
scanf("%d",&n);
DELETEATANY(&first,n);
break;
case 7:
TRAVERSE(first);
break;
case 8:
SEARCH(&first);
break;
case 9:
exit(0);
}
}
}
INITIALIZE(struct node **first)
{
(*first)==NULL;
}
TRAVERSE(struct node *first)
{
if(first==NULL)
printf("\n EMPTY LIST ");
else
{41
printf("\n TRAVERSING IN FORWARD DIRECTION : ");
printf("FIRST<->"); while(first!=NULL)
{
printf("%d<->",first->data);
first=first->right;
}
printf("LAST \n");
}
}
CREATE(struct node **f,int n)
{
struct node *temp,*current;
int i,item;
for(i=1;i<=n;i++)
{
printf("\n ENTER DATA : ");
scanf("%d",&item);
temp=(struct node*)malloc(sizeof(struct node));
temp->data=item;
temp->right=NULL;
if((*f)==NULL)
{
(*f)=temp;
temp->left=NULL;
}
else
{
current->right=temp;
temp->left=current;
}
current=temp;
}
}
INSERTFIRST(struct node **first,int item)
{
struct node *temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=item;
temp->left=NULL;
if(*first==NULL) temp->right=NULL;
else
{
temp->right=(*first); (*first)->left=temp;
}42
(*first)=temp;
}
INSERTLAST(struct node **first,int item)
{
struct node *current,*temp;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=item;
temp->right=NULL;
if(*first==NULL)
{
temp->left=NULL;
(*first)=temp;
}
else
{
current=(*first);
while(current->right!=NULL)
current=current->right;
temp->left=current;
current->right=temp;
}
}
INSERTATANY(struct node **first,int pos,int item)
{
struct node *temp,*current;
int i;
temp=(struct node*)malloc(sizeof(struct node));
temp->data=item;
if(pos==1)
{
if(*first!=NULL)
(*first)->left=temp;
temp->right=(*first);
temp->left=NULL;
(*first)=temp;
}
else
{
i=2;
current=(*first);
while((i<pos)&&(current->right!=NULL))
{
i++;
current=current->right;
}43
temp->left=current;
temp->right=current->right;
if(current->right!=NULL)
temp->right->left=temp;
current->right=temp;
}
}
DELETEFIRST(struct node **first)
{
struct node *current; int item;
if(*first==NULL)
{
printf("\n EMPTY LIST ");
return;
}
current=(*first);
(*first)=(*first)->right;
if(*first!=NULL)
(*first)->left=NULL;
item=current->data;
free(current);
printf("\n DELETED ITEM IS %d",item);
printf("\n");
}
DELETELAST(struct node **first)
{
struct node *current; int item;
if(*first==NULL)
{
printf("\n EMPTY LIST ");
return;
}
current=(*first);
while(current->right!=NULL)
current=current->right;
if(current->left!=NULL)
current->left->right=current->right;
else
(*first)=NULL;
item=current->data; free(current);
printf("\n DELETED ITEM IS %d",item);
printf("\n");
}44
DELETEATANY(struct node **first,int pos)
{
struct node *current,*previous;
int i=1,item;
if(*first==NULL)
{
printf("\n EMPTY LIST ");
return;
}
current=(*first);
while(current!=NULL)
{
if(i==pos)
{
item=current->data;
if(current->left==NULL)
{
current->right->left=NULL;
(*first)=current->right;
free(current);
}
else if(current->right==NULL)
{
current->left->right=current->right;
free(current);
}
else
{
current->left->right=current->right;
current->right->left=current->left;
free(current);
}
printf("\n DELETED ITEM IS %d",item);
printf("\n");
return;
}
i++;
current=current->right;
}
printf("\n SUCH A NODE NUMBER DOES NOT EXIST ");
}
SEARCH(struct node **first)
{
int i=0,item,flag;45
struct node *temp;
temp=(*first);
if(first==NULL)
{
printf("\n LIST IS EMPTY ");
}
else
{
printf("\n ENTER ELEMENT TO BE SEARCHED : ");
scanf("%d",&item);
while(temp!=NULL)
{
if(temp->data==item)
{
printf("\n ELEMENT FOUND AT %d ",i+1);
printf("\n");
flag=0;
break;
}
else
{
flag=1;
}
i++;
temp=temp->right;
}
if(flag==1)
{
printf("\n ELEMENT NOT FOUND ");
printf("\n");
}
}
}