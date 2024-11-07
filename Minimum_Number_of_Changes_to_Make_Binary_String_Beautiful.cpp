class Solution {
public:
    int minChanges(string s) {
        int i = 0, j = 1;
        int change = 0;
        while (j < s.size()) {
            if (s[i] != s[j]) {
                change++;
            }
            i += 2, j += 2;
        }
        return change;
    }
};