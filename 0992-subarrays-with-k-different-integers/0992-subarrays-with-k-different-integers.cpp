class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int total  = 0;     // Ateast(k) - Atleast(k + 1)
        unordered_map<int, int> freq;
        int start = 0, end = 0, n = nums.size();
        int count = 0;          // count of diff. element in that window

        while(end < n) {        // Ateast(k)
            freq[nums[end]]++;
            
            if(freq[nums[end]] == 1) {      // first time seeing num then 
                count++;                    // increase the count
            }
            while(count == k) {
                total += n - end;
                freq[nums[start]]--;

                if(freq[nums[start]] == 0) {
                    count--;
                }
                start++;
            }
            end++;
        }
        start = 0, end = 0, count = 0;
        freq.clear();
        k++;        // k + 1

        while(end < n) {        // Ateast(k + 1)
            freq[nums[end]]++;
            
            if(freq[nums[end]] == 1) {      // first time seeing num then 
                count++;                    // increase the count
            }
            while(count == k) {
                total -= n - end;
                freq[nums[start]]--;

                if(freq[nums[start]] == 0) {
                    count--;
                }
                start++;
            }
            end++;
        }


        return total;
    }
};