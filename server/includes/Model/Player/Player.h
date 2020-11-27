#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "../Item/StockableItem/StockableItem.h"
#include "../Item/StockableItem/Weapon/Weapon.h"

class Player {
 private:
  int x, y;
  unsigned int health, lifeRemaining;
  // Weapon* weapon;
  bool hasKey;

  int handleDeath();

 public:
  Player(unsigned int hp, unsigned int lifes);
  Player() {}
  int takeDamage(unsigned int damage);

  // Devuelve cuanto daño hace un ataque con su arma.
  // Si se queda sin balas, cambia de arma.
  int attack();

  void equipWeapon(Weapon* weapon);

  void pickupKey();

  int getHealth();
  void addHealth(int health);
};

#endif