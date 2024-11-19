//
// Created by Arch on 19/11/2024.
//
#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include "SceneManager.h"

class Game {
public:
    Game();
    ~Game();

    // Main game loop
    void run();

private:
    // Helper methods
    void init();
    void handleEvents();
    void update(float deltaTime);
    void render();
    void cleanup();

    // SDL variables
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;

    // Game state
    bool running = true;

    // Scene management
    SceneManager sceneManager;

    // Timing
    Uint32 lastTime = 0;
};

#endif // GAME_H
