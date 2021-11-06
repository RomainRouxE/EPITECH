import os

#wine python C:/Python27/Scripts/pyinstaller-script.py --onefile pbrain-PARIS-Afene-mebaley.Andy.py
PYINSTALLER_PATH="C:/Python27/Scripts/pyinstaller-script.py"
PYTHON_EXECUTABLE="python"
PROJECT_NAME = "test"
PROJECT_MAIN_SCRIPT = "pbrain-PARIS-Afene-mebaley.Andy.py"
MAKESPEC_CMD = """%s %s --onefile %s """ % (PYTHON_EXECUTABLE, PYINSTALLER_PATH, PROJECT_MAIN_SCRIPT)
SOURCE_MV = './dist/pbrain-PARIS-Afene-mebaley.Andy.exe'
DESTINATION_MV = './pbrain-PARIS-Afene-mebaley.Andy.exe'
os.system(MAKESPEC_CMD)
os.rename(SOURCE_MV, DESTINATION_MV)