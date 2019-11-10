
final: go_fish.o player.o deck.o card.o
	g++ -o test go_fish.o player.o deck.o card.o
go_fish.o: go_fish.cpp player.h deck.h card.h
	g++ -c -std=c++11 go_fish.cpp
player.o: player.cpp player.h
	g++ -c -std=c++11 player.cpp
deck.o: deck.cpp deck.h
	g++ -c -std=c++11 deck.cpp
card.o: card.cpp card.h
	g++ -c -std=c++11 card.cpp