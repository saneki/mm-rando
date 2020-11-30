@echo off

:: Run build command in Docker container to build & copy Asm files.
docker-compose up

:: Rebuild Randomizer source for Release.
devenv "..\Majora's Mask Randomiser.sln" /Rebuild Release

:: Randomize ROM and place in output directory.
run-cli.bat
