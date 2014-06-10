Project 4: Modifications to the MINIX filesystem
================================================
Everyone participated fairly in this project. 
We agreed to use all our grace days for this project. 
None of us have used a single grace day so far.

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
Run 

    chmod +x install.sh
    
Run 

    ./install.sh
    
This assumes your system runs bash-2.05

    cd /usr/src/lib
	make install
	cd /usr/src/include
	make install
    make libraries
    make includes
    cd servers/
    make install
    cd /usr/tools/
    make install
    
Restart your system

To run a test file in /testing/
Run
	
	cc -c test.c
	cc -o test test.o
	./test

Repeat the above compilation steps to build the user utilities metacat.c and metatag.c in /utils

Implementation Details
----------------------
Prototypes for the user library calls 
	ssize_t metaread(int _fd, void *_buf, size_t _n)
	ssize_t metawrite(int _fd, void *_buf, size_t _n)
are included in stdio.h.
These calls function in the same way as the standard read() and write().

The utils provided in /utils are 
	metacat filename
and 
	metatag filename text to append to metadata

Bugs
----
Sometimes install.sh will copy a file with a ? appended to the end of the filename. This happens when windows endlines using \r exist in install.sh.
If compilation fails it might be due to windows endline present in install.sh or Makefile.inc.


