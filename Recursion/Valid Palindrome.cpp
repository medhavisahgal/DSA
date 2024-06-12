class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        return isPalindromeHelper(s, start, end);
    }
    
    bool isPalindromeHelper(string& s, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (!isalnum(s[start])) {
            return isPalindromeHelper(s, start + 1, end);
        }
        if (!isalnum(s[end])) {
            return isPalindromeHelper(s, start, end - 1);
        }
        if (tolower(s[start]) != tolower(s[end])) {
            return false;
        }
        return isPalindromeHelper(s, start + 1, end - 1);
    }
};
