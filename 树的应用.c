#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef   struct STree
{
    int key;
    int price;
    struct STnode *lchild;
    struct STree *rchild;
}STnode;
typedef STnode *tree;
tree insert(tree *t,int x,int price)
{
    tree f=NULL,p;
    p=*t;
    while(p)
    {
        if (price==p->price)  return ;
        f=p;
        p=(price<p->price)?p->lchild:p->rchild;
    }
    p=(tree)malloc(sizeof(STnode));
    p->key=x;
    p->price=price;
    p->lchild=p->rchild=NULL;
    if(*t==NULL)  *t=p;
        else
            if(price<f->price)
                f->lchild=p;
            else f->rchild=p;
}
tree create_tree()
{
    tree t=NULL;
    int key,price;
    printf("please enter -1 for ending\n");
    scanf("%d",&key);
    while(key!=-1)
    {
        scanf("%d",&price);
        insert(&t,key,price);
        printf("successful\n");
        printf("please enter the key\n");
        scanf("%d",&key);
    }
    return t;
}
void inorder(tree t)
{
    if(t)
    {
        inorder(t->lchild);

        printf("%d\n",t->key);
        printf("%d\n",t->price);
        inorder(t->rchild);
    }
}
int main()
{
    tree t;
    t=create_tree();
    inorder(t);
    return 0;
}
