#pragma once

#include "FMOD/fmod.h"
#include <iostream>
using namespace std;

class Audio
{
public:
	Audio();
	void playSound(const char* filePath);
	void playSound(const char* filePath, bool looped);
	void setVolume(int volume);
private:
	void initFmod();
	bool handleError();
	FMOD_SYSTEM* system;
	FMOD_SOUNDGROUP* sGroup;
};