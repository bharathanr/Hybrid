#ifndef HYBRID_FRAME_LISTENER_H
#define HYBRID_FRAME_LISTENER_H

#include<Ogre.h>

namespace HybridRenderer
{
	class CameraInputHandler;

	class FrameListener: public Ogre::FrameListener
	{
		private:
			Ogre::SceneManager *sceneManager;
		public:
			FrameListener(Ogre::SceneManager*);
			~FrameListener();
			virtual bool frameStarted(const Ogre::FrameEvent &evt);
	};
}

#endif
