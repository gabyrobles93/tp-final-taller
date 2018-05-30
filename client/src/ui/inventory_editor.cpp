#include "inventory_editor.h"

View::EditorInventory::EditorInventory(SDL_Renderer * r, size_t amountTeams, int healthConfig) :
  amountTeams(amountTeams) {
  
  // Short girder
  ItemIcon * icon = new ItemIcon;
  icon->texture.loadFromFile(PATH_ICON_SHORT_GIRDER, r);
  icon->selected = true;
  icon->supplies = AMOUNT_WORMS_PER_TEAM;
  icon->itemName = WEAPON_NAME_SHORT_GIRDER;
  this->items.push_back(icon);

  icon = new ItemIcon;
  icon->texture.loadFromFile(PATH_ICON_LONG_GIRDER, r);
  icon->selected = false;
  icon->supplies = AMOUNT_WORMS_PER_TEAM;
  icon->itemName = WEAPON_NAME_LONG_GIRDER;
  this->items.push_back(icon);

  // Worms teams
  for (size_t i = 1 ; i <= amountTeams ; i++) {
    icon = new ItemIcon;
    icon->texture.loadFromFile(PATH_PLAIN_WORM, r);
    icon->selected = false;
    icon->supplies = AMOUNT_WORMS_PER_TEAM;
    icon->itemName = std::to_string(i); // Team ID
    this->items.push_back(icon);
  }

  this->open = false;
  this->girdersDegrees = ZERO_DEGREES;
  this->wormsHealth = healthConfig;
}

View::EditorInventory::~EditorInventory() {
  for (size_t i = 0 ; i < this->items.size() ; i++) {
    delete this->items[i];
  }
}

void View::EditorInventory::render(SDL_Renderer * r, int x, int y) {
  if (this->open) {
    SDL_Color colors[] = {
      {0, 0, 0, 0},
      {255, 0, 0, 0},
      {0, 255, 0, 0},
      {0, 0, 255, 0}
    };

    std::vector<ItemIcon *>::iterator it = this->items.begin();
    int iconWidth = this->items.back()->texture.getWidth();
    int iconHeight = this->items.back()->texture.getHeight();

    // Render short girder
    (*it)->texture.render(r, x, y, iconWidth, iconHeight);
    if ((*it)->selected) {
      this->renderItemSelected(r, x, y, iconWidth, iconHeight);
    }
    it++;

    (*it)->texture.render(r, x, y + iconHeight, iconWidth, iconHeight);
    if ((*it)->selected) {
      this->renderItemSelected(r, x, y + iconHeight, iconWidth, iconHeight);
    }
    it++;

    for (int i = 2 ; it != this->items.end() ; it++, i++) {
      size_t teamId = std::stoi((*it)->itemName);

      // Black rect
      SDL_Rect blackRect = {
        x,
        y + i * iconHeight,
        iconWidth,
        iconHeight
      };
      SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xFF);        
      SDL_RenderFillRect(r, &blackRect);

      // Color rect
      SDL_Rect colorRect = {
        x + PADDING,
        y + i * iconHeight + PADDING,
        iconWidth - 2 * PADDING,
        iconHeight - 2 * PADDING
      };
      SDL_SetRenderDrawColor(r, colors[teamId].r, colors[teamId].g, colors[teamId].b, 0xFF);
      SDL_RenderFillRect(r, &colorRect);

      // Worm icon
      (*it)->texture.render(r, x, y + i * iconHeight);

      if ((*it)->selected) {
        this->renderItemSelected(r, x, y + i * iconHeight, iconWidth, iconHeight);
      }   
    }
  }
}

void View::EditorInventory::renderItemSelected(SDL_Renderer * renderer, int x, int y, int width, int height) {
  SDL_Rect outlineRect = { 
    x,
    y,
    width, 
    height
  };

  // Color blanco
  SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); 
  // Dibujamos rectangulo blanco en item seleccionado       
  SDL_RenderDrawRect(renderer, &outlineRect);
}

void View::EditorInventory::renderSelectedInMouse(SDL_Renderer * r) {
  int mouseX, mouseY;
  SDL_GetMouseState(&mouseX, &mouseY);

  for (size_t i = 0; i < this->items.size() ; i++) {
    if (this->items.at(i)->selected) {
      // Short girder
      if (i == POS_GIRDER_SHORT) {
        View::GirderShort g(r, this->girdersDegrees);
        g.setX(0);
        g.setY(0);
        g.render(r, -mouseX, -mouseY);
      } else if (i == POS_GIRDER_LONG) {
        View::GirderLong g(r, this->girdersDegrees);
        g.setX(0);
        g.setY(0);
        g.render(r, -mouseX, -mouseY);
      } else {
        if (this->items.at(i)->supplies) {
          std::string name("Worm " + std::to_string(AMOUNT_WORMS_PER_TEAM - this->items.at(i)->supplies + 1));
          View::Worm w(r, name, std::stoi(this->items.at(i)->itemName), this->wormsHealth);
          w.setX(0);
          w.setY(0);
          w.render(r, -mouseX, -mouseY);
        }        
      }
    }
  }
}

// Evite mirar y entender este metodo
// puede causar migraña
void View::EditorInventory::handleEvent(
  SDL_Renderer * r,
  SDL_Event & e,
  View::MapGame & map, 
  int camX,
  int camY
  ) {
  
  this->Inventory::handleEvent(e);

  // Rotamos el dibujo de las vigas
  if (e.type == SDL_MOUSEWHEEL) {
    if (e.wheel.y > 0) {
      View::GirderShort g(r, this->girdersDegrees);
      g.rotateClockwise();
      this->girdersDegrees = g.getCurrentDegrees();
    }
    if (e.wheel.y < 0) {
      View::GirderShort g(r, this->girdersDegrees);
      g.rotateCounterClockwise();
      this->girdersDegrees = g.getCurrentDegrees();
    }
  }

  // Click izquierdo actualiza la coleccion de objetos estaticos
  if (e.type == SDL_MOUSEBUTTONDOWN) {
    if (e.button.button == SDL_BUTTON_LEFT) {
      int mouseX, mouseY;
      SDL_GetMouseState(&mouseX, &mouseY);

      size_t index = this->getIndexSelected();
      
      if (index == POS_GIRDER_SHORT) {
        map.addShortGirder(this->girdersDegrees, camX + mouseX, camY + mouseY);		
      } else if (index == POS_GIRDER_LONG) {
        map.addLongGirder(this->girdersDegrees, camX + mouseX, camY + mouseY);
      } else {
        if (this->items.at(index)->supplies) {
          int teamId = std::stoi(this->items.at(index)->itemName);
          std::string name("Worm " + std::to_string(AMOUNT_WORMS_PER_TEAM - this->items.at(index)->supplies + 1));
          map.addWormInTeam(teamId, name, this->wormsHealth, camX + mouseX, camY + mouseY);
          this->items.at(index)->supplies--;
        }
        
      }
    }
  }
}

int View::EditorInventory::getIndexSelected(void) {
  for (size_t i = 0 ; i < this->items.size() ; i++) {
    if (this->items.at(i)->selected) {
      return i;
    }
  }
  return -1;
}

void View::EditorInventory::updateWormsTeamSupplies(const YAML::Node & wormsNode) {
  std::map<int, size_t> teams;
  for (size_t i = 1 ; i <= this->amountTeams ; i++) {
    teams[i] = 0;
  }

  YAML::const_iterator it = wormsNode.begin();
  for (; it != wormsNode.end() ; it++) {
    const YAML::Node & eachWorm = *it;
    teams[eachWorm["team"].as<int>()]++;
  }

  for (size_t i = 0 ; i < this->amountTeams ; i++) {
    ItemIcon * wormTeam = this->items[i + POS_FIRST_WORMS_TEAM];
    wormTeam->supplies = AMOUNT_WORMS_PER_TEAM - teams[std::stoi(wormTeam->itemName)];
  }
}