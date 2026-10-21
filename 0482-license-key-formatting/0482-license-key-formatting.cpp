class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "";

        // Step 1: Remove '-' and convert to uppercase
        for (char c : s) {
            if (c != '-') {
                clean += toupper(c);
            }
        }

        string ans = "";
        int count = 0;

        // Step 2: Start from the end
        for (int i = clean.size() - 1; i >= 0; i--) {
            if (count == k) {
                ans += '-';
                count = 0;
            }

            ans += clean[i];
            count++;
        }

        // Step 3: Reverse answer
        reverse(ans.begin(), ans.end());

        return ans;
    }
};