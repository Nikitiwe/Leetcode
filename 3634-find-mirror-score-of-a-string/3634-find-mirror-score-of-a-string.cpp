class Solution {
public:
    long long calculateScore(string s) {
        long long ans=0;
        vector<vector<int>> arr(26, vector<int> (1, -1));
        arr[s[0]-'a'].push_back(0);
        for (int i=1; i<s.size(); i++)
        {
            if (arr[25-(s[i]-'a')].size()>1)
            {
                ans+=(i-arr[25-(s[i]-'a')].back());
                arr[25-(s[i]-'a')].pop_back();
            }
            else
            {
                arr[s[i]-'a'].push_back(i);
            }
        }
        return ans;
    }
};