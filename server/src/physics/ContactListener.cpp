#include "ContactListener.h"
#include <iostream>

ContactListener::ContactListener(){}
ContactListener::~ContactListener() {}


void ContactListener::BeginContact(b2Contact* contact) {

    void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
   
    if (bodyAUserData && bodyBUserData) {
        entity_t entityA_type = static_cast<Entity*>(bodyAUserData)->getEntityType(); 
        entity_t entityB_type = static_cast<Entity*>(bodyBUserData)->getEntityType();    

        //WORM FOOT CONTACT
        if (entityA_type == WORM && entityB_type == STRUCTURE) {
            float angle = static_cast<Girder*>(bodyBUserData)->getAngle();
            if (angle <= 0.8 && angle >= -0.8) {
                static_cast<Worm*>(bodyAUserData)->setAngle(angle);
                static_cast<Worm*>(bodyAUserData)->addFootContact();
            }
        }

        if (entityB_type == WORM && entityA_type == STRUCTURE) {
            float angle = static_cast<Girder*>(bodyAUserData)->getAngle();
            if (angle <= 0.8 && angle >= -0.8) {
                static_cast<Worm*>(bodyBUserData)->setAngle(angle);
                static_cast<Worm*>(bodyBUserData)->addFootContact();
            }
        }

        //WORM WATER CONTACT
        if (entityA_type == WORM && entityB_type == WATER) {
           static_cast<Worm*>(bodyAUserData)->kill();
        }

        if (entityB_type == WORM && entityA_type == WATER) {
           static_cast<Worm*>(bodyBUserData)->kill();
        }

        //WORM BAT CONTACT
        if (entityA_type == BAT && entityB_type == WORM) {
            static_cast<Bat*>(bodyAUserData)->atack(static_cast<Worm*>(bodyBUserData));
        }

        if (entityB_type == BAT && entityA_type == WORM) {
            static_cast<Bat*>(bodyBUserData)->atack(static_cast<Worm*>(bodyAUserData));
        }
    }
}

void ContactListener::EndContact(b2Contact* contact) {
    void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
    void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();

    if (bodyAUserData && bodyBUserData) {
        entity_t entityA_type = static_cast<Entity*>(bodyAUserData)->getEntityType(); 
        entity_t entityB_type = static_cast<Entity*>(bodyBUserData)->getEntityType();       

        //WORM FOOT CONTACT
        if (entityA_type == WORM && entityB_type == STRUCTURE) {
            static_cast<Worm*>(bodyAUserData)->deleteFootContact();
        }

        if (entityB_type == WORM && entityA_type == STRUCTURE) {
            static_cast<Worm*>(bodyBUserData)->deleteFootContact();
        }
    }
}