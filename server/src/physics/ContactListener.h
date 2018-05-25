#ifndef CONTACT_LISTENER_H
#define CONTACT_LISTENER_H

#include "Box2D.h"
#include "Entity.h"
#include "Worm.h"

class ContactListener : public b2ContactListener {
public: 
    ContactListener();
    virtual ~ContactListener();
    void BeginContact(b2Contact* contact);
    void EndContact(b2Contact* contact);
};

#endif