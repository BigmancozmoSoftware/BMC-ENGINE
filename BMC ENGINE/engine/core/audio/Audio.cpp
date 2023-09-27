#include "Audio.h"

Audio::Audio()
{
	initFmod();
}

void Audio::playSound(const char* filePath)
{
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
}

bool Audio::didErrorOccur(){
    if(result != FMOD_OK){
        cout << "An FMOD error occurred!" << endl;
		return true;
    }
    return false;
}