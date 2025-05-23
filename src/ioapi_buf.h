/* ioapi_buf.h -- IO base function header for compress/uncompress .zip
   files using zlib + zip or unzip API

   This version of ioapi is designed to buffer IO.

   Based on Unzip ioapi.c version 0.22, May 19th, 2003

   Copyright (C) 1998-2003 Gilles Vollant
             (C) 2003 Justin Fletcher
             (C) 2012 Nathan Moinvaziri

   This file is under the same license as the Unzip tool it is distributed
   with.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zlib.h"
#include "minizip/ioapi.h"

#define IOBUF_BUFFERSIZE (64 * 1024)

voidpf ZCALLBACK fopen_buf_func OF((voidpf opaque,const char* filename,int mode));
voidpf ZCALLBACK fopen64_buf_func OF((voidpf opaque,const char* filename,int mode));
voidpf ZCALLBACK fopendisk_buf_func OF((voidpf opaque, voidpf stream_cd, int number_disk, int mode));
voidpf ZCALLBACK fopendisk64_buf_func OF((voidpf opaque, voidpf stream_cd, int number_disk, int mode));
uLong ZCALLBACK fread_buf_func OF((voidpf opaque,voidpf stream,void* buf,uLong size));
uLong ZCALLBACK fwrite_buf_func OF((voidpf opaque,voidpf stream,const void* buf,uLong size));
long ZCALLBACK ftell_buf_func OF((voidpf opaque,voidpf stream));
ZPOS64_T ZCALLBACK ftell64_buf_func OF((voidpf opaque, voidpf stream));
long ZCALLBACK fseek_buf_func OF((voidpf opaque,voidpf stream,uLong offset,int origin));
long ZCALLBACK fseek64_buf_func OF((voidpf opaque, voidpf stream, ZPOS64_T offset, int origin));
int ZCALLBACK fclose_buf_func OF((voidpf opaque,voidpf stream));
int ZCALLBACK ferror_buf_func OF((voidpf opaque,voidpf stream));

typedef struct ourbuffer_s {
  zlib_filefunc_def filefunc;
  zlib_filefunc64_def filefunc64;
} ourbuffer_t;

void fill_buffer_filefunc OF((zlib_filefunc_def* pzlib_filefunc_def, ourbuffer_t *ourbuf));
void fill_buffer_filefunc64 OF((zlib_filefunc64_def* pzlib_filefunc_def, ourbuffer_t *ourbuf));