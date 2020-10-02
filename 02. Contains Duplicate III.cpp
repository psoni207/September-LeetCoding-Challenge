
/*
lower_bound returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘val’.
 
upper_bound returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘val’.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {        
        if (k <= 0) return false;
        if (k >= nums.size()) k = nums.size()-1;
        
        set<long long> s;
        int n = nums.size();
        for (int i = 0; i < n; i += 1) {
            if(i > k) {
                s.erase(nums[i-k-1]);   
            }
            long long item = (long long)nums[i] - t;
            
            auto pos = s.lower_bound(item);
			// Range: [n-t .... n .... n+t]
		    //If a number greater than or equal to n-t is found in set and it satisfies the absolute diff cond.
            if ( (pos != s.end() && abs(*pos-nums[i]) <= t) )
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
}; 
/*
Time: O(n*logk)
Explaination: klog(k) + 2(n-k)*log(k) (creating a balanced BST of k numbers + deleting and inserting (n-k) numbers in a balanced BST of k numbres)
Space: O(k)
*/