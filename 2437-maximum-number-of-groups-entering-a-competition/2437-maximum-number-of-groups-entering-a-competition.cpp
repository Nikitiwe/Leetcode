class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int ans=0, i=1;
        while (ans<=grades.size())
        {
            ans+=i;
            i++;
        }
        return i-2;

    }
};