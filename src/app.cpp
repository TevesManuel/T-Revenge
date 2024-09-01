#include <Window/Window.hpp>
#include <GameObjects/Player/Player.hpp>

int main()
{
    Window window;
    Player player(&window);
    window.addObject(&player);
    window.run();
    return 0;
}
