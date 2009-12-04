/*
 * Author: Bharathan Rajaram
 * This is the class that sets up the Ogre application and the ray trace system.
 */

#ifndef HYBRID_APPLICATION_H
#define HYBRID_APPLICATION_H

#include<Ogre.h>

namespace HybridRenderer
{
	//Forward Declarations
	class FrameListener;
	class StateManager;
	class InputListener;
	class StateManagerInputHandler;
	class CameraInputHandler;
	
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
			Ogre::Root *root;
			Ogre::SceneManager *sceneManager;
			StateManager *stateManager;
			InputListener *inputListener;
			//Are the following pointers necessary - Reconsider.
			CameraInputHandler *camInputHandler;
			StateManagerInputHandler *smInputHandler;

			void initialiseOgre();
			virtual void initialiseResourcePaths();
			virtual void initialiseResources();
			virtual void chooseSceneManager();
			void setupInputSystem();
			bool setupRenderSystem();
			virtual void createRenderWindow();
			virtual void createScene();
			virtual void createRayTraceScene();
			void createFrameListeners();
			virtual void startRenderLoop();
			bool initialiseRayTraceSystem();

	};
}

#endif

