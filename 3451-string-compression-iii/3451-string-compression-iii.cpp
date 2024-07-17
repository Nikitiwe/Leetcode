class Solution {
public:
    string compressedString(string word) {
        string ans;
        int count=1, f=1;
        for (int i=0; i<word.size()-1; i++)
        {
            if (word[i+1]==word[i])
            {
                count++;
                if (count==9)
                {
                    ans+='9';
                    ans+=word[i];
                    count=1;
                    i++;
                    if (i==word.size()-1) f=0;
                }
            }
            else
            {
                ans+=to_string(count);
                ans+=word[i];
                count=1;
            }
        }
        if (f==1) {
        ans+=to_string(count);
        ans+=word[word.size()-1];
        }
        return ans;
    }
};