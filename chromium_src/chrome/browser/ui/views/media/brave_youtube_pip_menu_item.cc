// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/media/brave_youtube_pip_menu_item.h"

#include "base/logging.h"
#include "chrome/browser/ui/views/frame/browser_view.h"
#include "chrome/browser/ui/views/media/youtube_picture_in_picture_controller.h"
#include "chrome/browser/ui/views/media/brave_youtube_picture_in_picture_controller_desktop.h"

BraveYouTubePiPMenuItem::BraveYouTubePiPMenuItem(
    BraveYouTubePictureInPictureControllerDesktop* controller)
    : controller_(controller) {
  LOG(INFO) << "Creating Brave YouTube PiP menu item";
}

BraveYouTubePiPMenuItem::~BraveYouTubePiPMenuItem() = default;

void BraveYouTubePiPMenuItem::ExecuteCommand(int command_id, int event_flags) {
  LOG(INFO) << "Executing YouTube PiP menu command: " << command_id;
  
  // Handle the Picture-in-Picture toggle functionality
  if (command_id == IDC_TOGGLE_PICTURE_IN_PICTURE) {
    if (controller_ && controller_->IsActive()) {
      controller_->DismissSession();
    } else {
      // In a real implementation, we'd get the current tab and start PiP
      controller_->OnSessionRequested(0, nullptr);
    }
  }
}

bool BraveYouTubePiPMenuItem::IsEnabled() const {
  return true;
}

bool BraveYouTubePiPMenuItem::IsVisible() const {
  return true;
}