#include <Arduino.h>

// https://www.buydisplay.com/download/ic/IT7259+User+Programming+Guide_V0.11.pdf

#define GID_Tap 0x20
#define GID_Double_Tap 0x23
#define GID_Tap_and_Slide 0x24
#define GID_Direction 0x26
#define GID_Clockwise 0x28
#define GID_2F_2D_Gestures 0x42

// for GID_Direction
#define DIRECTION_UP 0b000
#define DIRECTION_UP_RIGHT 0b001
#define DIRECTION_RIGHT 0b010
#define DIRECTION_LOWER_RIGHT 0b011
#define DIRECTION_DOWN 0b100
#define DIRECTION_LOWER_LEFT 0b101
#define DIRECTION_LEFT 0b110
#define DIRECTION_UPPER_LEFT 0b111

struct Pos {
  uint16_t x;
  uint16_t y;
  int16_t rot;
};

class IT7259 {
 private:
    uint8_t device_addr;
 public:
  void init();
  void reset(); //command 0x0c
  Pos get2DResolutions();
  void getGestureInformation();
  void setPowerMode(bool sleep);
};