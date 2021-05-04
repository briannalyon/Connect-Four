#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
	const int nofRows = 6; //number of rows
	const int nofCols = 7; //number of columns
	const int distance = 150; //distance between tokens
	const float offset = distance / 20.f; 
	const float height = std::sqrt(std::pow(distance, 2.f) - std::pow(offset, 2.f)); 
	const sf::Color blue = sf::Color(0, 76, 153, 255);
    const sf::Color grey = sf::Color(200, 200, 200, 255);


    sf::RenderWindow window(sf::VideoMode(1080, 910), "Connect Four");
    sf::CircleShape token(50.f);
    token.setFillColor(grey);

	while (window.isOpen()) 
    {	
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(blue);
		for (int i=0; i<nofRows; ++i){
			for (int j=0; j<nofCols; ++j){
			    
			    token.setPosition(j*distance+offset+30, i*height+30); //odd rows
				window.draw(token);
			}
		}
		window.display();
	}

	return 0;
}