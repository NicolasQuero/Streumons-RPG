#include "Board.hpp"
using namespace std;

bool Board::gameOn = true;

Board::Board(GameMap *gamemap, Oueurj *j) : gamemap(gamemap), score(0), monstreCree(false) { // each string from the list must have the same length
    setCharMaps(*gamemap); // stores the value of each character from mapText in charMap
    J = j;
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
    gamemap = gamemap_;
    charMap.clear();
    setCharMaps(*gamemap);
}

char Board::getCharAt(int &x, int &y) const { return charMap[x][y]; }

void Board::printMap() const {
    int row = 0;
    for (vector<char> line : charMap) {
        int col = 0;
        for (char c : line) {
            bool monsterFound = false;
            for (Entity* monster : monstersOnMap) {
                if (monster->pos.x == row && monster->pos.y == col) { // a monster was found!
                    cout << monster->getType();// << "  ";
                    monsterFound = true;
                    break; // so we print the monster and no need to print the rest
                }
            }
            if (!monsterFound && row == J->pos.x && col == J->pos.y) // Si le joueur est à la position rendue on l'affiche
                cout << 'J';// << "  ";
            else if (!monsterFound) { // Sinon on affiche la map
                    cout << c;// << c << c;
            }
            col++;
        }
        row++;
        cout << endl;
    }
      cout  << "- HP : " << J->getHp()<< "    - Téléportations : " << J->getTeleportsLeft()<< "    - Score : " << J->getScore()<< endl;
}

void Board::printInformation(int &row) const {
    switch ( row ) {
    case 0:
        cout << "    Score : " << J->getScore();
        break;
    case 2:
        cout << "    HP : " << J->getHp();
        break;
    case 4:
        cout << "    Téléportations : " << J->getTeleportsLeft();
        break;
    }
}

int Board::playTurn() {
    J->act(J, *gamemap, charMap, monstersOnMap);
    if (J->wantsToTeleport() && J->getTeleportsLeft() > 0) {
        J->useTeleport();
        return -1;
    }
    if (gameOn) {
        for (Entity* monstre : monstersOnMap) {
            monstre->act(J, *gamemap, charMap, monstersOnMap);
            if (!monstre->isAlive()) {
                gamemap->modifierValeurGameMap(' ',monstre->pos.x,monstre->pos.y);
                J->addScore(monstre);
                monstersOnMap.erase(remove(monstersOnMap.begin(), monstersOnMap.end(), monstre), monstersOnMap.end());
                delete monstre;
            }
        }
        if (!J->isAlive()) {
            for (int i = 0; i<5; i++)
                cout << " ********** VOUS ÊTES MORT ! ********** " << endl;
            gameOn = false;
            return -2;
        }
    }
    this->actualiseMap(gamemap);
    char portes[] = {'b', 'h', 'd', 'g'};
    for (int i = 0; i < 4; i++) {
        if (J->pos == gamemap->getPortesPos(portes[i]))
            return i+1;
    }
    return 0;
}

Board::~Board() {
    for (Entity* monster : monstersOnMap) {
        delete monster;
    }
    vector<Entity*>().swap(monstersOnMap); // On libère la mémoire de monstersOnMap
}
