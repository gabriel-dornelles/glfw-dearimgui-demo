@echo off

set BUILDIR="%~dp0..\__AppBuild__"
set TARGET=Debug

if NOT "%1" == "" (
    if "%1" == "debug" (
        set TARGET=Debug
    ) else if "%1" == "release" (
        set TARGET=Release
    )
)

echo -- Build type selected: %TARGET%

cmake -B %BUILDIR%
cmake --build %BUILDIR% --config %TARGET%
