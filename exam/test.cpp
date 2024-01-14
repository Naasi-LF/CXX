#include <bits/stdc++.h>
using namespace std;
vector <int> V;
int n,k;
// yxc的算法
void Qsort1(int l, int r) 
{
    if(l >= r)
        return;
    int i = l, j = r;
    int x = V[l];//第一个数作为基准数
    while (i < j) 
    {
        while(V[j]>=x&&i < j) j--;
        V[i] = V[j];
        while(V[i]<=x&&i < j) i++;
        V[j] = V[i];
    }
    V[i]=x;
    if(i+1==k) return;
    if(k<i+1)  Qsort1(l,i-1);
    if(k>i+1)  Qsort1(i+1,r);
}
int main()
{
        cin  >> n >> k;
        int nn = n;
        while (nn--)
        {
            int a;
            cin >> a;
            V.push_back(a);
        }
        int n = V.size();
        Qsort1(0,n-1);

        cout << V[k-1];
}