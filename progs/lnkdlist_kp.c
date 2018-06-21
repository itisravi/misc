#include <stdio.h>
#include <stdlib.h>

struct node {
        int value;
        struct node* next;
};

void delete_list(struct node *first)
{
        struct node *i1=first;
        struct node *i2;
        while (i1) {
                i2=i1->next;
                free(i1);
                i1=i2;
        }
}
void add_to_list (struct node *first, struct node *instance)
{
       struct node *iter=first;
       while(iter->next)
                iter=iter->next;
       iter->next=instance;
}

void print_list (struct node *node)
{
        while(node) {
                printf("%d ",node->value);
                node=node->next;        
        }       
        printf("\n");
}

struct node* reverse_list(struct node *first)
{
        struct node *prev=NULL;
        struct node *cur=first;
        struct node *next;
        while(cur) {
              next=cur->next;
              cur->next=prev;
               prev=cur;
               cur=next;
        }
        return prev;
        
}

struct node *reverse_recursive (struct node *cur, struct node *next)
{
        
        if(next->next!=NULL)
                reverse_recursive(next,next->next);
        next->next=cur;
        return next;
        
        
}
int main (void)
{       int i;
        struct node *instance=NULL;
        struct node *head=NULL;

        head = malloc(sizeof(struct node));
        head->value=1;
        head->next=NULL;

        for (i=2;i<5;i++) {
                             
                instance=malloc(sizeof(struct node));
                instance->value=i;
                instance->next=NULL;                                
                add_to_list(head,instance);
        }

        print_list(head);
        
        //head=reverse_list(head);
        //print_list(head);
        
        head=reverse_recursive(NULL,head);
        print_list(head);

        delete_list(head);
        return 0;
}

