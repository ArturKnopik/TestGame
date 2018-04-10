//
// Created by Streaming on 2017-12-13.
//
#include <Level/Test_Level.h>
#include "GameStates/PlayState.h"
#include "GameStates/PauseState.h"

PlayState::~PlayState()
{
    std::cout<<"Destroy PlayState - ";
}

void PlayState::draw()
{

    //player->draw(game->window);
    currentLevel->draw(game->window);
}

void PlayState::update(const float dt)
{
    // player->update(dt);
    currentLevel->update(dt);
}

void PlayState::input()
{

    while (this->game->window->pollEvent(*event.get()))
    {
        switch (event->type)
        {
            case sf::Event::Closed:
                this->game->window->close();
                break;

            case sf::Event::KeyPressed:
                if (event->key.code == sf::Keyboard::Escape)
                    game->pushState(std::make_shared<PauseState>(game));

                if (event->key.code == sf::Keyboard::F1)
                {
                    viewe.zoom(0.7);
                }

                if (event->key.code == sf::Keyboard::F2)
                {
                    viewe.zoom(1.3);
                }
                break;

        }
    }
}

PlayState::PlayState(std::shared_ptr<Game> game)
{
    event = std::make_shared<sf::Event>();

    this->game = game;
    //player=std::shared_ptr<Player>(new Player(100,100,event, Layers::CREATURES));
    currentLevel = std::unique_ptr<Level>(new Test_Level("abc", event));
    std::cout<<"Create PlayState - ";

}
