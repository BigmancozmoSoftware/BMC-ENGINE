#pragma once

#include "FMOD/fmod.h"
#include <iostream>
using namespace std;

class Audio
{
public:
	Audio();
	void playSound(const char* filePath);
private:
	void initFmod();
	FMOD_SYSTEM* system;
};
