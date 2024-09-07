class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if (s.size()!=t.size()) return 0;
        vector<int> arr(26, 0);
        for (int i=0; i!=s.size(); i++) arr[((t[i]-s[i])%26+26)%26]++;
        for (int i=1; i!=26; i++)
        {
            int a=k/26;
            if (k%26>=i) a++;
            if (a<arr[i]) return 0;
        }
        return 1;
    }
};