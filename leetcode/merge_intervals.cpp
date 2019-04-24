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
        static bool comp(const Interval & a,
            const Interval & b) {
            return (a.start < b.start);
        } // 自己定义一个comp函数(必须为静态函数)，用来对 区间的开始值 进行排序

        vector < Interval > merge(vector < Interval > & intervals) {
            // if intervals are sorted, it would be easy
            vector < Interval > res; // 存放结果区间
            if (intervals.empty()) return res; //去掉这句不能AC
            sort(intervals.begin(), intervals.end(), comp); //sort函数的用法
            res.push_back(intervals[0]); // 将第一个区间存放进结果中
            for (int i = 1; i < intervals.size(); ++i) {
                if (res.back().end >= intervals[i].start)
                    res.back().end = max(res.back().end, intervals[i].end); // 如果区间有重叠则进行区间融合
                else
                    res.push_back(intervals[i]); // 否则将区间直接存入结果
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
    intervals.push_back(Interval(1,3));
    intervals.push_back(Interval(2,6));
    intervals.push_back(Interval(8,10));
    intervals.push_back(Interval(15,18));

    Solution s;
    s.merge(intervals);
    
    return 0;
}