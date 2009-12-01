#include"OgreStringConverter.h"

#include "HybridInputListener.h"


namespace HybridRenderer
{
        InputListener::InputListener()  
	{

		//Variables for camera movementStepment.

		// set the rotation and movementStep speed
		rotationStep = 0.13;
		movementStep = 250;

		cameraMoveDirection = Ogre::Vector3::ZERO;

	}

        InputListener::~InputListener() 
        {
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