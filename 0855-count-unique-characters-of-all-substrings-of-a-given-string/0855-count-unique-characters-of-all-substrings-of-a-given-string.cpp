class Solution {
public:
    int uniqueLetterString(string s) {
        int ans = 0;
        for (int k = 0; k!=26; k++)
        {
            vector<int> arr;
            int t = 0;
            for (int i=0; i!=s.size(); i++)
            {
                if (s[i] == 'A' + k)
                {
                    arr.push_back(t+1);
                    t = 0;
                }
                else t++;
            }
            arr.push_back(t+1);
            for (int i=0; i+1<arr.size(); i++)
            {
                ans += arr[i] * arr[i+1];
            }
        }
        return ans;
    }
};