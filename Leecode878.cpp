/*
 * @Author: 快出来了哦
 * @Date: 2022-11-22 01:19:32
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-22 02:26:31
 * @FilePath: /c++/algorithm/Leecode/Leecode878.cpp
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <numeric>
using namespace std;
class Solution {
public:
    /**
     * @description: 采用优先级队列，超时
     * @param {int} n
     * @param {int} x
     * @param {int} y
     * @return {*}
     */
    int nthMagicalNumber(int n, int x, int y) {
        map<long,int> mp;
        priority_queue<long,vector<long>,less<long>>pq;
        long a = x;
        long b = y;
        while(pq.size()<n)
        {
            if(a<b)
            {
                pq.push(a);
                mp[a]++;
                a += x;
            }else if(b<a)
            {
                pq.push(b);
                mp[b]++;
                b += y;
            }else{
                if(!mp[a])pq.push(a);
                mp[a]++;
                a += x;
                b += y;
            }
        }
        return pq.top()% mod;
    }
    /**
     * @description: 二分加容斥定理，学到了
     * @param {int} n
     * @param {int} a
     * @param {int} b
     * @return {*}
     */    
    int func_violence(int n,int a,int b)
    {
        long long l = min(a, b);
        long long r = (long long) n * min(a, b);
        int c = lcm(a, b);
        while (l <= r) {
            long long mid = (l + r) / 2;
            long long cnt = mid / a + mid / b - mid / c;
            if (cnt >= n) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return (r + 1) % mod;
    }
private:
    long mod = 1e9+7;
};
int main()
{
    cout<<Solution().nthMagicalNumber(5,2,4)<<endl;
    return 0;
}
