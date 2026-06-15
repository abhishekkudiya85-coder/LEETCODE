class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(numRows);

        int currentRow = 0;
        bool goingDown = false;

        for (char ch : s) {

            rows[currentRow] += ch;

            if (currentRow == 0 || currentRow == numRows - 1)
                goingDown = !goingDown;

            currentRow += goingDown ? 1 : -1;
        }

        string result;

        for (string row : rows)
            result += row;

        return result;
    }
};
// Time Complexity
// O(n)
// Space Complexity
// O(n)
// Approach
// Create numRows strings.
// Traverse the input string character by character.
// Move down through rows, then move up diagonally.
// Append each character to its corresponding row.
// Concatenate all rows at the end.
