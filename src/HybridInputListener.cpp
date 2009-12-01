#include"OgreStringConverter.h"

#include "HybridInputListener.h"


namespace HybridRenderer
{
        InputListener::InputListener(size_t hWnd)  
	{

		//Set up the OIS parameter list
		//
		OIS::ParamList pl;
		//Just the window handle will do
		pl.insert(OIS::ParamList::value_type("WINDOW", Ogre::StringConverter::toString(hWnd)));
	 
		//Keep a hold of the window handle
		//Is this really necessary? Perhaps not.
	 	hWnd = hWnd;
		//Create the input system and use it to create a mouse and keyboard.
		//Hold on to these created objects
		ois = OIS::InputManager::createInputSystem(pl);
		mouse = static_cast<OIS::Mouse*>(ois->createInputObject(OIS::OISMouse, true));
		keyboard = static_cast<OIS::Keyboard*>(ois->createInputObject(OIS::OISKeyboard, true));
		//Register to recieve mouse events and keyboard events.
		mouse->setEventCallback(this);
		keyboard->setEventCallback(this);
	}

        InputListener::~InputListener() 
        {
	        if (mouse)
		        ois->destroyInputObject(mouse);
	        if (keyboard)
		        ois->destroyInputObject(keyboard);
        	OIS::InputManager::destroyInputSystem(ois);
        }
	
	void InputListener::capture() 
	{
		mouse->capture();
		keyboard->capture();
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
		return true;
	}


}
