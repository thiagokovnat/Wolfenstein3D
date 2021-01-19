#include "../../../includes/Model/Player/Player.h"

#include <math.h>

#include <functional>
#include <iostream>
#include <tuple>

#include "../../../includes/Model/Item/Weapon/Knife.h"
#include "../../../includes/Model/Item/Weapon/Shootable/Pistol.h"
#include "../../../includes/Model/Item/Weapon/Weapon.h"

Player::Player(YAMLConfigReader yamlConfigReader, Map& map,
               unsigned int playerID)
    : health(yamlConfigReader.getMaxHealth()),
      MAX_HEALTH(yamlConfigReader.getMaxHealth()),
      lifeRemaining(yamlConfigReader.getMaxReviveTimes()),
      ammo(yamlConfigReader.getBulletAmountAtStart()),
      MAX_AMMO(yamlConfigReader.getMaxAmountOfBullets()),
      BULLET_DROP_WHEN_DIES(
          yamlConfigReader.getBulletAmountDropWhenPlayerDies()),
      AMMO_PICK_UP(yamlConfigReader.getBulletAmountWhenPickUpAmmo()),
      key(false),
      score(0),
      x(3.0),
      y(3.0),
      dirX(-1),
      dirY(0),
      rotSpeed(0.0),
      moveSpeed(0.0),
      hasToBeNotified(false),
      map(map) {
  this->playerID = playerID;
  map.addPlayer(6, 4, this);
  weapons.push_back(
      weaponFactory.getWeapon(1, Map::getAndIncreaseByOneNextUniqueItemId()));
  weapons.push_back(
      weaponFactory.getWeapon(2, Map::getAndIncreaseByOneNextUniqueItemId()));
  this->currentWeapon = weapons.at(1);
}

Player::Player(YAMLConfigReader yamlConfigReader)
    : health(yamlConfigReader.getMaxHealth()),
      MAX_HEALTH(yamlConfigReader.getMaxHealth()),
      lifeRemaining(yamlConfigReader.getMaxReviveTimes()),
      ammo(yamlConfigReader.getBulletAmountAtStart()),
      MAX_AMMO(yamlConfigReader.getMaxAmountOfBullets()),
      BULLET_DROP_WHEN_DIES(
          yamlConfigReader.getBulletAmountDropWhenPlayerDies()),
      AMMO_PICK_UP(yamlConfigReader.getBulletAmountWhenPickUpAmmo()),
      key(false),
      score(0),
      x(6.0),
      y(4.0),
      dirX(-1),
      dirY(0),
      rotSpeed(0.0),
      moveSpeed(0.0),
      hasToBeNotified(false),
      map(map) {
  weapons.push_back(
      weaponFactory.getWeapon(1, Map::getAndIncreaseByOneNextUniqueItemId()));
  weapons.push_back(
      weaponFactory.getWeapon(2, Map::getAndIncreaseByOneNextUniqueItemId()));
  this->currentWeapon = weapons.at(1);
}

bool Player::hasGunWithId(int uniqueId) {
  std::vector<Weapon*>::iterator it = this->weapons.begin();

  for (; it != this->weapons.end(); ++it) {
    if ((*it)->getID() == uniqueId) return true;
  }

  return false;
}

void Player::addWeapon(Weapon* weapon) { this->weapons.push_back(weapon); }

bool Player::collidesWith(double x, double y) {
  return fabs(this->x - x) < 5 && fabs(this->y - y) < 5;
}

void Player::respawn(WaitingQueue<Notification*>& notis) {
  double x, y;

  std::tie(x, y) = map.handleRespawn();
  map.moveTo(this->x, this->y, x, y, this, notis);

  this->x = x;
  this->y = y;
}

int Player::handleDeath(WaitingQueue<Notification*>& notis) {
  if (this->lifeRemaining == 0) {
    this->health = 0;
    return -1;
  }

  map.addAmmoDropAt(this->y + 1, this->x + 1);
  this->respawn(notis);
  if (this->key) {
    this->key = false;
    map.addKeyDropAt(this->y + 1, this->x + 1);
  }

  this->lifeRemaining -= 1;
  this->health = this->MAX_HEALTH;  // Deberia restaurar la vida al maximo.

  if (this->ammo < this->BULLET_DROP_WHEN_DIES)
    this->ammo = 0;
  else
    this->ammo -= this->BULLET_DROP_WHEN_DIES;

  return 0;  // Devuelvo valor indicando que mi vida quedo en 0.
}

double Player::calculateDistanceTo(Player* p) {
  return sqrt(pow(this->x - p->getX(), 2) + pow(this->y - p->getY(), 2));
}

bool Player::hasToBeUpdated() { return this->hasToBeNotified; }

int Player::takeDamage(unsigned int damage,
                       WaitingQueue<Notification*>& notis) {
  this->hasToBeNotified = true;

  if (damage >= this->health) {
    return handleDeath(notis);
  }

  this->health -= damage;
  return this->health;
}

void Player::fillPlayerData(PlayerData& data) {
  data.posX = this->x;
  data.posY = this->y;
  data.dirX = this->dirX;
  data.dirY = this->dirY;
  data.rotSpeed = this->rotSpeed;
  data.lives = lifeRemaining;
  data.health = health;
  data.weaponID = this->currentWeapon->getID();
  data.bullets = this->ammo;

  this->hasToBeNotified = false;
  return;
}

void Player::moveTo(double x, double y) {
  this->x = x;
  this->y = y;
}

void Player::update(float timeElapsed, WaitingQueue<Notification*>& notis) {
  if (moveSpeed == 0.0 && rotSpeed == 0.0) return;

  double newX = x + dirX * (moveSpeed * (timeElapsed));
  double newY = y + dirY * (moveSpeed * (timeElapsed));

  if (map.moveTo(x, y, newX, newY, this, notis)) {
    x = newX;
    y = newY;
  }

  double oldDirX = dirX;

  dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
  dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);

  this->hasToBeNotified = true;
}

double Player::getX() { return this->x; }

double Player::getY() { return this->y; }

double Player::getDirX() { return this->dirX; }

double Player::getDirY() { return this->dirY; }

int Player::attack() {
  // Deberia pedirle a su arma que ataque, devolviendo el daño que hizo.
  // Luego le pregunto al arma cuantas balas tiene, si no tiene mas disponible,
  // cambio a cuchillo. Setearia Notificable a true salvo que tenga cuchillo.

  int ammo = this->ammo;
  int damageDealt = this->currentWeapon->attack(ammo);
  this->ammo = ammo;

  if (this->ammo <= 0) {
    this->currentWeapon = this->weapons.at(0);
  }

  this->hasToBeNotified = true;
  return damageDealt;
}

int Player::getRange() { return this->currentWeapon->getRange(); }

unsigned int Player::ID() { return this->playerID; }

void Player::updateMoveSpeed(double moveSpeed) { this->moveSpeed += moveSpeed; }

void Player::updateRotationSpeed(double rotSpeed) {
  this->rotSpeed += rotSpeed;
}

void Player::equipWeapon(int weaponPos) {
  if ((weaponPos >= this->weapons.size()) || (this->ammo <= 0)) return;

  this->currentWeapon = this->weapons.at(weaponPos);
  this->hasToBeNotified = true;
}

void Player::pickupKey() { this->key = true; }

bool Player::hasKey() { return key; }

bool Player::hasMaxAmmo() { return ammo >= this->MAX_AMMO; }

void Player::pickUpAmmo() {
  if (this->ammo == 0) this->currentWeapon = this->weapons.at(1);

  ammo += this->AMMO_PICK_UP;
  if (ammo > this->MAX_AMMO) ammo = this->MAX_AMMO;
  this->hasToBeNotified = true;
}

int Player::getHealth() { return this->health; }

bool Player::hasFullHealth() { return this->health == this->MAX_HEALTH; }

void Player::addHealth(int health) {
  this->health += health;
  if (this->health > MAX_HEALTH) this->health = this->MAX_HEALTH;
  this->hasToBeNotified = true;
}

void Player::addPoints(int points) { this->score += points; }

int Player::getScore() { return this->score; }

Player::~Player() {
  std::vector<Weapon*>::iterator it = this->weapons.begin();

  for (; it != this->weapons.end(); ++it) {
    delete (*it);
  }
}
