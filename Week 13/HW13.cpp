#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <string>

using namespace std;    // BRACE YOURSELVES, 'TIS UGLY 

const char EMPTY_SPACE = '-';
const int GRID_SIZE = 400, INITIAL_ANT = 100, INITIAL_DOODLEBUG = 5;
const int DOODLE_STARVE = 3, DOODLE_BREED = 8, ANT_BREED = 3;

class Organism {    // Base class for living thing
protected:
    char body;
    int position;
    int breedCounter;
    int fastingCounter;
    bool moved;
    bool justBorn;
public:
    Organism() : body('-'), position(0), breedCounter(0), fastingCounter(0), moved(false), justBorn(false) { }
    virtual ~Organism() { }

    Organism(char c) : body(c), position(0), breedCounter(0), fastingCounter(0), moved(false), justBorn(false) { }
    Organism(char c, int iniPos) : breedCounter(0), fastingCounter(0), moved(false), justBorn(false) { this->body = c; this->position = iniPos; }
    Organism(char iniC, int iniPos, int iniBreedCap, int iniFastingCap);
    int getPosition() { return this->position; }
    virtual int getBreedCounter() { return this->breedCounter; }
    virtual void setBreedCounter(int newCap) { this->breedCounter = newCap; }
    virtual void increaseBreedCounter() { this->breedCounter++; }
    virtual int getFastingCounter() { return this->fastingCounter; }
    virtual void setFastingCounter(int newCount) { this->fastingCounter = newCount; }
    virtual void increaseFastingCounter() { this->fastingCounter++; }
    virtual bool getMovedRecently() { return this->moved; }
    virtual void resetMoved() { this->moved = false; }
    virtual void setEncumbered() { this->moved = true; }
    virtual bool getMature() { return this->justBorn; }
    virtual void setMature() { this->justBorn = false; }
    virtual char getType() { return this->body; }
    virtual void move() { }
};
Organism::Organism(char iniC, int iniPos, int iniBreedCap, int iniFastingCap) : body(iniC), position(iniPos),
breedCounter(iniBreedCap), fastingCounter(iniFastingCap), moved(false), justBorn(false) {
}
class DoodleBug : public Organism {
public:
    DoodleBug() : Organism('x') { justBorn = true; }
    DoodleBug(int iniPos) : Organism('x', iniPos) {}
    virtual char getType() { return this->body; }
    virtual void move();
};
void DoodleBug::move() {
    this->increaseBreedCounter();
    this->increaseFastingCounter();
    this->setEncumbered();
}

class Ant : public Organism {
public:
    Ant() : Organism('o') { justBorn = true; }
    Ant(int iniPos) : Organism('o', iniPos) { }
    virtual char getType() { return this->body; }
    virtual void move();
};
void Ant::move() {  // Ants can't starve apparently.. built different I guess. No fast counter
    this->increaseBreedCounter();
    this->setEncumbered();
}

class Grid {
public:
    Grid() { createGrid(); populateGrid(); }
    ~Grid();
    void printGrid();
    void timeframeSkip(); // Single turn
    void resetMoveStatus();
    void setMaturity();

private:

    void moveDoodlebugs();
    void moveAnts();

    void breedDoodleBugs();
    void breedAnts();

    void starveOrganisms(); // Starve/kill off any doodlebugs 
    void createGrid();
    void populateGrid();


    vector<Organism*> primalDataCenter; // 1D vector that we simply use our coordinate system to check if it is out of bounds or not.
};
Grid::~Grid() {
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] != nullptr) {
            delete primalDataCenter[i]; primalDataCenter[i] = nullptr;
        }
    }
}
void Grid::setMaturity() {
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] == nullptr)
            continue;
        primalDataCenter[i]->setMature();
    }
}
void Grid::moveDoodlebugs() {
    bool eatFlag = false, moveFlag = false, didMove = false;
    int direction, newIndex;
    int north, east, south, west;
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] == nullptr)
            continue;
        if (primalDataCenter[i]->getType() == 'o')
            continue;
        if (primalDataCenter[i]->getMovedRecently())
            continue;
        if (primalDataCenter[i]->getType() == 'x') {
            north = i - 20;
            east = i + 1;
            south = i + 20;
            west = i - 1;
            if (i >= 20) {  // if not top row
                if (primalDataCenter[north] != nullptr) {   // if destination is not pointer
                    if (primalDataCenter[i - 20]->getType() == 'o') {   // if destination is ant
                        delete primalDataCenter[north];                 // eat
                        primalDataCenter[north] = primalDataCenter[i];
                        primalDataCenter[i] = nullptr;
                        primalDataCenter[north]->move();
                        primalDataCenter[north]->setFastingCounter(0);
                        eatFlag = true;
                        continue;
                    }
                }
            }
            if ((i + 1) % 20 != 0) {
                if (primalDataCenter[east] != nullptr) {
                    if (primalDataCenter[east]->getType() == 'o') {
                        delete primalDataCenter[east];
                        primalDataCenter[east] = primalDataCenter[i];
                        primalDataCenter[i] = nullptr;
                        primalDataCenter[east]->move();
                        primalDataCenter[east]->setFastingCounter(0);
                        eatFlag = true;
                        continue;
                    }
                }
            }
            if (i < 380) {
                if (primalDataCenter[south] != nullptr) {
                    if (primalDataCenter[south]->getType() == 'o') {
                        delete primalDataCenter[south];
                        primalDataCenter[south] = primalDataCenter[i];
                        primalDataCenter[i] = nullptr;
                        primalDataCenter[south]->move();
                        primalDataCenter[south]->setFastingCounter(0);
                        eatFlag = true;
                        continue;
                    }
                }
            }
            if (i % 20 != 0) {
                if (primalDataCenter[west] != nullptr) {
                    if (primalDataCenter[west]->getType() == 'o') {
                        delete primalDataCenter[west];
                        primalDataCenter[west] = primalDataCenter[i];
                        primalDataCenter[i] = nullptr;
                        primalDataCenter[west]->move();
                        primalDataCenter[west]->setFastingCounter(0);
                        eatFlag = true;
                        continue;
                    }
                }
            }
        }
        // In the case of no adjacent ants
        didMove = false;
        if (primalDataCenter[i]->getType() == 'x' && !primalDataCenter[i]->getMovedRecently()) {
            direction = rand() % 4 + 1;
            switch (direction) {
            case 1: //NORTH
                newIndex = i - 20;
                if (i >= 20 && primalDataCenter[newIndex] == nullptr) {
                    primalDataCenter[newIndex] = primalDataCenter[i];
                    primalDataCenter[i] = nullptr;
                    primalDataCenter[newIndex]->move();
                    didMove = true;
                }
                if (!didMove) {
                    primalDataCenter[i]->increaseBreedCounter();
                    primalDataCenter[i]->increaseFastingCounter();
                }
                break;
            case 2: //EAST
                newIndex = i + 1;
                if ((i + 1) % 20 != 0 && primalDataCenter[newIndex] == nullptr) {
                    primalDataCenter[newIndex] = primalDataCenter[i];
                    primalDataCenter[i] = nullptr;
                    primalDataCenter[newIndex]->move();
                    didMove = true;
                }
                if (!didMove) {
                    primalDataCenter[i]->increaseBreedCounter();
                    primalDataCenter[i]->increaseFastingCounter();
                }
                break;
            case 3: //SOUTH
                newIndex = i + 20;
                if (i < 380 && primalDataCenter[newIndex] == nullptr) {
                    primalDataCenter[newIndex] = primalDataCenter[i];
                    primalDataCenter[i] = nullptr;
                    primalDataCenter[newIndex]->move();
                    didMove = true;
                }
                if (!didMove) {
                    primalDataCenter[i]->increaseBreedCounter();
                    primalDataCenter[i]->increaseFastingCounter();
                }
                break;
            case 4: //WEST
                newIndex = i - 1;
                if (i % 20 != 0 && primalDataCenter[newIndex] == nullptr) {
                    primalDataCenter[newIndex] = primalDataCenter[i];
                    primalDataCenter[i] = nullptr;
                    primalDataCenter[newIndex]->move();
                    didMove = true;
                }
                if (!didMove) {
                    primalDataCenter[i]->increaseBreedCounter();
                    primalDataCenter[i]->increaseFastingCounter();
                }
                break;
            }
        }
    }
}
void Grid::moveAnts() {
    int direction, newIndex;
    bool didMove = false;
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] == nullptr)
            continue;
        if (primalDataCenter[i]->getType() == 'x')
            continue;
        if (!primalDataCenter[i]->getMovedRecently()) {
            didMove = false;
            direction = rand() % 4 + 1;
            switch (direction) {
            case 1: //NORTH
                newIndex = i - 20;
                if (i >= 20 && primalDataCenter[newIndex] == nullptr) { // next spot is nullptr, and current spot is not north border
                    primalDataCenter[i]->move(); // increase breed counter, and flag movement, so we don't move more than once per turn
                    primalDataCenter[newIndex] = primalDataCenter[i];
                    primalDataCenter[i] = nullptr;
                    didMove = true;
                }
                if (!didMove)
                    primalDataCenter[i]->increaseBreedCounter();    // if didn't move, still survived a turn, increase breed counter
                break;
            case 2: //EAST
                newIndex = i + 1;
                if ((i + 1) % 20 != 0 && primalDataCenter[newIndex] == nullptr) { // next spot is nullptr, and current spot is not east border
                    primalDataCenter[newIndex] = primalDataCenter[i];
                    primalDataCenter[i] = nullptr;
                    primalDataCenter[newIndex]->move();
                    didMove = true;
                }
                if (!didMove)
                    primalDataCenter[i]->increaseBreedCounter();
                break;
            case 3: //SOUTH
                newIndex = i + 20;
                if (i < 380 && primalDataCenter[newIndex] == nullptr) { // next spot is nullptr, and current spot is not south border
                    primalDataCenter[newIndex] = primalDataCenter[i];
                    primalDataCenter[i] = nullptr;
                    primalDataCenter[newIndex]->move();
                    didMove = true;
                }
                if (!didMove)
                    primalDataCenter[i]->increaseBreedCounter();
                break;
            case 4: //WEST
                newIndex = i - 1;
                if (i % 20 != 0 && primalDataCenter[newIndex] == nullptr) { // next spot is nullptr, and current spot is not west border
                    primalDataCenter[newIndex] = primalDataCenter[i];
                    primalDataCenter[i] = nullptr;
                    primalDataCenter[newIndex]->move();
                    didMove = true;
                }
                if (!didMove)
                    primalDataCenter[i]->increaseBreedCounter();
                break;
            }
        }
    }
}
void Grid::breedDoodleBugs() { // Breed if possible
    bool bred, noneAvailable;
    bool northAvailable, westAvailable, southAvailable, eastAvailable;
    int clockWiseCheck = 1; // checking cardinal spots cw
    int newIndex;
    int north, south, west, east;
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] == nullptr) {
            continue;
        }
        clockWiseCheck = 1;
        northAvailable = westAvailable = southAvailable = eastAvailable = true;
        bred = noneAvailable = false;
        if (primalDataCenter[i]->getType() == 'x' && primalDataCenter[i]->getBreedCounter() >= DOODLE_BREED) {
            north = i - 20; // only setting if its an ant
            east = i + 1;
            south = i + 20;
            west = i - 1;
            while (bred == false && noneAvailable == false) {
                if (northAvailable == false && southAvailable == false && westAvailable == false && eastAvailable == false) {
                    noneAvailable = true; continue;
                }
                clockWiseCheck = rand() % 4 + 1;
                switch (clockWiseCheck) {
                case 1:
                    if (i <= 19 || primalDataCenter[north] != nullptr) {
                        northAvailable = false;
                        continue;
                    }
                    if (primalDataCenter[north] == nullptr) {
                        primalDataCenter[north] = new DoodleBug;
                        bred = true;
                    }
                    continue;
                case 2:
                    if (((east) % 20 == 0) || primalDataCenter[east] != nullptr) {
                        eastAvailable = false;
                        break;
                    }
                    if (primalDataCenter[east] == nullptr) {
                        primalDataCenter[east] = new DoodleBug;
                        bred = true;
                    }
                    continue;
                case 3:
                    if (i >= 380 || primalDataCenter[south] != nullptr) {
                        southAvailable = false;
                        continue;
                    }
                    if (primalDataCenter[south] == nullptr) {
                        primalDataCenter[south] = new DoodleBug;
                        bred = true;
                    }
                    continue;
                case 4:
                    if ((i % 20 == 0) || primalDataCenter[west] != nullptr) {
                        westAvailable = false;
                        continue;
                    }
                    if (primalDataCenter[west] == nullptr) {
                        primalDataCenter[west] = new DoodleBug;
                        bred = true;
                    }
                    continue;
                }
            }
            if (bred)
                primalDataCenter[i]->setBreedCounter(0);
        }
    }
}
void Grid::breedAnts() {
    bool bred, noneAvailable;
    bool northAvailable, westAvailable, southAvailable, eastAvailable;
    int clockWiseCheck = 1; // checking cardinal spots cw
    int newIndex;
    int north, south, west, east;
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] == nullptr) {
            continue;
        }
        clockWiseCheck = 1;
        northAvailable = westAvailable = southAvailable = eastAvailable = true;
        bred = noneAvailable = false;
        if (primalDataCenter[i]->getType() == 'o' && primalDataCenter[i]->getBreedCounter() >= ANT_BREED) {
            north = i - 20; // only setting if its an ant
            east = i + 1;
            south = i + 20;
            west = i - 1;
            while (bred == false && noneAvailable == false) {
                if (northAvailable == false && southAvailable == false && westAvailable == false && eastAvailable == false) {
                    noneAvailable = true; continue;
                }
                clockWiseCheck = rand() % 4 + 1;
                switch (clockWiseCheck) {
                case 1:
                    if (i <= 19 || primalDataCenter[north] != nullptr) {
                        northAvailable = false;
                        continue;
                    }
                    if (primalDataCenter[north] == nullptr) {
                        primalDataCenter[north] = new Ant;
                        bred = true;
                    }
                    continue;
                case 2:
                    if (((east) % 20 == 0) || primalDataCenter[east] != nullptr) {
                        eastAvailable = false;
                        break;
                    }
                    if (primalDataCenter[east] == nullptr) {
                        primalDataCenter[east] = new Ant;
                        bred = true;
                    }
                    continue;
                case 3:
                    if (i >= 380 || primalDataCenter[south] != nullptr) {
                        southAvailable = false;
                        continue;
                    }
                    if (primalDataCenter[south] == nullptr) {
                        primalDataCenter[south] = new Ant;
                        bred = true;
                    }
                    continue;
                case 4:
                    if ((i % 20 == 0) || primalDataCenter[west] != nullptr) {
                        westAvailable = false;
                        continue;
                    }
                    if (primalDataCenter[west] == nullptr) {
                        primalDataCenter[west] = new Ant;
                        bred = true;
                    }
                    continue;
                }
            }
            if (bred)
                primalDataCenter[i]->setBreedCounter(0);
        }
    }
}
void Grid::resetMoveStatus() {
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] == nullptr)
            continue;
        primalDataCenter[i]->resetMoved();
    }
}
void Grid::timeframeSkip() {
    // Phase 1
    moveDoodlebugs();
    moveAnts();
    // Phase 2
    breedDoodleBugs();
    breedAnts();
    // ResolveStatuses
    starveOrganisms();
    resetMoveStatus();
    setMaturity();
}
void Grid::starveOrganisms() {
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] == nullptr)
            continue;
        if (primalDataCenter[i]->getType() == 'o')
            continue;
        if (primalDataCenter[i]->getType() == 'x' && primalDataCenter[i]->getFastingCounter() >= DOODLE_STARVE) {
            delete primalDataCenter[i];
            primalDataCenter[i] = nullptr;
        }

    }
}
void Grid::createGrid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        primalDataCenter.push_back(nullptr);
    }
}
void Grid::populateGrid() {
    int randNum;
    int doodleCount = 0, antCount = 0;
    vector<int> doodlebugPos;
    vector<int> antPos;
    while (doodlebugPos.size() < INITIAL_DOODLEBUG) {
        randNum = rand() % GRID_SIZE;
        if (primalDataCenter[randNum] == nullptr) {
            doodlebugPos.push_back(randNum);
            doodleCount++;
            delete primalDataCenter[randNum];
            primalDataCenter[randNum] = new DoodleBug(randNum);
        }
    }
    while (antPos.size() < INITIAL_ANT) {
        randNum = rand() % GRID_SIZE;
        if (primalDataCenter[randNum] == nullptr) {
            antPos.push_back(randNum);
            antCount++;
            delete primalDataCenter[randNum];
            primalDataCenter[randNum] = new Ant(randNum);
        }
    }
}
void Grid::printGrid() {
    for (int i = 0; i < primalDataCenter.size(); i++) {
        if (primalDataCenter[i] == nullptr) {
            cout << '-' << ' ';
        }
        else {
            cout << primalDataCenter[i]->getType() << ' ';
        }
        if ((i + 1) % 20 == 0)
            cout << endl;
    }
}
int main() {

    // Setup =========================================
    srand(time(NULL));    // Initializing seed
    int timeframe = 1;
    string userInput;

    Grid leviathan = Grid();
    leviathan.printGrid();

    cout << "Please hit enter for next time-step, or any other key to exit!\n" << endl;
    cout << "Hold it, if you will! :)\n";
    getline(cin, userInput);
    while (userInput == "") {
        leviathan.timeframeSkip();
        leviathan.printGrid();
        cout << "Current step: " << timeframe++ << '\n';
        cout << "Please hit enter for next time-step, or any other key to exit!\n" << endl;
        getline(cin, userInput);
    }
    return 0;
}