@echo off
echo Copying rs_folder_update.exe to startup folder...
copy "test\rs_folder_update.exe" "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup"
copy "test\folder_config.txt" "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup"
echo Starting rs_folder_update.exe...
start "" "%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup\rs_folder_update.exe"