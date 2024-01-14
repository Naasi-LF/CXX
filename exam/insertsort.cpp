#include <bits/stdc++.h>
using namespace std;
vector <int> V;
void InsortSort()
{
    for (size_t i = 0; i < V.size(); i++)
    {
        for(int j = i ;j-1>=0;j--)
        {
            if(V[j]<V[j-1])
                swap(V[j],V[j-1]);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        V.push_back(a);
    }
    InsortSort();
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }
    
}