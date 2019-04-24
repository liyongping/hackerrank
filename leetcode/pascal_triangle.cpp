#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    vector < int > getRow(int rowIndex) {
        vector < int > array(rowIndex + 1, 1);
        
        for (int i = 0; i <= rowIndex; i++) {
            for (int j = i - 1; j > 0; j--) {
                array[j] = array[j - 1] + array[j];
            }
        }
        return array;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector < int > r = s.getRow(1);
    for(int i=0; i < r.size(); i ++)   {
        cout<< r[i] << " ";
    }
    
    return 0;
}