@echo off
setlocal EnableDelayedExpansion

@REM build in root folder not recommended, but...
set buildDir=%~dp0build
set buildTarget=Debug
set buildWithNinja=0

:argloop
if NOT "%1" == "" (
    if "%1" == "release" (
        set buildTarget=Release
    ) else if "%1" == "ninja" (
        set buildWithNinja=1
    )

    shift /1
    goto argloop
)

if %buildWithNinja% == 1 (
    cmake -G Ninja -B %buildDir% -DCMAKE_BUILD_TYPE=%buildTarget%
    cmake --build %buildDir%
) else (
    cmake -B %buildDir%
    cmake --build %buildDir% --config %buildTarget%
)

endlocal
