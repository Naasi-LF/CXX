#include <bits/stdc++.h>
using namespace std;
// 定义二叉树节点
struct Node {
    int data;
    Node* left;
    Node* right;
};

// 创建新节点
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// 插入节点
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// 中序遍历
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
void preorder(Node* &root)
{
    stack <Node*> S;
    S.push(root);
    while (!S.empty())
    {
        auto ele = S.top();
        while(ele->left!=nullptr)
            S.push(ele);
        cout << ele->data;
        S.pop();
    }
    
}
// 释放节点
void destroyTree(Node* root) {
    if (root != nullptr) {
        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
    }
}
int leaf = 0;
int noleaf = 0;
void Sum(Node* &root)
{
    if(!root) return;

    if(root->left==nullptr && root->right==nullptr)
    {
        leaf++;
        return;
    }
    else 
    {
        noleaf++;
        Sum(root->left);
        Sum(root->right);
    }
}
int Maxdis = 0;
int dis(Node* root)//路径
{
    if(!root)
        return 0;
    int l = max(0,dis(root->left));
    int r = max(0,dis(root->right));
    int path = root->data + l + r;
    Maxdis = max(Maxdis,path);
    return root->data+max(l,r);
}
int WPL(Node* root,int d)
{
    if(root==nullptr)
        return 0;
    if(root->left==nullptr && root->right==nullptr)
        return ((root->data)*d);
    return (WPL(root->left,d+1) + WPL(root->right,d+1));
}

int main() {
    Node* root = nullptr;

    // 插入节点
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);
    insert(root, 6);
    insert(root, 8);
    insert(root, 9);
    // Sum(root);
    cout << WPL(root,0);

    return 0;
}
