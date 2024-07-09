class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if (stones.size()==1) return stones[0];
        sort(stones.begin(), stones.end());
        while (stones[stones.size()-2]>0)
        {
            stones[stones.size()-1]-=stones[stones.size()-2];
            stones[stones.size()-2]=0;
            sort(stones.begin(), stones.end());
        }
        return stones[stones.size()-1];
    }
};