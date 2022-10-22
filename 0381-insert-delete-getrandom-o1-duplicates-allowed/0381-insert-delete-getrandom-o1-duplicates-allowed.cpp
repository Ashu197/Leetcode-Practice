class RandomizedCollection {
public:
    vector<int>v;
    unordered_map<int,int>mp;
    RandomizedCollection() 
    {
        //no code
    }
    
    bool insert(int val) 
    {
        if(mp[val] == 0)  //the element is not present yet in the vector or map
        {
            v.push_back(val);
            mp[val]++;   //due to the reazon of duplicate 
            return true;
        }
        else if(mp[val] > 0)   //it is present in the vector or mp
        {
            v.push_back(val);
            mp[val]++;
            return false;
        }
        return false;    //this will not get encounterd
    }
    
    bool remove(int val) 
    {
         if(mp[val] > 0)  //the element is present
         {
             auto it = find(v.begin(),v.end(),val);
             v.erase(it);
             mp[val]--;
             return true;
         }
         return false;
    }
    
    int getRandom() 
    {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */