class Solution {
public:
    bool buddyStrings(string s, string w) {
        if (s.size()==1) return 0;
        if (s.size()!=w.size()) return 0;
        int l=0, r=s.size()-1;
        while (l<s.size()&&s[l]==w[l]) l++;
        while (r>=0&&s[r]==w[r]) r--;
        if (l<s.size()&&r>=0&&l!=r)
        {
            swap(s[l], s[r]);
            if (s==w) return 1;
            else return 0;
        }
        if (s==w)
        {
            vector<int> arr(26, 0);
            for (int i=0; i!=s.size(); i++) arr[s[i]-'a']++;
            for (int i=0; i!=26; i++)
            {
                if (arr[i]>=2) return 1;
            }
        }
        return 0;
    }
};