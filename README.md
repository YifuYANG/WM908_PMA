# Board Game Simulation

This is a C++ program that simulates a board game. The game involves characters moving around on a board and reproducing to create new characters. The program uses random numbers to add an element of unpredictability to the game.

# How to Run

To run the program, please copy below codes. 

To change the parameters, please go to [Setting.h](./Settings/Settings.h).

1. To initialize the board, place random blocks and characters on it, and display the initial state of the board. Please copy and run the following code:
```C++
Settings settings;
Simulation simulation;
srand(time(nullptr));
simulation.InitializeBoard().
place_random_blocks().
place_random_characters_at_random_locations_on_the_board().
display();
``` 
2. To initialize the board, place random blocks and characters on it, display the initial state of the board, move all the characters on the board once (without reproduction), and display the updated state of the board after each step. Please copy and run the following code (please change the [Setting.h](./Settings/Settings.h) depending on how many steps you want the character to move):

```C++
Settings settings;
Simulation simulation;
srand(time(nullptr));
simulation.InitializeBoard().
place_random_blocks().
place_random_characters_at_random_locations_on_the_board().
display();
for(int j=0;j<settings.steps;j++){
simulation.move_oneRound().
display();
}
``` 

3. To initialize the board, place random blocks and characters on it, display the initial state of the board, move all the characters on the board once, let the animals on the board reproduce themselves, and display the updated state of the board after each step. Please copy and run the following code (please change the [Setting.h](./Settings/Settings.h) depending on how many steps you want the character to move):
```C++
Settings settings;
Simulation simulation;
srand(time(nullptr));
simulation.InitializeBoard().
place_random_blocks().
place_random_characters_at_random_locations_on_the_board().
display();
for(int j=0;j<settings.steps;j++){
simulation.move_oneRound().
reproduction().
display();
}
``` 

4. To get average of amount of simulations after amount of steps for all types of animals, please copy and run the following code (please change the [Setting.h](./Settings/Settings.h) depending on the mount of simulation and steps you want):
```C++
Settings settings;
int Total_T=0;
int Total_H=0;
int Total_C=0;
int Total_O=0;
for(int i=0;i<settings.number_of_simulations;i++){
srand(time(nullptr));
Simulation simulation;
simulation.InitializeBoard().
place_random_blocks().
place_random_characters_at_random_locations_on_the_board();
for(int j=0;j<settings.steps;j++){
simulation.move_oneRound().
reproduction().
count_ave_character();
}
cout<<"Step: "<<i+1<<endl;
cout<<"Average T over 1000 steps: "<<simulation.T_total/1000<<endl;
Total_T+=simulation.T_total/1000;
cout<<"Average H over 1000 steps: "<<simulation.H_total/1000<<endl;
Total_H+=simulation.H_total/1000;
cout<<"Average C over 1000 steps: "<<simulation.C_total/1000<<endl;
Total_C+=simulation.C_total/1000;
cout<<"Average O over 1000 steps: "<<simulation.O_total/1000<<endl;
Total_O+=simulation.O_total/1000;
cout<<"===================================="<<endl;
}
cout<<"Average T in 100 times simulation after 1000 steps: " << Total_T/100<<endl;
cout<<"Average H in 100 times simulation after 1000 steps: " << Total_H/100<<endl;
cout<<"Average C in 100 times simulation after 1000 steps: " << Total_C/100<<endl;
cout<<"Average O in 100 times simulation after 1000 steps: " << Total_O/100<<endl;
``` 
5. To run simulations for a number of steps until the user presses ‘q’, please copy and run the following code:
```C++
Settings settings;
srand(time(nullptr));
Simulation simulation;
simulation.InitializeBoard().
place_random_blocks().
place_random_characters_at_random_locations_on_the_board().
display();
while(true){
    string input;
    cout << "Type anything to continue or q to quit: ";
    cin >>input;
    if(input!="q"){
        simulation.move_oneRound().
        reproduction().
        display();
    } else {
        cout <<"Program killed by user"<<endl;
        break;
    }
}
``` 
6. To Initialize the board with a input file, please copy and run the following code:
```C++

srand(time(nullptr));
Simulation simulation;
simulation.Initialize_board_with_input_source().
place_random_characters_at_random_locations_on_the_board().
display();
``` 

7. To save a map, please copy and run the following code:
```C++
srand(time(nullptr));
Simulation simulation;
simulation.InitializeBoard().
place_random_blocks().
place_random_characters_at_random_locations_on_the_board().
display();
for(int j=0;j<settings.steps;j++){
simulation.move_oneRound().
reproduction().
display();
}
string input;
cout << "Type s to save the map: ";
cin >>input;
if(input=="s"){
simulation.save_map();
cout << "Map is saved to ../File_IO/Output_Document/Output.txt !!";
}
``` 

7. To load a save map and let it continue to run, please copy and run the following code:
```C++
srand(time(nullptr));
Simulation simulation;
simulation.InitializeBoard().
place_random_blocks().
place_random_characters_at_random_locations_on_the_board().
display();
for(int j=0;j<settings.steps;j++){
simulation.move_oneRound().
reproduction().
display();
}
string input;
cout << "Type s to save the map: ";
cin >>input;
if(input=="s"){
simulation.save_map();
cout << "Map is saved to ../File_IO/Output_Document/Output.txt !!";
}
simulation.load_saved_map().
display().
move_oneRound().
reproduction().
display();
``` 
