//
// Created by lemurpwned on 09/10/17.
//

#include "Event.h"

Event::Event(int eventId, std::string event_type, std::string question, std::string answer):
                eventId(eventId), event_type(event_type), question(question), answer(answer){}

Event::Event(int eventId, std::string event_type, std::string question, std::string answer, \
            std::string item):
        eventId(eventId), event_type(event_type), question(question), answer(answer), item(item){
    event_item = true;
}

Event::Event(int eventId, std::string event_type, std::string question, std::string answer, int effect):
        eventId(eventId), event_type(event_type), question(question), answer(answer), effect(effect) {
    event_effect = true;
}

bool Event::isEvent_item() const {
    return event_item;
}

void Event::setEvent_item(bool event_item) {
    Event::event_item = event_item;
}

const std::string &Event::getItem() const {
    return item;
}

void Event::setItem(const std::string &item) {
    Event::item = item;
}

bool Event::isEffect() const {
    return event_effect;
}

void Event::setEvent_effect(bool event_effect) {
    Event::event_effect = event_effect;
}

int Event::getEffect() const {
    return effect;
}

void Event::setEffect(int effect) {
    Event::effect = effect;
}

void Event::setTeleport(bool teleportation){
    teleport = teleportation;
}

void Event::disableTeleport(){
    teleport = false;
}

Event::~Event() {

}

Event::Event(const Event &ev) {
    std::cout<<"COPYING AN OBJECT "<<std::endl;
    eventId = ev.eventId;
    event_type = ev.event_type;
}
