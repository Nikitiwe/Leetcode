class Solution {
public:
    int minimumLength(string s) {
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++)
        {
            arr[s[i]-'a']++;
        }
        int ans=0;
        for (int i=0; i!=26; i++)
        {
            while (arr[i]>2) {arr[i]--; arr[i]--;}
            ans+=arr[i];
        }
        return ans;
    }
};