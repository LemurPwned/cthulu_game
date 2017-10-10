//
// Created by lemurpwned on 09/10/17.
//

#include "Event.h"

Event::Event(int eventId, std::string event_type, std::string question, std::string answer):
                eventId(eventId), event_type(event_type), question(question), answer(answer){}

Event::Event(int eventId, std::string event_type, std::string question, std::string answer, std::string item):
        eventId(eventId), event_type(event_type), question(question), answer(answer), item(item){
    event_item = true;
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
