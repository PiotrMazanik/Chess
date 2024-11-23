//
// Created by Arch on 20/11/2024.
//

#include "InputHandler.h"

using ScannedCell::cell_type;

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

std::vector<ScannedCell> InputHandler::ScanCells()
{
    std::vector<ScannedCell> cells;
    if(pieceSelected)
    {
        cells.push_back(ScannedCell(cell_type::selectedCell,selectedRow, selectedCol));
    }
    Piece* selectedPiece = board->getPiece(selectedRow, selectedCol);

    int direction = 0;
    if (selectedPiece->GetFaction()== Piece::Black)
    {
        direction = -1;
    }
    else if (selectedPiece->GetFaction() == Piece::White)
    {
        direction = 1;
    }

switch (selectedPiece->GetType())
{
    case Piece::Type_Empty:
        break;
case Piece::Pawn:
        if(board->getPiece(selectedRow+direction,selectedCol)->GetType() == Piece::Type_Empty)
        {
            cells.push_back(ScannedCell(cell_type::canMoveTo,selectedRow+direction,selectedCol));
        }
        if(board->getPiece(selectedRow+direction+direction,selectedCol)->GetType() == Piece::Type_Empty)
        {
            cells.push_back(ScannedCell(cell_type::canMoveTo,selectedRow+direction+direction,selectedCol));
        }
        if(board->getPiece(selectedRow+direction,selectedCol+1)->GetType() != Piece::Type_Empty)
        {
            cells.push_back(ScannedCell(cell_type::CanCapture,selectedRow+direction,selectedCol+1));
        }
        if(board->getPiece(selectedRow+direction,selectedCol+1)->GetType() != Piece::Type_Empty)
        {
           cells.push_back(ScannedCell(cell_type::CanCapture,selectedRow+direction,selectedCol-1));
        }
        break;
    case Piece::Knight:
        break;
    case Piece::Bishop:
        break;
    case Piece::Rook:
        break;
    case Piece::Queen:
        break;
    case Piece::King:
        break;


}
return cells;
}