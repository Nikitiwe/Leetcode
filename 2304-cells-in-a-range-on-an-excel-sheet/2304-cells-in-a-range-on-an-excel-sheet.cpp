class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        int a = s[0] - 'A';
        int b = s[1] - '0';
        int c = s[3] - 'A';
        int d = s[4] - '0';
        for (int i=a; i<=c; i++)
        {
            for (int j=b; j<=d; j++)
            {
                char x = 'A'+i;
                char y = '0'+j;
                ans.push_back(string(1, x) + string(1, y));
            }
        }
        return ans;
    }
};