#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <climits>
#include <bit>
#include <cmath>
using namespace std;


class Solution {
    public:
        unsigned Row[9] = {0};
        unsigned Col[9] = {0};
        unsigned Block[9] = {0};
        vector<pair<char, char>> uncertain;
    
        void json_print(vector<vector<char>>& board) {
            cout << "[\n";
            for(int i=0;i<9;i++){
            cout << " [";
            for(int j=0;j<9;j++){
            cout << '"' << board[i][j] << '"';
            if(j<8) cout << ",";
            }
            cout << "]" << (i<8?",":"") << "\n";
            }
            cout << "]\n";
        }
    

        void print(vector<vector<char>>& board) {
            cout << "+-------+-------+-------+" << endl;
            for (int i = 0; i < 9; i++) {
                cout << "| ";
                for (int j = 0; j < 9; j++) {
                    cout << board[i][j] << " ";
                    if ((j + 1) % 3 == 0) {
                        cout << "| ";
                    }
                }
                cout << endl;
                if ((i + 1) % 3 == 0 && i != 8) {
                    cout << "+-------+-------+-------+" << endl;
                }
            }
            cout << "+-------+-------+-------+" << endl;
        }
        void set3Cond(int i, int j, int x) {
            const int x2 = 1 << x;
            Row[i] |= x2;
            Col[j] |= x2;
            const int bidx = (i / 3) * 3 + j / 3;
            Block[bidx] |= x2;
        }
        void setup(vector<vector<char>>& board) {
            uncertain.reserve(81);
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    char c = board[i][j];
                    if (c == '.') {
                        uncertain.emplace_back(i, j);
                    } else {
                        set3Cond(i, j, c - '1');
                    }
                }
            }
        }
        bool solve(vector<vector<char>>& board, int idx) {
            if (idx == uncertain.size())
                return 1;
            auto [i, j] = uncertain[idx];
            const int bidx = (i / 3) * 3 + j / 3;
            unsigned not_mask = ~(Row[i] | Col[j] | Block[bidx]) & 0b111111111;
            unsigned Bit = 0;
    
            for (; not_mask; not_mask ^= Bit) {
                Bit = std::bit_floor(not_mask);
                const int x = std::countr_zero(Bit);
    
                board[i][j] = '1' + x;
                Row[i] |= Bit;
                Col[j] |= Bit;
                Block[bidx] |= Bit;
                if (solve(board, idx + 1)) {
                    return 1;
                }
                Row[i] ^= Bit;
                Col[j] ^= Bit;
                Block[bidx] ^= Bit;
                board[i][j] = '.';
            }
            return 0;
        }
        void solveSudoku(vector<vector<char>>& board) {
            // cout<<"Initial board:"<<endl;
            // print(board);
            // cout<<endl;
            setup(board);
            solve(board,0);
            // cout<<"Solved board:"<<endl;
            // print(board);
        }
};

int main(){
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    Solution s;
    s.solveSudoku(board);
    s.json_print(board);
    return 0;
}