#include "entity_factory.h"
#include "guy_graphics_component.h"
#include "guy_input_component.h"

GameObject *EntityFactory::createGuy(Graphics &graphics) {
    return new GameObject(new GuyGraphicsComponent(graphics),
            new GuyInputComponent());
}
