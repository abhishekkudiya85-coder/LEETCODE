class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {

            while (!st.empty() &&
                  (i == n || heights[st.top()] >= heights[i])) {

                int height = heights[st.top()];
                st.pop();

                int width;

                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};
// Dry Run

// Input:

// heights = [2,1,5,6,2,3]

// Largest rectangle:

// Height = 5
// Width  = 2

// Area = 5 × 2 = 10

// Output:

// 10
// Example 2

// Input:

// heights = [2,4]

// Possible areas:

// 2 × 2 = 4
// 4 × 1 = 4

// Output:

// 4
// Complexity
// Time	Space
// O(n)	O(n)
