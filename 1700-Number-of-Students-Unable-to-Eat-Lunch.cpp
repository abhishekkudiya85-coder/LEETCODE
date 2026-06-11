class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count0 = 0, count1 = 0;

        for (int student : students) {
            if (student == 0)
                count0++;
            else
                count1++;
        }

        for (int sandwich : sandwiches) {
            if (sandwich == 0) {
                if (count0 == 0)
                    return count1;

                count0--;
            }
            else {
                if (count1 == 0)
                    return count0;

                count1--;
            }
        }

        return 0;
    }
};
// Dry Run

// Input:

// students = [1,1,1,0,0,1]
// sandwiches = [1,0,0,0,1,1]

// Count:

// 0 -> 2 students
// 1 -> 4 students

// Process:

// Sandwich 1 -> count1 = 3
// Sandwich 0 -> count0 = 1
// Sandwich 0 -> count0 = 0
// Sandwich 0 -> no student wants it

// Remaining:

// count1 = 3

// Output:

// 3
// Complexity
// Time	Space
// O(n)	O(1)
