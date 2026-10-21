class Solution {
public:
    string maskPII(string s) {

        // EMAIL
        if (s.find('@') != string::npos) {

            for (char &c : s) {
                c = tolower(c);
            }

            int at = s.find('@');

            string ans = "";
            ans += s[0];
            ans += "*****";
            ans += s[at - 1];
            ans += s.substr(at);

            return ans;
        }

        // PHONE NUMBER
        string digits = "";

        for (char c : s) {
            if (isdigit(c)) {
                digits += c;
            }
        }

        int n = digits.size();

        string ans = "";

        // Country code
        if (n > 10) {
            ans += "+";
            ans += string(n - 10, '*');
            ans += "-";
        }

        ans += "***-***-";
        ans += digits.substr(n - 4);

        return ans;
    }
};