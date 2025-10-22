class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        
        int start = 0, mid, end = arr.size() - 1;
        
        while(start <= end) {
            mid = end + (start - end) / 2;
            
            if(arr[mid] == key) {
                return mid;
            } else if(arr[mid] > arr[start]) {
                if(arr[mid] < key || key < arr[start]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                if(arr[start] <= key || key < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
        
        return -1;
    }
};