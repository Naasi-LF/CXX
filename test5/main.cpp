#include <bits/stdc++.h>
using namespace std;
const int N = 5;
//  利用邻接表表示方法，构建一个包含10个结点、20条边的有向图
//  用深度优先和宽度优先两种方法对该图进行遍历。
class Graph
{
private:
    vector<int> G[N+1];//构建邻接表,10个节点
    int vis[N+1];
public:
    Graph()
    {
        memset(vis,0,sizeof(vis));
        // int M = 2*N;
        int M;
        cin >> M;
        while (M--)
        {
            int a,b;
            cin >> a >> b;
            G[a].push_back(b);
        }
    }
    void dfs(int a)
    {

        vis[a]=1;
        cout << a << " ";
        for (unsigned int i = 0;i < G[a].size();i++)
        {
            if(vis[G[a][i]]==0)
                dfs(G[a][i]);
        }
        return;
    }
    void bfs()
    {
        memset(vis,0,sizeof(vis));
        queue <int> q;
        q.push(1);
        vis[1]=1;
        while (!q.empty())
        {
            auto temp = q.front();
            q.pop();
            cout << temp << " ";
            for (unsigned int i = 0; i < G[temp].size(); i++)
            {
                if(vis[G[temp][i]]==0)
                {
                    q.push(G[temp][i]);
                    vis[G[temp][i]]=1;
                }
            }
        }
    }
};


int main()
{
    Graph GG;
    GG.dfs(1);
    cout << endl;
    GG.bfs();
}