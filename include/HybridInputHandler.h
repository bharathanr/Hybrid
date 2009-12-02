/* Interface Definition: InputHandler
 * Author: Bhrathan Rajaram
 * This file defines the InputHandler interface. All classes which intend to recieve input and do something
 * meaningful with it must derive from the InputHandler class and register with the InputListenr. 
 * Input handler defines methods to handle events, which can be ignored or overridden.
 */

#ifndef HYBRID_INPUT_HANDLER_H
#define HYBRID_INPUT_HANDLER_H

#include"OISEvents.h"
#include"OISMouse.h"
#include"OISKeyboard.h"

namespace HybridRenderer
{

	/*
	 * Another option is to have separate KeyListener and
	 * MouseListener interfaces. If I were to do that, I would use 
	 * OIS::KeyListener and OIS::MouseListener and change input handler to have 
	 * two lists- registeredKeyboardHandlers and registeredMouseHandlers
	 */

	class InputHandler
	{
		public:
			// Functions to deal with mouse input.
			virtual bool mouseMoved(const OIS::MouseEvent &evt) 
			{
				return true;
			}
		
			virtual bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID)
			{
				return true;
			}
		
			virtual bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID)
			{
				return true;
			}	

			// Functions to deal with keyboard input.
			virtual bool keyPressed(const OIS::KeyEvent &evt)
			{
				return true;
			}	
			
			virtual bool keyReleased(const OIS::KeyEvent &evt)
			{
				return true;
			}
	};
}

#endif
