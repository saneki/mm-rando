@echo off

:: Run build command in Docker container to build & copy Asm files.
docker-compose up || goto :error

:: Rebuild Randomizer source for Release.
devenv "..\Majora's Mask Randomiser.sln" /Rebuild Release || goto :error

:: Randomize ROM and place in output directory.
run-cli.bat || goto :error

:: Exit successfully.
goto :EOF

:error
exit /b %errorlevel%
