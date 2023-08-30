/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
#define MAX 5
void insertr();
void display();
void deleter();
int dq[MAX],front=-1,rear=-1,i;

int main()
{
    int ch;
    while(10){
        printf("\n\nEnter \n 1 for insertr \n 2 for delete \n 3 for display \n 4 for exit:");
        scanf("%d",&ch);
        switch(ch){
            case 1:insertr(); break;
            case 2:deleter(); break;
            case 3:display(); break;
            case 4:exit(10);
        }
    }
}
void insertr(){
    if(front==0 && rear==MAX-1){   //10 20 30 40 50
        printf("\n\nDequeue is overflow");
        return;
    }
    else if(front==-1 && rear==-1){ //- - - - -
        int x;
        printf("\n\nEnter the element");
        scanf("%d",&x);
        rear++;
        dq[rear]=x;
        if(front==-1){
            front=0;
        }
        printf("%d is inserted",x);
    }
    else if(front==0&&rear!=MAX-1){ //10 20 - - -
        int x;
        printf("\n\nEnter the element");
        scanf("%d",&x);
        ++rear;
        dq[rear]=x;
        printf("%d is inserted",dq[rear]);
    }
    else if(front!=0 && rear==MAX-1){ //- - 30 40 50
        int x;
        printf("\n\nEnter the element");
        scanf("%d",&x);
        for(i=front;i<=rear;i++){
            dq[i-1]=dq[i];
            
        }
        dq[i-1]=x;
        --front;
        printf("%d is inserted",x);
    }
}
void display(){
    if(front==-1 && rear==-1){
        printf("Queue is underflow");
        return;
    }
    for(i=front;i<=rear;i++){
        printf("\n%d",dq[i]);
    }
}
void deleter(){
    if(front==-1 && rear ==-1){ //- - - - -
        printf("Queue is underflow");
        return;
    }
    else if(front==rear){//10 - - - -
        int x=dq[rear];
        rear=front=-1;
        printf("%d is deleted",x);
    }
  else if(front==0 && rear !=MAX-1){
        int x=dq[rear];
        rear--;
        printf("\n%d is deleted",x);
        
    }
}
