class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        int temp=0, count=0;
        for (int i=0; i!=boxes.size(); i++)
        {
            ans.push_back(0);
            ans[i]=ans[i]+temp;
            if (boxes[i]=='1') {count++;}
            temp=temp+count;
        }
        temp=0, count=0;
        for (int i=boxes.size()-1; i>=0; i--)
        {
            ans[i]=ans[i]+temp;
            if (boxes[i]=='1') {count++;}
            temp=temp+count;
        }
        return ans;
    }
};