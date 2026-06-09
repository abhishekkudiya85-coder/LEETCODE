class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};  
// //Input:

// nums = [4,3,2,7,8,2,3,1]
// After marking:

// [-4,-3,-2,-7,8,2,-3,-1]

// Positive positions:

// Index 4 -> Number 5
// Index 5 -> Number 6

// Output:

// [5,6]
