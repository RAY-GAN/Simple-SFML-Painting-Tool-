#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <iostream>



int main()
{

   
    float BrushRadius = 30.f; 
    sf::Color BrushColor = sf::Color::Green;
    int PointCount = 3;
    int Mousedown = 0;

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    sf::CircleShape shape(BrushRadius,PointCount);
    shape.setFillColor(BrushColor);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {


            if (event.type == sf::Event::Closed)
                window.close();

            // Control the brush radius with up and down
            if (event.key.code == sf::Keyboard::Up) {
                BrushRadius += 5;
                shape.setRadius(BrushRadius);
                
            }
                

            if (event.key.code == sf::Keyboard::Down) {
                BrushRadius -= 5;
                shape.setRadius(BrushRadius);
            }
               
            // Control the brush color with key "R""G""B"
            if (event.key.code == sf::Keyboard::R) {
                BrushColor = sf::Color::Red;
                shape.setFillColor(BrushColor);

            }


            if (event.key.code == sf::Keyboard::B) {
                BrushColor = sf::Color::Blue;
                shape.setFillColor(BrushColor);
            }

            if (event.key.code == sf::Keyboard::G) {
                BrushColor = sf::Color::Green;
                shape.setFillColor(BrushColor);
            }



            //Control the shape with left and right

            if (event.key.code == sf::Keyboard::Left) {
                if (PointCount > 3){
                    PointCount--;
                    shape = sf::CircleShape(BrushRadius, PointCount);
                    shape.setFillColor(BrushColor);
                }
            }


            if (event.key.code == sf::Keyboard::Right) {
                PointCount++;
                shape = sf::CircleShape(BrushRadius, PointCount);
                shape.setFillColor(BrushColor);
            }

            


            // Space key creates a screenshot
            if (event.key.code == sf::Keyboard::Space) {
                sf::Texture texture;
                texture.create(window.getSize().x, window.getSize().y);
                texture.update(window);
                if (texture.copyToImage().saveToFile("Homework 1 Screenshot.png"))
                {
                    std::cout << "Screenshot saved to Homework 1 Screenshot.png" << std::endl;
                }
            }

            // Start drawing only when left mouse key is pressed
            if (event.type == sf::Event::MouseButtonPressed)
            {
                Mousedown = 1;
            }
            else if (event.type == sf::Event::MouseButtonReleased)
            {
                Mousedown = 0;
            }


        }


        shape.setPosition(sf::Mouse::getPosition(window).x - BrushRadius, 
            sf::Mouse::getPosition(window).y -  BrushRadius);
        
        if ((event.type == sf::Event::MouseMoved) && (Mousedown == 1))
        {
            window.draw(shape);
        }
        
        
        window.display();
    }

    return 0;
}