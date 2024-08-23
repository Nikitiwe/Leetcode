class Solution {
public:
    int numberOfSpecialChars(string word) {
        int ans=0;
        bool low, hi, lowahi;
        for (int i=0; i!=26; i++)
        {
            low=0; hi=0; lowahi=0;
            for (int j=0; j!=word.size(); j++)
            {
                if (word[j]=='a'+i&&hi==0) low=1;
                else if (word[j]=='a'+i&&hi==1) {lowahi=1; break;}
                else if (word[j]=='A'+i) hi=1;
            }
            if (lowahi==0&&low==1&&hi==1) ans++;
        }
        return ans;
    }
};