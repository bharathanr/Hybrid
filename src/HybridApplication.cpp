#include"HybridApplication.h"

HybridApplication::HybridApplication()
	: mRoot(0)
{
}

HybridApplication::~HybridApplication()
{
	//Delete the Ogre root.-- if it exists
	delete mRoot;
}

bool HybridApplication::go()
{
	return true;
}

void HybridApplication::createScene()
{
}

void HybridApplication::createRayTraceScene()
{
}

void HybridApplication::createRenderWindow()
{
}

void HybridApplication::initialiseResources()
{
}

void HybridApplication::startRenderLoop()
{
}
