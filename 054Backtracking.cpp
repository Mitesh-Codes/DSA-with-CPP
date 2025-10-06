#include<iostream>
#include<vector>
#include<string>

using namespace std;

//Question1: Rat in a Maze Problem  by Backtracking
//TC: O(4^(n^2)), SC: O(n^2)
bool isSafe(int newx,int newy, vector<vector<bool>> &visited,vector<vector<int>>&arr,int n){
    if((newx>=0 && newx<n)&&(newy>=0 && newy<n)&&visited[newx][newy]!=1 && arr[newx][newy]==1){
        return true;
    }
    else{
        return false;
    }
}
void solve(int x, int y, vector<vector<int>>&arr, int n, vector<string>&ans, vector<vector<bool>> &visited,string path){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    visited[x][y]=1;
    if(isSafe(x+1,y,visited,arr,n)){
        solve(x+1,y,arr,n,ans,visited,path+'D');
    }
    if(isSafe(x,y-1,visited,arr,n)){
        solve(x,y-1,arr,n,ans,visited,path+'L');
        
    }
    if(isSafe(x,y+1,visited,arr,n)){
        solve(x,y+1,arr,n,ans,visited,path+'R');
        
    }
    if(isSafe(x-1,y,visited,arr,n)){
        solve(x-1,y,arr,n,ans,visited,path+'U');
        
    }
    
    //or just use one for loop
    /*
    int dx[] = {1, 0, 0, -1};
    int dy[] = {0, -1, 1, 0};
    char moveChar[] = {'D', 'L', 'R', 'U'};

    for(int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (isSafe(newx, newy, visited, arr, n)) {
            solve(newx, newy, arr, n, ans, visited, path + moveChar[i]);
        }
    }
    
    */

    visited[x][y]=0;

}
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,0));
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    solve(0,0,arr,n,ans,visited,path);
    return ans;
}



//Question2: The N Queens Puzzle by Backtracking
//TC: O(N!), SC: O(N^2)
void addSolution(vector<vector<int>> &ans,vector<vector<int>>&board,int n){
	vector<int>temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}
bool isSafe(int row,int col,vector<vector<int>>&board,int n){
	int x=row;
	int y=col;
	while(y>=0){
		if(board[x][y]==1){
			return false;
		}
		y--;
	}

	x=row;
	y=col;
	while(x>=0 && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x--;
		y--;
	}

	x=row;
	y=col;
	while(x<n && y>=0){
		if(board[x][y]==1){
			return false;
		}
		x++;
		y--;
	}
	return true;

    //optimised approach using hashing // but Tc still O(N!) because of the recursive calls
    /*
    if(leftRow[row]==1 || upperDiagonal[n-1 + col - row]==1 || lowerDiagonal[row + col]==1){
        return false;
    }
    return true;
    */


}

void solve(int col,vector<vector<int>> &ans,vector<vector<int>>&board,int n){
	if(col==n){
		addSolution(ans,board,n);
		return;
	}
	for(int row=0;row<n;row++){
		if(isSafe(row,col,board,n)){
			board[row][col]=1;
			solve(col+1,ans,board,n);
			//Backtracking
			board[row][col]=0;
		}
	}
}
vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>>ans;

	solve(0,ans,board,n);
	return ans;

	
}


//Question3: Sudoku Solver by Backtracking
//TC: O(9^(n^2)), SC: O(1)
bool isSafe2(int row, int col,vector<vector<int>>& board,int val){
    for(int i=0;i<board.size();i++){
        if(board[row][i]==val){
            return false;
        }
        if(board[i][col]==val){
            return false;
        }
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val){
            return false;
        }
    }
    return true;
}
bool solve2(vector<vector<int>>& board){
    int n=board[0].size();
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            if(board[row][col]==0){
                for(int val=1;val<=9;val++){
                    if(isSafe2(row,col,board,val)){
                        board[row][col]=val;

                        bool nextSolutionPossible=solve2(board);
                        if(nextSolutionPossible){
                            return true;

                        }
                        else{
                            board[row][col]=0;
                        }
                    }
                    
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
    solve2(sudoku);
}





int main(){

//Question1: Rat in a Maze Problem by Backtracking
    // vector<vector<int>> arr{{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    // int n=arr.size();
    // vector<string> ans=searchMaze(arr,n);
    // for(auto it: ans){
    //     cout<<it<<" ";
    // }
    // cout<<endl;


//Question2: The N Queens Puzzle by Backtracking
    // int n=4;
    // vector<vector<int>> ans=nQueens(n);
    // for(auto it: ans){
    // 	for(auto i: it){
    // 		cout<<i<<" ";
    // 	}
    // 	cout<<endl;
    // }

//Question3: Sudoku Solver by Backtracking
    vector<vector<int>> sudoku{
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    solveSudoku(sudoku);
    for(auto it: sudoku){
        for(auto i: it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    





    return 0;
}