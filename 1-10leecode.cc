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

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int startoff = 0;
        map<char,int> map_tt;
        if (s.length()== 1)
            return 1;
        
        for(int endoff = 0; endoff < s.length();endoff++) {
            if (map_tt.find(s[endoff])!=map_tt.end()){
                int offset = map_tt.find(s[endoff])->second + 1;
                if (offset > startoff )
                    startoff = offset;
            } 
            if (endoff - startoff + 1 > maxlen) {
                maxlen = endoff - startoff + 1;
            }  
            map_tt[s[endoff]] = endoff;
        }
        return maxlen;
    }
};

https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> temp;
        int index = 0;
        int index2 = 0;
        int numlen1 = nums1.size();
        int numlen2 = nums2.size();
        while (true) {
            if ((index < numlen1) && (index2 < numlen2)) {
                if (nums1[index] <= nums2[index2]) {
                    temp.push_back(nums1[index]);
                    index++;   
                } else {
                    temp.push_back(nums2[index2]);
                    index2++;               
                }               
            } else {
                break;
            }
        }
        while (index < numlen1) {
           temp.push_back(nums1[index++]) ;
        }
         while (index2 < numlen2) {

           temp.push_back(nums2[index2++]) ;
        }
        int dd = temp[(numlen1+numlen2)/2];
        int dd1;
        if ((numlen1+numlen2)%2 == 1) {
            dd1 = dd;
        } else {
             dd1 = temp[(numlen1+numlen2)/2 - 1];
        }

        return (dd+ dd1)/2.0;
    }
};

https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 0;
        int lindex = 0;
        int slen = s.length();
        for(int i = 0; i< slen;i++) {
            int len1 = getLongestPalindromic(s,slen,i,i);
            int len2 = getLongestPalindromic(s,slen,i,i+1);
             if(len1 > maxlen) {
                maxlen = len1;
                lindex = i - len1/2;
            } 
            if(len2 > maxlen) {
                maxlen = len2;
                lindex = i + 1 - len2/2;
            }            
        }
        
        return s.substr (lindex,maxlen);
    }
    int getLongestPalindromic(string s,int slen, int l, int r) {
        while(l>=0&&r<slen&&s[l]==s[r]) {
            l--;
            r++;
        }
        l++;
        r--;
        return r-l+1;
    }
};


https://leetcode.com/problems/zigzag-conversion/submissions/

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> aa(numRows);
        int rowindex2 = 0;
        if (numRows == 1)
            return s;

        for(int i = 0; i<s.size(); i++) {
           int temp;
           rowindex2 = (rowindex2%(2*numRows-2));
           if (rowindex2 < numRows) {
              temp = rowindex2;
           } else {
              temp = 2*numRows-2 - rowindex2;
           }           
           aa[temp]+= s[i];  
           rowindex2 ++;
        }
        string tt;
        int index = 0;
        while(index < numRows) {
            tt += aa[index];
            index++;
        }
        return tt;
    }
};

https://leetcode.com/problems/reverse-integer/submissions/

class Solution {
public:
    int reverse(int x) {
        int a = x%10;
        while(true) {
           x = x/10;
           if (x) {
               if ((INT_MAX/10)  < a ||(INT_MIN/10)  > a)
                   return 0;
               a= a*10 + x%10;
           } else {
               break;
           } 
        }
        if (x < 0) {
            return (0-a);
        } else {
            return a;
        }
        
    }
};

https://leetcode.com/problems/string-to-integer-atoi/submissions/
class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int neg = 0;
        int comed = 0;
        while (s[index] != 0) {
            if (s[index] == ' ') {
               if (comed)
                    return 0;
              index++;
              continue;
            } else if ( s[index] == '-') {
                  if (comed)
                    return 0;
                comed = 1;
                neg = 1;
            } else if ( s[index] == '+') {
                  if (comed)
                    return 0;
                comed = 1;
                neg = 0;
            } else {
                // break
                break;
            }
            index++;
        }
        while (s[index] != 0) {
            if (s[index] == '0') {
              index++;
              continue;
            } else {
                // break
                break;
            }
        }   
        int ret = 0;
        while (s[index] != 0) {
            if ((s[index] - '0') >=0 &&((s[index] - '0')<=9)) {
               if ((ret > INT_MAX/10)||((ret == INT_MAX/10)&&((s[index] - '0')>7))) {
                       return INT_MAX;      
               }               

               if ((ret < INT_MIN/10)||((ret == INT_MIN/10)&&((s[index] - '0')>8))) {
                       return INT_MIN;      
               }          
                if (neg == 1) {
                    ret = ret*10 -  (s[index] - '0');
                } else {
                    ret = ret*10 +  (s[index] - '0');
                }
        
              index++;
              continue;
            } else {
                // break
                break;
            }
        }
        std::cout << "ddddddreg" << neg << std::endl;
        return ret;
        
    }
};

https://leetcode.com/problems/palindrome-number/submissions/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        int pre = x;
        int64_t paliret = 0;
        while(true) {
            int mod1 = x%10;
            x = x/10;
            if(x) {
               paliret =  (paliret + mod1)*10;
            } else {
               paliret = paliret + mod1;
               if (paliret == pre)
                   return true;
                else 
                   return false;
            }        
        }
    }
};
// half find
class Solution {
public:
bool isPalindrome(int x) {
int remdigit,palli=0;
if(x<0 || (x%10==0 && x!=0))
{
return false;
}
while(x>palli)
{
remdigit = x % 10;
palli = palli*10 + remdigit;
x = x/10;
}
return x == palli || x == palli/10;
}
};


https://leetcode.com/problems/regular-expression-matching/submissions/

struct Solve {
    
    string &s, &p;
    
    Solve(string &s, string &p) : s(s), p(p) {}
    
    bool solve(int n, int m) {
        
        if (n == 0) {
            while (m > 0 && p[m-1] == '*') {
                m -= 2;
            }
            if (m == 0) return true;
            return false;
        }
        if (m == 0) return false;
        
        if (p[m-1] == '*') {
            if (p[m-2] == s[n-1] || p[m-2] == '.') {
                return solve(n-1, m) || solve(n, m-2);
            }
            return solve(n, m-2);
        }
        if (p[m-1] == '.' || p[m-1] == s[n-1]) {
            return solve(n-1, m-1);
        }
        
        return false;
    }
    
    bool solve() {
        return solve(s.size(), p.size());
    }
};

class Solution {
public:
    bool isMatch(string s, string p) {
        
        return Solve(s,p).solve();
    }
};


https://leetcode.com/problems/container-with-most-water/

class Solution {
    public:
        int maxArea(vector<int>& height) {

			// First Pointer At Extreme Left
            int i=0;

			// Second Pointer At Extreme Right
			int j = height.size()-1;

            int maxArea =0;

			// While First Pointer Is Less Than Second Pointer
            while(i<j){
				
				// Only Change Max Area If Current Area is Greater
                maxArea = max(min(height[i],height[j])*(j-i),maxArea);

				// Increment First Pointer
                if(height[i]<height[j]){
                    i++;
                }
				// Decrement Second Pointer
                else{
                    j--;
                }
                
            }

            return maxArea;
        }
};


https://leetcode.com/problems/integer-to-roman/submissions/


class Solution {
public:
    string intToRoman(int num) {
        string ss;
        int a1 = num/1000;
        a1 = a1%10;
        while(a1) {
            ss += 'M';
            a1--;
        }
        a1 = num/100;
        a1 = a1%10;
        while(a1) {
            if (a1 == 9) {
              ss += 'C';
              ss += 'M';
              break;  
            }
            if (a1 == 4) {
              ss += 'C';
              ss += 'D';
              break;  
            }            
            if (a1 >= 5) {
              ss += 'D';
              a1 = a1 -5;
              continue;  
            }
            ss += 'C';
            a1--;
        }
        a1 = num/10;
        a1 = a1%10;
        while(a1) {
            if (a1 == 9) {
              ss += 'X';
              ss += 'C';
              break;  
            }
            if (a1 == 4) {
              ss += 'X';
              ss += 'L';
              break;  
            }            
            if (a1 >= 5) {
              ss += 'L';
              a1 = a1 -5;
              continue;  
            }
            ss += 'X';
            a1--;
        }        
        a1 = num;
        a1 = a1%10;
        while(a1) {
            if (a1 == 9) {
              ss += 'I';
              ss += 'X';
              break;  
            }
            if (a1 == 4) {
              ss += 'I';
              ss += 'V';
              break;  
            }            
            if (a1 >= 5) {
              ss += 'V';
              a1 = a1 -5;
              continue;  
            }
            ss += 'I';
            a1--;
        } 
        return ss;
    }

    
};


https://leetcode.com/problems/longest-common-prefix/submissions/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int offset = 0;
        while (true) {
         for(int index = 0; index < strs.size(); index++) {
            if (strs[index].size() < (offset+1))
                return strs[index].substr(0,offset);
            if(index > 0 && (strs[index][offset] != strs[index-1][offset]))
                return strs[index].substr(0,offset);
         }           
            offset++;
        }

        return strs[0].substr(0,offset); 
        
    }
};

https://leetcode.com/problems/3sum/

1.  big(o3)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>  tt;
        
        for(int i=0;i<nums.size();i++) {
            for (int j = i; j<nums.size();j++) {
                for (int k=j;k<nums.size();k++) {
                    if((i!=j)&&(k!=j)&&(nums[i]+nums[j]+nums[k] == 0)){
                        
                        vector<int> tt1 = {nums[i],nums[j],nums[k]};
                        sort(tt1.begin(), tt1.end());
                        if(std::find(tt.begin(), tt.end(), tt1) == tt.end())
                            tt.push_back(tt1);
                    }
                }
            }
        }
        return tt;
    }
};
// sort -> target -> 2 point -> pass duplicate -> append
class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> sol;
	sort(nums.begin(), nums.end());
	for(int i=0; i<nums.size(); i++){
		int target = 0 - nums[i];
		int left = i + 1;
		int right = nums.size() - 1;
		while(left < right){
			int sum = nums[left] + nums[right];

			if(sum < target){
				left++;
			}
			else if(sum > target){
				right--;
			}
			else{
				vector<int> tmp = {nums[i], nums[left], nums[right]};
				sol.push_back(tmp);

				while(left < right && nums[left] == tmp[1]) left++;
				while(left > right && nums[right] == tmp[2]) right++;
			}
		}
		while (i < nums.size()-1 && nums[i] == nums[i+1]) i++;
	}

	return sol;
}
};

https://leetcode.com/problems/3sum-closest/submissions/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the nums
        sort(nums.begin(), nums.end());
        // 
        int index = 0;
        int minvalue = INT_MAX;
        int last = 0;
        while(index < (nums.size() -2)){
            int l = index+1;
            int r = nums.size() -1;
            int ltarget = target - nums[index];
            while(l<r) {
                if (nums[l]+nums[r] > ltarget) {
                    int pre = minvalue;
                    minvalue = min(minvalue,nums[l]+nums[r]-ltarget);
                    if (pre != minvalue)
                        last = 1;
                    r--;
                } else if (nums[l]+nums[r] < ltarget) {
                    int pre = minvalue;
                    minvalue = min(minvalue,ltarget- nums[l]-nums[r]);
                    if (pre != minvalue)
                        last = 2;
                    l++;
                } else {
                    return target;
                } 
            }
            index++;   
        }
        if (last == 1) {
            return minvalue + target;
        } else if (last ==2) {
           return target - minvalue ; 
        } else {
            return 0;
        }
        
    }
};


https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string comb = "";
        int index = 0;
        helper(comb, digits, index);
        return res;
    }
    
    void helper(string& comb, string& digits, int index){
        if(index == digits.size()){
            res.push_back(comb);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        for(auto &c: letters){
            comb += c;
            helper(comb, digits, index+1);
            comb.pop_back();
        }
    }
private:
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}, res;
};