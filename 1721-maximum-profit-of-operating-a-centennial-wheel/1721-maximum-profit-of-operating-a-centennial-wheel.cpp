class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        if (runningCost>=4*boardingCost) return -1;
        int ans=0, temp=0, count=0, i=0, id=0, t;
        while (i<customers.size()||count>0)
        {
            if (i<customers.size()) count+=customers[i];
            t=min(4, count);
            temp+=t*boardingCost;
            count-=t;
            temp-=runningCost;
            i++;
            if (ans<temp) {id=i; ans=temp;}
        }
        if (id==0) id--;
        return id;
    }    
};