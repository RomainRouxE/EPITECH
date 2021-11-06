import sys, os

def main(argv):
    exe_file = 'pbrain-PARIS-Afene-mebaley.Andy.exe'
    run(exe_file)

def run(exe_file):
    os.system('cmake .')
    os.system('cmake --build . --config Release')
    os.system('DEL pbrain-PARIS-Afene-mebaley.Andy.exe)
    os.system('COPY Release\pbrain-PARIS-afene-mebaley.exe pbrain-PARIS-afene-mebaley.exe')

if __name__=='__main__':
    main(sys.argv[1:])
