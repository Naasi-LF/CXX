#include <bits/stdc++.h>
using namespace std;

class node {
public:
    char data;
    node* left;
    node* right;
    node(char value) : data(value), left(nullptr), right(nullptr) {}
};

class Tree
{
public:
    node* root;//根节点
    Tree()//构造树的构造函数
    {
        root = nullptr;
        char x;//输入字符
        int n;//字符个数
        cout << "number of n:";
        cin >> n;
        cout << "elements of tree:\n";
        while(n--)
        {
            cin >> x;
            root = Insert(root,x);//内部调用类函数
        }
    }
    node* Insert(node* root,char data)
    {
        if(root==NULL)
        {
            root=new node(data);
            return root;
        }
        else if(data<=root->data)
            root->left=Insert(root->left,data);
        else
            root->right=Insert(root->right,data);
        return root;
    }
    void dfs11(node* root)//递归前序遍历
    {
        if(root==nullptr)
            return;
        cout << root->data << " " ;
        dfs11(root->left);
        dfs11(root->right);
    }
    void dfs12(node* root)//递归中序遍历
    {
        if(root==nullptr)
            return;
        dfs12(root->left);
        cout << root->data << " " ;
        dfs12(root->right);
    }
    void dfs13(node* root)//递归后序遍历
    {
        if(root==nullptr)
            return;
        dfs13(root->left);
        dfs13(root->right);
        cout << root->data << " " ;
    }
    void dfs21()//非递归前序遍历
    {
        stack<node*> S;
        S.push(root);
        while (!S.empty())
        {
            node* SS = S.top();
            S.pop();
            cout << SS->data << " " ;
            if(SS->right != nullptr)
                S.push(SS->right);
            if(SS->left != nullptr)
                S.push(SS->left);
        }
    }
    void dfs22()//非递归中序遍历
    {
        stack<node*> S;
        node* current = root;
        while (current != nullptr || !S.empty())
        {
            while (current != nullptr)
            {
                S.push(current);
                current = current->left;
            }
            current = S.top();
            S.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }
    void dfs23()//非递归后序遍历
    {
        stack<node*> S1, S2;//使用两个栈
        S1.push(root);
        while (!S1.empty())
        {
            node* current = S1.top();
            S1.pop();
            S2.push(current);//将元素
            if (current->left != nullptr)
                S1.push(current->left);
            if (current->right != nullptr)
                S1.push(current->right);
        }
        while (!S2.empty())
        {
            cout << S2.top()->data << " ";
            S2.pop();
        }
    } 
};

int main()
{
    Tree tree;//构建树结构
    cout << "Pre-order1:\n";
    tree.dfs11(tree.root);
    cout << endl;
    cout << "Pre-order2:\n";
    tree.dfs21();
    cout << endl;
    cout << "In-order1:\n";
    tree.dfs12(tree.root);
    cout << endl;
    cout << "In-order2:\n";
    tree.dfs22();
    cout << endl;
    cout << "Post-order1:\n";
    tree.dfs13(tree.root);
    cout << endl;
    cout << "Post-order2:\n";
    tree.dfs23();
    cout << endl;
}

