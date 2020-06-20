#include <iostream>
#include <array>
#include<vector>
#include "helper.hpp"

int main() {

	// 8 winning combinations

	welcome();

	int player1 = 1;
	int player2 = 2;

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

		if (is_winning_board(board, winning_moves)) {
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
		remove_move(move_player1, valid_moves);
		print_board(board);

		if (is_winning_board(board, winning_moves)) {
			end_of_game = true;
			break;
		}
	}
}
