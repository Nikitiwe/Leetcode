class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int count=0, temp=0;
        while (1)
        {
          /*  for (int i=0; i!=arr.size(); i++)
            {
                if (arr[i]!=0){
                if(i-arr[i]>=0&&arr[i-arr[i]]==0) {arr[i]=0; count++; break;}
                else if(i+arr[i]<arr.size()&&arr[i+arr[i]]==0) {arr[i]=0; count++; break;}
                }
            }*/
            for (int i=arr.size()-1; i>=0; i--)
            {
                if (arr[i]!=0){
                if(i-arr[i]>=0&&arr[i-arr[i]]==0) {arr[i]=0; count++; break;}
                else if(i+arr[i]<arr.size()&&arr[i+arr[i]]==0) {arr[i]=0; count++; break;}
                }
            }
            if (arr[start]==0) return 1;
            if (temp==count) return 0;
            temp=count;
        }
        return 0;
    }
}; // Time Limit Exceeded 55/56 testcases passed