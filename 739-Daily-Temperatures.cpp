class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> answer(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {

            while (!st.empty() &&
                   temperatures[i] > temperatures[st.top()]) {

                int index = st.top();
                st.pop();

                answer[index] = i - index;
            }

            st.push(i);
        }

        return answer;
    }
};
// Dry Run

// Input:

// temperatures = [73,74,75,71,69,72,76,73]

// Output:

// [1,1,4,2,1,1,0,0]

// Explanation:

// 73 → warmer after 1 day (74)
// 74 → warmer after 1 day (75)
// 75 → warmer after 4 days (76)
// 71 → warmer after 2 days (72)
// 69 → warmer after 1 day (72)
// 72 → warmer after 1 day (76)
// 76 → no warmer day
// 73 → no warmer day
// Complexity
// Time	Space
// O(n)	O(n)
