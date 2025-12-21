class Solution {
public:
    void heapify(vector<int> &nums, int size, int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if(left < size && nums[left] > nums[largest]) {
            largest = left;
        }

        if(right < size && nums[right] > nums[largest]) {
            largest = right;
        }

        if(largest != index) {
            swap(nums[largest], nums[index]);
            heapify(nums, size, largest);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        // for(int i = nums.size() / 2 - 1; i >= 0; i--) {
        //     heapify(nums, nums.size(), i);
        // }

        // // sort
        // for(int i = nums.size() - 1; i >= 0; i--) {
        //     swap(nums[i], nums[0]);
        //     heapify(nums, i, 0);
        // }

        sort(nums.begin(), nums.end());

        return nums;
    }
};