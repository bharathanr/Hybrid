#ifndef HYBRID_CAMERA_INPUT_HANDLER_H
#define HYBRID_CAMERA_INPUT_HANDLER_H

#include<pair>

#include<Ogre.h>

#include"HybridInputHandler.h"

namespace HybridRenderer
{
	class CameraInputHandler: public InputHandler
	{
		private:
			Ogre::Real movementStep;
			Ogre::Real rotationStep;
			Ogre::Vector3 cameraMoveDirection;
			Ogre::Quaternion cameraRotations;
		public:
			CameraInputHandler();
			~CameraInputHandler();
		        std::pair<Ogre::Vector3, Ogre::Quaternion> CameraInputHandler::getTransformations();
			// Functions to deal with mouse input.
			virtual bool mouseMoved(const OIS::MouseEvent &evt); 
			virtual bool mousePressed(const OIS::MouseEvent &evt, OIS::MouseButtonID);
			virtual bool mouseReleased(const OIS::MouseEvent &evt, OIS::MouseButtonID);

			// Functions to deal with keyboard input.
			virtual bool keyPressed(const OIS::KeyEvent &evt);
			virtual bool keyReleased(const OIS::KeyEvent &evt);
	};
}

#endif
