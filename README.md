Project 4: Modifications to the MINIX filesystem
================================================

By: Forrest Kerslager
    Nick Noto
    David Taylor
    Kevin Yeap
    Connie Yu

File Listing
------------

usr/
    src/
        lib/
            libc/
                posix/
                    Makefile.inc
                    _metaread.c
                    _metawrite.c
            libvtreefs/
                table.c
        include/
            stdio.h
            minix/
                callnr.h
                vfsif.h
        servers/
            hgfs/
                table.c
            mfs/
                proto.h
                read.c
                table.c
                write.c
            vfs/
                proto.h
                read.c
                request.c
                table.c
                write.c
    include/
        minix/
            callnr.h
            vfsif.h
            
utils/
    metacat.c
    metatag.c
    
testing/
    test.c
    testfile

install.sh
design.pdf
README.md                    

Installation
------------
Copy install.sh and /usr to minix.
Run chmod +x install.sh
Run ./install.sh
	This assumes your system runs bash-2.05
cd /usr/src/
make libraries
make includes
cd servers/
make install
cd /usr/tools/
make install
restart your system

Implementation Details
----------------------

#TODO

Production Notes
----------------

#TODO

Bugs
----

#TODO


