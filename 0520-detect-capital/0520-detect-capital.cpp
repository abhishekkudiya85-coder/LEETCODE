class Solution {
public:
    bool detectCapitalUse(string word) {
        int capital = 0;

        // Count uppercase letters
        for (char c : word) {
            if (isupper(c)) {
                capital++;
            }
        }

        // Case 1: All letters uppercase
        if (capital == word.size()) {
            return true;
        }

        // Case 2: All letters lowercase
        if (capital == 0) {
            return true;
        }

        // Case 3: Only first letter uppercase
        if (capital == 1 && isupper(word[0])) {
            return true;
        }

        return false;
    }
};