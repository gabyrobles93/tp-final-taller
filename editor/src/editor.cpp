#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "editor.h"
#include "yaml.h"
#include "map_game.h"
#include "yaml.h"
#include "inventory.h"
#include "inventory_editor.h"

Editor::Editor(YAML::Node map, std::string mn, std::string bgn) :
bg_name(bgn),
map_name(mn),
mapNode(YAML::Clone(map)),
staticNode(mapNode["static"]),
mapGame(mapNode),
editorWindow(staticNode),
camera(editorWindow.getScreenWidth(),
        editorWindow.getScreenHeight(),
        editorWindow.getBgWidth(),
        editorWindow.getBgHeight()),
renderer(editorWindow.getRenderer()),
editorInventory(renderer,
             mapNode["static"]["teams_amount"].as<int>(),
             mapNode["static"]["worms_health"].as<int>()) {
	this->teamsAmount = mapNode["static"]["teams_amount"].as<int>();
	this->wormsHealth = mapNode["static"]["worms_health"].as<int>();
    this->editorInventory.toggleOpen();
	this->mapGame.setRenderer(this->renderer);	
}

int Editor::start(void) {
    bool quit = false;
	SDL_Event e;
	while (!quit) {
		int camX = camera.getX(), camY = camera.getY();
		
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
				editorWindow.hide();
				validMap = mapGame.hasWorms();
				if (!validMap) {
                    QMessageBox msgBox;
                    msgBox.setWindowTitle("Mapa inválido.");
                    msgBox.setText("El mapa debe tener al menos un worm de cada team." "¿Desea continuar editando el mapa?");
                    msgBox.setStandardButtons(QMessageBox::Yes);
                    msgBox.addButton(QMessageBox::No);
                    msgBox.setDefaultButton(QMessageBox::Yes);
                    if(msgBox.exec() == QMessageBox::Yes) {
                        editorWindow.show();
						quit = false;
                    }
				}
			}

			if (e.type == SDL_KEYDOWN) {
				
					if (e.key.keysym.sym == SDLK_z && (e.key.keysym.mod & KMOD_CTRL)) {
						mapGame.setPreviousState(editorInventory);
					}
					
					if (e.key.keysym.sym == SDLK_y && (e.key.keysym.mod & KMOD_CTRL)) {
						mapGame.setNextState(editorInventory);
					}
				
			}

			editorInventory.handleEvent(renderer, e, mapGame, camX, camY);
		}

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);

		camera.updateCameraPosition();

		editorWindow.render(camera);

		mapGame.render(renderer, camX, camY);
		
		editorInventory.renderSelectedInMouse(renderer);

		editorWindow.renderWater(camera);

		editorInventory.render(renderer);
		
		SDL_RenderPresent(renderer);
		SDL_Delay(50); // Para no usar al mango el CPU
	}

	if (validMap) {
		QMessageBox msgBox;
		msgBox.setWindowTitle("Fin de edición");
		msgBox.setText("¿Desea guardar el mapa?");
		msgBox.setStandardButtons(QMessageBox::Yes);
		msgBox.addButton(QMessageBox::No);
		msgBox.setDefaultButton(QMessageBox::Yes);
		if(msgBox.exec() == QMessageBox::Yes) {
			mapGame.saveAs(this->map_name, this->bg_name);
			return 0;
		}
	}

	return -1;
}
