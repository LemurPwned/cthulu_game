cmake_minimum_required(VERSION 3.8)
project(cthulu_game)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp character.h character.cpp location.cpp location.h
        hero.cpp hero.h FileReader.cpp FileReader.h level_assembler.cpp level_assembler.h
        json/json.hpp Event.cpp Event.h EventChain.cpp EventChain.h opponent.cpp opponent.h
        Statistics.cpp Statistics.h Randomizer.cpp Randomizer.h npc.h)
add_executable(cthulu_game ${SOURCE_FILES})