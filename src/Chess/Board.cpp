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

Board::~Board()
{
}

Piece* Board::getPiece(int index)
{
    return &board_data[index];
}

Piece* Board::getPiece(int row, int col)
{
    return &board_data[row*HEIGHT + col];
}

void Board::setPiece(int index, Piece* piece)
{
    board_data[index] = *piece;
}

void Board::setPiece(int row, int col, Piece* piece)
{
    board_data[row*HEIGHT + col] = *piece;
}

void Board::removePiece(int index)
{
    board_data[index] = Piece();
}

void Board::removePiece(int row, int col)
{
    board_data[row*HEIGHT + col] = Piece();
}

void Board::MovePiece(int row1,int col1,int row2, int col2)
{
    board_data[row2*HEIGHT + col2] = Piece();
    std::swap(board_data[row1*HEIGHT + col1],board_data[row2*HEIGHT + col2]);
}


void Board::RenderPieces(SDL_Renderer* renderer)
{
    // Load the texture containing the pieces
    SDL_Texture* piecesTexture = IMG_LoadTexture(renderer, "../assets/Pieces.png");
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
    const int spriteWidth = textureWidth / 6; // 6 columns (types of pieces)
    const int spriteHeight = textureHeight / 2; // 2 rows (factions: white and black)

    // Dimensions of the board cells
    const int cellWidth = 100;  // Width of a single board cell
    const int cellHeight = 100; // Height of a single board cell

    // Iterate over the board data
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        Piece& piece = board_data[i];

        // Skip empty cells
        if (piece.GetType() == Piece::Type_Empty) {
            continue;
        }

        // Calculate board position
        int col = i % WIDTH;
        int row = i / WIDTH;

        // Calculate screen position
        int x = col * cellWidth;
        int y = row * cellHeight;

        // Determine the source rectangle for the piece
        SDL_Rect srcRect = {
            (static_cast<int>(piece.GetType())-1) * spriteWidth, // x-offset in the texture
            piece.GetFaction() == Piece::White ? 0 : spriteHeight, // y-offset in the texture
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


