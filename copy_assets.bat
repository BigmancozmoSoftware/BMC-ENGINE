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

cd ../..