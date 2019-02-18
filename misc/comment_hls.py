#!/usr/bin/env python

import os
import shutil
import sys

def usage():
    if len(sys.argv) < 2:
        print 'This script is used for commment out hls for source file msocnew.ppc \n'
        print 'Usage: ' + sys.argv[0] + ' <FILE>'
        print '    FILE. Required, input file name'
        sys.exit(0)

usage()

inputfile = ""
if len(sys.argv) >= 2:
    inputfile = sys.argv[1]

"""
funcs = []

if len(sys.argv) >= 3:
    funcs = sys.argv[2:])
"""
bakfile = inputfile+".before_comment"

if os.path.isfile(inputfile):
    # back up it fistly.
    if os.path.isfile(bakfile):
        print "Here is a back up file: " + bakfile +", Pls rename or remove it fistly"
        sys.exit(0)
    shutil.copyfile(inputfile,bakfile)

    with open(inputfile+".new", "wt") as fout:
        with open(bakfile, "rt") as fin:
            for line in fin:
                if line.find("bool HLSmain(new_args *arguments, bool regenP);") != -1:
                    #fout.write(line);
                    #fout.write("bool HLSmain_comment_out(new_args *arguments, bool regenP){return TRUE;}")
                    fout.write(line.replace("bool HLSmain(new_args *arguments, bool regenP);",
                                            "bool HLSmain_comment_out(new_args *arguments, bool regenP){return TRUE;}"))
                elif line.find("STATICF afboolean deletePegsForPIPByProducts();") != -1:
                    #fout.write(line);
                    #fout.write("STATICF afboolean deletePegsForPIPByProducts_comment_out(){return TRUE;}");
                    fout.write(line.replace("STATICF afboolean deletePegsForPIPByProducts();",
                                            "STATICF afboolean deletePegsForPIPByProducts_comment_out(){return TRUE;}"))
                elif line.find("!HLSmain") != -1:
                    fout.write(line.replace("HLSmain", "HLSmain_comment_out"))
                elif line.find("!deletePegsForPIPByProducts") != -1:
                    fout.write(line.replace("deletePegsForPIPByProducts", "deletePegsForPIPByProducts_comment_out"))
                else:
                    fout.write(line);

    shutil.move(inputfile+".new", inputfile)
    print "The file " + inputfile + " has been commented out successfully!"
    print "The original file " + inputfile + " has been backed up as " + bakfile
else:
    print inputfile + " doesn't exist."