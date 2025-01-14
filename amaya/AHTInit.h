/*

  
  					W3C Sample Code Library libwww Default Initialization


!
  Default Initialization Methods
!
*/

/*
**	(c) COPYRIGHT MIT 1995.
**	Please first read the full copyright statement in the file COPYRIGH.
*/

/*

As mentioned in the Library Architecture,
libwww consists of a small core and a large set of hooks for adding
functionality. By itself, the core it not capable of performing any Web related
tasks like accessing a HTTP server or parsing a HTML document. All this
functionality must be registered by the application. This way, the core of
libwww is kept application independent and can be used as the basic building
block for any kind of Web application. The Library comes with a large set
of default functions, for example for accessing HTTP and FTP servers, parsing
RFC
822 headers etc. This module helps the application programmer setting
up all this functionality, but it is important to note that none of it is
required in order to use the Library.

This module is implemented by HTInit.c, and it is
a part of the W3C Sample Code
Library. You can also have a look at the other
Initialization modules.
*/

#ifndef HTINIT_H
#define HTINIT_H
#include "WWWLib.h"
#include "WWWApp.h"

/*
.
  Default Transport Protocol Modules
.

Register the default set of transport protocols.
*/

#include "WWWTrans.h"

extern "C" void HTTransportInit (void);

/*
.
  Default Protocol Modules
.

Set up default bindings between access schemes and the set of protocol modules
in the Library. The preemptive version registers all protocol modules to
use blocking sockets.
*/

#include "WWWHTTP.h"
#include "WWWFTP.h"
#include "WWWFile.h"


#ifndef HTTP_PORT
#define HTTP_PORT	80
#endif
#ifndef FTP_PORT
#define FTP_PORT        21
#endif

/*
.
  Default MIME Parsers
.

The core doesn't have any built in MIME parsers, but many of the protocols
need them. For instance, many elements of the library rely on the
Content-Length being correctly set. HTMIMEInit()
provides the minimal functionality needed for library reliabilty.
*/

#include "WWWMIME.h"
#include "WWWApp.h"

extern "C" void HTMIMEInit (void);

/*
.
  Default Event Manager
.

libwww core does not have any default event loop - it has to be added by
the application. However, it does come with an example implementation thta
may be used. This implementation is based on a select system
call using non-blocking and interleaved sockets.
*/

#include "WWWApp.h"

/*
.
  Default Media Type Conversions
.

The Converters are used to convert a media type to another media
type, or to present it on screen. This is a part of the stream stack algorithm.
The Presenters are also used in the stream stack, but are initialized separately.
*/

#include "WWWMIME.h"
#include "WWWHTML.h"
#include "WWWStream.h"
#include "WWWDir.h"
#include "WWWCache.h"

#ifdef HT_EXPAT
#include "WWWXML.h"
#endif

/*
.
  Default Transfer Encodings
.

Transfer encoders and decoders can handle encodings like chunked
etc.
*/
#include "WWWHTTP.h"

extern "C" void HTTransferEncoderInit	(HTList * encodings);

/*
.
  Default Content Encodings
.

Content encoders and decoders can handle encodings like deflate
etc.
*/
#include "WWWZip.h"

extern "C" void HTContentEncoderInit	(HTList * encodings);

/*
.
  Default BEFORE and AFTER Filters
.

This module provides a set of default BEFORE and AFTER filters
that can be registered by the Net manager to be
called before and after a request. All filters can be registered either to
be called globally (all requests) or locally (pr request basis).
Not done automaticly - may be done by application!
(
  BEFORE Filters
)

The BEFORE filters handle proxies, caches, rule
files etc. The filters are called in the order by which the are registered
*/
#include "WWWApp.h"

/*
.
  Default Access Authentication Modules
.

The Access Manager which is implemented as a
BEFORE and an AFTER filter (automatically registered in
HTNetInit()) does not by default know of any access authentication
schemes. As everything else, this must be registered! This function does
the job and should be all you need.
*/
extern void HTAAInit (void);

/*
.
  Default Icons for Directory Listings
.

The WWWDir interface contains support for including
references (URLs and ALT text tags) to icons in directory listings.
The icons are selected as a function of the media type and the content encoding
of the file in question. That is - you can set up icons for compressed files,
postscript files etc. There is also a small set of specific icons representing
directories etc.
*/
#include "WWWFile.h"

/*
*/

#endif
