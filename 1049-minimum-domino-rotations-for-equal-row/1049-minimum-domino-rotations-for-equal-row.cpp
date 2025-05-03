class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int m=20000, f=1, temp=0;
        vector<int> arr(6, 1);
        for (int i=0; i!=tops.size(); i++)
        {
            for (int j=1; j<=6; j++) if (arr[j-1] == 1)
            {
                if (tops[i] != j && bottoms[i] != j) arr[j-1] = 0;
            }
        }
        for (int i=1; i<=6; i++) if (arr[i-1] == 1)
        {
            f=1;
            temp=0;
            for (int j=0; j!=tops.size(); j++)
            {
                if (tops[j]!=i)
                {
                    if (bottoms[j]!=i) {f=0; break;}
                    else temp++;
                }
            }
            if (f==1)
            {
                m=min(m, temp);
                temp=0;
                for (int j=0; j!=tops.size(); j++)
                {
                    if (bottoms[j]!=i)
                    {
                        if (tops[j]!=i) {f=0; break;}
                        else temp++;
                    }
                }
            }
            if (f==1) m=min(m, temp);
        }
        if (m==20000) return -1;
        else return m;
    }
};