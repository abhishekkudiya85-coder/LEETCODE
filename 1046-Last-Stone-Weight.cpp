class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {

        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {

            int y = pq.top();
            pq.pop();

            int x = pq.top();
            pq.pop();

            if (y != x) {
                pq.push(y - x);
            }
        }

        return pq.empty() ? 0 : pq.top();
    }
};
// Dry Run

// Input:

// stones = [2,7,4,1,8,1]

// Max Heap:

// [8,7,4,2,1,1]

// Process:

// 8 - 7 = 1
// Heap = [4,2,1,1,1]

// 4 - 2 = 2
// Heap = [2,1,1,1]

// 2 - 1 = 1
// Heap = [1,1,1]

// 1 - 1 = 0
// Heap = [1]

// Output:

// 1
// Complexity
// Time	Space
// O(n log n)	O(n)
