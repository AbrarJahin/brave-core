// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/ui/views/media/brave_youtube_pip_shortcut_manager.h"

#include "base/logging.h"

BraveYouTubePiPShortcutManager::BraveYouTubePiPShortcutManager() = default;

BraveYouTubePiPShortcutManager::~BraveYouTubePiPShortcutManager() = default;

void BraveYouTubePiPShortcutManager::Initialize() {
#if defined(OS_WIN)
  handler_ = std::make_unique<BraveYouTubePiPShortcutHandlerWin>();
  handler_->Initialize();
#elif defined(OS_MAC)
  handler_ = std::make_unique<BraveYouTubePiPShortcutHandlerMac>();
  handler_->initialize();
#elif defined(OS_LINUX)
  handler_ = std::make_unique<BraveYouTubePiPShortcutHandlerLinux>();
  handler_->Initialize();
#endif
}

void BraveYouTubePiPShortcutManager::HandleShortcut(
    const std::string& shortcut_id) {
#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
  if (handler_) {
    handler_->HandleShortcut(shortcut_id);
  }
#endif
}

bool BraveYouTubePiPShortcutManager::IsSupported() {
#if defined(OS_WIN) || defined(OS_MAC) || defined(OS_LINUX)
  if (handler_) {
    return handler_->IsSupported();
  }
#endif
  return false;
}