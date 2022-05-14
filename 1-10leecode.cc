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

https://leetcode.com/problems/add-two-numbers/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // make sure l1 and l2 can't empty
        ListNode* ret1 = l1;
        ListNode* ret2 = l2;
        ListNode* ret1pre;
        ListNode* ret2pre;        
        int add1 =0;
        int index = 0;
        int index1 = 0;
        while (l1 || l2) {
            int a1 = l1? l1->val:0;
            int a2 = l2? l2->val:0;
            int sum = a1 + a2 + add1;
            add1 = sum/10;
            if(l1) {
                l1->val = sum%10;
                ret1pre = l1;
                l1 = l1->next;
                index++;
            } 
            if(l2) {
                l2->val = sum%10;
                ret2pre = l2;
                l2 = l2->next; 
                index1++;
            }      
        }

        if (index <= index1) {
            if (add1) {
                ret2pre->next = new ListNode();
                ret2pre->next->val = 1;
                ret2pre->next->next = NULL;
            }
            ret1 = ret2;
        } else {
               if (add1) {
                ret1pre->next = new ListNode();
                ret1pre->next->val = 1;
                ret1pre->next->next = NULL;
            }         
        }
        return ret1;
    }
};

https://leetcode.com/problems/longest-substring-without-repeating-characters/

big(N*N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = s.length()?1:0;
        int startoff = 0;
        int endoff = 1;
        map<char,int> map_tt;
        for(; endoff < s.length();endoff++) {
            // find the duplicated characters
    //        for(int index = startoff ; index < endoff;index++){
    //            if (s[endoff] == s[index]) {
    //                startoff = index + 1;
    //            } 
    //        }
    // using 
            
            if (map_tt.find(s[startoff])!=map_tt.end()){
                startoff = map_tt.find(s[startoff])->second + 1;
            } else {
                map_tt.insert(std::pair<char,int>(s[startoff],startoff));
            }
            if (endoff - startoff + 1> maxlen) {
                maxlen = endoff - startoff + 1;
            }
        }
        return maxlen;
    }
};