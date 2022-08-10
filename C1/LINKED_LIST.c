/*write a c program to insert, delete at a particular position*/
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct ele
{
	int item;
	struct ele *next;
};
typedef struct ele node;

main()
{
	node *HEAD = NULL,*new,*temp,*temp1;
	int a[20],n,ch,pos,len=0,i;
	while(i)
	{
		printf("/n menu__...........");
		printf("1.creatiopn,2.insertion,3.deletion,4.display,5.reverse,6.exit./n");
		printf("enter your choice:/n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: /*creation of linked list*/
					if(HEAD!=NULL)
					printf("/n sll is aldready created");
					else
					{
						HEAD=(node*) malloc (sizeof(node));
						printf("/n enetr the first element");
						scanf("%d",&HEAD->item);
						HEAD->next=NULL;
						len++;
		     		}
		     		break;
		     
		     case 2: /*inserting at a particular position.*/
		     		if(HEAD==NULL)
		     		printf("/n sll is not created.");
		     		else
		     		{
		     			printf("/n length of the linked list is:%d",len);
		     			printf("/n enter the position");
		     			scanf("%d",&pos);
		     			temp=HEAD;
		     			if(pos>len+1)
		     			printf("/n position does not exist");
		     			else
		     			{
		     				new=(node*)malloc(sizeof(node));
		     				printf("/n enter the element to insert:");
		     				scanf("%d",&n);
		     				new->item=n;
		     				new->item=NULL;
		     				if(pos == 1 ) /*insertion at begining*/
		     				{
		     					new->next = HEAD;
		     					HEAD = new;
		     					len++;
						     }
						     else
						     if(pos==len+1)/*insertion at end position*/
						     {
						     	while(temp->next!=NULL)
						     	temp = temp->next;
						     	temp->next=new;
						     	len++;
							 }
							 else/*insertion at the particular position*/
							 {
							 	for(i=1;i<pos-1;i++)
							 	temp = temp->next;
							 	
							 	new ->next= temp->next;
							 	temp->next = new;
							 	len++;
							 }	 
						}
					 }
					 break;
			case 3: /*deletion a node at a particular position*/
					if(HEAD == NULL)
					printf("/n sll is empty.");
					else
					{
						temp= HEAD;
						printf("length of the linked list is:%d",len);
						printf("enter the position to delete");
						scanf("%d",&pos);
						if(pos>len)
						printf("position does not exist.");
						else
						{
							if(pos == 1)  /*deletion at the beginning*/
							{
								printf("/n %d is deleted",temp->item);
								HEAD = temp->next;
								free(temp);
								len--;
							}
							else
							{
								if(pos == len)  /*deletion at the ending*/
								{
									while(temp->next->next!=NULL)
									temp=temp->next;
									printf("/n %d is deleted",temp->next->item);
									free(temp->next);
									temp->next=NULL;
									len--;
								}
								else /*deletion at a particular position*/
								{
									for(i=1;i<pos-1;i++)
									temp=temp->next;
									printf("%d is deleted",temp->next->item);
									temp1=temp->next;
									temp->next=temp1->next;
									free(temp1);
									len--;
								}
						
							}
						}
					}
					break;
			case 4: /*display the elements.*/
					if(HEAD == NULL)
					printf("single limked list is empty");
					else
					{
						temp= HEAD;
						printf("/n single linked list elements are:");
						printf("HEAD ->");
						while(temp!= NULL)
						{
							printf("\t |%d|",temp->item);
							temp=temp->next;
						}
						printf("<- NULL /n");
					}
					break;
			case 5: /* reversing the sll elements*/
					if(HEAD == NULL )
					printf("/n sll is empty");
					else
					{
						i=1;
						temp = HEAD;
						while(temp!= NULL)
						{
							a[i]= temp-> item;
							temp= temp->next;
							i++;
						}
						printf("/n sll is in revers order:/n");
						printf("NULL->");
						for(n=1;n>0;n--)
						printf("\t |%d|",a[n]);
						printf(" <- HEAD");
					}
					break;
			case 6:exit(0);
					break;
					default:printf("invalid position");
					break;											 
		}		
	}
	getch();
}
