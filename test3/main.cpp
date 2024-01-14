#include <bits/stdc++.h>
using namespace std;
class PD
{
private:
    stack <char> J;//判断回文的工具
    string S;//储存回文
    int count;//回文总数
    int mid;//基准数
public:
    PD(const string& str):S(str),count(S.size()),mid(count>>1)
    {
        for(int i=0;i<mid;i++)//以mid为分界线，前面的数放入栈中
            J.push(S[i]);
    }
    bool JudgePD()//判断是否为回文
    {
        if(count%2) mid++;//mid后的元素开始和前面进行比对
        for(int i=mid;i<count;i++)
        {
            if(J.top()==S[i]) J.pop();
            else break;//只要有一个不满足就不是回文了
        }
        return J.empty();
    }
};
int main()
{
    string input,str;
    getline(cin,input);
    if (!input.empty() && input.back() == '@') 
        str = input.substr(0, input.size() - 1);//截断最后一个字符
    PD A(str);
    cout << A.JudgePD();
    return 0;
}