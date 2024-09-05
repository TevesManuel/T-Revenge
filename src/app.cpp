#include <Engine/Engine.hpp>
#include <GameObjects/Player/Player.hpp>
#include <GameObjects/Wall/Wall.hpp>

int main()
{
    Engine engine;
    Player player(&engine);
    Wall wall(&engine, WallTypes::NORMAL);
    engine.addObject(&player);
    engine.addObject(&wall);
    engine.run();
    return 0;
}
