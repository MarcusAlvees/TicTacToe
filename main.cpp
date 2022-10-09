#include <stdio.h>
#include <iostream>

using namespace std;

char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '},{' ', ' ', ' '}};
int rows, columns;
char _playerturn = 'O';
int choice;
char winner;
bool velha;

void player_turn() {
	cout << "     |     |     \n";
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
	cout << "_____|_____|_____\n";
	cout << "     |     |     \n";
	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
	cout << "     |     |     \n";

	cout << "PLAYER[" << _playerturn << "] TURN: ";
	cin >> choice;

	switch (choice) {
	case 1:
		rows = 0; columns = 0; break;
	case 2:
		rows = 0; columns = 1; break;
	case 3:
		rows = 0; columns = 2; break;
	case 4:
		rows = 1; columns = 0; break;
	case 5:
		rows = 1; columns = 1; break;
	case 6:
		rows = 1; columns = 2; break;
	case 7:
		rows = 2; columns = 0; break;
	case 8:
		rows = 2; columns = 1; break;
	case 9:
		rows = 2; columns = 2; break;
	}

	if ('O' != board[rows][columns] && 'X' != board[rows][columns]) {
		board[rows][columns] = _playerturn;
		system("cls");

		if (_playerturn == 'X') { _playerturn = 'O'; return; }
		if (_playerturn == 'O') { _playerturn = 'X'; return; }
	}
	else {
		system("cls");
		cout << "CHOOSE ANOTHER TILE\n";
		return;
	}
}

bool gameover() {
	for (int i = 0; i < 2; i++) {
		for (int y = 0; y < 2; y++){
			if (board[i][y] != ' ') {
				if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
					winner = board[i][0];
					return true;
				}
			}
			else { return false; }
		}
		for (int y = 0; y < 2; y++) {
			if (board[y][i] != ' ') {
				if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
					winner = board[0][i];
					return true;
				}
			}
			else { return false; }
		}
	}
	for (int i = 0; i < 2; i++)
	{
		for (int y = 0; y < 2; y++)
		{
			if (board[i][y] == ' ') {
				return false;
			}
			if (board[2][2] != ' ') {
				velha = true;
				return true;
			}
		}
	}
	return false;
}

int main() {
	while (!gameover()) {
		player_turn();
	}
	if (velha == true)
	{
		cout << "VELHA";
	}
	else { cout << "THE WINNER IS " << winner; }
}
