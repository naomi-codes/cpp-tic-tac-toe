
#include <iostream>
#include <vector>
/*
 * helper.hpp
 *
 *  Created on: 20 Jun 2020
 *      Author: zee
 */

#ifndef HELPER_HPP_
#define HELPER_HPP_




void welcome();
void set_valid_moves(std::vector<std::string> &valid_moves);
void remove_move(std::string move, std::vector<std::string> &valid_moves);
void set_winning_moves(std::vector<std::array<int,3> > &winning_moves);
void print_board(std::vector<std::string> board);
bool is_valid_move(std::vector<std::string> &valid_moves, std::string const &move_string, int &move);
void make_move(int const &player, int const &move,std::vector<std::string> &board);
bool is_winning_board(std::vector<std::string> &board, std::vector<std::array<int,3> > &winning_moves, int &winner);
bool is_winner(std::vector<std::array<int,3> > &winning_moves, char player,
		bool game_over, std::vector<std::string> &board);


#endif /* HELPER_HPP_ */
