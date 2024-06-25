class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int temp=1, i=0;
        vector<string> ans;
        while (temp<=*(target.end()-1))
        {
            if (target[i]==temp) {ans.push_back("Push"); temp++; i++;}
            else {ans.push_back("Push"); ans.push_back("Pop"); temp++;}
        }
        return ans;
    }
};