class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=2, l=0, r=0, t=1;
        vector<int> arr(26, 0);
        arr[s[0]-'a']++;
        while (r<s.size())
        {
            if (t<=2)
            {
                ans=max(ans, r-l+1);
                r++;
                if (r==s.size()) break;
                arr[s[r]-'a']++;
                t=max(t, arr[s[r]-'a']);
            }
            else
            {
                arr[s[l]-'a']--;
                l++;
                t=0;
                for (int i=0; i!=26; i++) t=max(t, arr[i]);
            }
        }
        return ans;
    }
};