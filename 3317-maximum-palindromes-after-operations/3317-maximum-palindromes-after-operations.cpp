class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        vector<int> arr(26, 0), l(words.size(), 0);
        int oddsum=0, oddw=0;
        for (int i=0; i!=words.size(); i++)
        {
            l[i]=words[i].size();
            if (l[i]%2==1) oddw++;
            for (int j=0; j!=words[i].size(); j++)
            {
                arr[words[i][j]-'a']++;
            }
        }
        for (int i=0; i!=26; i++)
        {
            if (arr[i]%2==1) oddsum++;
        }
        sort(l.begin(), l.end());
        int i=words.size()-1;
        oddsum-=oddw;
        while (oddsum>0)
        {
            oddsum-=l[i];
            if (l[i]%2==1) oddsum++;
            i--;
        }
        return i+1;
    }
};