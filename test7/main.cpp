#include <bits/stdc++.h>
using namespace std;

// 二叉树
class Tree {
public:
    int value;
    Tree *l, *r;
    Tree(int x) : value(x), l(nullptr), r(nullptr) {}
};

// 二叉排序树类
class BST {
private:
    Tree *root;

    // 递归插入
    Tree* insert(Tree* node, int value) 
    {
        if (node == nullptr) 
            return new Tree(value);
        if (value < node->value) 
            node->l = insert(node->l, value);
        else if (value >= node->value)
            node->r = insert(node->r, value);
        return node;
    }

    // 递归查找
    Tree* search(Tree* node, int value) 
    {
        if (node == nullptr || node->value == value) 
            return node;
        if (value < node->value) 
            return search(node->l, value);
        else
            return search(node->r, value);   
    }
    void Print(Tree* temp)
    {
        if(temp==nullptr)
            return;
        Print(temp->l);
        cout << temp->value << " ";
        Print(temp->r);
    }

public:
    BST() : root(nullptr) {}

    // 插入节点
    void insert(int value) 
    {
        root = insert(root, value);
    }

    // 查找节点
    Tree* search(int value) 
    {
        return search(root, value);
    }

    void Print()
    {
        return Print(root);
    }
};

// 主函数
int main() {
    BST bst;
    int m;
    cin >> m;
    while (m--)
    {
        int a;
        cin >> a;
        bst.insert(a);
    }
    
    // 查找节点
    cout << "need find:";
    int number ;
    cin >> number;
    Tree *found = bst.search(number);
    if (found != nullptr) 
        cout << found->value << endl;

    else 
    {
        cout << "not find and insert" << endl;
        bst.insert(number);
    }

    cout << "dfs:";
    bst.Print();
    return 0;
}
