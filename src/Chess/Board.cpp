//
// Created by Arch on 20/11/2024.
//

#include "Board.h"
#include <iterator>

using Piece::Rook,Piece::Knight,Piece::Bishop,Piece::King,Piece::Queen,Piece::Pawn,Piece::Black,Piece::White;

Board::Board()
{
    Piece temp_board_data[WIDTH*HEIGHT] =
    {
        Piece(Rook,Black),Piece(Knight,Black),Piece(Bishop,Black),Piece(Queen,Black),Piece(King,Black),Piece(Bishop,Black),Piece(Knight,Black),Piece(Rook,Black),
        Piece(Pawn,Black),Piece(Pawn,Black),Piece(Pawn,Black),Piece(Pawn,Black),Piece(Pawn,Black),Piece(Pawn,Black),Piece(Pawn,Black),Piece(Pawn,Black),
        Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),
        Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),
        Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),
        Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),Piece(),
        Piece(Pawn,White),Piece(Pawn,White),Piece(Pawn,White),Piece(Pawn,White),Piece(Pawn,White),Piece(Pawn,White),Piece(Pawn,White),Piece(Pawn,White),
        Piece(Rook,White),Piece(Knight,White),Piece(Bishop,White),Piece(Queen,White),Piece(King,White),Piece(Bishop,White),Piece(Knight,White),Piece(Rook,White)
    };
    std::copy(std::begin(temp_board_data), std::end(temp_board_data), std::begin(board_data));
}

