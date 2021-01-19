#include "wall_tile_factory.h"

#include <string>
#include <utility>

#include "tile.h"

wall_tile_factory::wall_tile_factory() {}

tile* wall_tile_factory::get_tile(std::vector<int>& coordinates) {
  int col = coordinates[0];
  int row = coordinates[1];
  QString path;
  int tipo;
  if (col == 1 && row == 1) {
    path = "./elementos_mapa/paredes/PARED_PIEDRA.png";
    tipo = 302;
  } else if (col == 1 && row == 2) {
    path = "./elementos_mapa/paredes/PARED_MADERA_CLARA.png";
    tipo = 304;
  } else if (col == 1 && row == 3) {
    path = "./elementos_mapa/paredes/PARED_AZUL_OSCURA_+.png";
    tipo = 301;
  } else if (col == 1 && row == 4) {
    path = "./elementos_mapa/paredes/PARED_MIX_PIEDRA_CLARA.png";
    tipo = 303;
  } else if (col == 1 && row == 5) {
    path = "./elementos_mapa/paredes/PARED_METAL_CLARA.png";
    tipo = 5;
  } else if (col == 1 && row == 6) {
    path = "./elementos_mapa/paredes/PARED_AZUL_CLARA.png";
    tipo = 6;
  } else if (col == 1 && row == 7) {
    path = "./elementos_mapa/paredes/PARED_TIERRA_CLARA.png";
    tipo = 7;
  } else if (col == 1 && row == 8) {
    path =
        "./elementos_mapa/paredes/"
        "PARED_PIEDRA_LADRILLO_CLARA.png";
    tipo = 8;
  } else if (col == 2 && row == 1) {
    path = "./elementos_mapa/paredes/PARED_PIEDRA_OSCURA.png";
    tipo = 9;
  } else if (col == 2 && row == 2) {
    path = "./elementos_mapa/paredes/PARED_MADERA_OSCURA.png";
    tipo = 10;
  } else if (col == 2 && row == 3) {
    path = "./elementos_mapa/paredes/PARED_AZUL_MUY_OSCURA.png";
    tipo = 11;
  } else if (col == 2 && row == 4) {
    path = "./elementos_mapa/paredes/PARED_MIX_PIEDRA_OSCURA.png";
    tipo = 12;
  } else if (col == 2 && row == 5) {
    path = "./elementos_mapa/paredes/PARED_METAL_OSCURA.png";
    tipo = 13;
  } else if (col == 2 && row == 6) {
    path = "./elementos_mapa/paredes/PARED_AZUL_OSCURA.png";
    tipo = 14;
  } else if (col == 2 && row == 7) {
    path = "./elementos_mapa/paredes/PARED_TIERRA_OSCURA.png";
    tipo = 15;
  } else {
    path =
        "./elementos_mapa/paredes/"
        "PARED_PIEDRA_LADRILLO_OSCURA.png";
    tipo = 16;
  }
  tile* tile = new class tile(path, tipo, true);
  return tile;
}