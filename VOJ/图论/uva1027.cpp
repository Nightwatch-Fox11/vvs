//Toll
#include <bits/stdc++.h>
using namespace std;
int mapp[55][55], tot; //因为总共26+26个字母，也就是图中最多52个节点，所以这里设为55. tot用来存储终点要剩余的货物量
int turn(char x)
{
    return (x < 'a' ? x - 'A' + 1 : x - 'a' + 27); //将图中字母节点转化为数字节点,标号从1开始
}
int dij(int from, int to, int o) //此题的改进版Dijkstra算法，调用一次函数就相当于进行一次Dijkstra，o为本次出发携带货量
{
    int dis[55] = {0}, flag[55] = {0}, temp; //dis为余货量数组类似于Dij里面的距离数组，flag还是记录临时标号和固定编号的
    dis[from] = o;                           //起点余货值
    while (1)
    {
        int w = 0, next = -1;
        for (int i = 1; i <= 52; i++) //该循环意在找出具有最大余货值的临时标号
        {
            if (!flag[i] && (next == -1 || w < dis[i]))
            {
                next = i;
                w = dis[i];
            }
            if (next == -1) //也就是再次进行寻找最大值的循环后next未变，也就是最大值不需更新了，就跳出大循环
            {
                break;
            }
            flag[next] = 1;               //临时标号变为固定标号
            for (int i = 1; i <= 52; i++) //找到最大标号后更新其邻接点dis
            {
                if (mapp[next][i]) //若该点与最大值点相邻
                {
                    temp = w - (i < 27 ? ((w + 19) / 20) : 1); //记住这种写法，每20收1，不足20只收1
                    dis[i] = (temp > dis[i] ? temp : dis[i]);
                }
            }
        }
    }
    return dis[to];
}
int T, cnt; //cnt为计数器
char s1[10], s2[10];

int main()
{
    scanf("%d", &T);
    while (1)
    {
        if (T == -1)
        {
            break;
        }
        for (int i = 0; i < T; i++)
        {
            scanf("%d %d", s1, s2);
        }
    }
    return 0;
}
