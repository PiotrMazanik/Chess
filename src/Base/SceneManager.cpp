//
// Created by Arch on 19/11/2024.
//
#include "SceneManager.h"

void SceneManager::changeScene(std::shared_ptr<Scene> newScene, SDL_Window* window, SDL_Renderer* renderer) {
    if (currentScene) {
        currentScene->cleanup();
    }
    currentScene = newScene;
    if (currentScene) {
        currentScene->init(window, renderer);
    }
}

void SceneManager::update(float deltaTime) {
    if (currentScene) {
        currentScene->update(deltaTime);
    }
}

void SceneManager::render(SDL_Renderer* renderer) {
    if (currentScene) {
        currentScene->render(renderer);
    }
}