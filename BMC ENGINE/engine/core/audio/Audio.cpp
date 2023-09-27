#include "Audio.h"

Audio::Audio()
{
	initFmod();
}

void Audio::playSound(const char* filePath)
{
	FMOD_SOUND* sound;
	FMOD_System_CreateSound(system, filePath, FMOD_DEFAULT, NULL, &sound);	
	FMOD_Sound_SetSoundGroup(sound, sGroup);
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
	FMOD_Sound_SetSoundGroup(sound, sGroup);
	FMOD_System_PlaySound(system, sound, NULL, false, NULL);
}

void Audio::setVolume(int volume)
{
	FMOD_SoundGroup_SetVolume(sGroup, ((float)volume)/100);
}

void Audio::initFmod()
{
	system = NULL;

	//FMOD_SoundGroup_SetVolume();
	FMOD_System_Create(&system, FMOD_VERSION);
	FMOD_System_Init(system, 512, FMOD_INIT_NORMAL, 0);

	FMOD_System_CreateSoundGroup(system, "KewlSoundGroup", &sGroup);
}

bool Audio::didErrorOccur(){
    // this was coded on mobile. it was rather difficult.
    if(result != FMOD_OK){
        cout << "An FMOD error occurred!" << endl;
    return true
    }
    return false;
}