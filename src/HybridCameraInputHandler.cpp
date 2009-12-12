#include "HybridCameraInputHandler.h"

namespace HybridRenderer
{
        CameraInputHandler::CameraInputHandler(Ogre::SceneNode *camNd)  
	{
		camNode = camNd;
		//Variables for camera movementStepment.

		// set the rotation and movementStep speed
		rotationStep = 0.13;
		movementStep = 250;

		cameraMoveDirection = Ogre::Vector3::ZERO;
		cameraRotation = Ogre::Quaternion::IDENTITY;
	}

        CameraInputHandler::~CameraInputHandler() 
        {
        }
	
	//Feedback to frame listener
	std::pair<Ogre::Vector3*, Ogre::Quaternion*> CameraInputHandler::getTransformations()
	{
		std::pair<Ogre::Vector3*, Ogre::Quaternion*> A(&cameraMoveDirection, &cameraRotation);
		return A;
	}
	
	// MouseListener
	bool CameraInputHandler::mouseMoved(const OIS::MouseEvent &evt) 
	{
		if (evt.state.buttonDown(OIS::MB_Right))
		{
			camNode->yaw(Ogre::Degree(-rotationStep * evt.state.X.rel), Ogre::Vector3::UNIT_Z);
			camNode->pitch(Ogre::Degree(-rotationStep * evt.state.Y.rel),Ogre::Vector3::UNIT_Y);
			//This is not a commutative multiplication...
			cameraRotation = pitch * yaw;
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
