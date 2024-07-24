class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        if (word.size()==1) return 0;
        if (word.size()==2&&abs(word[0]-word[1])<=1) return 1;
        if (word.size()==2&&abs(word[0]-word[1])>1) return 0;
        int ans=0, i=1;
        while (i<=word.size())
        {
            if (abs(word[i]-word[i-1])<=1)
            {
                ans++;
                i++;
                i++;
            }
            else i++;
        }
        return ans;
    }
};