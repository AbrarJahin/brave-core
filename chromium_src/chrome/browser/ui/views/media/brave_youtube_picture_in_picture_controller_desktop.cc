// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/media/brave_youtube_picture_in_picture_controller_desktop.h"

#include "base/logging.h"
#include "chrome/browser/ui/views/media/youtube_picture_in_picture_controller_delegate.h"

BraveYouTubePictureInPictureControllerDesktop::
    BraveYouTubePictureInPictureControllerDesktop(
        YoutubePictureInPictureControllerDelegate* delegate)
    : YoutubePictureInPictureController(delegate) {}

BraveYouTubePictureInPictureControllerDesktop::
    ~BraveYouTubePictureInPictureControllerDesktop() = default;

void BraveYouTubePictureInPictureControllerDesktop::OnSessionRequested(
    int tab_id,
    content::WebContents* web_contents) {
  if (is_transitioning_)
    return;

  // If there's an active session, dismiss it first
  if (is_active_) {
    DismissSession();
  }

  tab_id_ = tab_id;
  is_active_ = true;
  is_transitioning_ = false;

  // For desktop platforms, we would implement platform-specific PiP logic here
  // This could involve:
  // 1. Creating a window for the PiP mode
  // 2. Setting up appropriate shortcuts/keyboard bindings
  // 3. Managing the PiP session lifecycle
  
  LOG(INFO) << "Starting YouTube Picture-in-Picture session for tab " << tab_id;
}

void BraveYouTubePictureInPictureControllerDesktop::ResumeSession() {
  if (is_active_)
    return;

  is_transitioning_ = true;
  is_active_ = true;
  is_transitioning_ = false;

  LOG(INFO) << "Resuming YouTube Picture-in-Picture session for tab " << tab_id_;
}

void BraveYouTubePictureInPictureControllerDesktop::DismissSession() {
  if (!is_active_ || is_transitioning_)
    return;

  is_transitioning_ = true;
  is_active_ = false;
  is_transitioning_ = false;

  LOG(INFO) << "Dismissing YouTube Picture-in-Picture session for tab " << tab_id_;
}

bool BraveYouTubePictureInPictureControllerDesktop::IsActive() const {
  return is_active_;
}

bool BraveYouTubePictureInPictureControllerDesktop::IsTransitioning() const {
  return is_transitioning_;
}

int BraveYouTubePictureInPictureControllerDesktop::GetTabId() const {
  return tab_id_;
}