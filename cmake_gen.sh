#!/bin/bash

handle_dir ()
{
    echo "# CMakeLists.txt for $1" > $1/CMakeLists.txt

    for directory in `ls -d $1/*/ 2> /dev/null`
    do
        path=`echo $directory | sed -E 's,/$|//$,,'`
        dirname=`echo $path | sed "s,$1/,,"`

        if [[ $dirname != *".bak" ]]; then
            echo "ADD_SUBDIRECTORY($dirname)" >> $1/CMakeLists.txt
        fi

        handle_dir $path $2
    done

    echo >> $1/CMakeLists.txt
    echo "MACRO_ADD_SOURCES($2" >> $1/CMakeLists.txt
    echo `ls -p $1 | grep -E "\.cpp|\.h|\.inl"` >> $1/CMakeLists.txt
    echo ")" >> $1/CMakeLists.txt
}

echo "Generating CMakeLists..."

handle_dir "src"       EXE_SRC

echo "CMakeLists generation complete!"

# EOF