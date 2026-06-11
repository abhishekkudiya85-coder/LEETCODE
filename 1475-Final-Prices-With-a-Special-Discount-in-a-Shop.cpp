class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        for (int i = 0; i < prices.size(); i++) {
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }

            st.push(i);
        }

        return prices;
    }
};
// Dry Run

// Input:

// prices = [8,4,6,2,3]

// Process:

// 8 gets discount 4  -> 4
// 4 gets discount 2  -> 2
// 6 gets discount 2  -> 4
// 2 gets no discount -> 2
// 3 gets no discount -> 3

// Output:

// [4,2,4,2,3]
// Complexity
// Time	Space
// O(n)	O(n)
