class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[s[i] - 'a']++;
        int c = 0, v = 0;
        for (int i=0; i!=26; i++)
        {
            if (i == 'a' - 'a' || i == 'o' - 'a' || i == 'e' - 'a' || i == 'i' - 'a' || i == 'u' - 'a') v = max(v, arr[i]);
            else c = max(c, arr[i]);
        }
        return v + c;
    }
};