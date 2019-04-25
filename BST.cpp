#include<stdio.h>
#include<malloc.h>
#include<windows.h>
using namespace std;

typedef struct Node
{
    int date;
    struct Node * lchild,* rchild,*parent;
}Node, * LNode;

void visit(int t)
{
    printf("%d ",t);
}

LNode min(LNode & T)
{
    LNode p=T;
    while (p->lchild)
    {
        p=p->lchild;
    }
    return p;
}

void InOrderTraverseRe(LNode & T)
{
    if(T)
    {
        InOrderTraverseRe(T->lchild);
        visit(T->date);
        InOrderTraverseRe(T->rchild);
    }
}


void Insert (LNode &T, LNode & z)
{
    LNode x,y=NULL;
    x=T;
    if(!T)
    {
        T=z;
        z->parent=NULL;
    }
    else
    {
        while (x)
        {
            y=x;
            if(x->date>z->date)
            {
                x=x->lchild;
            }
            else
            {
                x=x->rchild;
            }
        }
        z->parent=y;
        if(z->date<y->date)
        {
            y->lchild=z;
        }
        else
        {
            y->rchild=z;
        }
    }
}

void transplant(LNode & T,LNode & u,LNode & v)
{
    if(u->parent==NULL)
    {
        T=v;
    }
    else if (u==u->parent->lchild)
    {
        u->parent->lchild=v;
    }
    else
    {
        u->parent->rchild=v;
    }
    if(v)
    {
        v->parent=u->parent;
    }
}

void del(LNode & T,LNode & z)
{
    LNode y;
    if(z==NULL)
    {
        exit(-1);
    }
    if(z->lchild==NULL)
    {
        transplant(T,z,z->rchild);
    }
    else if (z->rchild==NULL)
    {
        transplant(T,z,z->lchild);
    }
    else
    {
        y=min(z->rchild);
        if(y->parent != z)
        {
            transplant(T,y,y->rchild);
            y->rchild=z->rchild;
            y->rchild->parent=y;
        }
        transplant(T,z,y);
        y->lchild=z->lchild;
        y->lchild->parent=y;
    }
}

void CreatBST(LNode & T)
{
    int temp;
    char t;
    while(1)
    {
        scanf("%d",& temp);
        LNode x;
        x=(LNode)malloc(sizeof(Node));
        x->date=temp;
        x->lchild=NULL;
        x->rchild=NULL;
        x->parent=NULL;
        t=getchar();
        Insert(T,x);
        if(t=='#')
        {
            break;
        }    
    }
}

LNode search(LNode & T,int k)
{
    if(T==NULL || T->date==k)
    {
        return T;
    }
    if(T->date>k)
    {
        return search(T->lchild,k);
    }
    else
    {
        return search(T->rchild,k);
    }
}

int main()
{
    LNode T=NULL;
    printf("请输入一组整形数据！（以空格隔开,以#结束）");
    CreatBST(T);
    printf("中序遍历：\n");
    InOrderTraverseRe(T);
    while(1)
    {
        int key,m;
        printf("\n1.插入\n2.删除\n3.中序遍历\n4.退出\n");
        scanf("%d",&key);
        switch (key)
        {
        case 1:
        scanf("%d",&m);
        LNode x;
        x=(LNode)malloc(sizeof(Node));
        x->date=m;
        x->lchild=NULL;
        x->rchild=NULL;
        x->parent=NULL;
        Insert(T,x);
            break;
        case 2:
        scanf("%d",&m);
        LNode y;
        y=(LNode)malloc(sizeof(Node));
        y->date=m;
        y->lchild=NULL;
        y->rchild=NULL;
        y->parent=NULL;
        y=search(T,m);
        del(T,y);
        break;
        case 3:
        printf("中序遍历：\n");
        InOrderTraverseRe(T);
        break;
        case 4:
            exit(0);
        default:
            break;
        }
    }
    return 0;
}