//
// Created by lemurpwned on 09/10/17.
//

#ifndef CTHULU_GAME_EVENT_H
#define CTHULU_GAME_EVENT_H

#include <string>
#include <vector>
#include <iostream>

class Event{

private:
    int eventId;
    std::string event_type;
    bool event_item = false;
    bool event_decision = false;

    std::string question;
    std::string answer;
    std::string item;

    std::vector<std::string> decision;

public:
    Event(int eventId, std::string event_type, std::string question, std::string answer, std::string item);

    bool isEvent_item() const;

    void setEvent_item(bool event_item);

    const std::string &getItem() const;

    void setItem(const std::string &item);

    Event(int eventId, std::string event_type, std::string question, std::string answer);

    void addDecision(const std::string &decision){
        event_decision = true;
        Event::decision.push_back(decision);
    }

    void printEvent(){
        std::cout<<"Event: "<<eventId<<" type "<<event_type<<" question: "<<question<<std::endl;
    }

    const std::string &getQuestion() const {
        return question;
    }

    const std::string &getAnswer() const {
        return answer;
    }
};
#endif //CTHULU_GAME_EVENT_H
