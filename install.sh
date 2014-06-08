#!/usr/pkg/bin/bash

cp usr/include/minix/callnr.h /usr/include/minix/callnr.h
cp usr/include/minix/vfsif.h /usr/include/minix/vfsif.h

cp usr/src/include/minix/callnr.h /usr/src/include/minix/callnr.h
cp usr/src/include/minix/vfsif.h /usr/src/include/minix/vfsif.h
cp usr/src/include/stdio.h /usr/src/include/stdio.h

cp usr/src/lib/libc/posix/_metaread.c /usr/src/lib/libc/posix/_metaread.c
cp usr/src/lib/libc/posix/_metawrite.c /usr/src/lib/libc/posix/_metawrite.c
cp usr/src/lib/libc/posix/Makefile.inc /usr/src/lib/libc/posix/Makefile.inc
cp usr/src/lib/libvtreefs/table.c /usr/src/lib/libvtreefs/table.c

cp usr/src/servers/vfs/table.c /usr/src/servers/vfs/table.c
cp usr/src/servers/vfs/proto.h /usr/src/servers/vfs/proto.h
cp usr/src/servers/vfs/read.c /usr/src/servers/vfs/read.c
cp usr/src/servers/vfs/write.c /usr/src/servers/vfs/write.c
cp usr/src/servers/vfs/request.c /usr/src/servers/vfs/request.c

cp usr/src/servers/mfs/table.c /usr/src/servers/mfs/table.c
cp usr/src/servers/mfs/proto.h /usr/src/servers/mfs/proto.h
cp usr/src/servers/mfs/read.c /usr/src/servers/mfs/read.c

cp usr/src/servers/hgfs/table.c /usr/src/servers/hgfs/table.c

cp usr/src/commands/cp/cp.c /usr/src/commands/cp/cp.c
