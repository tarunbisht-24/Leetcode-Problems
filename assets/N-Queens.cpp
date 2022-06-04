class Solution {
public:
    vector<vector<string> > sols; // 2D vector of strings to store the solutions
    vector<vector<string>> solveNQueens(int n) {    
	    vector<string> board(n, string(n, '.'));  // creating an empty board
	    solve(board, 0); // calling the recursive function
	    return sols; 
    }
    bool isSafe(vector<string>& board, int row, int col) {
	    int n = size(board);
	    for(int i = 0; i < n; i++) {
			// checking if there is a queen in the same column
		    if(board[i][col] == 'Q') return false; 
		    // checking if there is a queen in the same diagonal (left to right)
		    if(row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
		    if(row - i >= 0 && col + i <  n && board[row - i][col + i] == 'Q') return false;
	    }
	    return true;
    }

    void solve(vector<string>& board, int row) {
	    if(row == size(board)) { 
		    sols.push_back(board);
		    return;
    	}            
	    
	    for(int col = 0; col < size(board); col++){
		    if(isSafe(board, row, col)) {
			    board[row][col] = 'Q';    // Queen placed on a valid cell
			    solve(board, row + 1);    // Exploring next row
			    board[row][col] = '.';    // Backtracking to get all possible solutions
		    }
        }
    }
};
