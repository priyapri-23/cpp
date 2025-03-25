var arr = [[], [], [], [], [], [], [], [], []]

for (var i = 0; i < 9; i++) {
	for (var j = 0; j < 9; j++) {
		arr[i][j] = document.getElementById(i * 9 + j);

	}
}


var board = [[], [], [], [], [], [], [], [], []]

function FillBoard(board) {
    for (var i = 0; i < 9; i++) {
        for (var j = 0; j < 9; j++) {
            if (board[i][j] != 0) {
                arr[i][j].innerText = board[i][j];
            } else {
                arr[i][j].innerText = '';
            }
        }
    }
}

let GetPuzzle = document.getElementById('GetPuzzle')
let SolvePuzzle = document.getElementById('SolvePuzzle')

GetPuzzle.onclick = function () {
	var xhrRequest = new XMLHttpRequest()
	xhrRequest.onload = function () {
		var response = JSON.parse(xhrRequest.response)
		console.log(response)
		board = response.board
		FillBoard(board)
	}
	xhrRequest.open('get', 'https://sugoku.onrender.com/board?difficulty=easy')
	//we can change the difficulty of the puzzle the allowed values of difficulty are easy, medium, hard and random
	xhrRequest.send()
}

SolvePuzzle.onclick = () => {
    console.log(board); // Check if the board is populated
    SudokuSolver(board, 0, 0, 9);
};

function isValid( board, i, j, num, n) { 
    // Row and column check
    for (let x = 0; x < n; x++) {
        if (board[i][x] == num || board[x][j] == num) {
            return false;
        }
    }

    // Submatrix check
    let rn = Math.sqrt(n); // Correctly cast the result of sqrt to an let
    let si = i - i % rn; // Starting index for the submatrix row
    let sj = j - j % rn; // Starting index for the submatrix column

    // Ensure loop bounds are within the board size
    for (let x = si; x < si + rn && x < n; x++) {
        for (let y = sj; y < sj + rn && y < n; y++) {
            if (board[x][y] == num) {
                return false;
            }
        }
    }

    return true; // Ensure the function returns true if all checks pass
}


function SudokuSolver(board, i, j, n) {
    function Sudoku_Solver(board, i, j, n) {
        // Base Case
        if (i == n) {
            FillBoard(board); // Update the UI with the solved board
            return true;
        }
        // If we reach the end of a row, move to the next row
        if (j == n) {
            return Sudoku_Solver(board, i + 1, 0, n);
        }
        // If the current cell is already filled, move to the next cell
        if (board[i][j] != 0) {
            return Sudoku_Solver(board, i, j + 1, n);
        }
        // Try filling the cell with numbers 1 to 9
        for (let num = 1; num <= 9; num++) {
            if (isValid(board, i, j, num, n)) {
                board[i][j] = num; // Place the number
                if (Sudoku_Solver(board, i, j + 1, n)) {
                    return true; // If the solution works, return true
                }
                board[i][j] = 0; // Backtrack if the solution doesn't work
            }
        }
        return false; // If no number works, return false
    }
    Sudoku_Solver(board, i, j, n);
}
