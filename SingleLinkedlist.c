/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
void addFirst();
void display();
struct node{
    int info;
    struct node *ptr;
};
typedef struct node node;
node *head=NULL,*tail=NULL,*temp;
node* createNode();
node* createNode(){
    temp=(node *) malloc(sizeof(node));
    if(temp==NULL){
        printf("Node is not Created");
        return;
    }
    printf("Enter data:");
    scanf("%d",&temp->info);
    temp->ptr=NULL;
    return temp;
}

main()
{
    int ch;
    while(10){
        printf("\nEnter \n 1 for addFirst \n 2 for addLast \n 3 for insertmiddle \n 4 for display \n 5 for deletefirst \n 6 fro deletelast\n 7 for size\n 8 for exit ");
        scanf("%d",&ch);
   
       switch(ch){
           case 1:addFirst(); break;
           case 2:addLast(); break;
           case 3:insertMiddle(); break;
           case 4:display(); break;
           case 5:deleteFirst(); break;
           case 6:deleteLast(); break;
           case 7:deleteMiddle(); break;
           case 8:sizeoflist(); break;
           case 9:exit(10); 
           
       }
   } 
    
}
void addFirst(){ //node * addFirst(){ return head;

    node *t;
    t=createNode();
    if(head==NULL){
        head=t;
        tail=t;
    }
    else{
        t->ptr=head;
        head=t;
    }
}
void display(){
    temp=head;
    printf("%u",temp);
    while(temp!=NULL){
        printf("-> || %d - %u", temp->info, temp->ptr);
        temp=temp->ptr;
    }
}
void addLast(){  //node *addLast(){ return tail
    node *t;
    if(head==NULL){
        head=createNode();
        tail=head;
    }
    t=createNode();
    tail->ptr=t;
    tail=t;
}
void deleteFirst(){
    if(head==NULL){
        printf("\n\nList is empty");
        return;
    }
    if(head==tail){
        head=tail=NULL;
    }
    else{
        head=head->ptr;
    }
}

void deleteLast(){
node *prev;
node *th;
    if(head==NULL){
        printf("List is Empty");
    }
    else if(head==tail){
        head=tail=NULL;
    }
    else{
        th=head;
        if(th->ptr!=NULL){
            prev=th;
            th=th->ptr;
        }
        prev->ptr=NULL;
        tail=prev;
    }
}

int sizeoflist(){
    node *th=head;
    int count=0;
    while(th!=NULL){
        count++;
        th=th->ptr;
    }
    
    return count;
}
void insertMiddle(){
    int pos,i=0;
    node *tins;
    node *temp;
 
    node *th=head;
    int count=sizeoflist();
    printf("Enter the position of the element you want to insert:  ");
    scanf("%d",&pos);
    if(pos<=0)
    {
        addFirst();
        
        return;
    }
    else if(pos>count){
        addLast();
        return;
    }

       tins=createNode();
        while(pos>1){
            temp=th;
            th=th->ptr;
        }
            tins->ptr=th->ptr;
            temp->ptr=tins;
            
        
    
    printf("%d is inserted", tins->info);
    
    
}

void deleteMiddle(){
    int pos,count,pos2;
    node *th, *th2;
    count=sizeoflist();
    printf("Enter the position of the node: ");
    scanf("%d",&pos);
    if(pos<=0){
        deleteFirst();
        return;
    }
    else if(pos>=count){
        deleteLast();
        return;
    }
    th=head;
    pos2=pos;
    while(pos>1){
        th=th->ptr;
        pos--;
    }
    th2=head;
    while(pos2>=0){
        th2=th2->ptr;
        pos2--;
    }
    th->ptr=th2;
}







