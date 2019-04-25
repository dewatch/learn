#include<stack>              //测试数据：ab cd  e  f g
#include<deque>
#include<stdio.h>
#include <iostream>
#include<malloc.h>

using namespace std;

typedef struct BiTNode
{
    char date;
    struct BiTNode * lchild, * rchild;
}BiTNode, * BiTree;

void CreateBiTree(BiTree &T)
{
    char temp;
    temp=getchar();
    if(temp!=' ')
    {
        T=(BiTree)malloc(sizeof(BiTNode));
        T->date=temp;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    if(temp==' ')
    {
        T=NULL;
    }
    
}

void visit(char e)
{
    printf("%c ",e-32);
}

void PreOrderTraverseRe(BiTree & T)
{
    if(T)
    {
        visit(T->date);
        PreOrderTraverseRe(T->lchild);
        PreOrderTraverseRe(T->rchild);
    }
}

void InOrderTraverseRe(BiTree & T)
{
    if(T)
    {
        InOrderTraverseRe(T->lchild);
        visit(T->date);
        InOrderTraverseRe(T->rchild);
    }
}

void PostOrderTraverseRe(BiTree & T)
{
    if(T)
    {
        PostOrderTraverseRe(T->lchild);
        PostOrderTraverseRe(T->rchild);
        visit(T->date);
    }
}

void InOrderTraverse(BiTree & T)
{
    stack<BiTree> s;
    s.push(T);
    BiTree p;
    while (!s.empty())
    {
        while (p=s.top())
        {
            s.push(p->lchild);
        }
        s.pop();
        if (!s.empty())
        {
            p=s.top();
            s.pop();
            visit(p->date);
            s.push(p->rchild);
        }
    }
}

void PreOrderTraverse(BiTree & T)
{
    stack<BiTree> s;
    s.push(T);
    BiTree p;
    while (!s.empty())
    {
        while (p=s.top())
        {
            visit(p->date);
            s.push(p->lchild);
        }
        s.pop();
        if (!s.empty())
        {
            p=s.top();
            s.pop();
            s.push(p->rchild);
        }
    }
}

void PostOrderTraverse(BiTree & T)
{
    stack<BiTree> s;
    BiTree p,prev=NULL,top;
    p=T;
    while (!s.empty()||p)
    {
        while (p)
        {
            s.push(p);
            prev=p;
            p=p->lchild;
        }
        top=s.top();
        if ((top->rchild != NULL) && (top->rchild!=prev))
        {
            p=top->rchild;
        }
        else
        {
            visit(top->date);
            s.pop();
            prev=top;
        }
        
    }
}

void BFS(BiTree & T)
{
    deque<BiTree> Q;
    Q.push_back(T);
    BiTree temp;
    while (!Q.empty())
    {
        temp=Q.front();
        Q.pop_front();
        visit(temp->date);
        if(temp->lchild)
        {
            Q.push_back(temp->lchild);
        }
        if(temp->rchild)
        {
            Q.push_back(temp->rchild);
        }
    }
    
}

int main()
{
    BiTree T;
    printf("请以先序次序输入二叉树中结点的值（一个字符），空格字符表示为空树！");
    CreateBiTree(T);
    printf("先序遍历：\n");
    PreOrderTraverseRe(T);
    printf("\n中序遍历：\n");
    InOrderTraverseRe(T);
    printf("\n后序遍历：\n");
    PostOrderTraverseRe(T);
    printf("\n先序遍历（非递归）：\n");
    PreOrderTraverse(T);
    printf("\n中序遍历（非递归）：\n");
    InOrderTraverse(T);
    printf("\n后序遍历（非递归）：\n");
    PostOrderTraverse(T);
    printf("\nBFS遍历（非递归）：\n");
    BFS(T);
    return 0;
}

