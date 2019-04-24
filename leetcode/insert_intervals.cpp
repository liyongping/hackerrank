#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size(), cur = 0;
        // 不重叠的情况，直接将新区间插入到对应的位置即可
        while (cur < n && intervals[cur].end < newInterval.start) {
            res.push_back(intervals[cur++]);
        }
        //重叠的情况，有时候会有多个重叠，更新新区间的范围以便包含所有重叠，之后将新区间加入结果res，最后将后面的区间再加入结果res即可
        while (cur < n && intervals[cur].start <= newInterval.end) {
            newInterval.start = min(newInterval.start, intervals[cur].start);
            newInterval.end = max(newInterval.end, intervals[cur].end);
            ++cur;
        }
        res.push_back(newInterval);
        // 不重叠的情况，直接将新区间插入到对应的位置即可
        while (cur < n) {
            res.push_back(intervals[cur++]);
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
/*
    vector<Interval> intervals;
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(6,9));
*/
    vector<Interval> intervals;
    intervals.push_back(Interval(1,2));
    intervals.push_back(Interval(3,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(12,16));

    Solution s;
    s.insert(intervals, Interval(4,9));
    
    return 0;
}