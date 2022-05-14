// https://leetcode.com/problems/two-sum/
#include <vector>
#include <map>
using std::map;
using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pairs;
        map<int, int> map_tt; // value and index
        int index = 0;
        while (index < nums.size()) {
            
            if (map_tt.find(target - nums[index]) != map_tt.end()) {               
                pairs.push_back(map_tt.find(target - nums[index])->second);
                pairs.push_back(index);
                return pairs;
            } else {
                map_tt.insert(std::pair<int,int>(nums[index],index));
            }
            index++;
        }
        return pairs;
    }
};



