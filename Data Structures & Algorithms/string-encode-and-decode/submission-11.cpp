class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string="";
        for(auto it:strs){
            encoded_string+=to_string(it.size())+'#'+it;
        }
        return encoded_string;
    }

    vector<string> decode(string encoded_string) {
        vector<string> decoded_strs;
        string size="";
        int x=0;
        string temp="";
        bool y=false;
        for(char ch:encoded_string){
            if(ch!='#' && y==false){
                size+=ch;
                continue;
            }
            if(ch=='#' && y==false){
                y=true;
                x=stoi(size);
                size="";

                if(x==0){
                    decoded_strs.push_back("");
                    y=false;
                }
                continue;
            }
            if(y){
                temp+=ch;
                x--;
            }
            if(x==0){
                y=false;
                decoded_strs.push_back(temp);
                temp="";
            }
            
        }
        return decoded_strs;

    }
};
