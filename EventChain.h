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

    explicit EventChain(int eventChainId);

    void pushChain(Event *ev);

    std::vector<Event*> getChain();

    virtual ~EventChain();
};
#endif //CTHULU_GAME_EVENTCHAIN_H
