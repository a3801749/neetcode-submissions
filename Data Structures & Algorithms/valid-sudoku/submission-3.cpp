class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // iterate through the entire board

        // for every point that you get, add it to an unordered map where
        // we each char is paired with a vector of coordinates it sits at

        // then, for each coordinate, we would run checks

        unordered_map<char, unordered_set<int>> row_hash;
        unordered_map<char, unordered_set<int>> col_hash;
        unordered_map<char, unordered_set<int>> square_hash;

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char current = board[r][c];
                if (current == '.') continue;

                auto row_it = row_hash.find(current);
                if (row_it == row_hash.end()) {
                    unordered_set<int> s;
                    s.insert(r);
                    row_hash.insert({current, s});
                }
                else {
                    if (row_it->second.contains(r)) {
                        return false;
                    }
                    else row_it->second.insert(r);
                }

                auto col_it = col_hash.find(current);
                if (col_it == col_hash.end()) {
                    unordered_set<int> s;
                    s.insert(c);
                    col_hash.insert({current, s});
                }
                else {
                    if (col_it->second.contains(c)) {
                        return false;
                    }
                    else col_it->second.insert(c);
                }

                int square = (r / 3) * 3 + (c / 3);
                auto square_it = square_hash.find(current);
                if (square_it == square_hash.end()) {
                    unordered_set<int> s;
                    s.insert(square);
                    square_hash.insert({current, s});
                }
                else {
                    if (square_it->second.contains(square)) {
                        return false;
                    }
                    else square_it->second.insert(square);
                }
            }
        }
        return true;
    }
};
