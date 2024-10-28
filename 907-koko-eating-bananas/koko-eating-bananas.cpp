class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max_pile = *max_element(piles.begin(), piles.end());
        int min_k = 0;

        int low = 1, high = max_pile;
        // cout << max_pile << endl;
        while(low <= high){
            int mid = (low+high)/2;
            long time = 0;
            for(int i=0; i<n; i++){
                if(piles[i] % mid == 0){
                    time += piles[i]/mid;
                }
                else{
                    time += piles[i]/mid + 1;
                }
                
                // cout << mid << " " << ceil(double(double(piles[i])/double(mid))) << endl;
            }
            if(time <= h){
                cout << mid << " " << time << endl;
                min_k = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return min_k;
    }
};