/*
 * @Author: 快出来了哦
 * @Date: 2022-11-20 01:04:41
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-20 01:29:09
 * @FilePath: /c++/algorithm/Leecode/Leecode799.cpp
 * @Description: 
 */
/*
我们把玻璃杯摆成金字塔的形状，其中 第一层 有 1 个玻璃杯， 第二层 有 2 个，依次类推到第 100 层，每个玻璃杯 (250ml) 将盛有香槟。

从顶层的第一个玻璃杯开始倾倒一些香槟，当顶层的杯子满了，任何溢出的香槟都会立刻等流量的流向左右两侧的玻璃杯。当左右两边的杯子也满了，就会等流量的流向它们左右两边的杯子，依次类推。（当最底层的玻璃杯满了，香槟会流到地板上）

例如，在倾倒一杯香槟后，最顶层的玻璃杯满了。倾倒了两杯香槟后，第二层的两个玻璃杯各自盛放一半的香槟。在倒三杯香槟后，第二层的香槟满了 - 此时总共有三个满的玻璃杯。在倒第四杯后，第三层中间的玻璃杯盛放了一半的香槟，他两边的玻璃杯各自盛放了四分之一的香槟，如下图所示。
现在当倾倒了非负整数杯香槟后，返回第 i 行 j 个玻璃杯所盛放的香槟占玻璃杯容积的比例（ i 和 j 都从0开始）。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * @description: 模拟加动态规划
     * @param {int} poured
     * @param {int} query_row
     * @param {int} query_glass
     * @return {*}
     */
    double champagneTower(int poured, int query_row, int query_glass)
     {
        vector<vector<double>>data(101,vector<double>(101,0));
        data[0][0] = poured;//第一个杯子装满
        for(int i = 0; i<= query_row; ++i)//从上往下遍历
        {
            for (int j =0; j <= i; ++j)
            {
                if (data[i][j] > 1)
                {
                    double remain = data[i][j]-1;//酒的剩余量
                    data[i][j] = 1;
                    data[i+1][j] += remain/2;//平均分给下面两个杯子
                    data[i+1][j+1] += remain/2; 
                }
            }
        }
        return data[query_row][query_glass];
     }
};
int main()
{
    
    return 0;
}