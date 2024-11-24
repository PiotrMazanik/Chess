#include "ChessScene.h"
#include <SDL2/SDL_image.h>


void ChessScene::init(SDL_Window* window, SDL_Renderer* renderer) {

    m_renderer = renderer;
    // Initialize the InputHandler
    //m_inputHandler = new InputHandler(&m_board);
    m_inputHandler = std::make_unique<InputHandler>(&m_board);

    // Load chessboard texture
    SDL_Surface* surface = SDL_LoadBMP("../assets/chess.bmp"); // Example file
    if (!surface) {
        SDL_Log("Failed to load chessboard texture: %s", SDL_GetError());
        return;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0) {
        SDL_Log("SDL could not initialize! SDL_Error: %s", SDL_GetError());
    }

    boardTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);


}

void ChessScene::handleInput(SDL_Event& e, SDL_Renderer* renderer) {
    // Ensure the input handler is initialized
    if (m_inputHandler) {
        m_inputHandler->HandleEvent(e, renderer);
    }
}

void ChessScene::update(float deltaTime) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            // Handle quit
            break;
        }

        SDL_Log("Event polled: %d", e.type); // Log event type
        handleInput(e, m_renderer);
        // Pass events to the input handler
    }

    // Update any other game logic if necessary
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
    m_inputHandler->RenderHighlight(renderer);

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