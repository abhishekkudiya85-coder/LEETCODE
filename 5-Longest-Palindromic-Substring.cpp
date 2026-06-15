class Solution {
public:
    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 1;
        int n = s.length();

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }

            // Even length palindrome
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    start = left;
                    maxLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLen);
    }
};

// e Complexity
// O(n²)
// Space Complexity
// O(1)
// Approach
// Every character can be the center of a palindrome.
// Expand from the center in both directions.
// Check both:
// Odd length palindromes (aba)
// Even length palindromes (abba)
// Keep track of the longest palindrome found
