//
// Created by Arch on 20/11/2024.
//
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>
#include "Board.h"

class InputHandler {
private:
    bool pieceSelected = false; // Whether a piece is selected
    int selectedRow = -1;       // Row of the selected piece
    int selectedCol = -1;       // Column of the selected piece
    Board* board;               // Pointer to the chess board

public:
    explicit InputHandler(Board* gameBoard);
    void HandleEvent(SDL_Event& e, SDL_Renderer* renderer);
};

#endif //INPUTHANDLER_H