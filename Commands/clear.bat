@echo off
REM List of folders to delete



REM Loop through each folder in the list

for %%F in ("..\build","..\output","..\vcpkg_installed") do (
    rmdir /s /q %%F
        echo Deleting Folder %%F.

)
echo Folders deleted successfully.
@REM pause
