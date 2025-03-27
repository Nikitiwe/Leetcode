class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& s) {
        vector<int> arr(12, 0);
        for (int i=0; i!=s.size(); i++)
        {
            int t = 0;
            vector<int> c(26, 0);
            for (int j=0; j!=s[i].size(); j++) c[s[i][j]-'a']++;
            for (int j=0; j!=26; j++) if (c[j] > 0)
            {
                t = c[j];
                break;
            }
            arr[t]++;
        }
        for (int i=arr.size()-1; i>0; i--) arr[i-1] += arr[i];
        vector<int> ans(q.size(), 0);
        for (int i=0; i!=q.size(); i++)
        {
            int t = 0;
            vector<int> c(26, 0);
            for (int j=0; j!=q[i].size(); j++) c[q[i][j]-'a']++;
            for (int j=0; j!=26; j++) if (c[j] > 0)
            {
                t = c[j];
                break;
            }
            ans[i] = arr[t+1];
        }
        return ans;
    }
};