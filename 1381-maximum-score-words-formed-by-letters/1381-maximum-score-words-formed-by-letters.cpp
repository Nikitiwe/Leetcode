class Solution {
public:
    int maxScoreWords(vector<string>& s, vector<char>& l, vector<int>& nums) {
        int ans = 0;
        vector<int> arr(26, 0);
        for (int i=0; i!=l.size(); i++) arr[l[i] - 'a']++;
        int k = 1 << s.size();
        unordered_map<int, int> score;
        for (int i=0; i!=s.size(); i++)
        {
            for (int j=0; j!=s[i].size(); j++)
            {
                score[i] += nums[s[i][j] - 'a'];
            }
        }
        for (int i=0; i!=k; i++)
        {
            int t = i, sum = 0;
            vector<int> tarr = arr;
            bool isit = 1;
            for (int j=0; j!=s.size(); j++)
            {
                if (t%2==1)
                {
                    for (int a = 0; a!=s[j].size(); a++)
                    {
                        tarr[s[j][a] - 'a']--;
                        if (tarr[s[j][a] - 'a'] < 0)
                        {
                            isit = 0;
                            break;
                        }
                    }
                    if (isit == 0) break;
                    sum += score[j];
                }
                t /= 2;
            }
            if (isit == 1) ans = max(ans, sum);
        }
        return ans;
    }
};