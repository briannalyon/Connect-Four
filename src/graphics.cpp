#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1100, 900), "Connect Four");
    sf::CircleShape dot(50.f);
    dot.setFillColor(sf::Color::White);

        const int nofRows = 6; //number of rows
        const int nofCols = 7; //number of columns
        const int distance = 150; //distance between dots
        const float offset = distance/20.f; 
        const float height = std::sqrt(std::pow(distance,2.f) - std::pow(offset,2.f)); 

        while (window.isOpen())
        {
                sf::Event event;
                while (window.pollEvent(event))
                {
                        if (event.type == sf::Event::Closed)
                                window.close();
                }

                window.clear();
                for (int i=0; i<nofRows; ++i){
                        for (int j=0; j<nofCols; ++j){
                            
                            dot.setPosition(j*distance+offset, i*height); //odd rows
                                window.draw(dot);
                        }
                }
                window.display();
        }

        return 0;
}