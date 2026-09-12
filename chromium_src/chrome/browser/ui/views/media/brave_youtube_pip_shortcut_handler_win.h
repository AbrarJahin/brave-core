// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_HANDLER_WIN_H_
#define BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_HANDLER_WIN_H_

#include <string>

class BraveYouTubePiPShortcutHandlerWin {
 public:
  BraveYouTubePiPShortcutHandlerWin();
  ~BraveYouTubePiPShortcutHandlerWin();

  void Initialize();
  void HandleShortcut(const std::string& shortcut_id);
  bool IsSupported();

 private:
  // Windows-specific implementation details
};

#endif  // BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_HANDLER_WIN_H_