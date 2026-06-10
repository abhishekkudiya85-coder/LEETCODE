class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int curr = 1;

        for (int num : target) {
            while (curr < num) {
                ans.push_back("Push");
                ans.push_back("Pop");
                curr++;
            }

            ans.push_back("Push");
            curr++;
        }

        return ans;
    }
};
// Dry Run

// Input:

// target = [1,3]
// n = 3

// Operations:

// 1 -> Push
// 2 -> Push, Pop
// 3 -> Push

// Output:

// ["Push","Push","Pop","Push"]
// Complexity
// Time	Space
// O(n)	O(n)
