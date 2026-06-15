class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<int,string>>> mp;

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});   
    }
    
    string get(string key, int timestamp) {
        auto arr=mp[key];
        int low=0;
        int high=arr.size()-1;
        string res="";
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid].first<=timestamp){
                res=arr[mid].second;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return res;
    }
};
