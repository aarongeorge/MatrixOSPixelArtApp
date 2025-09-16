# MatrixOS Application Template

A template repository for creating C++ native applications for [MatrixOS](https://github.com/203System/MatrixOS)

## 🚀 Quick Start

1. **Fork this template** to create your own repository
2. Clone your new repository locally
3. Rename files and update the application name:
   - Rename `ExampleApp.h` → `YourAppName.h`
   - Rename `ExampleApp.cpp` → `YourAppName.cpp`
   - Update class name from `ExampleApp` to `YourAppName` in all files
   - Update `APP_NAME` in `CMakeLists.txt`
4. Add more cpp or h files and Implement your application logic.
5. Add your app to MatrixOS (see [Installation](#installation))

## 🛠️ Installation

### Method 1: Git URL (Recommended)

Add your application to `ApplicationList.txt` in your MatrixOS device configuration:

```bash
# Regular application
git:https://github.com/yourusername/your-app@main

# System-level application (with elevated privileges)
[System]git:https://github.com/yourusername/your-app@main
```

You can specify different git references:
- Branch: `@main`, `@develop`, `@feature-branch`
- Tag: `@v1.0.0`, `@release-2024`
- Commit: `@abc123d` (short or full hash)

### Method 2: Local Development

For local development, clone directly into the Applications folder:
```bash
cd MatrixOS/Applications/
git clone https://github.com/yourusername/your-app
```

Then add to `ApplicationList.txt`:
```
your-app
```

## 🎮 Application Structure

### Required Methods

Your application class must inherit from `MatrixOS::Application` and implement:

```cpp
class YourApp : public MatrixOS::Application {
public:
    void Start() override;  // Called once when app starts
    void Loop() override;   // Called repeatedly while app runs
    void End() override;    // Called once when app exits
};
```

### Application Metadata

Define your application info:

```cpp
Application_Info YourApp::info = {
    .name = "Your App Name",
    .author = "Your Name",
    .color = Color(0xFF00FF),
    .version = 1,
    .visibility = true,
};
```

**Field descriptions:**
- `name` - Display name shown in the app launcher
- `author` - Developer/author name for credits
- `color` - Color used to represent your app in the launcher
- `version` - Application version number
- `visibility` - Whether the app appears in the launcher (set to false for hidden/system apps. If set, it can only be jumped from other app calling MatrixOS::SYS::ExecuteApp api)

### Registering Your Application

In `CMakeLists.txt`, ensure you have:
```cmake
RegisterApplicationClass(YourApp)
```

## 🎨 Available APIs

### OS API

All MatrixOS APIs are accessible through `#include "MatrixOS.h"`.

For the complete API reference, see [OS/MatrixOS.h](https://github.com/203-Systems/MatrixOS/blob/main/OS/MatrixOS.h) in the MatrixOS kernel repository. This header file contains all user-facing APIs including:

- **LED Control** - Matrix LED manipulation
- **KeyPad** - Input handling
- **System** - Core system functions
- **File System** - SD card and file operations
- **USB** - USB device modes
- **MIDI** - MIDI input/output
- **HID** - Human Interface Device functions
- **UI Framework** - UI components and utilities

### UI Framework

MatrixOS provides a comprehensive UI framework for building interactive interfaces on the 8x8 grid. The UI system includes:

- **UI Base Class** - Container for UI elements with automatic rendering and input handling
- **UIComponents** - Pre-built components like buttons, selectors, menus, and more
- **UIUtility** - Helper functions for common UI patterns (number input, text display, etc.)

To use the UI framework, create UI objects within your application and call their `Start()` method to enter UI. See the UI components in [OS/UI/](https://github.com/203System/MatrixOS/tree/main/OS/UI) for available components.
- And many more...

For complete documentation of all available APIs, refer to [Project Matrix Wiki](matrix.203.io) and [OS/MatrixOS.h](https://github.com/203-Systems/MatrixOS/blob/main/OS/MatrixOS.h).

## 🔗 Resources

- [Project Matrix Wiki](matrix.203.io) 
- [MatrixOS Repository](https://github.com/203System/MatrixOS)
- [Discord Community](https://discord.gg/rRVCBHHPfw)

