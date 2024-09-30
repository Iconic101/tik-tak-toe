#include <iostream> 
using namespace std; 

// Function to draw the Tic-Tac-Toe board 
void displayGrid(char gridMatrix[3][3]) 
{ 
	cout << "-------------\n"; 
	for (int row = 0; row < 3; row++) { 
		cout << "| "; 
		for (int col = 0; col < 3; col++) { 
			cout << gridMatrix[row][col] << " | "; 
		} 
		cout << "\n-------------\n"; 
	} 
} 

// Function to check if a player has won 
bool checkVictory(char gridMatrix[3][3], char activePlayer) 
{ 
	// Check rows, columns, and diagonals 
	for (int row = 0; row < 3; row++) { 
		if (gridMatrix[row][0] == activePlayer && gridMatrix[row][1] == activePlayer 
			&& gridMatrix[row][2] == activePlayer) 
			return true; 
		if (gridMatrix[0][row] == activePlayer && gridMatrix[1][row] == activePlayer 
			&& gridMatrix[2][row] == activePlayer) 
			return true; 
	} 
	// Check diagonals 
	if (gridMatrix[0][0] == activePlayer && gridMatrix[1][1] == activePlayer 
		&& gridMatrix[2][2] == activePlayer) 
		return true; 
	if (gridMatrix[0][2] == activePlayer && gridMatrix[1][1] == activePlayer 
		&& gridMatrix[2][0] == activePlayer) 
		return true; 
	return false; 
} 

// Function to reset the game board 
void clearGrid(char gridMatrix[3][3]) {
	for (int row = 0; row < 3; row++) { 
		for (int col = 0; col < 3; col++) { 
			gridMatrix[row][col] = ' '; 
		} 
	} 
}

int main() 
{ 
	char gridMatrix[3][3]; 
	char currentPlayer; 
	int inputRow, inputCol; 
	int movesMade; 

	while (true) { // Game restarts if an invalid move is made
		// Initialize/reset the game board and players 
		clearGrid(gridMatrix); 
		currentPlayer = 'X'; 

		cout << "Welcome to Tic-Tac-Toe!\n"; 

		// Main game loop 
		for (movesMade = 0; movesMade < 9; movesMade++) { 
			// Render the current state of the board 
			displayGrid(gridMatrix); 

			// Get valid input from the player 
			while (true) { 
				cout << "Player " << currentPlayer 
					<< ", enter row (0-2) and column (0-2): "; 
				cin >> inputRow >> inputCol; 

				// If input is invalid, restart the entire game 
				if (inputRow < 0 || inputRow > 2 || inputCol < 0 || inputCol > 2) {
					cout << "Invalid move. Restarting the game...\n";
					break; // Break to restart the game 
				}

				// Check if the chosen position is valid 
				if (gridMatrix[inputRow][inputCol] != ' ') { 
					cout << "Invalid move. Restarting the game...\n"; 
					break; // Restart game if invalid move
				} 
				else { 
					gridMatrix[inputRow][inputCol] = currentPlayer; 
					break; // Valid move, exit the input loop 
				} 
			}

			// Check if we need to restart the game due to invalid input
			if (inputRow < 0 || inputRow > 2 || inputCol < 0 || inputCol > 2 || gridMatrix[inputRow][inputCol] != currentPlayer) {
				break; // Go back to the beginning of the game
			}

			// Check if the current player has won 
			if (checkVictory(gridMatrix, currentPlayer)) { 
				displayGrid(gridMatrix); 
				cout << "Player " << currentPlayer << " wins!\n"; 
				break; // End the game if there is a winner 
			} 

			// Switch players for the next turn 
			currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; 
		} 

		// Draw the final state of the board 
		displayGrid(gridMatrix); 

		// Check for a draw if all turns are used up without a winner 
		if (movesMade == 9 && !checkVictory(gridMatrix, 'X') 
			&& !checkVictory(gridMatrix, 'O')) { 
			cout << "It's a draw!\n"; 
		} 

		// Option to replay the game 
		cout << "Do you want to play again? (y/n): "; 
		char restartGame;
		cin >> restartGame;
		if (restartGame != 'y' && restartGame != 'Y') {
			cout << "Goodbye!\n";
			break; // Exit the game loop if the player doesn't want to play again
		}
	}

	return 0; 
}
