cmake_minimum_required(VERSION 3.24)
project(PMA)

set(CMAKE_CXX_STANDARD 17)

add_executable(PMA main.cpp Components/Map.cpp Components/Map.h "Settings/Settings.cpp" "Settings/Settings.h" Components/GameStart.cpp Components/GameStart.h Components/Characters/Animal.cpp Components/Characters/Animal.h Components/Characters/Vegetation.cpp Components/Characters/Vegetation.h Components/Enum/Direction.h Components/Characters/Herbivore.cpp Components/Characters/Herbivore.h Components/Characters/Carnivore.cpp Components/Characters/Carnivore.h Components/Characters/Omnivore.cpp Components/Characters/Omnivore.h Components/Characters/Hunter.cpp Components/Characters/Hunter.h Container/SinglyLinkedList.cpp Container/SinglyLinkedList.h Container/Node.cpp Container/Node.h Components/Enum/Characters.h)
