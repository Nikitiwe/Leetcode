class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        for (int i=k; i<word.size(); i=i+k)
        {
            bool isit=1;
            for (int j=i; j<word.size(); j++)
            {
                if (word[j]!=word[j-i])
                {
                    isit=0;
                    break;
                }
            }
            if (isit==1)
            {
                return i/k;
            }
        }
        return (word.size()+k-1)/k;
    }
};