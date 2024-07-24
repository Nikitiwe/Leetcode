class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int m=20000, f=1, temp=0;
        for (int i=1; i<=6; i++)
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