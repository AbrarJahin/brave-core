// Copyright (c) 2026 The Brave Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_HANDLER_MAC_H_
#define BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_HANDLER_MAC_H_

#import <Cocoa/Cocoa.h>

@interface BraveYouTubePiPShortcutHandlerMac : NSObject

- (instancetype)init;
- (void)initialize;
- (void)handleShortcut:(NSString*)shortcut_id;
- (BOOL)isSupported;

@end

#endif  // BRAVE_CHROME_BROWSER_UI_VIEWS_MEDIA_BRAVE_YOUTUBE_PIP_SHORTCUT_HANDLER_MAC_H_