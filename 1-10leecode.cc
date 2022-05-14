// https://leetcode.com/problems/two-sum/
#include <vector>
#include <map>
using std::map;
using std::vector;
// big(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pairs;
        map<int, int> map_tt; // value and index
        int index = 0;
        while (index < nums.size()) {
            // find the pair
            if (map_tt.find(target - nums[index]) != map_tt.end()) {               
                pairs.push_back(map_tt.find(target - nums[index])->second);
                pairs.push_back(index);
                return pairs;
            } else {
                // if failed, add to map
                map_tt.insert(std::pair<int,int>(nums[index],index));
            }
            index++;
        }
        return pairs;
    }
};
// big(N*N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pairs;
        for(int index = 0; index < nums.size(); index++) {
            for(int index1 = index+1; index1 < nums.size(); index1++) {
                if ((nums[index1] + nums[index]) == target) {
                    pairs.push_back(index);
                    pairs.push_back(index1);
                    return pairs;
                }
            }
        }
     return pairs;       
    }
};
