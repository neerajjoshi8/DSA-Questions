class Solution {
private:
    int binarySearch(vector<int>& nums, int target, bool isFirst = true) {
        int l = 0, h = nums.size()-1;
        int ans = -1;
        while(l <= h) {
            int m = l + (h-l)/2;
            if(nums[m] > target) {
                h = m - 1;
            } else if(nums[m] < target) {
                l = m + 1;
            } else {
                ans = m;
                if(isFirst) {
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        return ans;
    }
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int f = binarySearch(nums, target);
        if(f == -1) {
            return {};
        }
        
        int l = binarySearch(nums, target, false);
        
        vector<int> ans;
        for(int i=f; i<=l; ++i) {
            ans.push_back(i);
        }
        return ans;
    }
};

// time complexity: O(nlogn)

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int lessThanTarget = 0, cntOfTarget = 0;
        for(int x : nums) {
            if(x == target) {
                cntOfTarget++;
            } else if(x < target) {
                lessThanTarget++;
            }
        }
        
        vector<int> ans;
        while(cntOfTarget-- > 0) {
            ans.push_back(lessThanTarget++);
        }
        return ans;
    }
};

// time complexity: O(nlogn)
