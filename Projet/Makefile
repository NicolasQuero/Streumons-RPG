CPP=g++ --std=c++11 -Wall

all : gp gc

gc: main.o creaJeu.o creaMap.o FonctionUtile.o
	$(CPP) -o gc main.o creaJeu.o creaMap.o FonctionUtile.o

gp : main2.o Board.o Combat.o FonctionUtile.o GameMap.o Jeu.o Entity.o Oueurj.o Pos.o Monster_o.o Monster_s.o Streumon.o TextOutput.o
	$(CPP) -o gp main2.o Board.o Combat.o FonctionUtile.o GameMap.o Jeu.o Entity.o Oueurj.o Pos.o Monster_o.o Monster_s.o TextOutput.o Streumon.o

main.o : Code/main.cpp
	$(CPP) -o main.o -c Code/main.cpp

creaJeu.o : Code/creaJeu.cpp
	$(CPP) -o creaJeu.o -c Code/creaJeu.cpp

creaMap.o : Code/creaMap.cpp
	$(CPP) -o creaMap.o -c Code/creaMap.cpp

main2.o : Code/main2.cpp
	$(CPP) -o main2.o -c Code/main2.cpp

Board.o : Code/Board.cpp
	$(CPP) -o Board.o -c Code/Board.cpp

Combat.o : Code/Combat.cpp
	$(CPP) -o Combat.o -c Code/Combat.cpp

FonctionUtile.o : Code/FonctionUtile.cpp
	$(CPP) -o FonctionUtile.o -c Code/FonctionUtile.cpp

GameMap.o : Code/GameMap.cpp
	$(CPP) -o GameMap.o  -c Code/GameMap.cpp

Jeu.o : Code/Jeu.cpp
	$(CPP) -o Jeu.o  -c Code/Jeu.cpp

Entity.o : Code/Entities/Entity.cpp
	$(CPP) -o Entity.o  -c Code/Entities/Entity.cpp

Oueurj.o : Code/Entities/Oueurj.cpp
	$(CPP) -o Oueurj.o  -c Code/Entities/Oueurj.cpp

Pos.o : Code/Entities/Pos.cpp
	$(CPP) -o Pos.o  -c Code/Entities/Pos.cpp

Monster_o.o : Code/Entities/Streumons/Monster_o.cpp
	$(CPP) -o Monster_o.o  -c Code/Entities/Streumons/Monster_o.cpp

Monster_s.o : Code/Entities/Streumons/Monster_s.cpp
	$(CPP) -o Monster_s.o  -c Code/Entities/Streumons/Monster_s.cpp

Streumon.o : Code/Entities/Streumons/Streumon.cpp
	$(CPP) -o Streumon.o  -c Code/Entities/Streumons/Streumon.cpp

TextOutput.o : Code/TextOutput.cpp
	$(CPP) -o TextOutput.o -c Code/TextOutput.cpp

clean :
	rm *.o
	rm gc
	rm gp
