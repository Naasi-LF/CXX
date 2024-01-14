#include <bits/stdc++.h>
using namespace std;
vector<char> V;

void Qsort(int l, int r) 
{
    if(l >= r)
        return;
    int i = l-1, j = r+1;
    // int x = V[l];
    while (i < j) 
    {
        do i++;while (V[i]!='B');
        do j--;while (V[j]!='A');
        if(i<j) swap(V[i],V[j]);
    }
}

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
    Qsort1(l,i-1);
    Qsort1(i+1,r);
}

int main()
{
        int nn ;
        cin  >> nn;
        while (nn--)
        {
            char a;
            cin >> a;
            V.push_back(a);
        }
        
        int n = V.size();
        Qsort(0,n-1);
        for (int i = 0; i < n; i++)
        {
            cout << V[i] << " ";
        }
        
}