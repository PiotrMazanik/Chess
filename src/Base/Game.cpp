//
// Created by Arch on 19/11/2024.
//
#include "Game.h"
#include "../Chess/ChessScene.h"
#include <SDL2/SDL.h>
#include <memory>

Game::Game() {
    init();
}

Game::~Game() {
    cleanup();
}

void Game::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        running = false;
        return;
    }

    window = SDL_CreateWindow("Chess Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, 0);
    if (!window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        running = false;
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        running = false;
        return;
    }

    // Initialize the first scene
    sceneManager.changeScene(std::make_shared<ChessScene>(), window, renderer);

    lastTime = SDL_GetTicks();
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }

        // Forward event to the current scene
        sceneManager.handleInput(event, renderer);
    }
}

void Game::update(float deltaTime) {
    sceneManager.update(deltaTime);
}

void Game::render() {
    sceneManager.render(renderer);
}

void Game::cleanup() {
    sceneManager.changeScene(nullptr, window, renderer); // Cleanup the current scene

    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    SDL_Quit();
}

void Game::run() {
    while (running) {
        Uint32 currentTime = SDL_GetTicks();
        float deltaTime = (currentTime - lastTime) / 1000.0f;
        lastTime = currentTime;

        handleEvents();
        update(deltaTime);
        render();
    }
}