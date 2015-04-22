Pre-processing of MPL-containers
--------------------------------

Pre-processing of MPL-containers can be accomplished using the script
"boost_mpl_preprocess.py". In the simplest case call it with a single
argument which is the path to the source-directory of Boost.

  python boost_mpl_preprocess.py <path-to-boost-sourcedir>

This will pre-process all four MPL-container types (vector, list, set,
map) and makes them able to hold up to 100 elements. They can be used
either in their 'numbered' or their 'variadic' form.

Additionally, the script also allows more fine-grained pre-processing.
The maximal number of elements an MPL-container type is able to hold can
be different from the one of other MPL-container types and it can also
differ between its 'numbered' and 'variadic' form.
To see all options, call the script like this:

  python boost_mpl_preprocess.py --help


Fixing pre-processing of MPL-containers
---------------------------------------

Sadly, pre-processing of MPL-containers might fail, if the source-files
used as input are missing some header-comments required during the pre-
processing step.
In such a case call the script "fix_boost_mpl_preprocess.py" like this:

  python fix_boost_mpl_preprocess.py <path-to-boost-sourcedir>

This will fix the header-comments of all the source-files needed during
pre-processing. Calling "boost_mpl_preprocess.py" afterwards should then
successfully pre-process the MPL-containers.

Note:
If pre-processing failed can be checked by examining at least one of the
following directories in which automatically generated files will be put
during pre-processing. If at least one file in these directories (or sub-
directories therein) has a size of zero bytes, the fix is needed.

 <path-to-boost-sourcedir>/boost/mpl/vector/aux_/preprocessed/
 <path-to-boost-sourcedir>/boost/mpl/list/aux_/preprocessed/
 <path-to-boost-sourcedir>/boost/mpl/set/aux_/preprocessed/
 <path-to-boost-sourcedir>/boost/mpl/map/aux_/preprocessed/
 <path-to-boost-sourcedir>/boost/mpl/aux_/preprocessed/

