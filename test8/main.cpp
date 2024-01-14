#include <bits/stdc++.h>

using namespace std;

class Sort
{
private:
    vector <int> V;//用来存储排序的数组  
    int n = 15000;//数组总量
public:
    Sort()//随机生成15000条数据
    {
        int a;//随机数
        srand((int)time(NULL));
        int nn=n;
        while (nn--)//放入15000个数
        {
            a = rand() % 1000;
            V.push_back(a);
        }
    };
    void Qsort()//快速排序
    {
        return Qsort(0,n-1);//确定左右边界
    }
    void Qsort1()//快速排序
    {
        return Qsort1(0,n-1);//确定左右边界
    }    
    void Qsort(int l,int r)
    {
        if(l>=r)
            return;
        int i = l-1,j = r+1;
        int x = V[(l+r)>>1];
        while (i<j)
        {
            do i++;while (V[i]<x);
            do j--;while (V[j]>x);
            if(i<j) swap(V[i],V[j]);
        }
        Qsort(l,j);
        Qsort(j+1,r);
    
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
    void Bsort()//冒泡
    {
        for(int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
        {
            if(V[j]>V[j+1])
                swap(V[j],V[j+1]);
        }
    }
    void Print()
    {
        for (int i = 0; i < 6; i++)
            cout << V[i] << " ";
        cout << "...";
        for (int i = n-7; i < n; i++)
            cout << V[i] << " ";        
    }
    void Print2()
    {
        for (int i = 0; i < n; i++)
        {
            if((i+1)%18==0)
                cout << endl;
            cout << V[i] << "\t";
        }
        cout << endl;
    }
};
void Caculate(Sort& data)
{
    Sort dataCopy = data;//做一个拷贝
    using namespace chrono;
    //计算时间1
    auto start = high_resolution_clock::now();
    data.Bsort();
    auto stop = high_resolution_clock::now();
    auto Time = duration_cast<microseconds>(stop - start);
    cout << "Bubble: " << Time.count() << " ms" << endl << "Bubble Sort:";
    data.Print();
    cout << endl;
    //计算时间2
    start = high_resolution_clock::now();
    dataCopy.Qsort1();
    stop = high_resolution_clock::now();
    Time = duration_cast<microseconds>(stop - start);
    cout << "Quick: " << Time.count() << " ms" <<  endl << "Quick Sort:";
    dataCopy.Print();
    dataCopy.Print2();
}
int main()
{
    Sort data;//冒泡排序
    //data.Print2();
    Caculate(data);
}