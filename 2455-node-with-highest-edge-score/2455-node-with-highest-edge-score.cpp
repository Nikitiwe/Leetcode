class Solution {
public:
    int edgeScore(vector<int>& edges) {
        vector<long long> arr(edges.size(), 0);
        for (int i=0; i!=edges.size(); i++)
        {
            arr[edges[i]]+=i;
        }
        int idans=0;
        for (int i=0; i!=edges.size(); i++)
        {
            if (arr[i]>arr[idans]) idans=i;
        }
        return idans;
    }
};