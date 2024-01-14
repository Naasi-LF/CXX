#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node* next;
    node(int val):data(val),next(nullptr){}
};
node* L = nullptr;
void Delete(node*& L , int index)
{
    if(!index)//处理首元素
    {
        node* pr = L->next;
        L->next=L->next->next;
        delete pr;
        return;
    }
        
    node* temp = L;//遍历指针
    node* prev = L;//后继指针
    //找到要删除的元素位置
    while(index--)
    {
        //指针向后遍LL
        temp=temp->next;
        //找前继指针
        if(index==1) prev = temp;
    }
    //删除元素
    prev->next = temp->next;
    delete temp;
}
