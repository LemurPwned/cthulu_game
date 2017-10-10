//
// Created by lemurpwned on 09/10/17.
//

#ifndef CTHULU_GAME_DIALOG_H
#define CTHULU_GAME_DIALOG_H

#include <string>
#include <vector>
#include <iostream>

class Dialog{

private:
    std::vector<std::string> current_dialog_options;
    std::vector<std::string> current_answer_options;

public:
    Dialog(const std::vector<std::string> &current_dialog_options,
           const std::vector<std::string> &current_answer_options) : current_dialog_options(current_dialog_options),
                                                                     current_answer_options(current_answer_options) {}

    void displayCurrentDialogOptions(){
        for (int i = 0; i < current_dialog_options.size(); ++i) {
            std::cout<<i<<") "<<current_dialog_options[i]<<std::endl;
        }
    }

    void displayAnswer(int dialog_number){
        if (dialog_number < current_answer_options.size()){
            std::cout<<"-"<<current_answer_options[dialog_number]<<std::endl;
        }
    }

};
#endif //CTHULU_GAME_DIALOG_H
