#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<string>
using namespace std;


class gameObjects
{
public:
    gameObjects(/* args */);
    ~gameObjects();
    sf::Sprite createSprite(string const& filename);

private:
sf::Texture fill;
};

gameObjects::gameObjects()
{
  //  fill.loadFromFile();
}

gameObjects::~gameObjects()
{
}

create

int main()
{
    sf::RenderWindow window(sf::VideoMode(2000,2000,64),"** chess **");

    while (window.isOpen())
    {
        sf::Event event;
         while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case  sf::Event::Closed :
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code== sf::Keyboard::Key::Space)
                {
                    window.setTitle("space is pressed");
                }
                break;

            default:

                break;
            }

        }
            window.clear();
            
            window.display();
      
    }
    

return 0;
}
