class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for(int i = 0; i < nums1.size(); i++) {
            merged.push_back(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            merged.push_back(nums2[i]);
        }
        sort(merged.begin(), merged.end());

        int msize = merged.size();
        if(msize % 2 != 0) {
            return merged[msize / 2];
        } else {

            return (merged[msize/2 - 1] + merged[msize/2]) / 2.0;
        }

    }
};