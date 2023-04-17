#include "Simulation.h"


Simulation::Simulation() = default;


Simulation &Simulation::InitializeBoard() {
    this->initializedBoard = new Map(10,7);
    return *this;
}

Simulation &Simulation::display() {
    //display map
    if(this->initializedBoard != nullptr) {
        this->initializedBoard->display();
    }
    //display counter
    display_counter();
    initializedBoard->getList().printList();
    return *this;
}

Simulation& Simulation::move_oneRound() {
    head = initializedBoard->getList().getHead();
    Node* temp = head;
    while (temp!= nullptr){
        //wen yi wen
        Animal* animal = temp->getData();

        if(animal->getCharacter()==(int) Characters::Vegetation){
            temp=temp->getNext();
            continue;
        }
        int x = animal->getX();
        int y = animal->getY();
//        cout<<"Old XY: "<<temp->getData()->getX()<<" X "<<temp->getData()->getY()<<endl;
//        cout<<"Old HP: "<<temp->getData()->getHp()<<endl;
        animal->move();
//        cout<<"NEW XY: "<<temp->getData()->getX()<<" X "<<temp->getData()->getY()<<endl;
        if (initializedBoard->placeAt(*animal)) {
            initializedBoard->board[x][y]=0;
            loss_HP_due_to_hunger(animal);
        } else {
            int next_x=animal->getX();
            int next_y=animal->getY();
            animal->setX(x);
            animal->setY(y);
            interaction(next_x,next_y,x,y);
        }
//        cout<<"New HP: "<<temp->getData()->getHp()<<endl;
//        cout<<"+++++++++++++++"<<endl;
        temp=temp->getNext();
    }
    remove_animals_with_no_HP();
    return *this;
}

Simulation & Simulation::place_random_characters_at_random_locations_on_the_board() {
    for(int i=0;i<15; i++){
        int rand_X;
        int rand_Y;
        Animal rand_an;
        do{
            rand_X = random_number_generator(initializedBoard->getY());
            rand_Y = random_number_generator(initializedBoard->getX());
            rand_an = random_character_generator(rand_X,rand_Y);
        } while(!initializedBoard->placeAt(rand_an));
        initializedBoard->store_animals_to_container(rand_an.getCharacter(),rand_X,rand_Y);
    }
    return *this;
}

/* helper function for place_random_characters_at_random_locations_on_the_board:
 * generate a random number in the range of given bounds,
 * for example: given range -> 1 - 10,
 * it will generate number -> 0 - 9,
 * which corresponds to the array index.
 * */
int Simulation::random_number_generator(int range) {
    return rand() % range;
}


Animal Simulation::random_character_generator(int in_x, int in_y) {
    int random_number = random_number_generator(4)+2;
    switch (random_number) {
        case (int)Characters::Vegetation:
            return *new Vegetation(in_x, in_y);
        case (int)Characters::Herbivore:
            return *new Herbivore(in_x, in_y);
        case (int)Characters::Carnivore:
            return *new Carnivore(in_x, in_y);
        case (int)Characters::Omnivore:
            return *new Omnivore(in_x, in_y);
        default:
            break;
    }
}

void Simulation::display_counter() {
    int T_counter=0;
    int H_counter=0;
    int C_counter=0;
    int O_counter=0;
    head = initializedBoard->getList().getHead();
    Node* temp = head;
    while (temp != nullptr){
        int character = temp->getData()->getCharacter();
        if(character == (int) Characters::Vegetation){
            T_counter++;
        } else if (character == (int) Characters::Herbivore){
            H_counter++;
        } else if(character == (int) Characters::Carnivore){
            C_counter++;
        } else if(character == (int) Characters::Omnivore){
            O_counter++;
        }
        temp=temp->getNext();
    }
    number_of_steps++;
    if(number_of_steps==0){
        cout<<"Initial Board => [";
    } else {
        cout<<"Step "<< number_of_steps<<" => [";
    }
    cout<< "T: " << T_counter <<" H: "<<H_counter <<" C: "<<C_counter <<" O: "<<O_counter<<"] "<<endl;
}

//wen yi wen?
void Simulation::interaction(int next_x, int next_y, int pre_x, int pre_y) {
    Animal* next_animal;
    SinglyLinkedList list = initializedBoard->getList();
    Animal* pre_animal = list.getByXY(pre_x,pre_y)->getData();
    if(initializedBoard->getXY(next_x,next_y)){
        next_animal = list.getByXY(next_x,next_y)->getData();
    } else {
        loss_HP_due_to_hunger(pre_animal);
        return;
    }
    int pre_character = pre_animal->getCharacter();
    int next_character = next_animal->getCharacter();
    if(pre_character == (int) Characters::Herbivore && next_character == (int) Characters::Vegetation){
        get_HP_due_to_consuming(pre_animal);
        loss_HP_due_to_being_consumed(next_animal);
    } else if(pre_character == (int) Characters::Carnivore && next_character == (int) Characters::Herbivore){
        get_HP_due_to_consuming(pre_animal);
        loss_HP_due_to_being_consumed(next_animal);
    } else if (pre_character == (int) Characters::Omnivore && (next_character == (int) Characters::Herbivore || next_character == (int) Characters::Vegetation)) {
        get_HP_due_to_consuming(pre_animal);
        loss_HP_due_to_being_consumed(next_animal);
    } else if(next_x==pre_x && next_y == pre_y){
        loss_HP_due_to_hunger(pre_animal);
    } else {
        loss_HP_due_to_hunger(pre_animal);
    }
}

void Simulation::loss_HP_due_to_being_consumed(Animal *animal) {
        animal->setHp(animal->getHp()-10);
}

void Simulation::loss_HP_due_to_hunger(Animal* animal) {
    animal->setHp(animal->getHp()-1);
}

void Simulation::get_HP_due_to_consuming(Animal *animal) {
    animal->setHp(animal->getHp()+10);
}

void Simulation::remove_animals_with_no_HP() {
    Node* prev = nullptr;
    Node* curr = initializedBoard->getList().getHead();

    while (curr != nullptr) {
        if (curr->getData()->getHp() <= 0) {
            initializedBoard->board[curr->getData()->getX()][curr->getData()->getY()] = 0;
            if (prev != nullptr) {
                prev->setNext(curr->getNext());
            } else {
                initializedBoard->getList().setHead(curr->getNext());
            }
            Node* temp = curr;
            curr = curr->getNext();
            delete temp;
            initializedBoard->getList().setSize(initializedBoard->getList().GetSize()-1);
        } else {
            prev = curr;
            curr = curr->getNext();
        }
    }
}

void Simulation::reproduction(Animal* animal) {
    double FR = animal->getFr();

    if(animal->getCharacter()==(int) Characters::Vegetation){
        if(initializedBoard->placeAt(*new Vegetation(1,1))){

        }
    }


}



