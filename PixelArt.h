#pragma once

#include "MatrixOS.h"
#include "Application.h"

class PixelArt : public Application {
 public:
  inline static Application_Info info = {
      .name = "Pixel Art",
      .author = "ADG",
      .color = Color(0xFF0000),
      .version = 1,
      .visibility = true,
  };

  void Setup(const vector<string>& args) override;
  void Loop() override;
  void End() override;

  CreateSavedVar("PixelArt", number, uint8_t, 0);
  CreateSavedVar("PixelArt", activeColor, Color, Color(0xFFFFFF));
  CreateSavedVar("PixelArt", pickerShowing, bool, true);

  Color color_grid[10][8]; // Store pixel colors in a 2D grid

  static constexpr size_t NUM_PICKER_COLORS = 8;
  const Color pickerColors[NUM_PICKER_COLORS] = {
      Color(0xFF0000),  // Red
      Color(0xFFFF00),  // Yellow
      Color(0x00FF00),  // Green
      Color(0x00FFFF),  // Cyan
      Color(0x0000FF),  // Blue
      Color(0xFF00FF),  // Magenta
      Color(0xFFFFFF),  // White
      Color(0x000000)   // Black
  };
  void KeyEventHandler(uint16_t KeyID, KeyInfo* keyInfo);
  void ShowPicker();
  void HidePicker();
};
