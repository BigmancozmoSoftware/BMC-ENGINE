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
copy "assets" "../../x64/Debug/resources"

echo Copying to Release
copy "assets" "../../x64/Release/resources"