#include "entity_factory.h"

GameObject *EntityFactory::createGuy(Graphics &graphics) {
    return new GameObject(new SimpleGraphicsComponent("guy.png", graphics),
            new GuyInputComponent());
}
