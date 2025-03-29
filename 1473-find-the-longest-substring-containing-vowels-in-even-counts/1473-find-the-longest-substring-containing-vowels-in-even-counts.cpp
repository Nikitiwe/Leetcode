class Solution {
public:
    int findTheLongestSubstring(string s) {
        vector<vector<int>> arr(s.size()+1, vector<int>(5, 0));
        for (int i=0; i!=s.size(); i++)
        {
            arr[i+1] = arr[i];
            if (s[i] == 'a') arr[i+1][0]++;
            else if (s[i] == 'e') arr[i+1][1]++;
            else if (s[i] == 'i') arr[i+1][2]++;
            else if (s[i] == 'o') arr[i+1][3]++;
            else if (s[i] == 'u') arr[i+1][4]++;
        }
        vector<vector<int>> ans(32, vector<int>({1000000, 0}));
        ans[0][0] = 0;
        for (int ii=1; ii!=arr.size()+1; ii++)
        {
            int i = ii-1;
            int k = (arr[i][0]%2)*1 + (arr[i][1]%2)*2 + (arr[i][2]%2)*4 + (arr[i][3]%2)*8 + (arr[i][4]%2)*16;
            ans[k][0] = min(ans[k][0], i);
            ans[k][1] = max(ans[k][1], i);
        }
        //int res = ans[0][1] - ans[0][0] + 1;
        int res = 0;
        for (int i=0; i!=ans.size(); i++)
        {
            //if (i == 0) res = max(res, ans[i][1] - ans[i][0] + 1);
            res = max(res, ans[i][1] - ans[i][0]);
        }
        return res;
    }
};