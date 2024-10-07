class Solution {
public:
    int calPoints(vector<string>& s) {
        vector<int> arr;
        for (int i=0; i!=s.size(); i++)
        {
            if (s[i][0]=='+') arr.push_back(arr[arr.size()-1]+arr[arr.size()-2]);
            else if (s[i][0]=='D') arr.push_back(2*arr[arr.size()-1]);
            else if (s[i][0]=='C') arr.pop_back();
            else arr.push_back(stoi(s[i]));
        }
        int sum=0;
        for (int i=0; i!=arr.size(); i++) sum+=arr[i];
        return sum;
    }
};