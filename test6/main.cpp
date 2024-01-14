// (1)目标：创建一个模拟交通网络，该网络使用有向图表示，其中顶点代表城市，边代表城市之间的道路。每条边上的权重代表从一个城市到另一个城市所需的时间。
// (2)功能：程序能够计算并显示从指定的起始城市到目标城市的最短时间和所在路径。

#include<iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 510, M = 510;

int h[N], e[M], ne[M], w[M], idx;//构建邻接表
int state[N];//记录是否找到了源点到该节点的最短距离
int dist[N]; //保存源点到其余各个节点的距离
int pre[N]; // 新增数组用于存储前驱节点

int n, m;

inline void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void Dijkstra()
{
    memset(dist, 0x3f, sizeof(dist));
    dist[1] = 0;//源点到源点的距离为0。即dist[1] = 0
    memset(pre, -1, sizeof(pre)); // 初始化 pre 数组

    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!state[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        }

        state[t] = 1;

        for (int j = h[t]; j != -1; j = ne[j])
        {
            int i = e[j];
            if (dist[i] > dist[t] + w[j]) 
            {
                dist[i] = dist[t] + w[j];
                pre[i] = t; // 更新前驱节点
            }
        }
    }
}

void printPath(int u) // 用于输出最短路径
{
    if (u == -1) return;
    printPath(pre[u]);
    cout << u << ' ';
}

int main()
{
    memset(h, -1, sizeof(h));//邻接表初始化
    cin >> n >> m;
    while (m--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        add(a, b, w);
    }
    
    Dijkstra();
    cout << dist[n] << endl;
    printPath(n); // 输出最短路径
    return 0;
}
