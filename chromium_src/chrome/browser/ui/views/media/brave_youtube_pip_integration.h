// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_INTEGRATION_H_
#define BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_INTEGRATION_H_

#include <memory>
#include <string>

class BraveYouTubePictureInPictureControllerDesktop;
class BraveYouTubePiPShortcutManager;

// Main integration class for YouTube Picture-in-Picture functionality on desktop
class BraveYouTubePiPIntegration {
 public:
  BraveYouTubePiPIntegration();
  ~BraveYouTubePiPIntegration();

  // Initialize the YouTube PiP functionality
  void Initialize();

  // Register desktop shortcuts and menu items
  void RegisterDesktopShortcuts();

  // Handle a shortcut event
  void HandleShortcut(const std::string& shortcut_id);

  // Check if PiP is currently active
  bool IsPiPActive() const;

 private:
  std::unique_ptr<BraveYouTubePictureInPictureControllerDesktop> controller_;
  std::unique_ptr<BraveYouTubePiPShortcutManager> shortcut_manager_;
};

#endif  // BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_INTEGRATION_H_