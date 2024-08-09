class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sumg=0, sumc=0;
        for (int i=0; i!=gas.size(); i++)
        {
            sumg+=gas[i];
            sumc+=cost[i];
        }
        if (sumg<sumc) return -1;
        sumg=0;
        sumc=0;
        int l=0, temp=0;
        while (1)
        {
            sumg+=gas[l];
            sumg-=cost[l];
            if (sumg<0)
            {
                sumg=0;
                temp=0;
                l++;
                l%=gas.size();
            }
            else
            {
                temp++;
                l++;
                l%=gas.size();
                if (temp==gas.size()) return l;
            }
        }
        return l;
    }
};