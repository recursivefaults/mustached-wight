#ifndef SIMPLEGRAPHICSCOMPONENT_H
#define SIMPLEGRAPHICSCOMPONENT_H

#include <string>

#include "zombie_walk.h"

#include "game_object.h"
#include "graphics_component.h"
#include "graphics.h"

class SimpleGraphicsComponent : public GraphicsComponent {
    public:
        SimpleGraphicsComponent(const std::string &file, Graphics &graphics);
        ~SimpleGraphicsComponent();
        void update(GameObject &object, Graphics &graphics);

    private:
        SDL_Rect getTileAt(int tileX, int tileY);
        const std::string assetPath(const std::string &file);
        SDL_Rect currentLocation;
        SDL_Texture *texture;
};

#endif
