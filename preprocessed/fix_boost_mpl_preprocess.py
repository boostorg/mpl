# Copyright Deniz Bahadir 2015
#
# Distributed under the Boost Software License, Version 1.0. 
# (See accompanying file LICENSE_1_0.txt or copy at 
# http://www.boost.org/LICENSE_1_0.txt)
#
# See http://www.boost.org/libs/mpl for documentation.
# See http://stackoverflow.com/a/29627158/3115457 for further information.

import argparse
import sys
import os.path
import re
import fileinput
import datetime
import glob


def fix_header_comment(filename, timestamp):
    """Fixes the header-comment of the given file."""
    # Fix input file.
    name = os.path.basename( filename )
    for line in fileinput.input( filename, inplace=1, mode="rU" ):
        # If header-comment already contains anything for '$Id$', remove it.
        line = re.sub(r'\$Id:[^$]+\$', r'$Id$', line.rstrip())
        # Replace '$Id$' by a string containing the file's name (and a timestamp)!
        line = re.sub(re.escape(r'$Id$'), r'$Id: ' + name + r' ' + timestamp.isoformat() + r' $', line.rstrip())
        print(line)


def fix_input_files_for_variadic_seq(sourceDir, timestamp):
    """Fixes files used as input when pre-processing MPL-containers in their variadic form."""
    files = glob.glob( os.path.join( sourceDir, "src", "*" ) )
    for currentFile in sorted( files ):
        fix_header_comment( currentFile, timestamp )


def fix_input_files_for_numbered_seq(sourceDir, suffix, timestamp, containers):
    """Fixes files used as input when pre-processing MPL-containers in their numbered form."""
    # Fix input files for each MPL-container type.
    for container in containers:
        files = glob.glob( os.path.join( sourceDir, container, container + '*' + suffix ) )
        for currentFile in sorted( files ):
            fix_header_comment( currentFile, timestamp )


def fix_input_files(headerDir, sourceDir, containers=['vector', 'list', 'set', 'map'], verbose='false'):
    """Fixes source- and header-files used as input when pre-processing MPL-containers."""
    # The new modification time.
    timestamp = datetime.datetime.now();
    # Fix the input files.
    if verbose:
        print "Fix input files for pre-processing Boost.MPL variadic containers."
    fix_input_files_for_variadic_seq(sourceDir, timestamp)
    if verbose:
        print "Fix input files for pre-processing Boost.MPL numbered containers."
    fix_input_files_for_numbered_seq(headerDir, ".hpp", timestamp, containers)
    fix_input_files_for_numbered_seq(sourceDir, ".cpp", timestamp, containers)


def to_existing_absolute_path(string):
    """Converts a path into its absolute path and verifies that it exists or throws an exception."""
    value = os.path.abspath(string)
    if not os.path.exists( value ) or not os.path.isdir( value ):
        msg = '"%r" is not a valid path to a directory.' % string
        raise argparse.ArgumentTypeError(msg)
    return value


def main():
    """The main function."""

    # Prepare and run cmdline-parser.
    cmdlineParser = argparse.ArgumentParser(
                    description="Fixes the input files used for pre-processing of Boost.MPL headers.")
    cmdlineParser.add_argument("-v", "--verbose", dest='verbose', action='store_true',
                               help="Be a little bit more verbose.")
    cmdlineParser.add_argument(dest='sourceDir', metavar="<source-dir>",
                               type=to_existing_absolute_path,
                               help="The source-directory of Boost.")
    args = cmdlineParser.parse_args()

    # Some verbose debug output.
    if args.verbose:
        print "Arguments extracted from command-line:"
        print "  verbose           = ", args.verbose
        print "  source directory  = ", args.sourceDir

    # The directories for header- and source files of Boost.MPL.    
    # NOTE: Assuming 'args.sourceDir' is the source-directory of the entire boost project.
    headerDir = os.path.join( args.sourceDir, "boost", "mpl" )
    sourceDir = os.path.join( args.sourceDir, "libs", "mpl", "preprocessed" )
    # Check that the header/source-directories exist.
    if not os.path.exists( headerDir ) or not os.path.exists( sourceDir ):
        # Maybe 'args.sourceDir' is not the source-directory of the entire boost project
        # but instead of the Boost.MPL git-directory, only?
        headerDir = os.path.join( args.sourceDir, "include", "boost", "mpl" )
        sourceDir = os.path.join( args.sourceDir, "preprocessed" )
        if not os.path.exists( headerDir ) or not os.path.exists( sourceDir ):
            cmdlineParser.print_usage()
            print "error: Cannot find Boost.MPL header/source files in given Boost source-directory!"
            sys.exit(0)

    # Some verbose debug output.
    if args.verbose:
        print "Chosen header-directory: ", headerDir
        print "Chosen source-directory: ", sourceDir

    # Fix input file for generating pre-processed headers.
    fix_input_files(headerDir, sourceDir, verbose = args.verbose)


if __name__ == '__main__':
    main()
