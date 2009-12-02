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
	};
}

#endif
