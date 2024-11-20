//
// Created by Arch on 20/11/2024.
//

#ifndef BOARD_H
#define BOARD_H

#include "Piece.h"


class Board
{
public:
    Board();
    ~Board();
    Piece* getPiece(int row, int col);
    Piece* getPiece(int index);
    void setPiece(int row, int col, Piece* piece);
    void setPiece(int index, Piece* piece);
    void removePiece(int row, int col);
    void removePiece(int index);

    void MovePiece(int row, int col);

private:
    const static int WIDTH = 8;
    const static int HEIGHT = 8;
    Piece board_data[WIDTH*HEIGHT];
};

#endif //BOARD_H
