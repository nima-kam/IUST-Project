#include<SFML/Graphics.hpp>
#include<iostream>

int main()
{
    sf::RenderWindow window (sf::VideoMode(900,900),"this is working");
    sf::CircleShape shape(100.f,45);
    shape.setPosition(40,34.5);
    shape.setFillColor(sf::Color::Cyan);
    shape.setOutlineColor(sf::Color::Magenta);
    shape.setOutlineThickness(3.4);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        
        }
            window.clear();
            window.draw(shape);
            window.display();
    }
    
return 0;

}

