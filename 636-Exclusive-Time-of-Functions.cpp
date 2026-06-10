class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string log : logs) {
            int p1 = log.find(':');
            int p2 = log.find(':', p1 + 1);

            int id = stoi(log.substr(0, p1));
            string type = log.substr(p1 + 1, p2 - p1 - 1);
            int time = stoi(log.substr(p2 + 1));

            if (type == "start") {
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }

                st.push(id);
                prevTime = time;
            }
            else {
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return ans;
    }
};
// Dry Run

// Input:

// n = 2

// logs = {
// "0:start:0",
// "1:start:2",
// "1:end:5",
// "0:end:6"
// }

// Execution:

// 0 runs from 0 to 1  -> 2 units
// 1 runs from 2 to 5  -> 4 units
// 0 runs from 6 to 6  -> 1 unit

// Result:

// [3,4]
// Complexity
// Time	Space
// O(logs.size())	O(n)
