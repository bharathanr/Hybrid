#include"OgreStringConverter.h"

#include "HybridInputListener.h"


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
		m_mouse = static_cast<OIS::Mouse*>(m_ois->createInputObject(OIS::OISMouse, true));
		m_keyboard = static_cast<OIS::Keyboard*>(m_ois->createInputObject(OIS::OISKeyboard, true));
		//Register to recieve mouse events and keyboard events.
		m_mouse->setEventCallback(this);
		m_keyboard->setEventCallback(this);

		m_sm = sm;

		//Variables for camera movement.

		// set the rotation and move speed
		m_rotate = 0.13;
		m_move = 250;

	}

        InputListener::~InputListener() 
        {
	        if (m_mouse)
		        m_ois->destroyInputObject(m_mouse);
	        if (m_keyboard)
		        m_ois->destroyInputObject(m_keyboard);
        	OIS::InputManager::destroyInputSystem(m_ois);
        }
	
	void InputListener::capture() 
	{
		m_mouse->capture();
		m_keyboard->capture();
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
			m_sm->requestStateChange(SHUTDOWN);

		return true;
	}

}
