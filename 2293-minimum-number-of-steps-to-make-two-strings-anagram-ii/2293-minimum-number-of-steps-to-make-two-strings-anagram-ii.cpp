class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[s[i]-'a']++;
        for (int i=0; i!=t.size(); i++) arr[t[i]-'a']--;
        int ans=0;
        for (int i=0; i!=26; i++)
        {
            ans+=abs(arr[i]);
        }
        return ans;
    }
};