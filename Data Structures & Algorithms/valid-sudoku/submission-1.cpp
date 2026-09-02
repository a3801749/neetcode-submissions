class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // iterate through the entire board

        // for every point that you get, add it to an unordered map where
        // we each char is paired with a vector of coordinates it sits at

        // then, for each coordinate, we would run checks

        unordered_map<char, vector<pair<int, int>>> helper;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char current = board[r][c];
                if (current == '.') continue;
                auto it = helper.find(current);

                if (it == helper.end()) {
                    vector<pair<int, int>> v{{r, c}};
                    helper.insert({current, v});
                }

                else {
                    for (pair<int, int> coordinate : it->second) {
                        if (coordinate.first == r || coordinate.second == c) {
                            cout << "Current at: " << r << " " << c << endl;
                            return false;
                        }
                        else if (coordinate.first/3 == r/3 && coordinate.second/3 == c/3) {
                            cout << "Current at: " << r << " " << c << endl;
                            cout << "Match at: " << coordinate.first/3 << " " << coordinate.second/3 << endl;
                            return false;
                        }
                    }
                    helper[current].push_back({r, c});
                }
            }
        }
        return true;
    }
};
