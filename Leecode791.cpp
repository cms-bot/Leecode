/*
 * @Author: 快出来了哦
 * @Date: 2022-11-13 00:43:38
 * @LastEditors: 快出来了哦
 * @LastEditTime: 2022-11-13 00:59:04
 * @FilePath: /c++/algorithm/Leecode/Leecode791.cpp
 * @Description: 
 */
/*
给定两个字符串 order 和 s 。order 的所有单词都是 唯一 的，并且以前按照一些自定义的顺序排序。

对 s 的字符进行置换，使其与排序的 order 相匹配。更具体地说，如果在 order 中的字符 x 出现字符 y 之前，那么在排列后的字符串中， x 也应该出现在 y 之前。

返回 满足这个性质的 s 的任意排列 。

*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        return funcone(order,s);
    }
    /**
     * @description: 自定义排序
     * @param {string} order
     * @param {string} s
     * @return {*}
     */    
    string funcone(string order, string s)
    {
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++)
        {
            mp[order[i]] = i;
        }
        sort(s.begin(),s.end(),[&](char c1,char c2)
        {
            return mp[c1] < mp[c2];
        });
        return s;
    }
     /**
      * @description: 计数排序
      * @param {string} order
      * @param {string} s
      * @return {*}
      */    
     string functwo(string order, string s)
     {
        vector<int> freq(26);
        for (char ch: s) {
            ++freq[ch - 'a'];
        }
        string ans;
        for (char ch: order) {
            if (freq[ch - 'a'] > 0) {
                ans += string(freq[ch - 'a'], ch);
                freq[ch - 'a'] = 0;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (freq[i] > 0) {
                ans += string(freq[i], i + 'a');
            }
        }
        return ans;
    }
};
int main()
{
    string order = "cba";
    string s = "abcd";
    cout <<Solution().customSortString(order,s) << endl;
    return 0;
}