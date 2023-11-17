#include <stdio.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp> 
#include <math.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int trava=0;
	int i=0;
	float alg=-1;	
	float v=0,angulo=0;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode().width,sf::VideoMode::getDesktopMode().height),"Circulos girando",sf::Style::Default,settings);
	std::vector<sf::CircleShape> circulos_negativo;
	window.setFramerateLimit(30);
	sf::CircleShape cursor(15.f);
	cursor.setFillColor(sf::Color().Cyan);			
	sf::Clock clock;
	sf::Font font;
	sf::Time tempo=clock.restart();
	for(int i=0;i<40;i++){
		sf::CircleShape circulo(15.f);
		circulo.setFillColor(sf::Color(rand()%255,rand()%255,rand()%255));	
		circulos_negativo.push_back(circulo);	
	}
	while(window.isOpen()){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type==sf::Event::Closed){
				window.close();
			}
		}
	
		window.clear(sf::Color::Black);
		
		if(i==0 && trava==0){
		alg++;
		
		circulos_negativo[alg].setPosition(rand()%(sf::VideoMode::getDesktopMode().width-sf::VideoMode::getDesktopMode().width/10),	rand()%(sf::VideoMode::getDesktopMode().height-sf::VideoMode::getDesktopMode().height/10));
		i=1;
		}
		cursor.setPosition(sf::Mouse::getPosition(window).x,sf::Mouse::getPosition(window).y);
		if((((sf::Mouse::getPosition(window).x-circulos_negativo[alg].getPosition().x)<=20)&&(sf::Mouse::getPosition(window).x-circulos_negativo[alg].getPosition().x)>=-20) && (((sf::Mouse::getPosition(window).y-circulos_negativo[alg].getPosition().y)<=20 &&((sf::Mouse::getPosition(window).y-circulos_negativo[alg].getPosition().y)>=-20)))){
		i=0;		
		}
		
		for(int y=0;y<alg;y++ ){
			angulo=v+y;
			circulos_negativo[y].setPosition(cos(angulo)*50+sf::Mouse::getPosition(window).x,sin(angulo)*50+sf::Mouse::getPosition(window).y);
		window.draw(circulos_negativo[y]);
		}
		v=v+0.3;
		if(v>360){
			v=0;
		}
		if(alg>=circulos_negativo.size() || trava==1){
			if(alg==0){
			tempo=clock.getElapsedTime();
			std::cout<<tempo.asSeconds()<<"\n";
			tempo=clock.restart();
			trava=0;
			}
			if(alg>0){
				alg=alg-0.25;
				trava=1;
			}
		}
	
		window.draw(circulos_negativo[alg]);
		window.draw(cursor);
		window.display();
	}
	return 0;
	}
