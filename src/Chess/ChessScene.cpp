#include "ChessScene.h"
#include <SDL2/SDL_image.h>


void ChessScene::init(SDL_Window* window, SDL_Renderer* renderer) {
    // Load chessboard texture
    SDL_Surface* surface = SDL_LoadBMP("../assets/chess.bmp"); // Example file
    if (!surface) {
        SDL_Log("Failed to load chessboard texture: %s", SDL_GetError());
        return;
    }
    boardTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

}

void ChessScene::update(float deltaTime) {
    // Handle chess logic (if any) here
}

void ChessScene::render(SDL_Renderer* renderer) {
    // Clear the screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Render the chessboard
    if (boardTexture) {
        SDL_RenderCopy(renderer, boardTexture, nullptr, nullptr);
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    m_board.RenderPieces(renderer);

    // Present the rendered content
    SDL_RenderPresent(renderer);
}

void ChessScene::cleanup() {
    // Free resources
    if (boardTexture) {
        SDL_DestroyTexture(boardTexture);
        boardTexture = nullptr;
    }
}