#include "../../includes/Socket/SocketWrapper.h"

#define PRECISION 100000

void SocketWrapper::send(double value) {
  uint32_t firstMessage = (uint32_t)value;
  uint32_t secondMessage = (value - (long int) value) * PRECISION;
  this->socket.send(firstMessage, sizeof(uint32_t));
  this->socket.send(secondMessage, sizeof(uint32_t));
}

double SocketWrapper::receiveDouble() {
  uint32_t firstReceived;
  uint32_t secondReceived;
  this->socket.receive(&firstMessage, sizeof(uint32_t));
  this->socket.receive(&secondMessage, sizeof(uint32_t));
  double ans = firstMessage + (((double)secondMessage) / PRECISION);
  return ((double)ans);
}

void SocketWrapper:send(PlayerData& value) {
  this->send(value.dirX);
  this->send(value.dirY);
  this->send(value.posX);
  this->send(value.posY);
  this->send(value.rotSpeed);
  //this->socket.send(value.weaponID, sizeof(uint32_t));
  //this->socket.send(value.lives, sizeof(uint32_t));
  //this->socket.send(value.health, sizeof(uint32_t));
}

void SocketWrapper:receivePlayerData(PlayerData& value) {
  value.dirX = this->receiveDouble();
  value.dirY = this->receiveDouble();
  value.posX = this->receiveDouble();
  value.posY = this->receiveDouble();
  value.rotSpeed = this->receiveDouble();
  //this->socket.receive(&value.weaponID, sizeof(uint32_t));
  //this->socket.receive(&value.lives, sizeof(uint32_t));
  //this->socket.senreceived(&value.health, sizeof(uint32_t));
}
