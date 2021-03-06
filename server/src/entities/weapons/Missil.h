#ifndef MISSIL_H
#define MISSIL_H

#include "Weapon.h"
#include "Box2D.h"
#include "types.h"
#include "ExplosionManager.h"
#include "Configuration.h"

#define MISSIL_WIDTH 0.2f
#define MISSIL_HEIGHT 0.7f

class Missil : public Weapon {
private:
    int blast_power;
    b2World& world;
    b2Body* body;
public:
    Missil(int id, b2World& world, float posX, float posY, weapon_t type);
    ~Missil();
    void explode();
    float getPosX();
    float getPosY();
    bool isMoving();
    entity_t getEntityType() {return MISSIL;}
    void update(int currentTime, int wind_force);
};

#endif