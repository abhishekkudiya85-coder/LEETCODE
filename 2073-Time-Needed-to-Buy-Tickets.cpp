class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int time = 0;

        for (int i = 0; i < tickets.size(); i++) {

            if (i <= k)
                time += min(tickets[i], tickets[k]);
            else
                time += min(tickets[i], tickets[k] - 1);
        }

        return time;
    }
};

// Example 1

// Input:

// tickets = [2,3,2]
// k = 2

// Calculation:

// Person 0: min(2,2) = 2
// Person 1: min(3,2) = 2
// Person 2: min(2,2) = 2

// Total = 6

// Output:

// 6
// Example 2

// Input:

// tickets = [5,1,1,1]
// k = 0

// Calculation:

// Person 0: min(5,5) = 5
// Person 1: min(1,4) = 1
// Person 2: min(1,4) = 1
// Person 3: min(1,4) = 1

// Total = 8

// Output:

// 8
// Complexity
// Time	Space
// O(n)	O(1)
