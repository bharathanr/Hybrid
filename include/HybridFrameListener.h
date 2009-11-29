#ifndef HYBRID_FRAME_LISTENER_H
#define HYBRID_FRAME_LISTENER_H

#include<Ogre.h>

namespace HybridRenderer
{
	class FrameListener: public Ogre::FrameListener
	{
		public:
			virtual bool frameStarted(const Ogre::FrameEvent &evt);
	};
}

#endif
