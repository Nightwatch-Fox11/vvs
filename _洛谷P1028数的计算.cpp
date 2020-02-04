/*我们要求找出具有下列性质数的个数(包含输入的自然数nn):
先输入一个自然数nn(n \le 1000n≤1000),然后对此自然数按照如下方法进行处理:
不作任何处理;
在它的左边加上一个自然数,但该自然数不能超过原数的一半;
加上数后,继续按此规则进行处理,直到不能再加自然数为止.
输入格式
11个自然数nn(n \le 1000n≤1000)
输出格式
11个整数，表示具有该性质数的个数。
输入输出样例
输入 
6
输出 
6
说明/提示
满足条件的数为

6，16，26，126，36，136*/
#include <iostream>
int f(int n);
int main()
{
    using namespace std;
    int n, f[1010];
    cin >> n;
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            f[i] = f[i - 1] + f[i / 2];
        }
        else
        {
            f[i] = f[i - 1];
        }
    }
    cout << f[n];
    return 0;
}
