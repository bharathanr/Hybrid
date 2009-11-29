/*
 * Author: Bharathan Rajaram
 * This is the class that sets up the Ogre application and the ray trace system.
 */

#ifndef HYBRID_APPLICATION_H
#define HYBRID_APPLICATION_H

#include<Ogre.h>

#include "HybridFrameListener.h"
#include "HybridStateManager.h"
#include "HybridInputListener.h"

namespace HybridRenderer
{
	/*
	 * Class Application
	 */
	class Application
	{
		public:
			Application();
			~Application();
			bool go();	//Start the application
		protected:
			Ogre::Root *mRoot;
			Ogre::SceneManager *sceneManager;
			StateManager *stateManager;
			InputListener *inputListener;

			void initialiseOgre();
			virtual void initialiseResourcePaths();
			virtual void initialiseResources();
			virtual void chooseSceneManager();
			void setupInputSystem();
			bool setupRenderSystem();
			virtual void createRenderWindow();
			virtual void createScene();
			virtual void createRayTraceScene();
			void createFrameListener();
			virtual void startRenderLoop();
			bool initialiseRayTraceSystem();

	};
}

#endif

