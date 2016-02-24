hostname=`hostname | sed 's/..$//'`

if [ "${hostname}" = "nl-rot-shell" ]
then
    SUDOKU_BUILD="/scratch/Sudoku"
    QTDIR="/apps/thirdparty64/qt-475-x11-gcc446-mt-dynamic-debug"
else
    export HTTPS_PROXY=https://nl-rot-shell25:3128/
    SUDOKU_BUILD="$HOME/sudoku"
    QTDIR=" "
fi

export SUDOKU_BUILD
export QTDIR
export QT_QPA_PLATFORM_PLUGIN_PATH=${QTDIR}/plugins
export MANPATH=$QTDIR/doc/man:$MANPATH
export LD_LIBRARY_PATH=$QTDIR/lib:$LD_LIBRARY_PATH
export PATH=$QTDIR/bin:$PATH
     
