class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[s[i] - 'a']++;
        sort(arr.rbegin(), arr.rend());
        int ans = 0;
        for (int i=k; i<26; i++) ans += arr[i];
        return ans;
    }
};