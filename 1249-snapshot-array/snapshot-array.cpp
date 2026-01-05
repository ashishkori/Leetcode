class SnapshotArray {
public:
    vector<vector<pair<int,int>>> sp;
    int n;
    int id;
    SnapshotArray(int length) {
        n=length;
        id=0;
        sp.resize(n);
        for(int i=0;i<n;i++) {
            sp[i].push_back(make_pair(id,0));
        }
    }
    
    void set(int index, int val) {
        sp[index].push_back({id,val});
    }
    
    int snap() {
        return id++;
    }
    
    int get(int index, int snap_id) {
        auto it=upper_bound(sp[index].begin(),sp[index].end(),make_pair(snap_id,INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */