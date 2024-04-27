#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

using namespace sf;
int main()
{
    RenderWindow window(sf::VideoMode(1000, 500), "Snail Race", sf::Style::Titlebar | sf::Style::Close);
    std::ifstream ifs{"seed.txt"};
    if(!ifs.is_open()) return 1;
    unsigned int seed{};
    ifs >> seed;
    int random;
    int winner;
    srand(seed);
    CircleShape c1(30);
    CircleShape c2(30);
    CircleShape c3(30);
    CircleShape c4(30);
    std::vector<CircleShape> contestants{c1,c2,c3,c4};
    for(int i{}; i < 4; i++)
    {
        contestants.at(i).setOrigin(15, -15);
        contestants.at(i).setPosition(15, (i+1)*100);
    }

    while(window.isOpen())
    {
        
        if(Keyboard::isKeyPressed(Keyboard::Escape)) window.close();
        random = 1 + (rand() % 4);
        for(int i{1}; i <= 4;i++)
        {
            if(i == random) contestants.at(i-1).move(4,0);
        }
        window.clear();
        winner = 0;
        for(auto c : contestants){
            winner++;
            if(c.getPosition().x == 975)
            {
                
                std::cout << "winner is number " << winner << std::endl; 
                window.close();
            }
            window.draw(c);

        }
        window.display();
        // sleep(seconds(0.04));
    }
    ifs.close();
    std::ofstream ofs;
    ofs.open("seed.txt");
    if(!ofs.is_open()) return 1;
    ofs << ++seed;
    return 0;
}