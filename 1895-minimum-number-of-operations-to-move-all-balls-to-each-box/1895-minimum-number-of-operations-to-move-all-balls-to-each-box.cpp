class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans;
        for (int i=0; i!=boxes.size(); i++)
        {
            ans.push_back(0);
            for (int j=0; j!=boxes.size(); j++) ans[i]=ans[i]+(boxes[j]-'0')*abs(i-j);
        }
        return ans;
    }
};