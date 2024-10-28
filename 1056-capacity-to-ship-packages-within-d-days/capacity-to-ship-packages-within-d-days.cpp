class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = 1, high = accumulate(weights.begin(), weights.end(), 0);
        int ans = INT_MAX;

        while(low <= high){
            int mid = (low+high)/2;

            int w = 0;
            int req_days = 0;
            int i = 0;

            while( i < n ){
                if(weights[i] > mid){
                    low = mid+1;
                    break;
                }
                else if(w+weights[i] <= mid){
                    w+=weights[i];
                    i++;
                    if(i==n){
                        req_days++;
                    }
                }
                else{
                    req_days++;
                    w = 0;
                }
            }


            if(i == n){
                // cout << mid << " " << req_days << endl;
                if(req_days <= days){
                    ans = min(ans, mid);
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }    
        }

        return ans;
    }
};