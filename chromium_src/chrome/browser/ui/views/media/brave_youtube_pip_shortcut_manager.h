// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_MANAGER_H_
#define BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_MANAGER_H_

#include <memory>
#include <string>

#if defined(OS_WIN)
#include "chrome/browser/ui/views/media/brave_youtube_pip_shortcut_handler_win.h"
#elif defined(OS_MAC)
#include "chrome/browser/ui/views/media/brave_youtube_pip_shortcut_handler_mac.h"
#elif defined(OS_LINUX)
#include "chrome/browser/ui/views/media/brave_youtube_pip_shortcut_handler_linux.h"
#endif

class BraveYouTubePiPShortcutManager {
 public:
  BraveYouTubePiPShortcutManager();
  ~BraveYouTubePiPShortcutManager();

  void Initialize();
  void HandleShortcut(const std::string& shortcut_id);
  bool IsSupported();

 private:
#if defined(OS_WIN)
  std::unique_ptr<BraveYouTubePiPShortcutHandlerWin> handler_;
#elif defined(OS_MAC)
  std::unique_ptr<BraveYouTubePiPShortcutHandlerMac> handler_;
#elif defined(OS_LINUX)
  std::unique_ptr<BraveYouTubePiPShortcutHandlerLinux> handler_;
#endif
};

#endif  // BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_MANAGER_H_