/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>
void addFirst();
void addLast();
void insertMiddle();
void display();
void reverseData();
void deleteFirst();
void deleteLast();
void deleteMiddle();
int sizeofList();
void evenNumberCount();
void oddNumberCount();
void polindrome();
void findKey();

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
        
    }
    else{
    printf("Enter data:");
    scanf("%d",&temp->info);
    temp->ptr=NULL;
    return temp;
    }
}

void main()
{
    int ch,ope;
    while(10){
        printf("\nEnter \n 1 for addFirst \n 2 for addLast \n 3 for insertmiddle \n 4 for display \n 5 for reverseData \n 6 for deletefirst \n 7 fro deletelast\n 8 for deletemiddle \n 9 for size\n 10 for extra operations \n 11 for exit ");
        scanf("%d",&ch);
   
       switch(ch){
           case 1:addFirst(); break;
           case 2:addLast(); break;
           case 3:insertMiddle(); break;
           case 4:display(); break;
           case 5:reverseData(head); break;
           case 6:deleteFirst(); break;
           case 7:deleteLast(); break;
           case 8:deleteMiddle(); break;
           case 9:sizeofList(); break;
           case 10: 
               printf("\n\nEnter \n 1 for polyndrome count \n 2 for even number count \n 3 for odd number count \n 4 for find key:");
                scanf("%d",&ope);
                switch(ope){
                    case 1: polindrome(); break;
                    case 2: evenNumberCount(); break;
                    case 3: oddNumberCount(); break;
                    case 4: findKey(); break;
                }
                break;
                
           case 11:exit(10); 
           
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

int sizeofList(){
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
    int count=sizeofList();
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
    count=sizeofList();
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
void reverseData(node *p){
    if(p){
        reverseData(p->ptr);
        printf("%d",p->info);
    }
    
}
void evenNumberCount(){
    
    int c=0;
    node *th=head;
    while(th!=NULL){
        if((th->info)%2==0){
            c++;
        }
        th=th->ptr;
    }
    printf("The count of even numbers is %d",c);
}
void oddNumberCount(){
    int c=0;
    node *th=head;
    while(th!=NULL){
        if(th->info%2!=0){
            c++;
        }
        th=th->ptr;
    }
        printf("The count of odd number is %d", c);
    
}
void polindrome(){
    node *p=head;
    int rem,rev;
    int c=0;
    while(p!=NULL){
        rev=0;
        int ori=p->info;
        int temp=p->info;
        while(temp!=0){
            rem=temp%10;
            rev=rev*10+rem;
            temp=temp/10;
        }
        
        if(ori == rev){
            printf("1\n");
            ++c;
        }
        p=p->ptr;
    }
    printf("The count of the polyndrome is %d",c);
    
}
void findKey(){
    int key;
    printf("Enter the key value: ");
    scanf("%d",&key);
    node *th=head;
    while(th!=NULL){
        if(th->info==key){
            printf("%d is present in the list",key);
            return;
        }
        else{
            printf("%d is not present in the list",key);
        }
        th=th->ptr;
    }
}










