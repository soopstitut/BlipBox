#include "KeyController.h"
#include "TouchController.h"
#include "globals.h"
#include <stdint.h>

#define GRID_COLS 10
#define GRID_ROWS 8

// x/y readings from four corners of P4 screen
// 808/218 br
// 806/784 tr
// 257/783 tl
// 256/212 bl

// x/y readings from four corners of V6 screen
// 808/210
// 802/774
// 258/783
// 251/210

// void KeyController::init(){
//   TouchController::init();
// }

bool KeyController::keyscan(){
  uint8_t oldRow = row;
  uint8_t oldCol = col;

  if(this->check() < config.sensitivity){
    this->update(); // sets row/col
    if(!pressed){
      // toggled from released to pressed
      pressed = true;
      return true;
    }else if(oldRow != row || oldCol != col){
      // different key pressed
      return true;
    }else{
      // same key, still pressed
      return false;
    }
  }else if(pressed){
    // toggled from pressed to released
    pressed = false;
    return true;
  }
  return false;
}

void KeyController::update(){
  row = this->readRow();
  if(row >= GRID_ROWS)
    row = GRID_ROWS - 1;
  col = this->readColumn();
  if(col >= GRID_COLS)
    col = GRID_COLS - 1;
}

uint8_t KeyController::readColumn(){
  return (this->getX() - config.touchscreen_x_min) * GRID_COLS / config.touchscreen_x_range;
}

uint8_t KeyController::readRow(){
  return (this->getY() - config.touchscreen_y_min) * GRID_ROWS / config.touchscreen_y_range;
}
