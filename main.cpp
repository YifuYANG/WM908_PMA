#include "Components/Simulation.h"
#include "Settings/Settings.h"
#include <random>
using namespace std;

int main() {
    Settings settings;

//    for(int i=0;i<settings.number_of_simulations;i++){
//        std::srand(time(nullptr));
//        Simulation simulation;
//        simulation.InitializeBoard().
//        place_random_blocks().
//        place_random_characters_at_random_locations_on_the_board();
//        for(int j=0;j<settings.steps;j++){
//            simulation.move_oneRound().
//                    reproduction().
//                    count_ave_character();
//        }
//        cout<<"Step: "<<i+1<<endl;
//        cout<<"Average T over 1000 steps: "<<simulation.T_total/1000<<endl;
//        cout<<"Average H over 1000 steps: "<<simulation.H_total/1000<<endl;
//        cout<<"Average C over 1000 steps: "<<simulation.C_total/1000<<endl;
//        cout<<"Average O over 1000 steps: "<<simulation.O_total/1000<<endl;
//        cout<<"===================================="<<endl;
//    }


//    std::srand(time(nullptr));
//    Simulation simulation;
//    simulation.InitializeBoard().
//    place_random_blocks().
//    place_random_characters_at_random_locations_on_the_board().
//    display();
//    while(true){
//        string input;
//        cout << "Type anything to continue or q to quit: ";
//        cin >>input;
//        if(input!="q"){
//            simulation.move_oneRound().
//            reproduction().
//            display();
//        } else {
//            cout <<"Program killed by user"<<endl;
//            break;
//        }
//    }

//        std::srand(time(nullptr));
//        Simulation simulation;
//        simulation.InitializeBoard().
//                place_random_blocks().
//                place_random_characters_at_random_locations_on_the_board().
//                display();
//        for(int j=0;j<settings.steps;j++){
//            simulation.move_oneRound().
//                    reproduction().
//                    display();
//        }

//        srand(time(nullptr));
//        Simulation simulation;
//        simulation.Initialize_board_with_input_source().
//        place_random_characters_at_random_locations_on_the_board().
//        display();
//
//        simulation.
//        move_oneRound().
//        reproduction().
//        display().
//        move_oneRound().
//        reproduction().
//        display().
//        move_oneRound().
//        reproduction().
//        display();


        std::srand(time(nullptr));
        Simulation simulation;
//        simulation.InitializeBoard().
//                place_random_blocks().
//                place_random_characters_at_random_locations_on_the_board().
//                display();
//        for(int j=0;j<settings.steps;j++){
//            simulation.move_oneRound().
//                    reproduction().
//                    display();
//        }
//        string input;
//        cout << "Type s to save the map: ";
//        cin >>input;
//        if(input=="s"){
//            simulation.save_map();
//            cout << "Map is saved to ../File_IO/Output_Document/Output.txt !!";
//        }
        simulation.load_saved_map().
        display().
        move_oneRound().
        reproduction().
        display();
}