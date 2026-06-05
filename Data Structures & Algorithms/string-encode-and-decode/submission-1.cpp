class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";

        for (auto str : strs) {
            result += to_string(str.size());
            result += '#';
            result += str;
        }

        return result;
    }

    vector<string> decode(string s) {
        int l = 0;
        vector<string> result;

        while (l < s.size()) {
            string lenStr = "";
            while (l < s.size() && s[l] != '#') {
                lenStr += s[l];
                l++;
            }
            
            int len = stoi(lenStr);
            if (s[l++] != '#') return result;
            result.push_back(s.substr(l, len));
            l += len;
        }

        return result;
    }
};
