#include <stdafx.h>
#include <Engine/Game.h>

static constexpr float APP_MAX_FRAMERATE{ 60.0f };
static const sf::Vector2u APP_INIT_WINDOW_SIZE{ 1024, 768 };

Game::Game(const char* windowTitle) : m_Window{ sf::VideoMode(APP_INIT_WINDOW_SIZE.x, APP_INIT_WINDOW_SIZE.y), windowTitle, sf::Style::Titlebar | sf::Style::Close }{
    m_Window.setVerticalSyncEnabled(true);
    m_Window.setFramerateLimit(static_cast<uint32_t>(APP_MAX_FRAMERATE));
    m_Window.setActive();
    ImGui::SFML::Init(m_Window);

    toggleImGui = false; //permet l'ouverture de la fenêtre info

}

Game::~Game(){
    ImGui::SFML::Shutdown();
}

void Game::RunGameLoop(){
    float deltaTime{ 1.0f / APP_MAX_FRAMERATE };
    sf::Clock clock;

    while (m_Window.isOpen()){
        clock.restart();

        sf::Event event;
       
        //while (m_Window.pollEvent(event)) {
        if (m_Window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    m_Window.close();
                    break;

                case sf::Event::KeyPressed:  
                    if (event.key.code == sf::Keyboard::Escape) {  m_Window.close(); }
                    else if (event.key.code == sf::Keyboard::F1) { toggleImGui = !toggleImGui; }
                    break;
            }

            HandleEvent(event); // to treat other event type with specific GamePlay

            ImGui::SFML::ProcessEvent(event);
        }
      
        ImGui::SFML::Update(m_Window, clock.restart());

        Update(deltaTime); // call Update function of GameDemo class
        Render(m_Window); //
        RenderDebugMenu(m_Window); //

        ImGui::EndFrame();
        if (toggleImGui) { ImGui::SFML::Render(m_Window); }

        m_Window.display();

        deltaTime = clock.getElapsedTime().asSeconds();
    }
 


    //

    //std::thread eventThread (runEventThread);
    //std::thread gameThread (runGameThread);

    //eventThread.join();
    //gameThread.join();

}

sf::RenderWindow* Game::getWindow(){
    sf::RenderWindow *win = &m_Window;
    return win;
}

void Game::runEventThread(){ //

    while (m_Window.isOpen()) {
        sf::Event event;

        mutex.lock(); //

        if (m_Window.pollEvent(event)) {

            switch (event.type) {
                case sf::Event::Closed:
                    m_Window.close();
                    break;

                case sf::Event::KeyPressed:
                    
                    if (event.key.code == sf::Keyboard::Escape) { m_Window.close(); }
                    else if (event.key.code == sf::Keyboard::F1) { toggleImGui = !toggleImGui; }
                    break;
                    
            }
            ImGui::SFML::ProcessEvent(event);
        }

        mutex.unlock(); //
    }
}

void Game::runGameThread(){
    float deltaTime{ 1.0f / APP_MAX_FRAMERATE };
    sf::Clock clock;

    while (m_Window.isOpen()) {
        clock.restart();

        ImGui::SFML::Update(m_Window, clock.restart());

        Update(deltaTime);
        Render(m_Window);
        RenderDebugMenu(m_Window);

        ImGui::EndFrame();
        mutex.lock(); //
        if (toggleImGui) { ImGui::SFML::Render(m_Window); }
        mutex.unlock(); //

        m_Window.display();

        deltaTime = clock.getElapsedTime().asSeconds();

    }
}

