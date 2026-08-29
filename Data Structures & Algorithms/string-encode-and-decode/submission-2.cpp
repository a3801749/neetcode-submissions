class Solution {
public:

    string encode(vector<string>& strs) {
        // for each string, find the length of the string
        // then, affix that to the beginning of the string, and then add the string
        string result = "";
        for (string str : strs) {
            int size_int = str.size();
            string size = to_string(size_int);
            result += size;
            result += " ";
            result += str;
        }
        cout << result << endl;
        return result;  
    }

    vector<string> decode(string s) {
        vector<string> result;
        int index = 0;

        while (index < s.size()) {
            string int_str;
            while (s.substr(index, 1) != " ") {
                int_str += s[index];
                index++;
            }
            int substr_size = stoi(int_str);
            cout << substr_size << " ";
            index++;

            string substr = s.substr(index, substr_size);
            cout << substr;
            result.push_back(substr);

            index += (substr_size);
            cout << " " << index << endl;
        }

        return result;
    }
};
