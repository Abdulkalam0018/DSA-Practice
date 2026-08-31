class LRUCache {
    int sz;
    list<pair<int,int>>ls;
    unordered_map<int,list<pair<int,int>>::iterator>mp;
public:
    LRUCache(int capacity) {
        sz=capacity;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        ls.splice(ls.begin(),ls,mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if (sz < 1) return;
        if (mp.find(key) != mp.end()) {
            mp[key]->second = value;
            ls.splice(ls.begin(), ls, mp[key]);
            return; 
        }

        if (ls.size() == sz) {
            auto it = ls.back();
            mp.erase(it.first);
            ls.pop_back();
        }
        ls.push_front({key, value});
        mp[key] = ls.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */