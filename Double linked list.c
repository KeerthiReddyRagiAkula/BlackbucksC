/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
typedef struct node{
    struct node *lptr,*rptr;
    int info;
}node;
node *head=NULL, *tail=NULL, *temp;
int count=0;
node *createNode(){
    temp=(node *) malloc(sizeof(node));
    if(temp==NULL){
        printf("\n\nNode not created");
        return;
    }
    printf("\n\nEnter data:");
    scanf("%d",&temp->info);
    temp->lptr=NULL;
    temp->rptr=NULL;
    
    return temp;
}
int sizeoflist(){
    node *th=head;
    int count=0;
    while(th!=NULL){
        count++;
        th=th->rptr;
    }
    
    return count;
}


int main()
{
    int ch;
    while(1){
        printf("\n\nEnter\n 1 for insertion \n 2 for deletion \n 3 for display1 \n 4 for diplay2 \n 5 for exit: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:insertion(); break;
            case 2:deletion(); break;
            case 3:display1(); break;
            case 4:display2(); break;
            case 5:exit(10);
        }
    }
}
/*insertion(){
    int pos;
    node *t;
    t=createNode();
    printf("Enter position: ");
    scanf("%d",&pos);
    if(head==NULL && tail==NULL){
        head=t;
        tail=t;
    }
    else if(pos<=0){
        t->rptr=head;
        head->lptr=t;
        head=t;
    }
    else if(pos>sizeoflist()){
        t->lptr=tail;
        tail->rptr=t;
        tail=t;
        
    }
    else{
        node *th=head;
        while(pos>1){
            th=th->rptr;
            pos--;
        }
        t->lptr=th;
        t->rptr=th->rptr;
        t->lptr->rptr=t;
        t->rptr->lptr=t;
    }
}*/
insertion(){
    node *t;
    int pos;
     t=createNode();
    printf("enter position:");
    scanf("%d",&pos);
   
   if(pos <= 0)
   {
    if(head==NULL){
        head=t;
        tail=t;
        //return;
    }
    else{
        t->rptr=head;
        head->lptr=t;
        head=t;
    }
   }
    else if(pos >= sizeoflist()){
        if(tail == NULL)
        {
            head = tail =t;
        }
        else{
        t->lptr=tail;
        tail->rptr=t;
        tail=t;
        }
    }
    else{
        node *th=head;
            th=head;
            while(pos>1){
                th=th->rptr;
                pos--;
            }
            t->lptr=th;
            t->rptr=th->rptr;
            th->rptr->lptr=t;
            th->rptr=t;
        
    }
}

display1(){
    temp=head;
    printf("%u",temp);
    while(temp!=NULL){
        printf("->%u  -   %d   -   %u",temp->lptr, temp->info,temp->rptr);
        temp=temp->rptr;
    }
}
display2(){
    node *th;
    th=tail;
    printf("%u",th);
    while(th!=NULL){
        printf("%u <- %d -> %u",th->rptr,th->info,th->lptr);
        th=th->lptr;
    }
}
deletion(){
    int pos;
    printf("Enter the position:");
    scanf("%d",&pos);
    if(head==NULL && tail==NULL){
        printf("List is empty");
    }
    else if(head==tail){
        head==tail==0;
    }
    else if(pos<=0){
        head=head->rptr;
        head->lptr=NULL;
    }
    else if(pos>=count){
        tail=tail->lptr;
        tail->rptr=NULL;
    }
    else{
        node *th=head;
        while(pos>1){
            th=th->rptr;
            pos--;
        }
        th->rptr->rptr->lptr=th;
        th->rptr=th->rptr->rptr;
    }
    
}










