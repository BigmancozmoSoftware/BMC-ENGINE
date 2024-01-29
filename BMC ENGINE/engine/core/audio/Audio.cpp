#include "Audio.h"
#include <string>

Audio::Audio()
{
	initFmod();
}

void Audio::playSound(const char* filePath)
{
	std::cout << "Playing sound '";
	std::cout << filePath;
	std::cout << "' once." << std::endl;

	FMOD_SOUND* sound;
	result = FMOD_System_CreateSound(system, filePath, FMOD_DEFAULT, NULL, &sound);
	if (didErrorOccur()) { return; }
	result = FMOD_Sound_SetSoundGroup(sound, sGroup);
	if (didErrorOccur()) { return; }
	result = FMOD_System_PlaySound(system, sound, NULL, false, NULL);
	if (didErrorOccur()) { return; }
}

void Audio::playSound(const char* filePath, bool looped)
{
	std::cout << "Playing sound '";
	std::cout << filePath;
	std::cout << "' and looping." << std::endl;

	auto mode = FMOD_DEFAULT;
	if (looped) {
		mode = FMOD_LOOP_NORMAL;
	}

	FMOD_SOUND* sound;

	result = FMOD_System_CreateSound(system, filePath, mode, NULL, &sound);
	if (didErrorOccur()) { return; }
	result = FMOD_Sound_SetSoundGroup(sound, sGroup);
	if (didErrorOccur()) { return; }
	result = FMOD_System_PlaySound(system, sound, NULL, false, NULL);
	if (didErrorOccur()) { return; }
}

void Audio::setVolume(int volume)
{
	std::cout << "Set volume to ";
	std::cout << volume << std::endl;
	result = FMOD_SoundGroup_SetVolume(sGroup, ((float)volume)/100);
	if (didErrorOccur()) { return; }
}

void Audio::initFmod()
{
	system = NULL;


	//FMOD_SoundGroup_SetVolume();
	result = FMOD_System_Create(&system, FMOD_VERSION);
	if (didErrorOccur()) { return; }
	result = FMOD_System_Init(system, 512, FMOD_INIT_NORMAL, 0);
	if (didErrorOccur()) { return; }

	result = FMOD_System_CreateSoundGroup(system, "KewlSoundGroup", &sGroup);
	if (didErrorOccur()) { return; }

	std::cout << "Initialized FMOD" << std::endl;
}

bool Audio::didErrorOccur(){
    if(result != FMOD_OK){
		std::cout << "An FMOD error occurred!" << std::endl;
		return true;
    }
    return false;
}