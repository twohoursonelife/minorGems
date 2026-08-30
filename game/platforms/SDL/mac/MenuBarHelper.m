#import <Cocoa/Cocoa.h>

#import "SDLMain_Ext.h"

/* NSMenu_setMenuBarVisible normally comes from SDLMain.m, but when
   linking against sdl12-compat's libSDLmain.a (which provides main),
   compiling all of SDLMain.m would duplicate main.  This file supplies
   just the helper that ScreenGL_SDL.cpp needs for fullscreen mode. */

void NSMenu_setMenuBarVisible(int flag) {
    if (flag) {
        [NSMenu setMenuBarVisible:TRUE];
    } else {
        [NSMenu setMenuBarVisible:FALSE];
    }
}
