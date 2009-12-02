#ifndef HYBRID_CAMERA_INPUT_HANDLER_H
#define HYBRID_CAMERA_INPUT_HANDLER_H

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
		public:
			CameraInputHandler();
			~CameraInputHandler();
			
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
