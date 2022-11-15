/*
 * @Author: 快出来了哦
 * @Date: 2022-11-15 01:18:54
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-15 01:30:21
 * @FilePath: /c++/algorithm/Leecode/Leecode1710.cpp
 * @Description: 
 */
/*
请你将一些箱子装在 一辆卡车 上。给你一个二维数组 boxTypes ，其中 boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi] ：

numberOfBoxesi 是类型 i 的箱子的数量。
numberOfUnitsPerBoxi 是类型 i 每个箱子可以装载的单元数量。
整数 truckSize 表示卡车上可以装载 箱子 的 最大数量 。只要箱子数量不超过 truckSize ，你就可以选择任意箱子装到卡车上。

返回卡车可以装载 单元 的 最大 总数。
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    /**
     * @description: 利用贪心，先装单元格多的
     * @param {int} truckSize
     * @return {*}
     */
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int ans=0;
        sort(boxTypes.begin(), boxTypes.end(),[](vector<int>&a, vector<int>&b)
        {
            return a[1]>b[1];
        });
        for(auto boxType:boxTypes)
        {
            if(boxType[0]<=truckSize)
            {
                ans+=boxType[0]*boxType[1];
                truckSize-=boxType[0];
            }else{
                ans+=truckSize*boxType[1];
                break;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}
