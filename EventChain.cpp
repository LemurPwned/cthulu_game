//
// Created by lemurpwned on 09/10/17.
//

#include "EventChain.h"

std::vector<Event *> EventChain::getChain() {
    return eventchain;
}

void EventChain::pushChain(Event *ev) {
    eventchain.push_back(ev);
}

EventChain::EventChain(int eventChainId) : eventChainId(eventChainId) {}

EventChain::~EventChain() {
    delete &eventchain;
}
