class Solution {
public:
    int leastInterval(vector<char>& s, int n) {
        //if (n == 1) return s.size();
        //return s.size();
        vector<int> arr(26, 0), next(26, 1);
        for (int i=0; i!=s.size(); i++) arr[s[i]-'A']++;
        int c = 0;
        int i=1;
        while (i<2000000)
        {
            int idma = -1;
            int j=0;
            int inext = i+1;
            for (j; j!=26; j++)
            {
                if (next[j] <= i )
                {
                    idma = j;
                    break;
                }
            }
            if (idma > -1) for (j; j<26; j++)
            {
                if (next[j] <= i && arr[j] >= arr[idma] )
                {
                    idma = j;
                }
            }
            if (idma > -1 && next[idma] <= i && arr[idma] > 0)
            {
                arr[idma]--;
                next[idma] = i + n + 1;
                c++;
                if (c == s.size()) return i;
            }
            for (int j; j!=26; j++)
            {
                if (next[j] > i )
                {
                    inext = min(inext, next[j]);
                }
            }
            i = inext;
        }
        return -1;
    }
};