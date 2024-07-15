class Solution {
public:
    int maxVowels(string s, int k) {
        int ans=0, temp=0;
        for (int i=0; i!=k; i++)
        {
            if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') temp++;
        }
        ans=temp;
        int l=0, r=k;
        while (r<s.size())
        {
            if (s[r]=='a'||s[r]=='e'||s[r]=='i'||s[r]=='o'||s[r]=='u') temp++;
            if (s[l]=='a'||s[l]=='e'||s[l]=='i'||s[l]=='o'||s[l]=='u') temp--;
            ans=max(ans, temp);
            r++;
            l++;
        }
        return ans;
    }
};