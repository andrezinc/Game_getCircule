#include <stdio.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 
#include <math.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int i=0,alg=-1;	
	float v=0;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height),"Circulos girando",sf::Style::Default,settings);
	std::vector<sf::CircleShape> circulos_negativo;
	window.setFramerateLimit(30);
	sf::CircleShape cursor(15.f);
	cursor.setFillColor(sf::Color().Red);			
	for(int i=0;i<40;i++){
		sf::CircleShape ronaldos(15.f);
		ronaldos.setFillColor(sf::Color(255-20*i%255,255-30*i%255,255-75*i%255));	
		circulos_negativo.push_back(ronaldos);	
	}
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				window.close();
			}
		}
	
		window.clear(sf::Color::Black);
		
		if(i==0){
		alg++;
		
		circulos_negativo[alg].setPosition(rand()%(sf::VideoMode::getDesktopMode().width-sf::VideoMode::getDesktopMode().width/10),	rand()%(sf::VideoMode::getDesktopMode().height-sf::VideoMode::getDesktopMode().height/10));
		i=1;
		}
		cursor.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
		if((((sf::Mouse::getPosition(window).x-circulos_negativo[alg].getPosition().x)<=20)&&(sf::Mouse::getPosition(window).x-circulos_negativo[alg].getPosition().x)>=-20) && (((sf::Mouse::getPosition(window).y-circulos_negativo[alg].getPosition().y)<=20 &&((sf::Mouse::getPosition(window).y-circulos_negativo[alg].getPosition().y)>=-20)))){
		i=0;		
		}
		
		for(int y=0;y<alg;y++){
			circulos_negativo[y].setPosition(cos(v+y)*50+sf::Mouse::getPosition(window).x,sin(v+y)*50+sf::Mouse::getPosition(window).y);
		window.draw(circulos_negativo[y]);
		}
		v=v+0.3;
		if(v>360){
			v=0;
		}
		if(alg>=circulos_negativo.size()){
			alg=0;
		}
		window.draw(circulos_negativo[alg]);
		window.draw(cursor);
		window.display();
	}
	return 0;
	}
