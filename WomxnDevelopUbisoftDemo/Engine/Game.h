#pragma once
#include <thread> //
#include <mutex> //

class Game {

public:
    Game(const char* windowTitle);
    virtual ~Game();

    void RunGameLoop();

protected:

    sf::RenderWindow* getWindow();

    // To override
    virtual void Update(float deltaTime) = 0;
    virtual void Render(sf::RenderTarget& target) = 0;
    virtual void RenderDebugMenu(sf::RenderTarget& target) = 0;
    virtual void HandleEvent(sf::Event event) = 0;

private:
    sf::RenderWindow m_Window;
    std::mutex mutex;
    bool toggleImGui;
};