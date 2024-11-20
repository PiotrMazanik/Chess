#ifndef CHESSBOARD_SCENE_H
#define CHESSBOARD_SCENE_H

#include "../Base/Scene.h"
#include "Board.h"

class ChessScene : public Scene {
public:
    void init(SDL_Window* window, SDL_Renderer* renderer) override;
    void update(float deltaTime) override;
    void render(SDL_Renderer* renderer) override;
    void cleanup() override;

private:
    SDL_Texture* boardTexture = nullptr; // Chessboard texture
    SDL_Rect square;

    Board m_board;
};

#endif // CHESSBOARD_SCENE_H
