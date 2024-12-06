class Solution {
public:
    int superPow(int aa, vector<int>& b) {
        unordered_map<int, int> m;
        aa%=1337;
        int p=1, a=aa;
        while (1)
        {
            a*=aa;
            a%=1337;
            if (a==aa) break;
            else p++;
        }
        int s=b[0];
        for (int i=1; i<b.size(); i++)
        {
            s*=10;
            s+=b[i];
            s%=p;
        }
        a=aa;
        if (s==0) s=p;
        while (s>1)
        {
            a*=aa;
            a%=1337;
            s--;
        }
        return a;
    }
};