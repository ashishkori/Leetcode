class SnapshotArray {
public:
    unordered_map<int,vector<pair<int,int>>> sp;
    int n;
    int id;
    SnapshotArray(int length) {
        n=length;
        id=0;
        for(int i=0;i<n;i++) {
            sp[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        if(index>n) return;
        sp[index].push_back({id,val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        vector<pair<int,int>> &vec=sp[index];
        pair<int,int> p={snap_id,INT_MAX};
        auto itr=upper_bound(vec.begin(),vec.end(),p);
        itr--;
        return itr->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */