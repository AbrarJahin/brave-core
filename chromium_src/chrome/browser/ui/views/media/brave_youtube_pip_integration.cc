// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/media/brave_youtube_pip_integration.h"

#include "base/logging.h"
#include "chrome/browser/ui/views/media/brave_youtube_picture_in_picture_controller_desktop.h"
#include "chrome/browser/ui/views/media/brave_youtube_pip_shortcut_manager.h"

BraveYouTubePiPIntegration::BraveYouTubePiPIntegration() = default;

BraveYouTubePiPIntegration::~BraveYouTubePiPIntegration() = default;

void BraveYouTubePiPIntegration::Initialize() {
  LOG(INFO) << "Initializing Brave YouTube PiP integration";

  // Create the controller
  controller_ = std::make_unique<BraveYouTubePictureInPictureControllerDesktop>(nullptr);
  
  // Initialize shortcut manager
  shortcut_manager_ = std::make_unique<BraveYouTubePiPShortcutManager>();
  shortcut_manager_->Initialize();
  
  LOG(INFO) << "Brave YouTube PiP integration initialized";
}

void BraveYouTubePiPIntegration::RegisterDesktopShortcuts() {
  LOG(INFO) << "Registering desktop shortcuts for YouTube PiP";
  
  // This would be called during browser initialization
  if (shortcut_manager_) {
    shortcut_manager_->Initialize();
  }
}

void BraveYouTubePiPIntegration::HandleShortcut(
    const std::string& shortcut_id) {
  LOG(INFO) << "Handling shortcut: " << shortcut_id;
  
  if (shortcut_manager_) {
    shortcut_manager_->HandleShortcut(shortcut_id);
  }
}

bool BraveYouTubePiPIntegration::IsPiPActive() const {
  return controller_ ? controller_->IsActive() : false;
}