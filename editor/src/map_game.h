#ifndef __MAP_GAME_H__
#define __MAP_GAME_H__

#include <SDL2/SDL.h>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include "girder_long.h"
#include "girder_short.h"
#include "inventory_editor.h"
#include "girder.h"
#include "worm.h"
#include "yaml.h"
#include "map_state.h"

namespace View {
  class EditorInventory;

  class MapGame {
    private:

      size_t statIndex;

      std::vector<MapState*> mapStates;
      unsigned int stateIndex;
      SDL_Renderer * renderer;
      YAML::Node & map;
      YAML::Node mapToSave;
      unsigned int index;
    
      // Obtiene el id del proximo
      // worm a agregar
      int getNextWormId(void);
      void addInventoryToTeams();
      void addLongGirdersToMap();
      void addShortGirdersToMap();
      void addWormsToMap();
      void addMaxWormsAmount(void);
      void updateIndex();
      
    public:
      // Constructor, recibe el nodo YAML
      // donde guardara toda la informacion del mapa
      MapGame(YAML::Node &);

      // Destructor, libera los items dibujados
      ~MapGame();

      // Dibuja lo que ya fue clickeado por el usuario
      void render(SDL_Renderer * r, int camX, int camY);

      // Agrega una short girder en la posicion del mapa indicada
      void addShortGirder(degrees_t, int, int);

      // Agrega una long girder en la posicion del mapa indicada
      void addLongGirder(degrees_t, int, int);

      // Agrega un worm
      void addWormInTeam(int, std::string &, int, int, int);

      // Establece el estado anterior (si hay)
      void setPreviousState(View::EditorInventory &);

      // Establece el estado posterior (si hay)
      void setNextState(View::EditorInventory &);

      // Imprime el estado actual
      void printCurrentState(void);

      // Guarda el mapa en la carpeta de mapas del servidor
      // bajo el nombre indicado
      void saveAs(std::string, std::string, std::string);

      bool hasWorms();

      void setRenderer(SDL_Renderer * renderer);
      void initializeStates();
      void createMapToSave();
      int amountWormsTeam(int);
  };
}

#endif
