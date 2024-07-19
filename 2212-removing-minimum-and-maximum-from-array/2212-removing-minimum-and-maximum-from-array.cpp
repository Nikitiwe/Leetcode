class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idmin=0, idmax=0;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>nums[idmax]) idmax=i;
            else if (nums[i]<nums[idmin]) idmin=i;
        }
        if (idmax<idmin) swap(idmax,idmin);
        if (idmin+1<nums.size()-idmax) return idmin+1+min((int)nums.size()-idmax, idmax-idmin);
        else return nums.size()-idmax+min(idmin+1, idmax-idmin);
    }
};