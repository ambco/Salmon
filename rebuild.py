#!/usr/bin/python3

import os
import sys

# Default settings for project, has to be changed for new project.
project_name = 'salmon'

# End of project specific default settings.

class build_settings:
    def __init__(self):
        self.threads = 1
        self.objs = []

    def to_string(self):
        print('Settings')
        print('\tThread count: ' + str(self.threads))
        print('\tObjects:\n\t\t' + str(self.objs))

def build_project(thread_count):
    r = os.system('qmake ' + project_name + '.pro')
    if r != 0:
        print('Failed at qmake ' + project_name + '.pro')
        sys.exit(1)
    r = os.system('make -j ' + str(thread_count))
    if r != 0:
        print('Failed at make')
        sys.exit(2)

def run_project():
    os.chdir('build')
    r = os.system('./' + project_name)
    print(project_name + ' exited with code: ' + str(r))


def clean_project():
    r = os.system('rm build/' + project_name)
    if r != 0:
        print(project_name + ' binary not present')
    r = os.system('rm build/obj/*.o')
    if r != 0:
        print(project_name + ' object files not present')

def remove_specific(objs):
    if len(objs) == 0:
        return

    os.chdir('build/obj')

    for r in objs:
        try:
            os.remove(r + '.o')
        except os.error:
            print('file ' + r + '.o was not found')

    os.chdir('../../')

def set_thread_count(args, sett):
    if len(args) == 0:
        return False
    else:
        sett.threads = args.pop(0)
    return True

def parse_args(args, sett):
    if len(args) == 0:
        return
    arg = args.pop(0)
    if arg[0] == '-':
        if arg == '-a' or arg == '--all':
            clean_project()
            parse_args(args, sett)
        elif arg == '-j':
            if set_thread_count(args, sett) == False:
                print("No thread cout set.")
                sys.exit(3)
            parse_args(args, sett)
    else:
        sett.objs += [arg]
        parse_args(args, sett)

sett = build_settings()

l = len(sys.argv)

if l == 1:
    build_project(sett)

else:
    args = sys.argv
    args.pop(0)

    parse_args(args, sett)
    remove_specific(sett.objs)
    build_project(sett.threads)
    run_project()
    sett.to_string()

sys.exit(0)
