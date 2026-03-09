class BrowserHistory {
public:
    stack<string> backStack;    // backward stack
    stack<string> forStack;     // forward stack;
    string current;             // current page

    BrowserHistory(string homepage) {
        current = homepage;
    }
    
    void visit(string url) {
        backStack.push(current);
        current = url;

        while(!forStack.empty()) {
            forStack.pop();
        }
    }
    
    string back(int steps) {
        while(steps-- && !backStack.empty()) {
            forStack.push(current);
            current = backStack.top();
            backStack.pop();
        }

        return current;
    }
    
    string forward(int steps) {
        while(steps-- && !forStack.empty()) {
            backStack.push(current);
            current = forStack.top();
            forStack.pop();
        }

        return current;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */