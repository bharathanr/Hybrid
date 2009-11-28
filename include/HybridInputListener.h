#include "OISEvents.h"
#include "OISInputManager.h"
#include "OISMouse.h"
#include "OISKeyboard.h"

namespace HybridRenderer
{
	class InputListener: public KeyboardListener, public MouseListener
	{
	        private:
			OIS::InputManager *m_ois;
	        	OIS::Mouse *mMouse;
	        	OIS::Keyboard *mKeyboard;
	        	unsigned long m_hWnd;
	       		StateManager m_sm;	
                public:
	        	InputHandler(StateManager *sim, unsigned long hWnd); 
        		~InputHandler();
	
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
