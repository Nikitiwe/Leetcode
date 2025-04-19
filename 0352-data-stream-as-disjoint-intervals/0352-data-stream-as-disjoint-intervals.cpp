class SummaryRanges {
public:
    vector<bool> arr;
    SummaryRanges() {
        return;
    }
    
    void addNum(int value) {
        while (arr.size() <= value + 1) arr.push_back(0);
        arr[value] = 1;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int l = -1;
        for (int i=0; i!=arr.size(); i++)
        {
            if (arr[i] == 1)
            {
                if (l == -1) l = i;
            }
            else
            {
                if (l != -1)
                {
                    ans.push_back({l, i-1});
                    l = -1;
                }
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */