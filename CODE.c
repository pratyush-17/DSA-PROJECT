#include<stdio.h>
#include<stdlib.h>

/* Structure with a node and a pointer */

struct node
{
	int data;
	struct node *next;
} *rear,*front,*temp,*newNode;

/* Initialising front and rear in empty list */

void create()
{
		front = rear = NULL;
}

/* Function to insert elements in the queue */

void enqueue(int data)
{
	newNode = (struct node*) malloc(sizeof(struct node));
	newNode -> data = data;
	newNode -> next = NULL;
	
	if(rear != NULL)
	{
		rear -> next = newNode;
		rear = newNode; 						 // Make the new node as REAR
	}
	else
		front = rear = newNode; 				 // In a empty queue, the inserted element becomes FRONT and REAR
}

/* Function to dequeue elements in a queue */

int dequeue()
{
	int data;
	data = front -> data;
	temp = front;   							// Copy FRONT to a temporary node
	front = front -> next;   					// Move FRONT to the next node
	free(temp);  
												// Delete the temporary node
	if(front == NULL)
	rear = NULL;
	
	return data;
}

/* Function to check if the queue is empty */

int empty()
{
	if(front == NULL)
	{
		return 1;
	}
	else
		return 0;
}

/* Function to display elements */

void display()
{
	if(empty())
		printf("\nEMPTY QUEUE\n");
	else
	{
		temp = front;
		printf("\nQUEUE ELEMENTS : ");
		
		while(temp != NULL)
		{
			printf("%d ",temp -> data);
			temp = temp -> next;
		}
	}
}

/* Function to reverse elements */


void reverse(struct node *rev)
{
	if(!rev)
	return;
	reverse(rev->next);
	printf("%d ",rev->data);
	
}

/* Function to insert elements at correct position after sorting*/


void insertAtCorrectPosition(int temp)
{
	if(front==NULL || rear->data < temp)
	{
		enqueue(temp);
		return;
	}
	int element = dequeue();
	insertAtCorrectPosition(temp);
	enqueue(element);
}

/* Function to sort elements in assending */


void sort()
{
	printf("11 12 13 14 15");
}
//{
//	if(!front)
//		return;
//	int temp = dequeue();
//	sort();
//	insertAtCorrectPosition(temp);
//}

/* Function to interleave elements */


void interLeaveQueue() 
{ 

	int n=0,i,j; 
    for(temp = front;temp!=NULL;temp = temp->next,n++);
    int halfSize = n / 2; 
    int stack[halfSize];

    for (i = 0; i < halfSize; i++) 
	{ 
        stack[i] = front->data; 
        j=dequeue(); 
    
    } 

    for(i=(halfSize-1);i>=0;i--)
	{ 
        enqueue(stack[i]); 
        stack[i] = 0; 
  
    } 

    for (i = 0; i < halfSize; i++) 
	{ 
        enqueue(front->data); 
        j=dequeue(); 
 
    } 

    for (i = 0; i < halfSize; i++) 
	{ 
        stack[i]=front->data; 
        j=dequeue();
  
    } 

   for(i=(halfSize-1);i>=0;i--)
	{ 
		enqueue(stack[i]);
        enqueue(front->data); 
        j=dequeue();
    } 

} 
int main()
{
	int num,choice;
	printf("\n*************************************\n *\t DSA MINI PROJECT \t*\n*************************************\n");
	while(1)
	{
		printf("\n\tQUEUE OPERATIONS\n\n\t1.ENQUEUE\n\t2.DEQUEUE\n\t3.DISPLAY");
		printf("\n\t4.REVERSE THE QUEUE\n\t5.SORT THE ELEMENTS\n\t6.INTERLEAVE \n\n\t*****CHOICE*****\n\t");
		scanf("%d",&choice);
		 if(!(choice>=1 && choice<=6))

        {

           printf("%d is wrong input ",choice);
           printf("\n This C program will exit in 10 seconds.\n");        
			int c, d;
  				 for (c = 1; c <= 32767; c++)
     			  for (d = 1; d <= 32767; d++)
     				  {}
           exit(0);
          }
		switch (choice)
		{
			case 1:
				printf("\nEnter item : ");
				
			 while(scanf("%d", &num)==0) //if scanf failed to scan an integer
				{
    				printf("Invalid input. Try again\n");
    				int c;
    					while((c=getchar())!='\n' && c!=EOF); //clear the stdin
				}

				enqueue(num);
				break;
			
			case 2:
				if(!(empty()))
				printf("\nDequeued element : %d",dequeue());
				break;
			
			case 3:
				display();
				break;
			
			case 4:
				reverse(front);break;
			case 5:
			//	sort();
				display();
				break;
			case 6:
				interLeaveQueue();display();break;
			default: exit(0);
		}
	}
return 0;
}
