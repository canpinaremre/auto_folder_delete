# auto_folder_delete
- Deletes folders in spesific date and time
- Takes input from folder_config.txt as:
    - Date: DD.MM.YYYY
    - Time: HH:MM
    - Path: path\to\my\folder
- Checks time every 1 miniute
- input.txt generated to give feedback to user
- In case of invalid input, input.txt will display error and program exit right away

# Example folder config
- Date: 14.02.2024
- Time: 00:08
- Path: C:\Users\90554\Desktop\deneme\deneme

# Implement
- Run startup.bat script or,
- Press Win + R to open the "Run" dialog.
- Type shell:startup and press Enter. This will open the "Startup" folder.
- Copy the rs_folder_update.exe with config file to this folder.
- Now, whenever the computer starts, the program will run automatically.

# Windows Defender
- Open Windows Security by clicking on the Windows Security icon in the system tray.
- Go to "Virus & threat protection" > "Manage settings".
- Scroll down to "Exclusions" and click on "Add or remove exclusions".
- Click on "Add an exclusion" and choose "File". Then, select your executable file.
- If you can not add exe, you can just add startup folder then put exe in the folder or run startup.bat script.
- Or you can just disable defender (not suggested)

