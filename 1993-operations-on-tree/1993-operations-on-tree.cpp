class LockingTree {
public:
    int sz;
    vector<pair<string, int>> node;
    vector<int> parent;
    vector<vector<int>> children;

    LockingTree(vector<int>& parent) {
        this->parent = parent;
        sz = parent.size();
        node = vector<pair<string, int>>(sz, {"unlocked", -1});

        children.resize(sz);
        for (int i = 0; i < sz; i++) {
            if (parent[i] != -1) {
                children[parent[i]].push_back(i);       // store only direct child
            }
        }
    }

    bool lock(int num, int user) {
        if (node[num].first == "unlocked") {
            node[num] = {"locked", user};
            return true;
        }
        return false;
    }

    bool unlock(int num, int user) {
        if (node[num].first == "locked" && node[num].second == user) {
            node[num] = {"unlocked", -1};
            return true;
        }
        return false;
    }

    bool dfs(int curr, vector<int>& lockedindex) {
        bool found = false;

        for (int child : children[curr]) {
            if (node[child].first == "locked") {        // node is locked
                found = true;   
                lockedindex.push_back(child);           // index of locked node
            }
            if (dfs(child, lockedindex)) {
                found = true;
            }
        }
        return found;
    }

    bool upgrade(int num, int user) {
        if (node[num].first == "locked")
            return false;

        int p = parent[num];
        while (p != -1) {
            if (node[p].first == "locked")
                return false;
            p = parent[p];
        }

        vector<int> lockedindex;            // store the locked descendent node
        if (!dfs(num, lockedindex)) {       // getting locked descendet node using DFS
            return false;
        }

        for (int i : lockedindex) {         // mark all descendent locked node to unlock
            node[i] = {"unlocked", -1};
        }

        node[num] = {"locked", user};       // mark that current node which need to upgrade locked
        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */