#include "camera.h"
#include <iostream>

#define OFFSET_NEAR 25
#define MOVE_PER_FRAME 10
#define MAX_MANUAL_QUIET_MS 1500

View::Camera::Camera(int camW, int camH, int levelW, int levelH) :
  width(camW), height(camH), levelWidth(levelW), levelHeight(levelH) {
    // Inicializamos la camara centrada al nivel
    this->camera = {
      (this->levelWidth - this->width) / 2,
      (this->levelHeight - this->height) / 2,
      this->width,
      this->height
    };

    this->movingLeft = false;
    this->movingRight = false;
    this->movingUp = false;
    this->movingDown = false;
    this->mode = CAMERA_AUTOMATIC;
}

View::Camera::~Camera() {}

int View::Camera::getX(void) const {
  return this->camera.x;
}

int View::Camera::getY(void) const {
  return this->camera.y;
}

SDL_Rect View::Camera::getCamera(void) const {
  return this->camera;
}

void View::Camera::setX(int x) {
  if (x < 0) {
    this->camera.x = 0;
    return;
  }

  if (x > this->levelWidth - this->width) {
    this->camera.x = this->levelWidth - this->width;
    return;
  }

  this->camera.x = x;
}

void View::Camera::setY(int y) {
  if (y < 0) {
    this->camera.y = 0;
    return;
  }

  if (y > this->levelHeight - this->height) {
    this->camera.y = this->levelHeight - this->height;
    return;
  }
  
  this->camera.y = y;
}

void View::Camera::setXY(int x, int y) {
  this->setX(x);
  this->setY(y);
  return;
}

void View::Camera::focus(const Drawable & d) {
  if (this->mode == CAMERA_MANUAL) {
    if (this->timer.getTicks() > MAX_MANUAL_QUIET_MS) {
      this->mode = CAMERA_AUTOMATIC;
      this->timer.stop();
    }
  }
  
  if (this->mode == CAMERA_AUTOMATIC) {
    this->setX(d.getX() - this->width / 2);
    this->setY(d.getY() - this->height / 2);
  }
}

void View::Camera::setManualMode(void) {
  this->mode = CAMERA_MANUAL;
  this->restartTimer();
}

void View::Camera::restartTimer(void) {
  this->timer.stop();
  this->timer.start();
}

void View::Camera::handleEvent(SDL_Event & e) {
  if (e.type == SDL_KEYDOWN) {
    if (e.key.keysym.sym == SDLK_LEFT) {
      this->setX(this->camera.x - 25);
      this->setManualMode();
    }
    if (e.key.keysym.sym == SDLK_RIGHT) {
      this->setX(this->camera.x + 25);
      this->setManualMode();
    }
    if (e.key.keysym.sym == SDLK_UP) {
      this->setY(this->camera.y - 25);
      this->setManualMode();
    }
    if (e.key.keysym.sym == SDLK_DOWN) {
      this->setY(this->camera.y + 25);
      this->setManualMode();
    }
  }
}

void View::Camera::updateCameraPosition(void) {
  int mouseX, mouseY;
  SDL_GetMouseState(&mouseX, &mouseY);

  if (
    mouseX > 0 + OFFSET_NEAR &&
    mouseX < this->width - OFFSET_NEAR &&
    mouseY > 0 + OFFSET_NEAR &&
    mouseY < this->height - OFFSET_NEAR
  ) {
    this->movingLeft = false;
    this->movingRight = false;
    this->movingUp = false;
    this->movingDown = false;
  } else {
    if (mouseX < 0 + OFFSET_NEAR || this->movingLeft) {
      this->setX(this->camera.x - MOVE_PER_FRAME);
      this->movingLeft = true;
      this->setManualMode();
    }
    if (mouseX > this->width - OFFSET_NEAR || this->movingRight) {
      this->setX(this->camera.x + MOVE_PER_FRAME);
      this->movingRight = true;
      this->setManualMode();
    }
    if (mouseY < 0 + OFFSET_NEAR || this->movingUp) {
      this->setY(this->camera.y - MOVE_PER_FRAME);
      this->movingUp = true;
      this->setManualMode();
    }
    if (mouseY > this->height -OFFSET_NEAR || this->movingDown) {
      this->setY(this->camera.y + MOVE_PER_FRAME);
      this->movingDown = true;
      this->setManualMode();
    }
    return;
  }
}