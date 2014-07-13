#ifndef SIMPLEGRAPHICSCOMPONENT_H
#define SIMPLEGRAPHICSCOMPONENT_H

#include "zombie_walk.h"
#include "graphics.h"

class SimpleGraphicsComponent : public GraphicsComponent {
    public:
        SimpleGraphicsComponent(const std::string &file, Graphics &graphics);
        ~SimpleGraphicsComponent();
        virtual void update(GameObject &object, const Graphics &graphics);

    private:
        const std::string assetPath(const std::string &file);
        SDL_Texture *texture;
};

#endif
