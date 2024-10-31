class Solution {
public:
    bool checkZeroOnes(string s) {
        int o=0, z=0, mo=0, mz=0;
        if (s[0]=='1')
        {
            o++;
            mo=max(mo, o);
        }
        else
        {
            z++;
            mz=max(mz, z);
        }
        for (int i=1; i!=s.size(); i++)
        {
            if (s[i]=='1')
            {
                if (o>0)
                {
                    o++;
                    mo=max(mo, o);
                }
                else
                {
                    o++;
                    mo=max(mo, o);
                    z=0;
                }
            }
            else
            {
                if (z>0)
                {
                    z++;
                    mz=max(mz, z);
                }
                else
                {
                    z++;
                    mz=max(mz, z);
                    o=0;
                }
            }
        }
        if (mo>mz) return 1;
        else return 0;
    }
};