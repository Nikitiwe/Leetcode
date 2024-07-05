class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        vector<int> ans;
        int i=1;
        while (memory1>=0&&memory2>=0)
        {
            if (memory1>=memory2) if (memory1-i>=0) memory1=memory1-i; else break;
            else if (memory2-i>=0) memory2=memory2-i; else break;
            i++;
        }
        return {i, memory1, memory2};
    }
};