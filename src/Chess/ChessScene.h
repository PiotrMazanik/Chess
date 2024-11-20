#ifndef CHESSBOARD_SCENE_H
#define CHESSBOARD_SCENE_H

#include "../Base/Scene.h"
#include "Board.h"
#include <memory>
#include "inputHandler.h"

class ChessScene : public Scene {
public:
    void init(SDL_Window* window, SDL_Renderer* renderer) override;
    void handleInput(SDL_Event& e, SDL_Renderer* renderer);
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    void cleanup() override;

private:
    SDL_Texture* boardTexture = nullptr; // Chessboard texture
    SDL_Rect square;

    std::unique_ptr<InputHandler>m_inputHandler = nullptr; // Input handler
    Board m_board;
    SDL_Renderer* m_renderer = nullptr;
};

#endif // CHESSBOARD_SCENE_H
