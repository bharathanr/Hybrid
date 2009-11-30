#ifndef HYBRID_INPUT_LISTENER_H
#define HYBRID_INPUT_LISTENER_H

#include <Ogre.h>

#include "OISEvents.h"
#include "OISInputManager.h"
#include "OISMouse.h"
#include "OISKeyboard.h"

#include "HybridStateManager.h"

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
	       		StateManager *stateManager;
			//Variables for camera movement in rasterise mode
			Ogre::Real rotationStep;
			Ogre::Real movementStep;
			Ogre::Vector3 cameraMoveDirection;		
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
