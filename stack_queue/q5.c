#include <stdio.h>  
  
# define max 6  
int queue_1001[max];   
int front_1001=-1;  
int rear_1001=-1;  
 
void enqueue(int element_1001)  
{  
    if(front_1001==-1 && rear_1001==-1) 
    {  
        front_1001=0;  
        rear_1001=0;  
        queue_1001[rear_1001]=element_1001;  
    }  
    else if((rear_1001+1)%max==front_1001)    
    {  
        printf("Queue is overflow..");  
    }  
    else  
    {  
        rear_1001=(rear_1001+1)%max;       
        queue_1001[rear_1001]=element_1001;      
    }  
}  
 
int dequeue()  
{  
    if((front_1001==-1) && (rear_1001==-1))   
    {  
        printf("\nQueue is underflow..");  
    }  
 else if(front_1001==rear_1001)  
{  
   printf("\nThe dequeued element is %d", queue_1001[front_1001]);  
   front_1001=-1;  
   rear_1001=-1;  
}   
else  
{  
    printf("\nThe dequeued element is %d", queue_1001[front_1001]);  
   front_1001=(front_1001+1)%max;  
}  
}  
 
void display()  
{  
    int i_1001=front_1001;  
    if(front_1001==-1 && rear_1001==-1)  
    {  
        printf("\n Queue is empty..");  
    }  
    else  
    {  
        printf("\nElements in a Queue are :");  
        while(i_1001<=rear_1001)  
        {  
            printf("%d  ", queue_1001[i_1001]);  
            i_1001=(i_1001+1)%max;  
        }  
    }  
}  
int main()  
{  
    int choice_1001=1,x_1001;  
      
    while(choice_1001<4 && choice_1001!=0)    
    {  
    printf("\n Press 1: Insert an element");  
    printf("\nPress 2: Delete an element");  
    printf("\nPress 3: Display the element");  
    printf("\nEnter your choice");  
    scanf("%d", &choice_1001);  
      
    switch(choice_1001)  
    {  
          
        case 1:  
      
        printf("Enter the element which is to be inserted");  
        scanf("%d", &x_1001);  
        enqueue(x_1001);  
        break;  
        case 2:  
        dequeue();  
        break;  
        case 3:  
        display();  
  
    }}  
    return 0;  
}  