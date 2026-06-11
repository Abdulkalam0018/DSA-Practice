class LRUCache {
private:
    int capacity;

    // {key, value}
    list<pair<int, int>> cacheList;

    // key -> iterator pointing to node in cacheList
    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {

        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }

        auto node = cacheMap[key];
        int value = node->second;

        // Move accessed node to front
        cacheList.erase(node);
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();

        return value;
    }

    void put(int key, int value) {

        // Key already exists
        if (cacheMap.find(key) != cacheMap.end()) {

            cacheList.erase(cacheMap[key]);

            cacheList.push_front({key, value});

            cacheMap[key] = cacheList.begin();

            return;
        }

        // Cache full -> remove LRU
        if (cacheList.size() == capacity) {

            int lruKey = cacheList.back().first;

            cacheMap.erase(lruKey);

            cacheList.pop_back();
        }

        // Insert new key-value pair
        cacheList.push_front({key, value});

        cacheMap[key] = cacheList.begin();
    }
};