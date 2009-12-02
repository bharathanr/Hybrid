#ifndef HYBRID_INPUT_LISTENER_H
#define HYBRID_INPUT_LISTENER_H

#include<vector>

#include "OISEvents.h"
#include "OISInputManager.h"
#include "OISMouse.h"
#include "OISKeyboard.h"

#include"HybridInputHandler.h"

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
	        	size_t hWnd;
			std::vector<InputHandler> x;

                public:
	        	InputListener(size_t hWnd); 
        		~InputListener();
			
			//Captures the keyboard and mouse state!	
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
