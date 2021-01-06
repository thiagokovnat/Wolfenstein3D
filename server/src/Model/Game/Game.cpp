#include "../../../includes/Model/Game/Game.h"

#include <iostream>
#include <string>
#include <time.h>

#include "../../../includes/Control/Notification/PlayerPackageUpdate.h"
#include "../../../includes/Model/Player/Player.h"

Game::Game(std::string mapFile, std::string configFile) {
  std::string mapFileName = "./common/src/YAML/map.yaml";
  auto t1 = std::chrono::steady_clock::now();
  MapLoader mapLoader(mapFileName);
  map = mapLoader.loadMap();
  auto t2 = std::chrono::steady_clock::now();
  std::chrono::duration<float, std::milli> diff;
  diff = t2 - t1;
  std::cout<<"[GAME] Map loaded, required time: "<<ceil(diff.count()) / 1000<<"s."<<std::endl;
}

void Game::addPlayer(int playerID) {
  unsigned int health = 100;  // Deberian obtenerse del file de config.
  unsigned int lifes = 2;

  Player* newPlayer = new Player(health, lifes, *map, playerID);

  this->players[playerID] = newPlayer;
}

void Game::playerShoot(int playerID) {
  Player* attacker = this->players[playerID];

  Player* receiver = nullptr;
  int receiverHealth = 0;

  if ((receiver = map->traceAttackFrom(attacker)) != nullptr) {
    receiverHealth = receiver->takeDamage(attacker->attack(), *(this->map));

    // if(receiverHealth == 0) // El jugador murio y debe respawnear
    //  this->map.handleRespawn(receiver);
  }
}

void Game::updatePositions() {
  std::map<int, Player*>::iterator it = this->players.begin();

  for (; it != this->players.end(); ++it) {
    it->second->update(*(this->map));
  }
}

int Game::moveDoor(int playerID) {
  // return this->map.moveDoor(this->players[playerID]);
  return 0;
}

void Game::sendUpdateMessages(WaitingQueue<Notification*>& notis) {
  std::map<int, Player*>::iterator it = this->players.begin();

  for (; it != this->players.end(); ++it) {
    PlayerData data;
    if (it->second->hasToBeUpdated()) {
      it->second->fillPlayerData(data);
      PlayerPackageUpdate* noti = new PlayerPackageUpdate(it->first, data);
      notis.push(noti);
    }
  }
}

void Game::removePlayer(int playerID) {
  std::map<int, Player*>::iterator it = this->players.find(playerID);

  if (it != this->players.end()) {
    delete it->second;
    this->players.erase(it);
  }
}

void Game::updatePlayerMoveSpeed(int playerID, double moveSpeed) {
  this->players[playerID]->updateMoveSpeed(moveSpeed);
}

void Game::updatePlayerRotationSpeed(int playerID, double rotSpeed) {
  this->players[playerID]->updateRotationSpeed(rotSpeed);
}
void Game::start() {
  // Deberia controlar la logica de iniciar el juego -> mandar la notificacion a
  // los jugadores
}

void Game::end() {
  // Lo mismo pero para terminarlo.
}

Game::~Game() {
  std::map<int, Player*>::iterator it = this->players.begin();

  for (; it != this->players.end(); ++it) {
    delete it->second;
  }
}
