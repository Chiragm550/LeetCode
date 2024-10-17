class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int ct1 = 0, ct2 = 0;

        for(int i=0; i<n; i++){
            if(ct1 == 0 && ele2 != nums[i]){
                ct1 = 1;
                ele1 = nums[i];
            }
            else if(ct2 == 0 && ele1 != nums[i]){
                ct2 = 1;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i]){
                ct1++;
            }
            else if(ele2 == nums[i]){
                ct2++;
            }
            else{
                ct1--;
                ct2--;
            }
        }

        ct1 = 0;
        ct2 = 0;
        int maxct = (int)(n/3) + 1;
        for(int i=0; i<n; i++){
            if(nums[i] == ele1) ct1++;
            else if(nums[i] == ele2) ct2++;
        }

        if(ct1 >= maxct)
            v.push_back(ele1);
        if(ct2 >= maxct)
            v.push_back(ele2);

        sort(v.begin(), v.end());
        return v;
    }
};