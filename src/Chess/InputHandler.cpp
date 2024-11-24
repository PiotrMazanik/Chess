//
// Created by Arch on 20/11/2024.
//

#include "InputHandler.h"

using cell_type = ScannedCell::cell_type;

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
            if ((selectedRow != clickedRow || selectedCol != clickedCol) &&
                board->getPiece(selectedRow, selectedCol)->GetFaction() != board->getPiece(clickedRow, clickedCol)->GetFaction())
            {
                board->MovePiece(selectedRow, selectedCol, clickedRow, clickedCol);
                pieceSelected = false;
            SDL_Log("Moved piece to (%d, %d)", clickedRow, clickedCol);
            }
            else
            {
            SDL_Log("Failed to Move piece to (%d, %d)", clickedRow, clickedCol);
                pieceSelected = false;

            }
            // Optional: redraw the board after the move
            board->RenderPieces(renderer);
            RenderHighlight(renderer);
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
    else
    {
        cells.clear();
        return cells;
    }
    Piece* selectedPiece = board->getPiece(selectedRow, selectedCol);

    int direction = 0;
    if (selectedPiece->GetFaction()== Piece::Black)
    {
        direction = 1;
    }
    else if (selectedPiece->GetFaction() == Piece::White)
    {
        direction = -1;
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
        if((direction == 1 && selectedRow  == 1)||(direction == -1 && selectedRow  == 6))
        {
            if(board->getPiece(selectedRow+direction+direction,selectedCol)->GetType() == Piece::Type_Empty)
            {
                cells.push_back(ScannedCell(cell_type::canMoveTo,selectedRow+direction+direction,selectedCol));
            }
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

void InputHandler::RenderHighlight(SDL_Renderer* renderer)
{
    ScannedCells = ScanCells();

    // Load the texture containing the pieces
    SDL_Texture* piecesTexture = IMG_LoadTexture(renderer, "../assets/Highlight.png");
    if (!piecesTexture) {
        SDL_Log("Failed to load texture: %s", SDL_GetError());
        return;
    }

    // Query the dimensions of the texture
    int textureWidth, textureHeight;
    if (SDL_QueryTexture(piecesTexture, nullptr, nullptr, &textureWidth, &textureHeight) != 0) {
        SDL_Log("Failed to query texture: %s", SDL_GetError());
        SDL_DestroyTexture(piecesTexture);
        return;
    }

    // Calculate sprite dimensions dynamically
    const int spriteWidth = textureWidth / 3; // 6 columns (types of pieces)
    const int spriteHeight = textureHeight / 1; // 2 rows (factions: white and black)

    // Dimensions of the board cells
    const int cellWidth = 100;  // Width of a single board cell
    const int cellHeight = 100; // Height of a single board cell

    // Iterate over the board data
    for (int i = 0; i <ScannedCells.size() ; i++) {
        ScannedCell& cell = ScannedCells[i];

        // Calculate screen position
        int x = cell.Get_X() * cellWidth;
        int y = cell.Get_Y() * cellHeight;


        int sprite_offset_x = 0;
        int sprite_offset_y = 0;
        switch (cell.Get_Type())
        {
        case cell_type::blank:
            continue;
        case cell_type::CanCapture:
            sprite_offset_x = spriteWidth;
            break;
        case cell_type::canMoveTo:
            sprite_offset_y = 0;
            sprite_offset_x = 0;
            break;
        case cell_type::selectedCell:
            sprite_offset_x = spriteWidth*2;
            break;

        }
        // Determine the source rectangle for the piece
        SDL_Rect srcRect = {
            sprite_offset_x, // x-offset in the texture
            sprite_offset_y, // y-offset in the texture
            spriteWidth,
            spriteHeight
        };

        // Destination rectangle on the screen
        SDL_Rect destRect = { x, y, cellWidth, cellHeight };

        // Render the piece
        SDL_RenderCopy(renderer, piecesTexture, &srcRect, &destRect);
    }

    // Clean up the texture after rendering
    SDL_DestroyTexture(piecesTexture);
}