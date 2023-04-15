#include "GameStart.h"


GameStart::GameStart() = default;


GameStart &GameStart::InitializeBoard() {
    this->initializedBoard = new Map(10,7);
    return *this;
}

GameStart &GameStart::display() {
    //display map
    if(this->initializedBoard != nullptr) {
        this->initializedBoard->display();
    }
    //display counter
    display_counter();
    return *this;
}

GameStart& GameStart::move_oneRound() {
    for (int i = 1; i <= initializedBoard->getList().GetSize(); i++) {
        Animal& animal = *initializedBoard->getList().getByIndex(i)->getData();
        int x = animal.getX();
        int y = animal.getY();
        animal.move();
        if (!animal.isWhetherThisAnimalHasMovedOrNot()) {
            if (initializedBoard->placeAt(animal)) {
                initializedBoard->board[x][y]=0;
            } else {
                animal.setX(x);
                animal.setY(y);
            }
        }
        set_all_animal_to_has_not_moved();
    }

    return *this;
}

GameStart & GameStart::place_random_characters_at_random_locations_on_the_board() {
    for(int i=0;i<12; i++){
        int rand_X;
        int rand_Y;
        do{
            rand_X = random_number_generator(initializedBoard->getY());
            rand_Y = random_number_generator(initializedBoard->getX());
        } while(!initializedBoard->placeAt(random_character_generator(rand_X,rand_Y)));
    }
    return *this;
}

/* helper function for place_random_characters_at_random_locations_on_the_board:
 * generate a random number in the range of given bounds,
 * for example: given range -> 1 - 10,
 * it will generate number -> 0 - 9,
 * which corresponds to the array index.
 * */
int GameStart::random_number_generator(int range) {
    return rand() % range;
}

void GameStart::set_all_animal_to_has_not_moved() {
    SinglyLinkedList list=this->initializedBoard->getList();
    for(int i=1;i<list.GetSize();i++){
        list.getByIndex(i)->getData()->setWhetherThisAnimalHasMovedOrNot(false);
    }
}

Animal& GameStart::random_character_generator(int in_x, int in_y) {
    int random_number = random_number_generator(4)+2;
    switch (random_number) {
        case 2:
            return *new Vegetation(in_x, in_y);
        case 3:
            return *new Herbivore(in_x, in_y);
        case 4:
            return *new Carnivore(in_x, in_y);
        case 5:
            return *new Omnivore(in_x, in_y);
        default:
            break;
    }
}

void GameStart::display_counter() {
    int T_counter=0;
    int H_counter=0;
    int C_counter=0;
    int O_counter=0;

    SinglyLinkedList list = initializedBoard->getList();
    for(int i=1;i<=list.GetSize();i++){
        int character=list.getByIndex(i)->getData()->getCharacter();
        if(character == 2){
            T_counter++;
        } else if (character == 3){
            H_counter++;
        } else if(character == 4){
            C_counter++;
        } else {
            O_counter++;
        }
    }
    number_of_steps++;
    if(number_of_steps==0){
        cout<<"↑ Initial Board => [";
    } else {
        cout<<"↑ Step "<< number_of_steps<<" => [";
    }
    cout<< "T: " << T_counter <<" H: "<<H_counter <<" C: "<<C_counter <<" O: "<<O_counter<<"] "<<endl;

}



