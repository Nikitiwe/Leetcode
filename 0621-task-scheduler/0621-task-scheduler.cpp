class Solution {
public:
    int leastInterval(vector<char>& s, int n) {
        //if (n == 1) return s.size();
        //return s.size();
        vector<int> arr(26, 0), next(26, 1);
        for (int i=0; i!=s.size(); i++) arr[s[i]-'A']++;
        int c = 0;
        for (int i=1; i<2000000; i++)
        {
            int idma = -1;
            int j=0;
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
        }
        return -1;
    }
};