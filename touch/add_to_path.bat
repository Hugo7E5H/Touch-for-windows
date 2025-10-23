@echo off
setlocal

net session >nul 2>&1
if %errorlevel% neq 0 (
    echo This script must be run as Administrator.
    pause
    exit /b 1
)

set "TOUCH_DIR=%~dp0"

if "%TOUCH_DIR:~-1%"=="\" set "TOUCH_DIR=%TOUCH_DIR:~0,-1%"

if not exist "%TOUCH_DIR%" (
    echo The folder "%TOUCH_DIR%" doesn't exist.
    pause
    exit /b 1
)

echo %PATH% | find /I "%TOUCH_DIR%" >nul
if %errorlevel%==0 (
    echo The folder "%TOUCH_DIR%" is already in the PATH.
    pause
    exit /b 0
)

setx PATH "%PATH%;%TOUCH_DIR%"

echo Done.
echo The "%TOUCH_DIR%" folder has been added to the user's PATH.
echo Please restart your terminal for the change to take effect.
pause
