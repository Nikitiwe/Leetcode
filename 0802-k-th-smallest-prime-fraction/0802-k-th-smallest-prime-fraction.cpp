class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<double> m;
        for (int i=0; i!=arr.size(); i++)
        {
            for (int j=i+1; j<arr.size(); j++)
            {
                m.push((double)arr[i]/arr[j]);
            }
        }
        while (m.size()>k) m.pop();
        double t=m.top();
        for (int i=0; i!=arr.size(); i++)
        {
            for (int j=i+1; j<arr.size(); j++)
            {
                if ((double)arr[i]/arr[j]==t) return {arr[i], arr[j]};
            }
        }
        /*for (int i=0; i!=arr.size(); i++)
        {
            double tt=t*arr[i];
            if (tt-(int)tt<0.000005||tt-(int)tt>0.999995)
            {
                if ((double)(arr[(int)tt]/arr[i])==m.top()) return {arr[(int)tt], arr[i]};
                //else return {arr[(int)tt], arr[i]};
            }
        }*/
        return {-1, -1};
    }
};