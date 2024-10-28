class Solution {
public:

    int minDayCalc(vector<int>& bloomDay, int m, int k, int mid){
        int n = bloomDay.size();

        int i = 0;

        int bqNo = 0;
        int count = 0;

        for(int i=0; i<n; i++){
            if(bloomDay[i] <= mid){
                count++;
            }
            else{
                count = 0;
            }

            if(count == k){
                bqNo++;
                count = 0;
            }
        }

        if(bqNo >= m){
            return mid;
        }
        else{
            return -1;
        }
        
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int low = *min_element(bloomDay.begin(), bloomDay.end());

        int minDays = -1;

        while(low <= high){
            int mid = (low+high)/2;
            int res = minDayCalc(bloomDay, m, k, mid);

            if(res == -1){
                low = mid+1;
            }
            else{
                high = mid-1;
                minDays = res;
            }
        }
        return minDays;
    }
};