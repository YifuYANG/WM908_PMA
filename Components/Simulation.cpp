#include "Simulation.h"


Simulation::Simulation() = default;


Simulation &Simulation::InitializeBoard() {
    this->initializedBoard = new Map(settings.Y,settings.X);
    return *this;
}

Simulation &Simulation::display() {
    //display map
    if(this->initializedBoard != nullptr) {
        this->initializedBoard->display();
    }
    //display counter
    display_counter();
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
        animal->move();
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
        temp=temp->getNext();
    }
    remove_animals_with_no_HP();
    return *this;
}

Simulation & Simulation::place_random_characters_at_random_locations_on_the_board() {
    place_random_T_at_random_locations_on_the_board(settings.T);
    place_random_C_at_random_locations_on_the_board(settings.C);
    place_random_H_at_random_locations_on_the_board(settings.H);
    place_random_O_at_random_locations_on_the_board(settings.O);
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


Animal Simulation::character_generator(int in_x, int in_y, int character) {
    switch (character) {
        case (int)Characters::Vegetation:
            return *new Vegetation(in_x, in_y);
        case (int)Characters::Herbivore:
            return *new Herbivore(in_x, in_y);
        case (int)Characters::Carnivore:
            return *new Carnivore(in_x, in_y);
        case (int)Characters::Omnivore:
            return *new Omnivore(in_x, in_y);
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
    } else if(pre_character == (int) Characters::Carnivore && (next_character == (int) Characters::Herbivore || next_character == (int) Characters::Omnivore)){
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

Simulation& Simulation::reproduction() {
    head = initializedBoard->getList().getHead();
    Node* temp = head;
    while (temp!= nullptr){
        int total_t = count_T();
        int total_h = count_H();
        int total_c = count_C();
        if (temp->getData()->getCharacter() == (int) Characters::Vegetation) {
            if(total_t < (initializedBoard->getX() * initializedBoard->getY())/6){
                place_random_T_at_random_locations_on_the_board(1);
            } else if(total_t >= (initializedBoard->getX() * initializedBoard->getY())/3){
                temp = temp->getNext();
                continue;
            }
        }
        if(temp->getData()->getCharacter() == (int)Characters::Herbivore){
            if(total_h < (initializedBoard->getX() * initializedBoard->getY())/6){
                place_random_H_at_random_locations_on_the_board(1);
            } else if(total_h >= (initializedBoard->getX() * initializedBoard->getY())/3){
                temp = temp->getNext();
                continue;
            }
        }

        if(temp->getData()->getCharacter() == (int)Characters::Carnivore){
            if(total_c < (initializedBoard->getX() * initializedBoard->getY())/6){
                place_random_C_at_random_locations_on_the_board(1);
            } else if(total_c >= (initializedBoard->getX() * initializedBoard->getY())/5){
                temp = temp->getNext();
                continue;
            }
        }
        Animal* animal = temp->getData();
        double FR = animal->getFr();
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0, 1);
        double per= dis(gen);
        if(per < FR){
            Animal offspring = determine_parent_and_generator_offspring(animal);
            if(determine_if_there_are_spaces_for_reproduction(animal->getX(),animal->getY())){
                do{
                    offspring.setX(animal->getX());
                    offspring.setY(animal->getY());
                    random_select_spawn_point_in_one_of_the_four_cardinal_compass_points(&offspring);
                } while(!initializedBoard->placeAt(offspring));
                initializedBoard->store_animals_to_container(offspring.getCharacter(),offspring.getX(),offspring.getY());
            }
        }
        temp=temp->getNext();
    }
    return * this;
}

//random spawn around the parent (four directions).
void Simulation::random_select_spawn_point_in_one_of_the_four_cardinal_compass_points(Animal* offspring) {
    int random_point = rand() % 4;
    switch (random_point) {
        case (int) Direction::South: // Move South (increase x)
            offspring->setX(offspring->getX()+1);
            break;
        case (int) Direction::North: // Move North (decrease x)
            offspring->setX(offspring->getX()-1);
            break;
        case (int) Direction::East: // Move East (increase y)
            offspring->setY(offspring->getY()+1);
            break;
        case (int) Direction::West: // Move West (decrease y)
            offspring->setY(offspring->getY()-1);
            break;
        default:
            break;
    }
}

//create offsprings with their parent's characters.
Animal Simulation::determine_parent_and_generator_offspring(Animal *animal) {
    switch (animal->getCharacter()) {
        case (int)Characters::Vegetation:
            return *new Vegetation(animal->getX(),animal->getY());
        case (int)Characters::Herbivore:
            return *new Herbivore(animal->getX(),animal->getY());
        case (int)Characters::Carnivore:
            return *new Carnivore(animal->getX(),animal->getY());
        case (int)Characters::Omnivore:
            return *new Omnivore(animal->getX(),animal->getY());
        default:
            break;
    }
}

//return true if at least one animal can be placed on the board.
bool Simulation:: determine_if_there_are_spaces_for_reproduction(int x,int y){
    if(initializedBoard->placeAt(*new Animal(x-1,y))
       || initializedBoard->placeAt(*new Animal(x+1,y))
       || initializedBoard->placeAt(*new Animal(x,y-1))
       || initializedBoard->placeAt(*new Animal(x,y+1))){
        return true;
    } else {
        return false;
    }
}

Simulation &Simulation::count_ave_character() {
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
    T_total+=T_counter;
    C_total+=C_counter;
    O_total+=O_counter;
    H_total+=H_counter;
    return *this;
}

void Simulation::place_random_C_at_random_locations_on_the_board(int amount) {
    for(int i=0;i<amount; i++){
        int rand_X;
        int rand_Y;
        Animal rand_an;
        do{
            rand_X = random_number_generator(initializedBoard->getY());
            rand_Y = random_number_generator(initializedBoard->getX());
            rand_an = character_generator(rand_X,rand_Y,(int)Characters::Carnivore);
        } while(!initializedBoard->placeAt(rand_an));
        initializedBoard->store_animals_to_container(rand_an.getCharacter(),rand_X,rand_Y);
    }
}

void Simulation::place_random_T_at_random_locations_on_the_board(int amount) {
    for(int i=0;i<amount; i++){
        int rand_X;
        int rand_Y;
        Animal rand_an;
        do{
            rand_X = random_number_generator(initializedBoard->getY());
            rand_Y = random_number_generator(initializedBoard->getX());
            rand_an = character_generator(rand_X,rand_Y,(int)Characters::Vegetation);
        } while(!initializedBoard->placeAt(rand_an));
        initializedBoard->store_animals_to_container(rand_an.getCharacter(),rand_X,rand_Y);
    }
}

void Simulation::place_random_H_at_random_locations_on_the_board(int amount) {
    for(int i=0;i<amount; i++){
        int rand_X;
        int rand_Y;
        Animal rand_an;
        do{
            rand_X = random_number_generator(initializedBoard->getY());
            rand_Y = random_number_generator(initializedBoard->getX());
            rand_an = character_generator(rand_X,rand_Y,(int)Characters::Herbivore);
        } while(!initializedBoard->placeAt(rand_an));
        initializedBoard->store_animals_to_container(rand_an.getCharacter(),rand_X,rand_Y);
    }
}

void Simulation::place_random_O_at_random_locations_on_the_board(int amount) {
    for(int i=0;i<amount; i++){
        int rand_X;
        int rand_Y;
        Animal rand_an;
        do{
            rand_X = random_number_generator(initializedBoard->getY());
            rand_Y = random_number_generator(initializedBoard->getX());
            rand_an = character_generator(rand_X,rand_Y,(int)Characters::Omnivore);
        } while(!initializedBoard->placeAt(rand_an));
        initializedBoard->store_animals_to_container(rand_an.getCharacter(),rand_X,rand_Y);
    }
}

int Simulation::count_T() {
    int T_counter=0;
    head = initializedBoard->getList().getHead();
    Node* temp = head;
    while (temp != nullptr){
        int character = temp->getData()->getCharacter();
        if(character == (int) Characters::Vegetation){
            T_counter++;
        }
        temp=temp->getNext();
    }
    return T_counter;
}

int Simulation::count_H() {
    int H_counter=0;
    head = initializedBoard->getList().getHead();
    Node* temp = head;
    while (temp != nullptr){
        int character = temp->getData()->getCharacter();
        if (character == (int) Characters::Herbivore){
            H_counter++;
        }
        temp=temp->getNext();
    }
    return H_counter;
}

int Simulation::count_C() {
    int C_counter=0;
    head = initializedBoard->getList().getHead();
    Node* temp = head;
    while (temp != nullptr){
        int character = temp->getData()->getCharacter();
        if(character == (int) Characters::Carnivore){
            C_counter++;
        }
        temp=temp->getNext();
    }
    return C_counter;
}

int Simulation::count_O() {
    int O_counter=0;
    head = initializedBoard->getList().getHead();
    Node* temp = head;
    while (temp != nullptr){
        int character = temp->getData()->getCharacter();
        if(character == (int) Characters::Omnivore){
            O_counter++;
        }
        temp=temp->getNext();
    }
    return O_counter;
}

Simulation &Simulation::Initialize_board_with_input_source() {
    ifstream file("../File_IO/Input_Document/Input.txt");
    string line;
    getline(file, line);
    int x = stoi(line);
    getline(file, line);
    int y = stoi(line);
    this->initializedBoard = new Map(x,y);

    int i=0;
    while (getline(file, line)) {
        for(int j=0;j<line.length();j++){
            char curr = line[j];
            if(curr=='#'){
                place_input_blocks_to_board(i,j);
            }
        }
        i++;
    }
    file.close();
    return *this;
}

Simulation &Simulation::place_random_blocks() {
    int BlockCounter=0;
    while(BlockCounter<settings.Blocks){
        int rand_i = rand() % initializedBoard->getY();
        int rand_j = rand() % initializedBoard->getX();
        if(initializedBoard->board[rand_i][rand_j]==0){
            initializedBoard->board[rand_i][rand_j] = 1;
            BlockCounter++;
        }
    }
    return *this;
}

Simulation &Simulation::save_map() {
    ofstream outFile;
    outFile.open("../File_IO/Output_Document/Output.txt");
    outFile<<initializedBoard->getX()<<endl;
    outFile<<initializedBoard->getY()<<endl;
    for(int i=0;i<initializedBoard->getY();i++){
        for(int j=0;j<initializedBoard->getX();j++){
            outFile << initializedBoard->board[i][j];
        }
        outFile<<endl;
    }
    outFile.close();
    return *this;
}

Simulation &Simulation::load_saved_map() {
    ifstream file("../File_IO/Output_Document/Output.txt");
    string line;

    getline(file, line);
    int x = stoi(line);
    getline(file, line);
    int y = stoi(line);
    this->initializedBoard = new Map(x,y);

    int i=0;
    while (getline(file, line)) {
        for(int j=0;j<line.length();j++){
            char curr = line[j];
            if(curr=='1'){
                place_input_blocks_to_board(i,j);
            } else if(curr=='2'){
                place_input_T_to_board(i,j);
                initializedBoard->store_animals_to_container((int)Characters::Vegetation,i,j);
            } else if(curr=='3'){
                place_input_H_to_board(i,j);
                initializedBoard->store_animals_to_container((int)Characters::Herbivore,i,j);
            } else if(curr=='4'){
                place_input_C_to_board(i,j);
                initializedBoard->store_animals_to_container((int)Characters::Carnivore,i,j);
            } else if(curr=='5'){
                place_input_O_to_board(i,j);
                initializedBoard->store_animals_to_container((int)Characters::Omnivore,i,j);
            }
        }
        i++;
    }
    file.close();
    return *this;
}
void Simulation::place_input_blocks_to_board(int input_x, int input_y) {
    initializedBoard->board[input_x][input_y] = 1;
}

void Simulation::place_input_T_to_board(int input_x, int input_y) {
    initializedBoard->board[input_x][input_y] = 2;
}

void Simulation::place_input_H_to_board(int input_x, int input_y) {
    initializedBoard->board[input_x][input_y] = 3;
}

void Simulation::place_input_C_to_board(int input_x, int input_y) {
    initializedBoard->board[input_x][input_y] = 4;
}

void Simulation::place_input_O_to_board(int input_x, int input_y) {
    initializedBoard->board[input_x][input_y] = 5;
}




