// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_DESKTOP_SHORTCUTS_H_
#define BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_DESKTOP_SHORTCUTS_H_

#include <string>

// Registers desktop shortcuts for YouTube Picture-in-Picture functionality
void RegisterBraveYouTubePiPShortcuts();

// Handles execution of a YouTube PiP shortcut
void HandleBraveYouTubePiPShortcut(const std::string& shortcut_id);

#endif  // BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_DESKTOP_SHORTCUTS_H_