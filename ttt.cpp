#include <iostream>
#include <array>
#include<vector>
#include "helper.hpp"

/**
 * Author: Naomi Lambert
 *
 * Main classs responsible for the execution of the main game loop
 */
int main() {

	welcome();

	// constants to hold the player numbers
	int const player1 = 1;
	int const player2 = 2;

	//variable to hold the final winner
	int winner = 0;

	//whether or not the end of the game has been reached
	bool end_of_game = false;
	std::vector<std::string> valid_moves;
	set_valid_moves(valid_moves);

	std::vector<std::array<int,3> > winning_moves;
	set_winning_moves(winning_moves);

	std::vector<std::string> board;

	for (int i = 0; i <10; i++) {
		board.push_back(" ");
	}
	while (!end_of_game) {

		print_board(board);
		std::string move_player1;
		std::string move_player2;

		int move_p1;

		while (!is_valid_move(valid_moves, move_player1, move_p1)) {
			std::cout << "Player 1: ";
			std::cin >> move_player1;

			if (move_player1 == "Q") {
				exit(0);
			}
		}

		make_move(player1, move_p1, board);
		remove_move(move_player1, valid_moves);
		print_board(board);

		if (is_winning_board(board, winning_moves, winner)) {
			end_of_game = true;
			break;
		}

		int move_p2;

		while (!is_valid_move(valid_moves, move_player2, move_p2)) {
			std::cout << "Player 2: ";
			std::cin >> move_player2;

			if (move_player2 == "Q") {
				exit(0);
			}
		}

		make_move(player2, move_p2, board);
		remove_move(move_player2, valid_moves);
		print_board(board);

		if (is_winning_board(board, winning_moves, winner)) {
			end_of_game = true;
			break;
		}

		if (end_of_game) {
				std::cout << "The winner is Player " << winner << "!\n";
			}
	}


}
