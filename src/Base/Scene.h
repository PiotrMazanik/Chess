#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>

class Scene {
public:
    virtual ~Scene() = default;

    // Initialize the scene (load textures, set up data, etc.)
    virtual void init(SDL_Window* window, SDL_Renderer* renderer) = 0;

    // Update the scene (game logic)
    virtual void update(float deltaTime) = 0;

    // Render the scene (draw to the screen)
    virtual void render(SDL_Renderer* renderer) = 0;

    // Clean up resources
    virtual void cleanup() = 0;
};

#endif // SCENE_H
