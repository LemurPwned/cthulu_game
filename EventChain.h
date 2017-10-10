//
// Created by lemurpwned on 09/10/17.
//

#ifndef CTHULU_GAME_EVENTCHAIN_H
#define CTHULU_GAME_EVENTCHAIN_H

#include <vector>
#include "Event.h"

class EventChain{

private:
    int eventChainId;
    std::vector<Event*> eventchain;
public:
    EventChain() = default;

    explicit EventChain(int eventChainId) : eventChainId(eventChainId) {}

    void pushChain(Event *ev){
        eventchain.push_back(ev);
    }

    std::vector<Event*> getChain(){
        return eventchain;
    }
};
#endif //CTHULU_GAME_EVENTCHAIN_H
