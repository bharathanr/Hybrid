#ifndef HYBRID_INPUT_LISTENER_H
#define HYBRID_INPUT_LISTENER_H

#include "OISEvents.h"
#include "OISInputManager.h"
#include "OISMouse.h"
#include "OISKeyboard.h"

namespace HybridRenderer
{
	class InputListener: 
		public OIS::KeyListener, 
		public OIS::MouseListener
	{
	        private:
			OIS::InputManager *ois;
	        	OIS::Mouse *mouse;
	        	OIS::Keyboard *keyboard;
	        	unsigned long hWnd;
                public:
	        	InputListener(StateManager *sim, unsigned long hWnd); 
        		~InputListener();
	
			void setWindowExtents(int width, int height) ;
			void capture();

			// MouseListener
			bool mouseMoved(const OIS::MouseEvent &evt);
			bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID);
			bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID);
	
			// KeyListener
			bool keyPressed(const OIS::KeyEvent &evt);
			bool keyReleased(const OIS::KeyEvent &evt);

	};
}

#endif
