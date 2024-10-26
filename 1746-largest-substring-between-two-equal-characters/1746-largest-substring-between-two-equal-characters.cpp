class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans=-1;
        for (int i=0; i!=26; i++)
        {
            int l=0, r=s.size()-1;
            while (l<s.size()&&s[l]!='a'+i) l++;
            while (r>=l&&s[r]!='a'+i) r--;
            ans=max(ans, r-l-1);
        }
        return ans;
    }
};