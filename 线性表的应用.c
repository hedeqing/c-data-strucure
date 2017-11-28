#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef  struct student
{
    double num;
    char name[15];
    struct student *next;
}node;
typedef node * linklist;
linklist init()
{
    node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    return head;
}
void display(linklist head)
{
    linklist p;
    p=head->next;
    if(!p)
        printf("the list is empty\n");
    else
    {
        while(p)
        {
            printf("名字是：%s\n",p->name);
            printf("号码是%d\n",p->num);
            p=p->next;
        }
    }
}
linklist find(linklist head,int i)
{
    int j=1;
    linklist p=head;
    if(i<1)
        return NULL;
    while(p&&i!=j)
    {
        p=p->next;
        j++;
    }
    return p;
}
linklist insert(linklist head,char name[20],double num,int i)
{
    linklist p,q;
    q=find(head,i);
    if(!q)
    {
        printf("can not find\n");
        return head;
    }
    else
        {
            p=(node*)malloc(sizeof(node));
            strcpy(p->name,name);
            p->num=num;
        }
        if(i==0)
        {
            p=p->next;
            head=p;
        }
        else
        {
            p->next=q->next;
            q->next=p;
        }
        printf("successful insert\n");
    return head;
}
linklist delete_list(linklist head,char name[20])
{
    linklist p,pre=NULL;
    if(!head)
        {
            printf("the list is empty\n");
            return head;
        }
    p=head;
    while(p&&strcmp(p->name,name)!=0)
    {
        pre=p;
        p=p->next;
    }
    if(p)
    {
        if(!pre)
        head=head->next;
        else
            pre->next=p->next;
            free(p);
    }
    return head;
}
int main()
{
    char name[20];
    int num;
    linklist head;
    int i,j;
    head=init();
    while(1)
    {
        printf("please enter the function:\ninsert :1\ndelete :2\ndisplay :3\n");
        scanf("%d",&i);
        if(i==1)
        {
            printf("please enter the name\n");
            fflush(stdin);
            gets(name);
            printf("please enter the num\n");
            scanf("%d",&num);
            printf("please enter the position\n");
            scanf("%d",&j);
            head=insert(head,name,num,j);
        }
        if(i==2)
        {
            printf("please enter the name\n");
            gets(name);
            head=delete_list(head,name);
        }
        if(i==3)
        {
            display(head);
        }

    }

/*
    display(head);
    gets(name);
    scanf("%d",&num);
    printf("\n");
    head=insert(head,name,num,1);
    head=insert(head,"张",13156,2);
    display(head);
    head=delete_list(head,"张");
    display(head);*/
    return 0;
}

