#include <SFML\Graphics.hpp>
#include <cmath>

const float PI = 3.14159265;

int main()
{
	int N = 3;
	sf::Clock clock;
  sf::RenderWindow window(sf::VideoMode(1000, 600), "My window");

  /*sf::CircleShape circle(50, N);
  circle.setPosition(100, 100);
  circle.setFillColor(sf::Color(150, 50, 250));
  circle.setOutlineThickness(10);
  circle.setOutlineColor(sf::Color(250, 150, 100));*/

  sf::Texture texture;
  texture.loadFromFile("hero.png");
  sf::Sprite circle(texture);
  while (window.isOpen())
  {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	sf::Time time = clock.getElapsedTime();
	double x = time.asSeconds() - 1;
    window.clear(sf::Color::Black);


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		circle.move(-0.5*(time.asSeconds()-x), 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		circle.move(0.5*(time.asSeconds() - x), 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		circle.move(0, -0.5*(time.asSeconds() - x));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		circle.move(0, 0.5*(time.asSeconds() - x));

	
	window.draw(circle);
	/*float x = 200*sin(PI/N) / (2 * tan(PI / N));
	sf::CircleShape circle2(x);
	circle2.setPosition(300-x, 300-x);
	circle2.setFillColor(sf::Color(250, 250, 250, 10));
	circle2.setOutlineThickness(2);
	circle2.setOutlineColor(sf::Color(250, 250, 250));
	window.draw(circle2);

	float z = 100;
	sf::CircleShape circle3(z);
	circle3.setPosition(200, 200);
	circle3.setFillColor(sf::Color(250, 250, 250, 10));
	circle3.setOutlineThickness(2);
	circle3.setOutlineColor(sf::Color(250, 250, 250));
	window.draw(circle3);
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(10, 10)),
		sf::Vertex(sf::Vector2f(150,150))
	};
	window.draw(line, 2, sf::Lines);

	sf::RectangleShape rectangle(sf::Vector2f(120, 50));
	rectangle.setSize(sf::Vector2f(100, 300));
	rectangle.move(sf::Vector2f(400, 200));
	window.draw(rectangle);*/
    window.display();
  }

  return 0;
}
