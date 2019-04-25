#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

void creat(vector<int> & V)
{
    printf("请输入一组整形数据！（以空格隔开，以#结束）\n");
    int temp;
    char c;
    while(1)
    {
        scanf("%d",&temp);
        V.push_back(temp);
        c=getchar();
        if(c=='#')
        {
            break;
        }
    }
}

int creat(int a[])
{
    printf("请输入一组整形数据！（以空格隔开，以#结束）\n");
    int temp,i;
    char c;
    for(i=0;;)
    {
        scanf("%d",&temp);
        a[i++]=temp;
        c=getchar();
        if(c=='#')
        {
            break;
        }
    }
    return i;
}

void InsertionSort(vector<int> & V)
{
    int i,j;
    for(i=1;i<V.size();i++)
    {
        for(j=0;j<i;j++)
        {
            if(V[i]<V[j])
            {
                break;
            }
        }
        V.insert(V.begin()+j,V[i]);
        V.erase(V.begin()+i+1);
    }
}

int partition(int a[],int left,int right)
{
    int temp,i=left,j=right;
    temp = a[left];
    while(i<j)
    {
        for(;j>i;j--)
        {
            if(a[j]<temp)
            {
                a[i]=a[j];
                i++;
                break;
            }
        }
        for(;i<j;i++)
        {
            if(a[i]>temp)
            {
                a[j]=a[i];
                j--;
                break;
            }
        }
    }
    a[i]=temp;
    return i;
}

void QuickSort(int a[],int left,int right)
{
    int i;
    if(left>=right)
    {
        return;
    }
    i=partition(a,left,right);
    QuickSort(a,left,i-1);
    QuickSort(a,i+1,right);
}

void Merge(vector<int> & V,vector<int> & v1,vector<int> & v2)
{
    int n1,n2,p1=0,p2=0;
    n1=v1.size();
    n2=v2.size();
    while(p1<n1 || p2<n2)
    {
        if(p1>=n1)
        {
            V.push_back(v2[p2++]);
        }
        else if (p2>=n2)
        {
            V.push_back(v1[p1++]);
        }
        else if (v1[p1]>v2[p2])
        {
            V.push_back(v2[p2++]);
        }
        else
        {
            V.push_back(v1[p1++]);
        }
    }
}

void MergeSort(vector<int> & V)
{
    int i,n;
    n=V.size();
    if(n<=1)
    {
        return;
    }
    std::vector<int> v1;
    std::vector<int> v2;
    for(i=0;i<n;i++)
    {
        if(i<n/2)
        {
            v1.push_back(V[i]);
        }
        else
        {
            v2.push_back(V[i]);
        }
    }
    MergeSort(v1);
    MergeSort(v2);
    V.clear();
    Merge(V,v1,v2);
}

void ContingSort(int a[],int e)
{
    int i,min=0,max=0;
    for(i=0;i<e;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
        else if (a[i]<min)
        {
            min=a[i];
        }
    }
    int x=max-min+1;
    int b[100]={0},j;
    for(i=0;i<e;i++)
    {
        b[a[i]+2]++;
    }
    for(i=0;i<x+2;i++)
    {
        for(j=0;j<b[i];j++)
        {
            printf("%d ",i-2);
        }
    }
}

void output(vector<int> & V)
{
    vector<int>::iterator iter;
    for(iter=V.begin();iter!=V.end();iter++)
    {
        printf("%d ",*iter);
    }
}

void output(int a[],int e)
{
    int i;
    for(i=0;i<e;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    vector<int> V;
    vector<int>::iterator iter;
    int a[100],e;
    // creat(V);
    // printf("插入排序：\n");
    // InsertionSort(V);
    // output(V);

    // e=creat(a);
    // printf("快速排序：\n");
    // QuickSort(a,0,e-1);
    // output(a,e);

    creat(V);
    MergeSort(V);
    printf("归并排序：\n");
    output(V);

    // e=creat(a);
    // printf("计数排序：\n");
    // ContingSort(a,e);
    return 0;
}