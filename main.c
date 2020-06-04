#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head;

void create(int a[],int n)
{
    int i;
    struct node *t,*last;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}
void rdisplay(struct node *p)
{
    static int f=0;
    if(p!=head || f==0)
    {
        f=1;
        printf("%d ",p->data);
        rdisplay(p->next);
    }
    f=0;
}
void display(struct node *p)
{
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}
int length(struct node *p)
{
    int l=0;
    do
    {
        l++;
        p=p->next;
    }while(p!=head);
    return l;
}
void insert(struct node *p,int pos,int x)
{
    struct node *t;
    int i;
    if(pos<0 || pos>length(p))
    {
        return;
    }
    if(pos==0)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        if(head==NULL)
        {
            head=t;
            head->next=head;
        }
        else
        {
            while(p->next!=head)
            {
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else
    {
        for(i=0;i<pos-1;i++)
        {
            p=p->next;
        }
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}
int deletee(struct node *p,int pos)
{
    struct node *q;int i,x;
    if(pos<0 || pos>length(head))
        return;
    if(pos==1)
    {
        while(p->next!=head)
        {
            p=p->next;
        }
        x=head->data;
        if(p==head)
        {
            free(head);
            head=NULL;
        }
        else
        {
            p->next=head->next;
            free(head);
            head=p->next;
        }
    }
    else
    {
        for(i=2;i<=pos-1;i++)
        {
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}
int main()
{
  int a[]={2,3,4,5,6};
  create(a,5);
  display(head);

  //insert(head,2,10);
  display(head);

  deletee(head,4);
  display(head);
}
