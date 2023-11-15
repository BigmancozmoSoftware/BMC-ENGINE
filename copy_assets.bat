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

cd ../..