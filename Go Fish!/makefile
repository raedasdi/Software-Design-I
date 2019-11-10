
final: card_demo.o player.o deck.o card.o
	g++ -o test card_demo.o player.o deck.o card.o
card_demo.0: card_demo.cpp player.h deck.h card.h
	g++ -c -std=c++11 card_demo.cpp
player.o: player.cpp player.h
	g++ -c -std=c++11 player.cpp
deck.o: deck.cpp deck.h
	g++ -c -std=c++11 deck.cpp
card.o: card.cpp card.h
	g++ -c -std=c++11 card.cpp