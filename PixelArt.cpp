#include "PixelArt.h"
#include "ui/UI.h"

// Run once at start
void PixelArt::Setup(const vector<string>& args) {
	MLOGI("PixelArt", "Pixel Art Started");
	ShowPicker();
}

// Run in a loop after Setup
void PixelArt::Loop() {
	struct KeyEvent keyEvent;
	while (MatrixOS::KEYPAD::Get(&keyEvent)) {
		KeyEventHandler(keyEvent.id, &keyEvent.info);
	}
}

void PixelArtApp::ShowPicker() {
	for (size_t i = 0; i < NUM_PICKER_COLORS; i++) {
        MatrixOS::LED::SetColor(Point(i, 0), pickerColors[i], 0);
    }
	pickerShowing = true;
}

void PixelArtApp::HidePicker() {
	for (size_t i = 0; i < NUM_PICKER_COLORS; i++) {
        MatrixOS::LED::SetColor(Point(i, 0), color_grid[i + 1][0], 0);
    }
	pickerShowing = false;
}

void PixelArtApp::KeyEventHandler(uint16_t keyID, KeyInfo* keyInfo) {
	Point xy = MatrixOS::KEYPAD::ID2XY(keyID);

	// Pad or Touch Strip
	if (xy) {

		if (keyInfo -> state == PRESSED) {

			// Touch Strip pressed so colour underglow
			if (xy.x == -1 || xy.x == 8) {
				color_grid[xy.x + 1][xy.y] = activeColor;
				MatrixOS::LED::SetColor(xy, activeColor, 0);
			}

			// Pad pressed
			else {
				// Colour picker pressed
				if (pickerShowing && xy.y == 0) {
					activeColor = pickerColors[xy.x];
				}
				else {
					color_grid[xy.x + 1][xy.y] = activeColor;
					MatrixOS::LED::SetColor(xy, activeColor, 0);
				}
			}
		}
	}

	// Not Pad or Touch Strip (Almost exclusively FUNCTION_KEY)
	else {
		if (keyID == FUNCTION_KEY) {
			if (keyInfo -> state == HOLD) {
				Exit();
			}
			else if (keyInfo -> state == RELEASED) {
				if (pickerShowing) { HidePicker(); }
				else { ShowPicker(); }
			}
		}
	}
}

// Run when App exits
void PixelArt::End() {
	MLOGI("PixelArt", "Pixel Art Exited");
}
