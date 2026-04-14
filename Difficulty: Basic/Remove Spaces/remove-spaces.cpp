class Solution {
  public:
    string removeSpaces(string& s) {
        // code here
        stringstream ss(s);
        string word,result="";
        while(ss>>word)
        {
            result+=word;
        }
        return result;
    }
};