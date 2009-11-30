#include"OgreStringConverter.h"

#include "HybridInputListener.h"


namespace HybridRenderer
{
        InputListener::InputListener(StateManager *sourceStateManager, unsigned long hWnd)  
	{

		//Set up the OIS parameter list
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

		stateManager = sourceStateManager;

		//Variables for camera movementStepment.

		// set the rotation and movementStep speed
		rotationStep = 0.13;
		movementStep = 250;

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
		switch(evt.key)
		{	
			case OIS::KC_UP:
			case OIS::KC_W:
			    cameraMoveDirection.z = -movementStep;
			    break;
		 
			case OIS::KC_DOWN:
			case OIS::KC_S:
			    cameraMoveDirection.z = movementStep;
			    break;
		 
			case OIS::KC_LEFT:
			case OIS::KC_A:
			    cameraMoveDirection.x = -movementStep;
			    break;

			case OIS::KC_RIGHT:
			case OIS::KC_D:
			    cameraMoveDirection.x = movementStep;
			    break;

			case OIS::KC_PGDOWN:
			case OIS::KC_E:
			    cameraMoveDirection.y = -movementStep;
			    break;
		 
			case OIS::KC_PGUP:
			case OIS::KC_Q:
			    cameraMoveDirection.y = movementStep;
			    break; 

			case OIS::KC_ESCAPE:
				stateManager->requestStateChange(SHUTDOWN);
				break;
			default:
				break;
		}
		return true;
	}
	bool InputListener::keyReleased(const OIS::KeyEvent &evt) 
	{	
		switch (evt.key)
		{
			case OIS::KC_UP:
			case OIS::KC_W:
		    	 	cameraMoveDirection.z = 0;
		  	  	break;
	 
			case OIS::KC_DOWN:
			case OIS::KC_S:
			    cameraMoveDirection.z = 0;
			    break;
	 
			case OIS::KC_LEFT:
			case OIS::KC_A:
			    cameraMoveDirection.x = 0;
			    break;
	 
			case OIS::KC_RIGHT:
			case OIS::KC_D:
			    cameraMoveDirection.x = 0;
			    break;
	 	
			case OIS::KC_PGDOWN:
			case OIS::KC_E:
			    cameraMoveDirection.y = 0;
			    break;
	 
			case OIS::KC_PGUP:
			case OIS::KC_Q:
			    cameraMoveDirection.y = 0;
			    break;
	 
			default:
			    break;
		} // switch

		return true;
	}


}
