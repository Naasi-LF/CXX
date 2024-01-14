#include <bits/stdc++.h>
using namespace std;
struct tree
{
    int val;
    tree* l;
    tree* r;
    tree(int data):val(data),l(nullptr),r(nullptr){}
};

int ans = INT_MIN;//存储最大值
int dfs(tree* root)
{
    if(!root) return 0;
    int l = max(0,dfs(root->l));
    int r = max(0,dfs(root->r));
    ans = max(ans,root->val+l+r);
    return root->val+max(l,r);
}
int main()
{
    // 创建树的节点
    tree* root = new tree(1);
    root->l = new tree(-2);
    root->r = new tree(3);
    root->l->l = new tree(4);
    root->l->r = new tree(-5);
    root->r->l = new tree(8);
    root->r->r = new tree(-9);

    dfs(root);
    cout << ans;
}