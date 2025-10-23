class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0, mid, high = arr.size() - 1;

        while(low <= high) {
            mid = high +  (low - high) / 2;

            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {    // if mid is the peak
                return mid;
            } else if(arr[mid] > arr[mid - 1]) {      // if peak ele. in right side of mid ele.
                low = mid + 1;
            } else {
                high = mid - 1;     // if peak ele. in the left side of mid ele.
            }
        }
        return -1;  // array is null
    }
};