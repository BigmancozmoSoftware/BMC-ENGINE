@echo off
echo Please make sure 7-zip is installed and added to PATH!
echo:
pause

echo:
echo Step 1: Copy assets
echo:

echo Clearing existing resources

cd x64/Debug
rmdir resources /s /q
mkdir resources
cd ../Release
rmdir resources /s /q
mkdir resources
cd ../..

cd "BMC ENGINE"
cd engine

echo Copying to Debug
robocopy "assets" "../../x64/Debug/resources" /s /e

echo Copying to Release
robocopy "assets" "../../x64/Release/resources" /s /e

echo:
echo Step 2: Delete unnecessary files
echo:
cd ../../x64/Release/
del "BMC ENGINE.pdb"

echo:
echo Step 3: Zip folder
echo:

del BMCEngine.zip
7z a -tzip BMCEngine.zip "BMC ENGINE.exe"
7z a -tzip BMCEngine.zip resources

cd ../..