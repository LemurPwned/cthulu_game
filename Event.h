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
    bool event_effect = false;
    bool teleport = false;

    std::string question;
    std::string answer;
    std::string item;
    int effect;

public:
    explicit Event(int eventId, std::string event_type, std::string question, std::string answer,\
                    int effect);

    explicit Event(int eventId, std::string event_type, std::string question, std::string answer, \
                    std::string item);

    Event(int eventId, std::string event_type, std::string question, std::string answer);

    Event (int eventId, std::string event_type): eventId(eventId), event_type(event_type) {};

    Event (const Event &ev);

    bool isTeleport() const{
        return teleport;
    }

    bool isEvent_item() const;

    void setEvent_item(bool event_item);

    const std::string &getItem() const;

    void setItem(const std::string &item);

    void printEvent(){
        std::cout<<"Event: "<<eventId<<" type "<<event_type<<" question: "<<question<<std::endl;
    }

    const std::string &getQuestion() const {
        return question;
    }

    bool isEffect() const;

    void setEvent_effect(bool event_effect);

    int getEffect() const;

    void setEffect(int effect);

    const std::string &getAnswer() const {
        return answer;
    }

    void setTeleport(bool teleportation);

    void disableTeleport();

    virtual ~Event();
};
#endif //CTHULU_GAME_EVENT_H
