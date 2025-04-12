class Solution {
public:
    bool digitCount(string s) {
        vector<int> arr(10, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i] - '0']++;
        }
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i] - '0' != arr[i]) return 0;
        }
        return 1;
    }
};