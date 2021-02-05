#include "../../includes/Match/Match.h"

#include "../../includes/Server/ClientCommunication.h"

#define MAP_YAML_FILE_NAME "./common/src/YAML/map1.yaml"
#define CONFIG_YAML_FILE_NAME "./common/src/YAML/config.yaml"

Match::Match(int lobbyID)
    : ID(lobbyID),
      playerCount(0),
      running(true),
      game(MAP_YAML_FILE_NAME, CONFIG_YAML_FILE_NAME) {
  cont = true;
}

Match::Match() : game(MAP_YAML_FILE_NAME, CONFIG_YAML_FILE_NAME) {}

bool Match::hasID(int lobbyID) { return this->ID == lobbyID; }

void Match::forceShutdown() { this->running = false; }

ConnectionHandler* Match::addPlayerToMatch(ClientCommunication* player) {
  this->playerCount++;
  this->game.addPlayer(player->ID(), this->notis);

  this->players[player->ID()] = player;
  ConnectionHandler* playerHandler =
      new ConnectionHandler(player->getSock(), this->commands, player->ID());

  return playerHandler;
}

void Match::start() {
  engine = new Engine(commands, notis, cont, players, this->game);
  engine->start();
}

bool Match::hasEnded() { return !running; }

Match::~Match() {
  cont = false;
  engine->requestShutdown();
  engine->join();
  delete engine;
}
