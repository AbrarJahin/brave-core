// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_MENU_ITEM_H_
#define BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_MENU_ITEM_H_

#include "ui/views/controls/menu/menu_model.h"

class BraveYouTubePictureInPictureControllerDesktop;

// Menu item for YouTube Picture-in-Picture functionality
class BraveYouTubePiPMenuItem : public views::MenuModel {
 public:
  explicit BraveYouTubePiPMenuItem(
      BraveYouTubePictureInPictureControllerDesktop* controller);
  ~BraveYouTubePiPMenuItem() override;

  // views::MenuModel:
  void ExecuteCommand(int command_id, int event_flags) override;
  bool IsEnabled() const override;
  bool IsVisible() const override;

 private:
  raw_ptr<BraveYouTubePictureInPictureControllerDesktop> controller_;
};

#endif  // BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_MENU_ITEM_H_