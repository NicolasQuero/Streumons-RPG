#include "Oueurj.hpp"
#include "../Board.hpp"


using namespace std;

const int Oueurj::BASE_DMG = 10;
const int Oueurj::HP_MAX = 100;
const int Oueurj::MP_MAX = 100;
const int Oueurj::POWER_MAX = 20;
const int Oueurj::HEAL_COST = 20;
const int Oueurj::POWERATK_COST = 10;

Oueurj::Oueurj(string nom) : Entity('j', -1, -1, HP_MAX, BASE_DMG), mp(MP_MAX), power(POWER_MAX) , score(0), teleportsLeft(0), m_nom(nom){}

Oueurj::Oueurj(Pos p) : Entity('j', p, HP_MAX, BASE_DMG), mp(MP_MAX), power(POWER_MAX), score(0), teleportsLeft(0) {}

Oueurj::Oueurj(int row, int col) : Entity('j', row, col, HP_MAX, BASE_DMG), mp(MP_MAX), power(POWER_MAX), score(0), teleportsLeft(0){}

void Oueurj::act(Entity *J, GameMap &gameMap, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    bool tourEnded = false;
    wantsTeleport = false;
    while (!tourEnded) { // Tant que le tour n'est pas valide on demande au joueur ce qu'il veut faire
        cout << endl << "Que désirez-vous faire ?" << endl << endl
        << "Se déplacer :" << endl << "1 (bas gauche), 2 (bas), 3 (bas droite)" << endl << "4 (gauche), 5 (immobile), 6 (droite)" << endl
        << "7 (haut gauche), 8 (haut), 9 (haut droite)" << endl << endl;
        cout << "Téléportation : t" << endl;
        string choice;
        cin >> choice;
        tourEnded = manageChoice(choice, charMap, streumons);
    }
    if (charMap[J->pos.x][J->pos.y] == 'D') {
        gameMap.prendreCle();
        gameMap.creaPorte(1);
        gameMap.modifierValeurGameMap(' ', J->pos.x, J->pos.y);
        TextOutput::addText("Vous obtenez le diamant ! Les portes s'ouvrent...\n");
    }
    else if (charMap[J->pos.x][J->pos.y] == 'C') {
        this->addTeleport();
        gameMap.modifierValeurGameMap(' ', J->pos.x, J->pos.y);
        TextOutput::addText("Vous obtenez un Chargeur ! Vous gagnez une téléportation.\n");
    }
}

/*bool Oueurj::quitGame() const {
    string confirmChoice;
    cout << "Êtes-vous sûr de vouloir quitter le jeu ? o/n" << endl;
    cin >> confirmChoice; // Demande de confirmation
    while (confirmChoice[0] != 'o' && confirmChoice[0] != 'n') {
        cout << "Êtes-vous sûr de vouloir quitter le jeu ? (Oui = o, Non = n)" << endl;
        cin >> confirmChoice; // Si le joueur n'a entré ni 'o' ni 'n' en premier caractère
    }
    if (confirmChoice[0] == 'o') { // Le joueur veut quitter
        Board::gameOn = false;
        return true;
    }
    else if (confirmChoice[0] == 'n') // Le joueur ne veut pas quitter
        return false;
}*/

bool isNumber(char c) {
    char integers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (char i : integers) {
        if (c == i)
            return true;
    }
    return false;
}

bool Oueurj::manageChoice(string choice, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    if (isNumber(choice[0])) { // Le joueur veut se déplacer
        int deplacement = choice[0] - '0'; // on convertit l'entier entré (de type string) en entier
        movePlayer(deplacement, charMap, streumons);
        return true;
    }
    else if (choice[0] == 't' || choice [0] == 'T') {
        wantsTeleport = true;
        return true;
    }
    return false;


}

void Oueurj::movePlayer(int deplacement, vector<vector<char>> &charMap, vector<Entity*> &streumons) {
    if (0 < deplacement && deplacement < 10) {
        Pos targetPos = pos + DEPLACEMENTS_POS[deplacement-1]; // Target position is the position of the player plus the vector associated to the movement

        if (charMap[targetPos.x][targetPos.y] != '#' && charMap[targetPos.x][targetPos.y] != 'X') { // If it's not a wall
            int monsterIndex = monsterIndexAt(targetPos, streumons); // We check the monster type at the target position (if there is one)
            if ( monsterIndex == -1 ) { // Si il n'y a pas de monstre on se déplace
                pos = targetPos;
            }
            else { // Sinon on se bat comme un vrai Oueurj (ou on ajoute le mob au Streumédex)
                cout << "Monstre " << streumons[monsterIndex]->getType() << " rencontré !" << endl;
                Combat combat = Combat(this, streumons[monsterIndex]);
                combat.startCombat();
                if (this->isAlive()) {
                    this->addScore(streumons[monsterIndex]);
                    pos = targetPos;
                }
                else
                    cout << "Vous avez été vaincu..." << endl;
            }
        }
        else
            cout << "COULDN'T MOVE" << endl;
    }
}

int Oueurj::monsterIndexAt(Pos target, vector<Entity*> &streumons) {
    int i = 0;
    for (Entity* monster : streumons) {
        if (monster->pos == target)
            return i; // monster found, return its type
        i++;
    }
    return -1; // no monster found, return empty char
}

void Oueurj::addScore(Entity *M) {
    if (M->getType() == 's')
        score += 100;
    else if (M->getType() == 'S')
        score += 250;
    else if (M->getType() == 'o')
        score += 500;
}

    //////////////////////////////////
    // BELOW ARE THE COMBAT METHODS //
    //////////////////////////////////

bool Oueurj::playCombatTurn(Entity *M) { // Method managing the turn of the player in the combat
    char attackChoice;
    bool turnOver = false;
    while (!turnOver) {
        cout << endl << " Quelle attaque désirez-vous lancer ? " << endl << endl
        << "  - Attaque normale : n" << endl
        << "  - Attaque puissante : p (" << POWERATK_COST << " points de mana)" << endl
        << "  - Soin : s (" << HEAL_COST << " points de mana)" << endl << endl;
        cin >> attackChoice;

        switch ( attackChoice ) {
            case 'n': {
                attack(M); // Normal attack designed in the Entity class
                return didMonsterDie(M);
            }
            case 'p': {
                if ( powerAttack(M) ) // More powerful attack
                    return didMonsterDie(M);
            }
            case 's': {
                if ( heal() ) // Heal the player
                    return true;
            }
        }
    }
    return false;
}

bool Oueurj::didMonsterDie(Entity *M) {
    if (!M->isAlive()) {
        string text = "Vous venez de vaincre un monstre de type "; text += M->getType(); text += " ! ("; text += to_string(hp); text += " HP restants)\n";
        TextOutput::addText(text);
    }
    return M->isAlive();
}

bool Oueurj::powerAttack(Entity *M) {
    if (mp >= POWERATK_COST) {
        M->inflictDamage(power);
        mp -= POWERATK_COST;
        cout << " Vous infligez une attaque puissante !" << endl
        << " L'ennemi n'a plus que " << M->getHp() << " point(s) de vie" << endl;
        setAttackInUse('p');
        return true;
    }
    else {
        cout << " Pas assez de mana ! Vous avez " << mp << " point(s) de mana (" << POWERATK_COST << " mp requis)" << endl;
        return false; // Not enough mp
    }
}

bool Oueurj::heal() {
    if (mp >= HEAL_COST) {
        hp += power;
        mp -= HEAL_COST;
        if (hp > HP_MAX)
            hp = HP_MAX;
        cout << " Vous vous soignez, vous avez désormais " << hp << " points de vie" << endl;
        setAttackInUse('s');
        return true;
    }
    else {
        cout << " Pas assez de mana ! Vous avez " << mp << " point(s) de mana (" << HEAL_COST << " mp requis)" << endl;
        return false; // Not enough mp
    }
}

void Oueurj::enregistrerScore()
{
    string scoreTXT="Code/JeuCree/Score.txt";
    std::ofstream flux(scoreTXT.c_str(),ios::app);
    if (flux)
    {
        flux<<this->getNom()<<endl;
        flux<<this->getScore()<<endl;
    }
    else
        cout<<"ERREUR: impossible d'enregistrer le score";
}



void Oueurj::afficherScore()
{
    bool i=0;
    vector<string> nom;
    vector<int> score;
    string scoreTXT="Code/JeuCree/Score.txt";
    std::ifstream flux(scoreTXT.c_str());
    if (flux)
    {
        while(getline(flux,scoreTXT))
        {
            if(i==0)
            {
                nom.push_back(scoreTXT);
                i=1;
            }
            else
            {
                score.push_back(atoi(scoreTXT.c_str()));
                i=0;
            }
        }
    }
    else
        cout<<"ERREUR: impossible d'enregistrer le score";

    int taille = score.size();
    for (int k=0 ; k< taille-1 ; k++)
    {
        int Max=k;
        for(int l=k+1 ; l< taille; l++)
        {
            if(score[l]>score[Max])
                Max=l;
        }
        swap(score[k],score[Max]);
        swap(nom[k],nom[Max]);
    }
    cout<<endl<<"Tableau des Scores"<<endl<<endl;
    for (int j=0 ; j<taille ; j++)
        cout<<nom[j]<<" : "<<score[j]<<endl;
}
