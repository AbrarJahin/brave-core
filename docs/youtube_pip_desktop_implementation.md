# YouTube Picture-in-Picture Implementation for Desktop Platforms

This document describes the implementation of YouTube Picture-in-Picture functionality for desktop platforms (Windows, Mac, and Linux) in Brave Browser.

## Overview

The YouTube Picture-in-Picture implementation consists of several components that work together to provide:
1. Platform-specific shortcut handling
2. Desktop menu integration
3. Session management
4. Cross-platform compatibility

## Components

### 1. Controller Implementation (`BraveYouTubePictureInPictureControllerDesktop`)

This class manages the YouTube PiP session lifecycle on desktop platforms.

```cpp
class BraveYouTubePictureInPictureControllerDesktop
    : public YoutubePictureInPictureController {
 public:
  explicit BraveYouTubePictureInPictureControllerDesktop(
      YoutubePictureInPictureControllerDelegate* delegate);
  ~BraveYouTubePictureInPictureControllerDesktop() override;

  // Methods for managing the PiP session
  void OnSessionRequested(int tab_id, content::WebContents* web_contents) override;
  void ResumeSession() override;
  void DismissSession() override;
  bool IsActive() const override;
  bool IsTransitioning() const override;
  int GetTabId() const override;
};
```

### 2. Shortcut Handlers

Platform-specific shortcut handlers for Windows, Mac, and Linux:

- `BraveYouTubePiPShortcutHandlerWin` - Windows implementation
- `BraveYouTubePiPShortcutHandlerMac` - macOS implementation  
- `BraveYouTubePiPShortcutHandlerLinux` - Linux implementation

### 3. Shortcut Manager

A platform-agnostic manager that handles the coordination of shortcuts across platforms:

```cpp
class BraveYouTubePiPShortcutManager {
 public:
  void Initialize();
  void HandleShortcut(const std::string& shortcut_id);
  bool IsSupported();
};
```

### 4. Integration Class

The main integration class that coordinates all components:

```cpp
class BraveYouTubePiPIntegration {
 public:
  void Initialize();
  void RegisterDesktopShortcuts();
  void HandleShortcut(const std::string& shortcut_id);
  bool IsPiPActive() const;
};
```

## Usage

To enable YouTube PiP functionality on desktop platforms, the following steps are required:

1. Initialize the integration during browser startup
2. Register desktop shortcuts and menu items
3. Handle shortcut events when triggered by users

## Platform-Specific Considerations

### Windows
- Uses Windows API for global hotkey registration
- Integrates with Windows system tray/menu
- Supports Ctrl+Shift+P keyboard shortcut

### macOS
- Uses NSUserDefault for global shortcut management
- Integrates with macOS menu bar
- Supports Cmd+Shift+P keyboard shortcut

### Linux
- Uses X11 or Wayland APIs for global shortcuts
- Integrates with desktop environment menus
- Supports Ctrl+Shift+P keyboard shortcut

## Implementation Notes

1. The implementation is designed to be cross-platform compatible
2. Each platform handles its own specific UI integration
3. The core session management logic is shared across platforms
4. Menu items are added to the browser's application menu
5. Global shortcuts are registered for quick access to PiP mode