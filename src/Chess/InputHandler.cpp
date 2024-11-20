//
// Created by Arch on 20/11/2024.
//

#include "InputHandler.h"

InputHandler::InputHandler(Board* gameBoard) : board(gameBoard) {}

void InputHandler::HandleEvent(SDL_Event& e, SDL_Renderer* renderer) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        // Calculate the clicked cell
        const int cellWidth = 100;  // Board cell width
        const int cellHeight = 100; // Board cell height
        int clickedCol = mouseX / cellWidth;
        int clickedRow = mouseY / cellHeight;

        if (!pieceSelected) {
            // First click: select a piece
            Piece* selectedPiece = board->getPiece(clickedRow, clickedCol);
            if (selectedPiece->GetType() != Piece::Type_Empty) {
                pieceSelected = true;
                selectedRow = clickedRow;
                selectedCol = clickedCol;
                SDL_Log("Piece selected at (%d, %d)", selectedRow, selectedCol);
            }
        } else {
            // Second click: move the piece
            board->MovePiece(selectedRow, selectedCol, clickedRow, clickedCol);
            pieceSelected = false;
            SDL_Log("Moved piece to (%d, %d)", clickedRow, clickedCol);

            // Optional: redraw the board after the move
            board->RenderPieces(renderer);
            SDL_RenderPresent(renderer);
        }
    }
}