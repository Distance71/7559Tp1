#ifndef EVENT_HANDLER_H_
#define EVENT_HANDLER_H_

class EventHandler {

public:
    virtual int handleSignal(int signum) = 0;
    virtual ~EventHandler() {};
};

#endif
