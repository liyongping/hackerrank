#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;


class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        int res = 0;
        stack<int> st;
        height.push_back(0);
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty() || height[st.top()] < height[i]) {
                st.push(i);
            } else {
                int cur = st.top(); st.pop();
                res = max(res, height[cur] * (st.empty() ? i : (i - st.top() - 1)));
                --i;
            }     
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector < int > r;

    r.push_back(4);
    //r.push_back(1);
    r.push_back(5);
    r.push_back(6);
    r.push_back(2);
    r.push_back(3);
    
    cout << s.largestRectangleArea(r);
    return 0;
}