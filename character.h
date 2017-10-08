//
// Created by Jakub on 06/10/2017.
//

#ifndef CTHULU_GAME_CHARACTER_H
#define CTHULU_GAME_CHARACTER_H

#include <string>
#include <iostream>
#include <vector>

class Character{
private:
    std::string name;
    int hp = 100;
    bool alive = true;

    std::string description;
    std::vector<std::string> dialog_options;
    std::vector<std::string> dialog_answers;

protected:
    int x = 0;
    int y = 0;

public:
    Character();

    explicit Character(const std::string &name) : name(name) {};

    Character(const std::string &name, const std::string &desc): name(name), description(desc) {};

    void loadCharacter(const std::string &filename);

    virtual void introduction();

    void pushDialog(const std::string &dialog){
        dialog_options.push_back(dialog);
    }

    void pushAnswers(const std::string &answer){
        dialog_answers.push_back(answer);
    }

    std::string popDialog(int dialog_number){
        return dialog_options[dialog_number];
    }

    std::string popAnswer(int answer_number){
        return dialog_answers[answer_number];
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Character::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Character::y = y;
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Character::name = name;
    }

    int getHp() const {
        return hp;
    }

    void setHp(int hp) {
        Character::hp = hp;
        if (Character::hp < 0){
            std::cout<<Character::name<<" has died"<<std::endl;
            Character::alive = false;
        }
    }

    bool isAlive() const {
        return alive;
    }

    void setAlive(bool alive) {
        Character::alive = alive;
    }

    const std::string &getDescription() const {
        return description;
    }

    void setDescription(const std::string &description) {
        Character::description = description;
    }
};
#endif //CTHULU_GAME_CHARACTER_H
