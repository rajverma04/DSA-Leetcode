class Solution {
public:
    int clumsy(int n) {
        // stack<int> st1;
        // int num;
        // st1.push(n--);

        // int i = 0;  // 0: *, 1: /, 2: +, 3: -
        // while(n) {
        //     if(i == 0) {    // multiply
        //         num = st1.top();
        //         st1.pop();
        //         st1.push(num * n);
        //     } else if(i == 1) {     // divide
        //         num = st1.top();
        //         st1.pop();
        //         st1.push(num / n);
        //     } else {
        //         st1.push(n);
        //     }
        //     i = (i + 1) % 4;        // sign change
        //     n--;
        // }

        // stack<int> st2;
        // while(st1.size()) {
        //     st2.push(st1.top());
        //     st1.pop();
        // }

        // int sum = st2.top();
        // st2.pop();

        // bool flag = false;
        // while(st2.size()) {
        //     if(!flag) {             // addition
        //         sum += st2.top();
        //     } else {        // substraction
        //         sum -= st2.top();
        //     }
        //     st2.pop();
        //     flag = !flag;
        // }

        // return sum;

        // M2: pattern recoginition

        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 6;
        if(n == 4) return 7;

        if(n % 4 == 0) {
            return n + 1;
        } 
        if(n % 4 == 1 || n % 4 == 2) {
            return n + 2;
        }
        
        return n - 1;

    }
};