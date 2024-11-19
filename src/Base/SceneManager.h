//
// Created by Arch on 19/11/2024.
//

#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"
#include <memory>

class SceneManager {
public:
    void changeScene(std::shared_ptr<Scene> newScene, SDL_Window* window, SDL_Renderer* renderer);
    void update(float deltaTime);
    void render(SDL_Renderer* renderer);

private:
    std::shared_ptr<Scene> currentScene = nullptr;
};

#endif // SCENEMANAGER_H
