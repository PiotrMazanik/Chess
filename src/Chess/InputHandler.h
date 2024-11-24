//
// Created by Arch on 20/11/2024.
//
#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H

#include <SDL.h>
#include <vector>

#include "Board.h"
#include "ScannedCell.h"

class InputHandler {
public:
    explicit InputHandler(Board* gameBoard);
    void HandleEvent(SDL_Event& e, SDL_Renderer* renderer);

    std::vector<ScannedCell>  ScanCells();
    void RenderHighlight(SDL_Renderer* renderer);
private:

    std::vector<ScannedCell> ScannedCells;

    bool pieceSelected = false; // Whether a piece is selected
    int selectedRow = -1;       // Row of the selected piece
    int selectedCol = -1;       // Column of the selected piece
    Board* board;               // Pointer to the chess board
    const int WIDTH = 8;
    const int HEIGHT = 8;
};

#endif //INPUTHANDLER_H