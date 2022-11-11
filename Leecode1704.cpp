#include <iostream>
#include <string>
#include <set>
using namespace std;
using namespace std;
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size();
        set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        int cnt = 0;
        for (int i =0 ;i < n/2; ++i)
        {
            if (st.count(s[i]))cnt++;
        }
        for(int i = n/2; i < n; ++i)
        {
            if (st.count(s[i]))cnt--;
        }
        return cnt == 0;
    }
};
int main()
{
    string s ="book";
    cout << Solution().halvesAreAlike(s) <<endl;
    return 0;
}