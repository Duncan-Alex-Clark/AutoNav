#!/bin/bash

# change directory to top level data directory. This is the directory
# that has the directories cam0, cam1, throttle, steering
#
# Then run this script. This script will create a new directory named
# reorder that reindexes the image files and concatenates the steering
# and throttle text files. Reorder will have folders for cameras and 


trap "cd $ROOT" SIGINT

# generate random number for this run. Can be used to keep track of
# runs. Not tested, but this is intended to permit successive
# reording/reindexing of reordered data

RunId=`tr -dc 0-9 </dev/urandom | head -c 6`

# need to make sure this RunId has not been previously used
while [ -d reorder/cam0/$RunId ]
do
    # used this ID previously. Roll the dice to find a new one
    RunId=`tr -dc 0-9 </dev/urandom | head -c 6`
done

# make the directories for this run
[ ! -d reorder             ] && mkdir reorder
[ ! -d reorder/cam0        ] && mkdir reorder/cam0
[ ! -d reorder/cam1        ] && mkdir reorder/cam1
[ ! -d reorder/cam0/$RunId ] && mkdir reorder/cam0/$RunId
[ ! -d reorder/cam1/$RunId ] && mkdir reorder/cam1/$RunId
[ ! -d reorder/throttle    ] && mkdir reorder/throttle
[ ! -d reorder/steering    ] && mkdir reorder/steering

# same this directory
ROOT=`pwd`

(
    # reorder images from cameras first
    for camera in 0 1
    do
        echo $camera
        (
            echo cam TOL fileIndex=$fileIndex
            cd $ROOT/cam${camera}
            
            export fileIndex=0
            Destination=$ROOT/reorder/cam${camera}
            for i in `ls`
            do
                
                    cd $i
                    echo TOL fileIndex=$fileIndex
                    # need to first zero pad the indices to 7 digits
                    # WARNING: this does not account to omitted indices
                    for jpg in `ls`
                    do
                        prefix=Camera_${camera}_Frame_
                        theIndex=`ls $jpg | cut -f 4 -d _ | cut -f 1 -d .`
                        fieldWidth=`echo -n $theIndex | wc -c`

                        if [ $fieldWidth -gt 7 ]
                        then
                            echo $0: Error: index field width too wide field width \
                                 $fieldWidth is greater than 7 characters
                            exit 1
                        fi

                        digits=`echo -n $theIndex | tr [0-9] '\n'  | grep -c $`
                        if [ $digits -ne $fieldWidth ]
                        then                               
                            echo $0: Error: invalid index: must be all digits
                            exit 1
                        fi                            

                        if [ $fieldWidth -eq 7 ]
                        then
                            # field format already zero padded
                            continue
                        fi
                        
                        # now zero padd the index
                        index7=$theIndex
                        [ $theIndex -lt 1000000 ] && index7=0$index7
                        [ $theIndex -lt 100000  ] && index7=0$index7
                        [ $theIndex -lt 10000   ] && index7=0$index7
                        [ $theIndex -lt 1000    ] && index7=0$index7
                        [ $theIndex -lt 100     ] && index7=0$index7
                        [ $theIndex -lt 10      ] && index7=0$index7
                        newJpg=Camera_${camera}_Frame_${index7}.jpg

                        # finally move the file 
                        echo mv -i $jpg $newJpg
                        mv -i $jpg $newJpg
                    done
                    # now we can copy and globally reindex
                    # assume all file names are clean here
                    for jpg in `ls`
                    do
                        # assume files above are in order
                        prefix=Camera_${camera}_Frame_
                        theIndex=`ls $jpg | cut -f 4 -d _ | cut -f 1 -d .`
                        index7=$fileIndex
                        [ $fileIndex -lt 1000000 ] && index7=0$index7
                        [ $fileIndex -lt 100000  ] && index7=0$index7
                        [ $fileIndex -lt 10000   ] && index7=0$index7
                        [ $fileIndex -lt 1000    ] && index7=0$index7
                        [ $fileIndex -lt 100     ] && index7=0$index7
                        [ $fileIndex -lt 10      ] && index7=0$index7
                        newJpg=Camera_${camera}_Frame_${index7}.jpg
                        echo cp -ai $jpg $Destination/$RunId/$newJpg
                        cp -ai $jpg $Destination/$RunId/$newJpg
                        export fileIndex=`expr $fileIndex + 1`
                    done
                    echo fileIndex=$fileIndex
                    cd ..
            done
        )
    done
    
    cd $ROOT/throttle
    Destination=$ROOT/reorder/throttle
    cat *.txt >  $Destination/throttle-$RunId.txt
    
    cd $ROOT/steering
    Destination=$ROOT/reorder/steering
    cat *.txt >  $Destination/steering-$RunId.txt
)
