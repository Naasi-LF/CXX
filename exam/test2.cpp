#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int x):data(x),next(nullptr){}
};
void Delete(node* &L,int n)
{
    node* cur = L;
    if(!L)  return;
    if(n==0)
    {
        L=L->next;
        delete cur;
        return;
    }
    int k=n-1;
    while(k--)
        cur = cur->next;
    node* prev = cur->next;
    cur->next = cur->next->next;
    delete prev;
}
void Reverse(node* &L)
{
    //三指针算法
    node* pre = L;
    node* curr = L->next;
    node* nex = L->next->next;
    //第一个节点接地
    pre->next = nullptr;
    while(nex!=nullptr)
    {
        curr->next = pre;
        //三指针像后面遍历
        pre = curr; curr = nex; nex = nex->next;
    }
    curr->next = pre;//最后头节点特殊处理
    //补充头指针
    L = curr;
}
void insert(node* &L , int x)
{
    node* temp = L;
    while (temp->next!=nullptr)
    {
        temp = temp->next;
    }
    node* curr = new node(x);
    temp -> next = curr;    
}
bool back(node* &L,int k)
{
    node* temp1 = L->next;
    node* temp2 = L->next;
    while (k--)
    {
        if(temp1!=nullptr)
            temp1 = temp1->next;
        else
            return 0;
    }
    while (temp1!=nullptr)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    cout << temp2->data << endl;
    return 1;
}
void OrderInsert(node* &L,int x)
{
    node* prev = L;
    node* temp = L->next;
    //双指针算法
    while (temp!=nullptr && temp->data<x)
    {
        prev = prev->next;
        temp = temp->next;
    }
    node* curr = new node(x);
    prev->next = curr;
    curr->next = temp;
}
node* search (node* &L,int x)
{
    node* temp = L->next;//有头节点
    while (temp!=nullptr && temp->data!=x)
    {
        temp = temp->next;
    }
    if(temp!=nullptr)
        return temp;
    else
        return nullptr;
}
int main()
{
    node* L = new node(-1);//头指针 ,带有头节点 ,本身不记录数值
    int n;
    cin >> n;
    while (n--)//递增
    {
        int x;
        cin >> x;
        insert(L,x);
    }
    // int k; cin >> k;
    // OrderInsert(L,k);
    int k;
    cin >> k;
    // cout << back(L,k);//输出第k个数
    cout << search(L,k)->data << endl;
}