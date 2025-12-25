class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        // M1: Two pointer
        // int left = 0, right = 1;
        // int n = arr.size();
        
        // while (left < n) {
        //     right = left + 1;
        //     while (right < n) {
        //         if (arr[left] + arr[right] == target) {
        //             return {left, right};
        //         }
        //         right++;
        //     }
        //     left++;
        // }
        // return {};


        // M2: Using Hashing(unordered_map)

        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            if(mp.count(target - arr[i])) {
                ans.push_back(mp[target - arr[i]]);
                ans.push_back(i);
                return ans;
            } else {
                if(mp.count(arr[i]) == 0) {
                    mp[arr[i]] = i;
                }
            }
        }

        return ans;
    }
};