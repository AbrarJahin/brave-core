// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/media/brave_youtube_pip_desktop_shortcuts.h"

#include "base/logging.h"
#include "chrome/browser/ui/views/frame/browser_view.h"
#include "chrome/browser/ui/views/media/youtube_picture_in_picture_controller.h"
#include "chrome/browser/ui/views/media/brave_youtube_picture_in_picture_controller_desktop.h"

#if defined(OS_WIN)
#include "chrome/browser/ui/views/media/brave_youtube_pip_shortcut_handler_win.h"
#elif defined(OS_MAC)
#include "chrome/browser/ui/views/media/brave_youtube_pip_shortcut_handler_mac.h"
#elif defined(OS_LINUX)
#include "chrome/browser/ui/views/media/brave_youtube_pip_shortcut_handler_linux.h"
#endif

void RegisterBraveYouTubePiPShortcuts() {
  // This function would register desktop shortcuts for YouTube PiP functionality
  LOG(INFO) << "Registering Brave YouTube Picture-in-Picture desktop shortcuts";
  
#if defined(OS_WIN)
  BraveYouTubePiPShortcutHandlerWin shortcut_handler;
  shortcut_handler.Initialize();
#elif defined(OS_MAC)
  BraveYouTubePiPShortcutHandlerMac* shortcut_handler = [[BraveYouTubePiPShortcutHandlerMac alloc] init];
  [shortcut_handler initialize];
#elif defined(OS_LINUX)
  BraveYouTubePiPShortcutHandlerLinux shortcut_handler;
  shortcut_handler.Initialize();
#endif

  // Register the shortcut in the application's menu system
  LOG(INFO) << "Desktop shortcuts registered for YouTube PiP mode";
}

void HandleBraveYouTubePiPShortcut(const std::string& shortcut_id) {
  // This function handles the execution of desktop shortcuts
  LOG(INFO) << "Handling Brave YouTube Picture-in-Picture shortcut: " << shortcut_id;
  
#if defined(OS_WIN)
  BraveYouTubePiPShortcutHandlerWin shortcut_handler;
  shortcut_handler.HandleShortcut(shortcut_id);
#elif defined(OS_MAC)
  BraveYouTubePiPShortcutHandlerMac* shortcut_handler = [[BraveYouTubePiPShortcutHandlerMac alloc] init];
  [shortcut_handler handleShortcut:[NSString stringWithUTF8String:shortcut_id.c_str()]];
#elif defined(OS_LINUX)
  BraveYouTubePiPShortcutHandlerLinux shortcut_handler;
  shortcut_handler.HandleShortcut(shortcut_id);
#endif
}