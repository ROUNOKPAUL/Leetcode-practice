class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<bool>> t(n + 1, vector<bool>(n + 1, false)); // initialize 2D dp array
        t[n][0]=true;//base case
        for (int i = n - 1; i >= 0; i--) {
            for (int open = 0; open <= n; open++) {
                bool isValid = false;
                if (s[i] == '*') {
                    if (open > 0) {
                        isValid |=
                            t[i + 1][open - 1]; // treating as ')' brackets
                    }
                    isValid |= t[i + 1][open];     // treating as empty
                    isValid |= t[i + 1][open + 1]; // treating as '(' bracket
                } else if (s[i] == '(') {
                    isValid |= t[i + 1][open + 1];
                } else if (s[i] == ')') {
                    if (open > 0) {
                        isValid |= t[i + 1][open - 1];
                    }
                }
                t[i][open]=isValid;
            }
        }
        return t[0][0];
    }
};