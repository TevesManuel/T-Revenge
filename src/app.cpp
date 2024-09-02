#include <Window/Window.hpp>
#include <GameObjects/Player/Player.hpp>
#include <GameObjects/Wall/Wall.hpp>

int main()
{
    Window window;
    Player player(&window);
    Wall wall(WallTypes::NORMAL);
    window.addObject(&player);
    window.addObject(&wall);
    window.run();
    return 0;
}
