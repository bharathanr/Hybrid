#ifndef HYBRID_INPUT_LISTENER_H
#define HYBRID_INPUT_LISTENER_H

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
			OIS::InputManager *m_ois;
	        	OIS::Mouse *m_mouse;
	        	OIS::Keyboard *m_keyboard;
	        	unsigned long m_hWnd;
	       		StateManager *m_sm;
			//Variables for camera movement in rasterise mode
			Ogre::Real m_rotate;
			Ogre::Real m_move;
			Ogre::Vector3 *m_direction;		
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
