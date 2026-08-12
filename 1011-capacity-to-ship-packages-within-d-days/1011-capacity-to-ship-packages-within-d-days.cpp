class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<high){
            int mid=low+(high-low)/2;
            int Days=1;
            int currentweight=0;
            for(int weight:weights){
                if(currentweight+weight<=mid){
                    currentweight+=weight;
                }
                else{
                    Days++;
                    currentweight=weight;
                }
            }
            if(Days<=days){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};