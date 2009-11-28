include "HybridInputListener.h"
#include "HybridStateManager.h"

namespace HybridRenderer
{
        InputListener::InputListener(StateManager *sm, unsigned long hWnd)  
	{

		//Set up the OIS parameter list
		OIS::ParamList pl;
		//Just the window handle will do
		pl.insert(OIS::ParamList::value_type("WINDOW", Ogre::StringConverter::toString(hWnd)));
	 
		//Keep a hold of the window handle
		//Is this really necessary? Perhaps not.
	 	m_hWnd = hWnd;
		//Create the input system and use it to create a mouse and keyboard.
		//Hold on to these created objects
		m_ois = OIS::InputManager::createInputSystem(pl);
		mMouse = static_cast<OIS::Mouse*>(m_ois->createInputObject(OIS::OISMouse, true));
		mKeyboard = static_cast<OIS::Keyboard*>(m_ois->createInputObject(OIS::OISKeyboard, true));
		//Register to recieve mouse events and keyboard events.
		mMouse->setEventCallback(this);
		mKeyboard->setEventCallback(this);

		m_sm = sm;
	}

        InputListener::~InputListener() 
        {
	        if (mMouse)
		        m_ois->destroyInputObject(mMouse);
	        if (mKeyboard)
		        m_ois->destroyInputObject(mKeyboard);
        	OIS::InputManager::destroyInputSystem(m_ois);
        }

	// MouseListener
	bool InputListener::mouseMoved(const OIS::MouseEvent &evt) 
	{
		return true;
	}

	bool InputListener::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID btn) 
	{
		return true;
	}

	bool InputListener::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID btn) 
	{
		return true;
	}
	
	// KeyListener
	bool InputListener::keyPressed(const OIS::KeyEvent &evt) 
	{
		return true;
	}

	bool InputListener::keyReleased(const OIS::KeyEvent &evt) 
	{
		if (evt.key == OIS::KC_ESCAPE)
			m_simulation->requestStateChange(SHUTDOWN);

		return true;
	}

}
