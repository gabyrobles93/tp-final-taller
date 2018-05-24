#include <iostream>
#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include "window_game.h"
#include "girder_long.h"
#include "girder_short.h"
#include "worm.h"
#include "yaml.h"

#define MAX_ARG 4
#define POS_BG_PATH 1
#define POS_BG_DISP 2
#define POS_WATER_LEVEL 3

int validateArgs(int, char*[]);

int main(int argc, char * argv[]) {

	//validateArgs(argc, argv);
	std::string path;
	std::string display;
	int waterLevel;

	if (argc == 1) {
		std::cout << "Default configuration" << std::endl;
		path = "../../resources/graphics/lava_pattern.jpg";
		display = "expanded";
		waterLevel = 300;
	}
	
	YAML::Node map;
	map["static"]["background"]["file"] = path;
	map["static"]["background"]["display"] = display;
	map["static"]["water_level"] = waterLevel;
	/*map["static"]["short_girders"];
	map["static"]["long_girders"];
	map["dynamic"]["worms"];*/

	std::cout << "NODO DE MAPA VACIO CREADO:" << std::endl;
	std::cout << map << std::endl;
	/* Luego hay que cargarle secuencias de nodos.
	YAML::Node girderNode1;
	girderNode1["id"] = 1;
	girderNode1["x"] = 100;
	girderNode1["y"] = 200;
	YAML::Node girderNode2;
	girderNode2["id"] = 2;
	girderNode2["x"] = 10;
	girderNode2["y"] = 20;
	map["static"]["long_girders"].push_back(girderNode1);
	map["static"]["long_girders"].push_back(girderNode2);
	*/

	YAML::Node staticMap = map["static"];

	View::WindowGame editorWindow(staticMap);
	SDL_Renderer * renderer = editorWindow.getRenderer();
	View::Camera camera(
		editorWindow.getScreenWidth(), 
		editorWindow.getScreenHeight(),
		editorWindow.getBgWidth(), 
		editorWindow.getBgHeight()
	);

	int mouseX;
	int mouseY;

	View::GirderShort shortGirder(renderer);
	View::GirderLong longGirder(renderer);

	std::vector<View::GirderShort*> shortCollection;

	// Comienza el ciclo del juego para el cliente
	bool quit = false;	
	SDL_Event e;
	while (!quit) {
		SDL_GetMouseState(&mouseX, &mouseY);
		int camX = camera.getX(), camY = camera.getY();
		
		while (SDL_PollEvent(&e) != 0) {
			if (e.type == SDL_QUIT) {
				quit = true;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				if (SDL_BUTTON(SDL_BUTTON_LEFT)) {
					std::cout << "size: " << shortCollection.size() << std::endl;
					shortCollection.push_back(new View::GirderShort(renderer, shortGirder.getCurrentDegrees()));
					shortCollection.back()->setX(camX + mouseX);
					shortCollection.back()->setY(camY + mouseY);
				}
			}
			std::cout << "Cam handle\n";
			camera.handleEvent(e);
		}

		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderClear(renderer);

		editorWindow.render(camera);

		// Render de girder del mouse
		// Funciona asi, no entiendo por que
		shortGirder.setX(0);
		shortGirder.setY(0);
		shortGirder.render(renderer, -mouseX, -mouseY);

		for (size_t i = 0 ; i < shortCollection.size() ; i++) {
			shortCollection.at(i)->render(renderer, camX, camY);
		}

		editorWindow.renderWater(camera);
		
		SDL_RenderPresent(renderer);
		SDL_Delay(10);
	}
				


	return 0;
}

int validateArgs(int argc, char * argv[]) {
	int error = 0;
	if (argc != MAX_ARG) {
		error = 1;
	}

	if (error) {
		std::cerr << "La invocacion del programa es: " << std::endl;
		std::cerr << "./editor <path to background file> <background display mode> <water level>\n";
		std::cerr << "display mode disponibles: mosaic | centered | expanded \n";
	}
	return 0;
}

