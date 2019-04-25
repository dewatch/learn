#include <stack>
#include <iostream>
#include<stdio.h>
using namespace std;
int GetValue (char c)
{
    int value=0;
    switch (c)
    {
    case '+':value=1;
        break;
    case '-':value=1;
        break;
    case '*':value=2;
        break;
    case '/':value=2;
        break;
    default:
        break;
    }
    return value;
}
int main()
{
    stack<char> s1;
    stack<char> s2;
    char c[30]={0};
    char temp;
    int i,j,v1,v2;
    printf("��������׺���ʽ������30�ַ�����#��������");
    for(i=0;;i++)
    {
        scanf("%c",&c[i]);
        if(c[i]=='#')
        break;
    }
    s1.push('#');
    for(i=0;c[i]!='#';)
    {
        if('0'<=c[i]&&c[i]<='9'||c[i]>=96&&c[i]<=123)
        {
            s2.push(c[i]);
            i++;
        }
        if(c[i]=='+'||c[i]=='-'||c[i]=='*'||c[i]=='/')
        {
            v1=GetValue(c[i]);
            temp=s1.top();
            v2=GetValue(temp);
            if(v1>v2)
            {
                s1.push(c[i]);
                i++;
            }
            else
            {
                s1.pop();
                s2.push(temp);
            }
        }
        if(c[i]=='(')
        {
            s1.push(c[i]);
            i++;
        }
        if(c[i]==')')
        {
            temp=s1.top();
            for(;temp!='(';)
            {
                s2.push(temp);
                s1.pop();
                temp=s1.top();
            }
            s1.pop();
            i++;
        }
        if(c[i]=='#')
        {
            for(;s1.top()!='#';)
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    for(i=0;!s2.empty();i++)
    {
        c[i]=s2.top();
        s2.pop();
    }
    printf("��׺���ʽΪ��  ");
    for(j=i-1;j>=0;j--)
    {
        printf("%c",c[j]);
    }
    printf("\n");
    return 0;
}
