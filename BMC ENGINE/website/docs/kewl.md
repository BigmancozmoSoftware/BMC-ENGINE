<h1 align="center">
  <img src="https://github-production-user-asset-6210df.s3.amazonaws.com/67850768/266583069-92ac3769-7ae4-4a48-bc32-5826dcbd4140.png" width=850>
</h1>
BMC engine is a game engine made by Bigmancozmo. Continue reading to learn how to use it.

## Installation/Setup
To download BMC Engine, first head over to [this](https://github.com/Bigmancozmo/BMC-ENGINE/releases) link. It'll take you to the engine's latest release. Note that currently the engine is a framework - the executable is a game demo. Download the source code to make games.
Next, you'll need to download and install *Microsoft Visual Studio* via [this](https://visualstudio.microsoft.com/downloads/) link.
That's it, you've installed the engine!

## Compiling
To compile, there's a few steps you must do first.
1. Compile the engine as Debug. It's OK if it makes errors, we just need the build's directory.
2. Run `copy_assets.bat` and `copy_dll.bat`.
3. Add a file called `PrivateData.h` in the same directory as `Main.cpp`. The contents of this are as follows:
    ```
    #pragma once
    #define RESOURCE_DIRECTORY L"ResourceDir"
    ```
    Change "ResourceDir" to the directory of `BMC ENGINE/x64/Debug`.</br></br>
Now, `hit Local Windows Debugger`!</br>
[Here](https://github.com/Bigmancozmo/BMC-ENGINE/assets/67850768/c59a6406-0232-44a4-a706-7de328f49943)'s a video of this entire process if you'd rather see that:

