#ifndef GRENADE_H
#define GRENADE_H

#include "Box2D.h"
#include "Weapon.h"
#include "GrenadePhysic.h"
#include "types.h"
#include "Configuration.h"

class Grenade : public Weapon {
private:    
    int detonationTime;
    weapon_t type;
    int blast_radius;
    int blast_power;
    int shooting_angle;
    int power_factor;
    GrenadePhysic grenadePhysic;
    void explode(void);
public:
    Grenade(int id, b2World& world, float posX, float posY, float shooting_angle, int power_factor, int delay, int currentTime, weapon_t type);
    void shoot(void);
    void update(int currentTime);
    bool hasExploded(void);
    float getPosX();
    float getPosY();
};

#endif