#include "HybridCameraInputHandler.h"


namespace HybridRenderer
{
        CameraInputHandler::CameraInputHandler()  
	{
		//Variables for camera movementStepment.

		// set the rotation and movementStep speed
		rotationStep = 0.13;
		movementStep = 250;

		cameraMoveDirection = Ogre::Vector3::ZERO;

	}

        CameraInputHandler::~CameraInputHandler() 
        {
        }
	

	// MouseListener
	bool CameraInputHandler::mouseMoved(const OIS::MouseEvent &evt) 
	{
		if (e.state.buttonDown(OIS::MB_Right))
		{
			//mCamNode->yaw(Degree(-mRotate * e.state.X.rel), Node::TS_WORLD);
			//mCamNode->pitch(Degree(-mRotate * e.state.Y.rel), Node::TS_LOCAL);
		}

		
		return true;
	}

	bool CameraInputHandler::mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID btn) 
	{
		return true;
	}

	bool CameraInputHandler::mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID btn) 
	{
		return true;
	}
	
	// KeyListener
	bool CameraInputHandler::keyPressed(const OIS::KeyEvent &evt) 
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
			
			default:
				break;
		}
		return true;
	}
	bool CameraInputHandler::keyReleased(const OIS::KeyEvent &evt) 
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
