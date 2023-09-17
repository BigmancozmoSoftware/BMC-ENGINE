#include "Audio.h"

Audio::Audio()
{
	initFmod();
}

void Audio::playSound(const char* filePath)
{
	FMOD_SOUND* sound;
	FMOD_System_CreateSound(system, filePath, FMOD_DEFAULT, NULL, &sound);	
	FMOD_System_PlaySound(system, sound, NULL, false, NULL);
	
}

void Audio::playSound(const char* filePath, bool looped)
{
	auto mode = FMOD_DEFAULT;
	if (looped) {
		mode = FMOD_LOOP_NORMAL;
	}

	FMOD_SOUND* sound;
	FMOD_System_CreateSound(system, filePath, mode, NULL, &sound);
	FMOD_System_PlaySound(system, sound, NULL, false, NULL);
}

void Audio::initFmod()
{
	FMOD_RESULT result;
	system = NULL;

	result = FMOD_System_Create(&system, FMOD_VERSION);      // Create the main system object.
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d)\n", result);
		exit(-1);
	}

	result = FMOD_System_Init(system, 512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d)\n", result);
		exit(-1);
	}
}
