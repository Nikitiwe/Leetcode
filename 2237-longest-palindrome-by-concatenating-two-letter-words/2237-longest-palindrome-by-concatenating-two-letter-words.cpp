class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> arr(26, vector<int>(26, 0));
        for (int i=0; i!=words.size(); i++)
        {
            arr[words[i][0] - 'a'][words[i][1] - 'a']++;
        }
        int ans = 0, ans1 = 0, ans2 = 0;
        for (int i=0; i!=26; i++)
        {
            for (int j=i+1; j<26; j++)
            {
                ans += min(arr[i][j], arr[j][i]);
            }
        }
        for (int i=0; i!=26; i++)
        {
            ans1 += arr[i][i]/2;
            if (ans2 == 0 && arr[i][i]%2 == 1) {ans2 = 1;}
        }
        return 4*ans + 4*ans1 + 2*ans2;
    }
};