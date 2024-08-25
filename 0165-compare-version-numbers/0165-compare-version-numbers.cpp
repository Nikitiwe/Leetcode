class Solution {
public:
    int compareVersion(string ver1, string ver2) {
        int l1=0, l2=0, r1=0, r2=0;
        while (l1<ver1.size()||l2<ver2.size())
        {
            r1=0; r2=0;
            while (l1<ver1.size()&&ver1[l1]!='.')
            {
                r1*=10;
                r1+=ver1[l1]-'0';
                l1++;
            }
            while (l2<ver2.size()&&ver2[l2]!='.')
            {
                r2*=10;
                r2+=ver2[l2]-'0';
                l2++;
            }
            if (r1>r2) return 1;
            else if (r1<r2) return -1;
            l1++;
            l2++;
        }
        return 0;
    }
};