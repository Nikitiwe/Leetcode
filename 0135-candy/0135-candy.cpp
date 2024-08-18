class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> arr(ratings.size(), 1);
        int temp=1;
        for (int i=1; i<ratings.size(); i++)
        {
            if (ratings[i]>ratings[i-1])
            {
                temp++;
                arr[i]=temp;
            }
            else temp=1;
        }
        temp=1;
        for (int i=ratings.size()-2; i>=0; i--)
        {
            if (ratings[i]>ratings[i+1])
            {
                temp++;
                arr[i]=max(temp, arr[i]);
            }
            else temp=1;
        }
        temp=0;
        for (int i=0; i!=ratings.size(); i++) temp+=arr[i];
        return temp;
    }
};