@echo off
echo Please make sure 7-zip is installed and added to PATH!
echo:
pause

echo:
echo Step 1: Copy assets
echo:

echo Clearing existing resources

echo Clearing existing resources

cd x64/Debug
rmdir resources /s /q
mkdir resources
cd ../Release
rmdir resources /s /q
mkdir resources
cd ../..

cd "BMC ENGINE"

echo Copying to Debug
robocopy "resources" "../x64/Debug/resources" /s /e

echo Copying to Release
robocopy "resources" "../x64/Release/resources" /s /e

echo:
echo Step 2: Delete unnecessary files
echo:
cd ../../x64/Release/
del "BMC ENGINE.pdb"

echo:
echo Step 3: Copy DLLs
echo:

cd ../..

copy "dlls" "x64/Release"
copy "dlls" "x64/Debug"

echo:
echo Step 3: Zip folder
echo:

cd x64/Release
del BMCEngine.zip
7z a -tzip BMCEngine.zip "BMC ENGINE.exe"
7z a -tzip BMCEngine.zip resources
7z a -tzip BMCEngine.zip "fmodL.dll"

cd ../..