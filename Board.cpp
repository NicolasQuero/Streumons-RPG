#include "Board.h"
using namespace std;

bool Board::gameOn = true;

Board::Board(GameMap *gamemap,Oueurj &j) : gamemap(gamemap), score(0),monstreCree(false),J(j) { // each string from the list must have the same length
    setCharMaps(*gamemap); // stores the value of each character from mapText in charMap
   // J = Oueurj(2, 3);
}

void Board::setCharMaps(GameMap &gameMap) {
    int i = 0; // Coordonnées i,j d'un caractère parcouru
    int j = 0;
    vector<string> mapStrings = gameMap.getMapStrings();
    for (string line : mapStrings) { // On parcourt mapStrings avec line
        vector<char> charLine;
        for (char c : line) { // Pour chaque caractère de line
            if (find(monsterPossibleLetters.begin(), monsterPossibleLetters.end(), c) != monsterPossibleLetters.end()) { // Si la lettre réprésente un monstre i.e. est contenue dans monsterLetters
                if (monstreCree==false)//une fois les monstre cree plus besoin de les cree de nouveau
                {
                    addMonster(c, i, j);
                } // On ajoute un nouveau monstre associé à c avec addMonster() dans monstersOnMap
                charLine.push_back(' '); // On ajoute la case vide de la map derrière le monstre dans charLine
            }
            else {
                //monsterLine.push_back(' '); // Sinon on ajoute un caractère vide dans monsterLine
                charLine.push_back(c); // Et le caractère dans la charLine
            }
            j++;
        }
        charMap.push_back(charLine); // On met la ligne charLine dans charMap
        i++; j = 0;
    }
    monstreCree=true;
}

void Board::addMonster(char c, int i, int j) {
    switch ( c ) {
        case 's': {
            Monster_s* Ms = new Monster_s(i, j);
            monstersOnMap.push_back(Ms); //->push_back(new Monster_s(i, j));
            break;
        }
        case 'o': {
            Monster_o* Mo = new Monster_o(i, j);
            monstersOnMap.push_back(Mo);
            break;
        }
        case 'S': {
            Monster_s* Ms = new Monster_s(i, j,2,'S');
            monstersOnMap.push_back(Ms);
            break;
        }
    }
}

void Board::actualiseMap(GameMap *gamemap_)
{
    gamemap=gamemap_;
    charMap.clear();
    setCharMaps(*gamemap);
}

char Board::getCharAt(int &x, int &y) const { return charMap[x][y]; }

void Board::printMap() const {
    /*cout << J.pos.x << ", " << J.pos.y << endl;
    for (Streumon* monster : monstersOnMap) {
        cout << monster->pos.x << ", " << monster->pos.y << " " << monster->getType() << endl;
    }*/
    int row = 0; int col = 0;
    for (vector<char> line : charMap) {
        //printCoordinatesAroundTheMap(charMap, row, col); // print coordinates around the map
        for (char c : line) {
            bool monsterFound = false;
            for (Entity* monster : monstersOnMap) {
                if (monster->pos.x == row && monster->pos.y == col) { // a monster was found!
                    cout << monster->getType();// << "  ";
                    monsterFound = true;
                    break; // so we print the monster and no need to print the rest
                }
            }
            if (!monsterFound && row == J.pos.x && col == J.pos.y) // Si le joueur est à la position rendue on l'affiche
                cout << 'J';// << "  ";
            else if (!monsterFound) { // Sinon on affiche la map
                if (c == '#')
                    cout << c;// << c << c;
                else
                    cout << c;// << "  ";
            }
            col++;
        }
        printInformation(row);
        row++;
        col = 0;
        cout << endl;
    }
}

void Board::printCoordinatesAroundTheMap(vector<vector<char>> charMap, int row, int col) const {
    if (row == 0 && col == 0) { // We print the column indexes over the map
        cout << "   "; // mise en page
        for (char c : charMap[0]) {
            if (col < 10) {
                cout << col << "  "; // If the index of the column is 1 char long we print it with a space behind
                col++;
            }
            else {
                cout << col << " "; // If it's 2 chars long we print it without space behind
                col++;
            }
        }
        cout << endl << 0 << "  "; // after printing the top line we break the line and print the first 0 for the rows
    }
    else if (col == 0) {
        if (row < 10)
            cout << row << "  ";
        else
            cout << row << " ";
    }
}

void Board::printInformation(int &row) const {
    switch ( row ) {
    case 0:
        cout << "    Score : " << score;
        break;
    case 2:
        cout << "    HP : " << J.getHp();
        break;
    case 4:
        cout << "    Téléportations : " << J.getTeleportsLeft();
    }
}

int Board::playTurn() {
    J.act(J, *gamemap, charMap, monstersOnMap);
    if (gameOn) {
        for (Entity* monstre : monstersOnMap) {
            monstre->act(J, *gamemap, charMap, monstersOnMap);
            cout<<monstre->pos.x<<"et"<<monstre->pos.y<<endl;
            if (!monstre->isAlive()) {
                cout<<"je suis al";
                gamemap->modifierValeurGameMap(' ',monstre->pos.x,monstre->pos.y);
                monstersOnMap.erase(remove(monstersOnMap.begin(), monstersOnMap.end(), monstre), monstersOnMap.end());
                delete monstre;
            }
        }
        if (!J.isAlive()) {
            for (int i = 0; i<5; i++)
                cout << " ********** VOUS ÊTES MORT ! ********** " << endl;
            gameOn = false;
            return -2;
        }
    }
    this->actualiseMap(gamemap);
    char portes[] = {'b', 'h', 'd', 'g'};
    for (int i = 0; i < 4; i++) {
        if (J.pos == gamemap->getPortesPos(portes[i]))
            return i+1;
        cout << J.pos << " Porte : " << portes[i] << " " << gamemap->getPortesPos(portes[i]) << endl;
    }
    return 0;
}



Board::~Board() {
    for (Entity* monster : monstersOnMap) {
        delete monster;
    }
    vector<Entity*>().swap(monstersOnMap); // On libère la mémoire de monstersOnMap
}

