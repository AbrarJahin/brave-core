// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PICTURE_IN_PICTURE_CONTROLLER_DESKTOP_H_
#define BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PICTURE_IN_PICTURE_CONTROLLER_DESKTOP_H_

#include "base/memory/raw_ptr.h"
#include "chrome/browser/ui/views/media/youtube_picture_in_picture_controller.h"
#include "chrome/browser/ui/views/media/youtube_picture_in_picture_controller_delegate.h"

class BraveYouTubePictureInPictureControllerDesktop
    : public YoutubePictureInPictureController {
 public:
  explicit BraveYouTubePictureInPictureControllerDesktop(
      YoutubePictureInPictureControllerDelegate* delegate);
  ~BraveYouTubePictureInPictureControllerDesktop() override;

  // YoutubePictureInPictureController:
  void OnSessionRequested(int tab_id, content::WebContents* web_contents) override;
  void ResumeSession() override;
  void DismissSession() override;
  bool IsActive() const override;
  bool IsTransitioning() const override;
  int GetTabId() const override;

 private:
  // Whether a Picture-in-Picture session is currently active.
  bool is_active_ = false;

  // Whether the controller is in the process of entering or exiting PiP mode.
  bool is_transitioning_ = false;

  // The tab ID associated with this session.
  int tab_id_ = -1;
};

#endif  // BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PICTURE_IN_PICTURE_CONTROLLER_DESKTOP_H_