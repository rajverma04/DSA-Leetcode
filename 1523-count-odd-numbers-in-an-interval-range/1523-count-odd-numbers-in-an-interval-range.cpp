class Solution {
public:
    int countOdds(int low, int high) {
        // int count = 0;
        // for(int i = low; i <= high; i++) {
        //     if(i % 2 == 1) {
        //         count++;
        //     }
        // }
        // return count;

        if(low % 2 == 0){
            while(low % 2 == 0){
                low++ ;
            }
            
        }
        
        int count = 0;
        for(int i = low ;i <=high ; i += 2){
            count ++;
        }
        return count;
    }
};