class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        vector<int> arr(26, 0);
        for (int i=0; i!=k; i++) arr[s[i] - 'a']++;
        bool isit = 1;
        if (s.size() == k || (s.size() > k && s[k] != s[k-1])) for (int i=0; i!=26; i++)
        {
            if (arr[i] > 0 && arr[i] != k)
            {
                isit = 0;
                break;
            }
        }
        else isit = 0;
        if (isit == 1) return 1;
        for (int i=k; i<s.size(); i++)
        {
            arr[s[i] - 'a']++;
            arr[s[i-k] - 'a']--;
            bool isit = 1;
            if (s[i-k] != s[i-k+1])
            {
                if (s.size() == i+1 || (s.size() > i+1 && s[i] != s[i+1])) for (int j=0; j!=26; j++)
                {
                    if (arr[j] > 0 && arr[j] != k)
                    {
                        isit = 0;
                        break;
                    }
                }
                else isit = 0;
            }
            else isit = 0;
            if (isit == 1) return 1;
        }
        return 0;
    }
};