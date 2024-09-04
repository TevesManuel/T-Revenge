#include <Window/Window.hpp>
#include <GameObjects/Player/Player.hpp>
#include <GameObjects/Wall/Wall.hpp>
#include <GameObjects/Player/Bullet/Bullet.hpp>

int main()
{
    Window window;
    Player player(&window);
    Wall wall(&window, WallTypes::NORMAL);
    Bullet bullet;
    window.addObject(&player);
    window.addObject(&wall);
    window.addObject(&bullet);
    window.run();
    return 0;
}
