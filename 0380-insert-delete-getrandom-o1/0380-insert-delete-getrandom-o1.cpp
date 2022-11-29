class RandomizedSet
{
    public:
        unordered_map<int, int> mp;
    vector<int> vec;
    RandomizedSet() {}

    bool insert(int val) {
        if(mp.find(val) != mp.end()) 
            return false ;
        vec.push_back(val);
        mp[val] =vec.size() - 1 ;
        return true ;
    }

    bool remove(int val)
    {

        if (mp.find(val) == mp.end())
            return false;
        auto it = mp.find(val);
        vec[it->second] = vec.back();
        vec.pop_back();
        mp[vec[it->second]] = it->second;
        mp.erase(val);
        return true;
    }

    int getRandom()
    {
        return vec[rand() % vec.size()];
    }
};

/**
 *Your RandomizedSet object will be instantiated and called as such:
 *RandomizedSet* obj = new RandomizedSet();
 *bool param_1 = obj->insert(val);
 *bool param_2 = obj->remove(val);
 *int param_3 = obj->getRandom();
 */