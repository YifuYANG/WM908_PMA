#include "GameStart.h"


GameStart::GameStart() = default;


GameStart &GameStart::InitializeBoard() {
    this->initializedBoard = new Map(10,7);
    return *this;
}

GameStart &GameStart::display() {
    //display map
    if(this->initializedBoard != nullptr) {
        //check animals HP
        this->initializedBoard->display();
    }
    //display counter
    display_counter();
    return *this;
}

GameStart& GameStart::move_oneRound() {
    for (int i = 1; i <= initializedBoard->getList().GetSize(); i++) {
        Animal& animal = *initializedBoard->getList().getByIndex(i)->getData();
        if(animal.getCharacter()==(int) Characters::Vegetation) continue;
        int x = animal.getX();
        int y = animal.getY();
        animal.move();
        if (!animal.isWhetherThisAnimalHasMovedOrNot()) {
            if (initializedBoard->placeAt(animal)) {
                initializedBoard->board[x][y]=0;
            } else {
                int next_x=animal.getX();
                int next_y=animal.getY();
                animal.setX(x);
                animal.setY(y);
//                cout<<"Old: "<<x<<" X "<<y<<endl;
//                cout<<"New: "<<next_x<<" X "<<next_y<<endl;
//                interaction(next_x,next_y,x,y);
            }
        }
    }
    set_all_animal_to_has_not_moved();
    cout<<"====================="<<endl;
    initializedBoard->getList().printList();
    return *this;
}

GameStart & GameStart::place_random_characters_at_random_locations_on_the_board() {
    for(int i=0;i<10; i++){
        int rand_X;
        int rand_Y;
        do{
            rand_X = random_number_generator(initializedBoard->getY());
            rand_Y = random_number_generator(initializedBoard->getX());
        } while(!initializedBoard->placeAt(random_character_generator(rand_X,rand_Y)));
    }

    initializedBoard->getList().printList();

//    initializedBoard->placeAt(*new Omnivore(0,0));
//    initializedBoard->placeAt(*new Vegetation(0,1));
//    initializedBoard->placeAt(*new Vegetation(1,1));
//    initializedBoard->placeAt(*new Vegetation(1,0));
//    initializedBoard->placeAt(*new Omnivore(0,2));
//    initializedBoard->placeAt(*new Omnivore(1,2));
//    initializedBoard->placeAt(*new Omnivore(2,2));
//    initializedBoard->placeAt(*new Omnivore(2,0));
//    initializedBoard->placeAt(*new Omnivore(2,1));
//    initializedBoard->placeAt(*new Vegetation(0,3));
//    initializedBoard->placeAt(*new Vegetation(1,3));
//    initializedBoard->placeAt(*new Vegetation(2,3));
//    initializedBoard->placeAt(*new Vegetation(3,3));
//    initializedBoard->placeAt(*new Vegetation(3,0));
//    initializedBoard->placeAt(*new Vegetation(3,1));
//    initializedBoard->placeAt(*new Vegetation(3,2));
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
    SinglyLinkedList& list=this->initializedBoard->getList();
    for(int i=1;i<=list.GetSize();i++){
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

    SinglyLinkedList& list = initializedBoard->getList();
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
        cout<<"Initial Board => [";
    } else {
        cout<<"Step "<< number_of_steps<<" => [";
    }
    cout<< "T: " << T_counter <<" H: "<<H_counter <<" C: "<<C_counter <<" O: "<<O_counter<<"] "<<endl;
}

void GameStart::interaction(int next_x, int next_y, int pre_x, int pre_y) {
    SinglyLinkedList& list = initializedBoard->getList();
    //if(list.getByXY(pre_x,pre_y)== nullptr) return;

    Animal& next_animal = *list.getByXY(next_x,next_y)->getData();
    Animal& pre_animal = *list.getByXY(pre_x,pre_y)->getData();

//    int pre_character = pre_animal.getCharacter();
//    int cur_character = animal.getCharacter();
//    if(pre_character == (int) Characters::Herbivore && cur_character == (int) Characters::Vegetation){
//        cout<<"Her ==========================================================> Veg"<<endl;
//        Animal updated_animal = animal;
//        updated_animal.setHp(updated_animal.getHp()-10);
//        list.ReplaceByIndex(updated_animal.getIndex(), &updated_animal);
//    } else if(pre_character == (int) Characters::Carnivore && cur_character == (int) Characters::Herbivore){
//        cout<<"Car ==========================================================> Her"<<endl;
//        Animal updated_animal = animal;
//        updated_animal.setHp(updated_animal.getHp()-10);
//        list.ReplaceByIndex(updated_animal.getIndex(), &updated_animal);
//    } else if (pre_character == (int) Characters::Omnivore && (cur_character == (int) Characters::Herbivore || cur_character == (int) Characters::Vegetation)) {
//        cout<<"Omn ==========================================================> H&V"<<endl;
//        Animal updated_animal = animal;
//        updated_animal.setHp(updated_animal.getHp()-10);
//        list.ReplaceByIndex(updated_animal.getIndex(), &updated_animal);
//    }
//    cout<<"X and Y: "<<animal.getX()<<" X "<<animal.getY()<<endl;
//    cout<<"old X and Y "<<pre_x<<" X "<<pre_y<<endl;
}



