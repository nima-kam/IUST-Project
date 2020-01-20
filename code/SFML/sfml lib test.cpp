#include<SFML/Graphics.hpp>
#include<iostream>

int main()
{
    sf::RenderWindow window (sf::VideoMode(900,900),"this is working");
    sf::CircleShape shape(900.f);
    shape.setFillColor(sf::Color::Blue);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            /* code */
            if (event.type== sf::Event::Closed)
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

