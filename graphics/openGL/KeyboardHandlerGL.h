/*
 * Modification History
 *
 * 2000-December-19		Jason Rohrer
 * Created.
 *
 * 2001-February-4		Jason Rohrer
 * Added key release functions.
 *
 * 2001-October-29		Jason Rohrer
 * Added fuction for querying a handler's focus.  
 *
 * 2008-October-27	Jason Rohrer
 * Switched to implementation-independent keycodes.
 *
 * 2010-March-17	Jason Rohrer
 * Support for Ctrl, Alt, and Meta.
 *
 * 2010-April-6 	Jason Rohrer
 * Blocked event passing to handlers that were added by event.
 *
 * 2010-November-2 	Jason Rohrer
 * Support for eating key events.
 *
 * 2010-November-18 	Jason Rohrer
 * Added first and last macros for walking through all keycodes.
 */
 
 
#ifndef KEYBOARD_HANDLER_GL_INCLUDED
#define KEYBOARD_HANDLER_GL_INCLUDED 



// special key codes
#define  MG_KEY_F1           128
#define  MG_KEY_F2           129
#define  MG_KEY_F3           130
#define  MG_KEY_F4           131
#define  MG_KEY_F5           132
#define  MG_KEY_F6           133
#define  MG_KEY_F7           134
#define  MG_KEY_F8           135
#define  MG_KEY_F9           136
#define  MG_KEY_F10          137
#define  MG_KEY_F11          138
#define  MG_KEY_F12          139
#define  MG_KEY_LEFT         140
#define  MG_KEY_UP           141
#define  MG_KEY_RIGHT        142
#define  MG_KEY_DOWN         143
#define  MG_KEY_PAGE_UP      144
#define  MG_KEY_PAGE_DOWN    145
#define  MG_KEY_HOME         146
#define  MG_KEY_END          147
#define  MG_KEY_INSERT       148
#define  MG_KEY_RSHIFT       149
#define  MG_KEY_LSHIFT       150
#define  MG_KEY_RCTRL        151
#define  MG_KEY_LCTRL        152
#define  MG_KEY_RALT         153
#define  MG_KEY_LALT         154
#define  MG_KEY_RMETA        155
#define  MG_KEY_LMETA        156


// bounds of key constants
#define  MG_KEY_FIRST_CODE    MG_KEY_F1
#define  MG_KEY_LAST_CODE     MG_KEY_LMETA                     




/**
 * Interface for an object that can field OpenGL keystrokes.
 *
 * @author Jason Rohrer 
 */
class KeyboardHandlerGL { 
	
	public:

        virtual ~KeyboardHandlerGL() {
            }

		
		/**
		 * Gets whether this handler is focused (in other words,
		 * whether this handler wants to reserve keyboard
		 * events for itself).
		 *
		 * If no registered handler is focused, then all
		 * registered handlers receive keyboard events.  However,
		 * if some handlers are focused, then only focused handlers
		 * receive keyboard events.
		 *
		 * Note that in general, handlers should be unfocused.
		 * A default implementation is included in this interface,
		 * so handlers that do not care about focus can ignore
		 * this function.
		 *
		 * @return true iff this handler is focused. 
		 */
		virtual char isFocused();
		
		
		
		/**
		 * Callback function for when an ASCII-representable key is pressed.
		 *
		 * @param inKey ASCII representation of the pressed key.
		 * @param inX x position of mouse when key was pressed.
		 * @param inY y position of mouse when key was pressed.
		 */
		virtual void keyPressed( unsigned char inKey, int inX, int inY ) = 0;
		
		
		/**
		 * Callback function for when an ASCII-representable key is released.
		 *
		 * @param inKey ASCII representation of the released key.
		 * @param inX x position of mouse when key was released.
		 * @param inY y position of mouse when key was released.
		 */
		virtual void keyReleased( unsigned char inKey, int inX, int inY ) = 0;
		
		
		/**
		 * Callback function for when an special key is pressed.
		 *
		 * @param inKey integer constant representation of the pressed key.
		 * @param inX x position of mouse when key was pressed.
		 * @param inY y position of mouse when key was pressed.
		 */
		virtual void specialKeyPressed( int inKey, int inX, int inY ) = 0;
		
		
		/**
		 * Callback function for when an special key is released.
		 *
		 * @param inKey integer constant representation of the released key.
		 * @param inX x position of mouse when key was released.
		 * @param inY y position of mouse when key was released.
		 */
		virtual void specialKeyReleased( int inKey, int inX, int inY ) = 0;


		virtual void unmodifiedKeyPressed( unsigned char inKey ) { }
		virtual void unmodifiedKeyReleased( unsigned char inKey ) { }

        char mHandlerFlagged;

        // set to true by a handler if this key even was consumed
        // specially by the handler and should not be passed on to other
        // listening handlers
        char mEatEvent;
        
			
    protected:
        
        KeyboardHandlerGL()
                : mHandlerFlagged( false ),
                  mEatEvent( false ) {
            }
		
	};



inline char KeyboardHandlerGL::isFocused() {
	return false;
	}



#endif
