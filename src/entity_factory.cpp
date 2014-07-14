#include "entity_factory.h"
#include "simple_graphics_component.h"
#include "guy_input_component.h"

GameObject *EntityFactory::createGuy(Graphics &graphics) {
    return new GameObject(new SimpleGraphicsComponent("guy.png", graphics),
            new GuyInputComponent());
}
