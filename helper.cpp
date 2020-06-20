
#include "helper.hpp"
#include <iostream>
#include <vector>
#include <array>

void set_valid_moves(std::vector<std::string> &valid_moves) {

	valid_moves.push_back("1a");
	valid_moves.push_back("1b");
	valid_moves.push_back("1c");
	valid_moves.push_back("2a");
	valid_moves.push_back("2b");
	valid_moves.push_back("2c");
	valid_moves.push_back("3a");
	valid_moves.push_back("3b");
	valid_moves.push_back("3c");
}

void remove_move(std::string move, std::vector<std::string> &valid_moves) {
	for (int i = 0; i < valid_moves.size(); i++ ){
		if ( valid_moves[i] == move) {
			valid_moves[i] = " ";
		}
	}
}

void set_winning_moves(std::vector<std::array<int,3> > &winning_moves) {
	std::array<int, 3> mv = {0,1,2};
	winning_moves.push_back(mv);

	std::array<int, 3> mv1 = {3,4,5};
	winning_moves.push_back(mv1);

	std::array<int, 3> mv2 = {6,7,8};
	winning_moves.push_back(mv2);

	std::array<int, 3> mv3 = {0,3,6};
	winning_moves.push_back(mv3);

	std::array<int, 3> mv4 = {1,4,7};
	winning_moves.push_back(mv4);

	std::array<int, 3> mv5 = {2,5,8};
	winning_moves.push_back(mv5);

	std::array<int, 3> mv6 = {2,4,6};
	winning_moves.push_back(mv6);

	std::array<int, 3> mv7 = {0,4,8};
	winning_moves.push_back(mv7);

}

bool is_valid_move(std::vector<std::string> &valid_moves, std::string const &move_string, int &move) {

	for (int i = 0; i < valid_moves.size(); i++) {
		if (valid_moves[i] == move_string) {
			move = i;
			return true;
		}
	}

	return false;
}

void make_move(int const &player, int const &move,std::vector<std::string> &board ) {

	if (player == 1) {
		board[move] = "X";
	} else if (player == 2) {
		board[move] = "O";
	}
}


bool is_winner(std::vector<std::array<int,3> > &winning_moves, char player,
		bool game_over, std::vector<std::string> &board) {

	int match = 0;
	for (int i = 0; i < winning_moves.size(); i++) {

		std::array<int, 3> curr_move = winning_moves[i];

		for (int i = 0; i < curr_move.size(); i++) {
			if (board[curr_move[i]].at(0) == player) {
				match++;
			}
		}
		if (match == 3) {
			game_over = true;
		}
		match = 0;
	}
	return game_over;
}

bool is_winning_board(std::vector<std::string> &board, std::vector<std::array<int,3> > &winning_moves) {
	char p1 = 'X';
	char p2 = 'O';
	bool game_over = false;

	game_over = is_winner(winning_moves, p1, game_over, board);
	game_over = is_winner(winning_moves, p2, game_over, board);

	return game_over;
}


void welcome(){
	std::cout << "============\n";
	std::cout << "TIC TAC TOE\n";
	std::cout << "============\n";
	std::cout << "Welcome to the classic game Tic Tac Toe\n";
	std::cout << "for two players (You and a friend!).\n";
	std::cout << "Player 1 is always X and Player 2 is always O.";
	std::cout << "To make a move, enter the coordinates of the square you would like to mark. E.g. b2.\n";
	std::cout << "Type Q at any time to quit\n";

}

void print_board(std::vector<std::string> board){
	std::cout << "\n     a       b       c   \n";
	std::cout << "         |       |       \n";
	std::cout << "1    " << board[0] << "   |   " << board[1]<< "   |   " << board[2] << "   \n";
	std::cout << "  _______|_______|_______\n";
	std::cout << "         |       |       \n";
	std::cout << "2    " << board[3] << "   |   " << board[4] << "   |   " << board[5] << "   \n";
	std::cout << "  _______|_______|_______\n";
	std::cout << "         |       |       \n";
	std::cout << "3    " << board[6] << "   |   " << board[7] << "   |   " << board[8] << "   \n";
	std::cout << "         |       |       \n";
}
