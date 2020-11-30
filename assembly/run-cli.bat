@echo off

:: Use CLI to generate randomized ROM file. Uses input ROM from "input" directory, and gameplay settings from UI settings file.
"..\MMR.CLI\bin\Release\netcoreapp3.1\MMR.CLI.exe" -input "input\Rom.z64" -settings "..\MMR.UI\bin\Release\settings.json"
