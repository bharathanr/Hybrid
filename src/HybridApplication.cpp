#include "HybridApplication.h"
#include "HybridStateManager.h"
#include "HybridInputListener.h"
#include "HybridFrameListener.h"

namespace HybridRenderer
{
	Application::Application()
		: root(0)
	{
		stateManager = new StateManager();
	}

	Application::~Application()
	{
		//Delete the Ogre root.
		delete root;
	}	

	void Application::initialiseOgre()
	{
		root = new Ogre::Root();
	}

	bool Application::go()
	{
		//1. Create Ogre root. Rely on the default plugin loading mechanism.
		initialiseOgre();
		//2.Initialise resources from resources.cfg - For now!
		initialiseResourcePaths();
		//3.Try to initialise a render system.
		//Uses the config dialog and ogre.cfg restoration for now.
		if(!setupRenderSystem())
			return false;
		//4.Create the render window using root->initialise
		createRenderWindow();
		//5.Set the default no. of mipmaps and initialise resources as needed.
		//This step needs a RenderWindow to be created first.
		initialiseResources();
		//6.Create a scene.
		createScene();
		//7.Set up OIS
		setupInputSystem();
		//8.Keep looping until exit.
		startRenderLoop();
		return true;
	}		

	bool Application::setupRenderSystem()
	{
		if (!root->restoreConfig() && !root->showConfigDialog())
			return false;
		//This else is for intent more than anything else.
		else
			return true;
	}	

	void Application::chooseSceneManager()
	{
        	sceneManager = root->createSceneManager(Ogre::ST_GENERIC, "HybridSceneManager");
	}	


	void Application::createScene()
	{
		chooseSceneManager();
		Ogre::Camera *cam = sceneManager->createCamera("Camera");
		Ogre::Viewport *vp = root->getAutoCreatedWindow()->addViewport(cam);
		vp->setBackgroundColour(Ogre::ColourValue(0.0f,0.0f,0.0f));
		cam->setAspectRatio(Ogre::Real(vp->getActualWidth()) /
				Ogre::Real(vp->getActualHeight()));

		//temp
		// set its position, direction  
		cam->setPosition(Ogre::Vector3(-20,20,150));
		cam->lookAt(Ogre::Vector3(0,0,0));
		                 
		//I'm adding a statue of liberty model.
		sceneManager->setAmbientLight(Ogre::ColourValue(1, 1, 1));
		Ogre::Entity *libertyStatue = sceneManager->createEntity("Liberty", "Liberty.mesh");
		//libertyStatue->setMaterialName("Ogre/Skin");
		Ogre::SceneNode *node1 = \
			sceneManager->getRootSceneNode()->createChildSceneNode("LibertyNode");
		//node1->yaw(Ogre::Degree(-180));
		node1->attachObject(libertyStatue);
	}

	void Application::createRayTraceScene()
	{
	}

	void Application::createRenderWindow()
	{
		root->initialise(true, "Tutorial Render Window");
	}

	void Application::initialiseResourcePaths()
	{
		//Define Resources
		
		//Handle with more care later.
		Ogre::String secName, typeName, archName;
		Ogre::ConfigFile cf;
		cf.load("resources.cfg");
		Ogre::ConfigFile::SectionIterator seci = cf.getSectionIterator();
        	while (seci.hasMoreElements())
        	{
	        	secName = seci.peekNextKey();
			Ogre::ConfigFile::SettingsMultiMap *settings = seci.\
								      getNext();
			Ogre::ConfigFile::SettingsMultiMap::iterator i;
		        for (i = settings->begin(); i != settings->end(); ++i)
		        {
		        	typeName = i->first;
				archName = i->second;
				Ogre::ResourceGroupManager::getSingleton().\
					addResourceLocation(archName, typeName, secName); 
			}
   		}
	
	}		

	void Application::initialiseResources()
	{
		//Set the default number of mipmaps.
		Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
		//Resource loading -- Change this to initialise only the resources
		//needed later.
		Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
	}

	void Application::setupInputSystem()
	{
		// set up the input handlers
		size_t hWnd = 0;
		Ogre::RenderWindow *win = root->getAutoCreatedWindow();
		win->getCustomAttribute("WINDOW", &hWnd);
		inputListener = new InputListener(hWnd);
	}

	void Application::startRenderLoop()
	{

		while (stateManager->getCurrentState() != SHUTDOWN) 
		{
			inputListener->capture();
			// run the message pump (Eihort)
			Ogre::WindowEventUtilities::messagePump();
			root->renderOneFrame();
		}

	}
}	
