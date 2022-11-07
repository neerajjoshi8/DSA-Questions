class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int prefixSum[len];
        prefixSum[0] = nums[0];
        
        for(int i=1; i<len; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }
        
        vector<int> res;
        for(int x : queries) {
            int l = 0, h = len - 1;
            int ans = 0;
            
            while(l <= h) {
                int m = l + (h-l)/2;
                if(prefixSum[m] <= x) {
                    ans = m + 1;
                    l = m + 1;
                } else {
                    h = m - 1;
                }
            }
            
            res.push_back(ans);
        }
        return res;
    }
};

/**
 * Approach:
 * 1. Sort the array
 * 2. Calculate the prefixSum array
 * 3. Apply binary search against the target on prefixSum array
 */
