#include "GU.h"

/*
Library GU - Graphic Unit to draw polygons in the video board
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifdef printMessages
#warning "            Inside GU.cpp"
#endif

/*
// Miscellaneous
void edk::guClearIndex( edk::GUfloat c ){ glClearIndex( c );edkEnd(); }
void edk::guClearColor( edk::GUclampf red, edk::GUclampf green, edk::GUclampf blue, edk::GUclampf alpha ){ glClearColor( red, green, blue, alpha );edkEnd(); }
void edk::guClear( edk::GUbitfield mask ){ glClear(mask);edkEnd(); }
void edk::guIndexMask( edk::GUuint mask ){ glIndexMask( mask );edkEnd(); }
void edk::guColorMask( edk::GUboolean red, edk::GUboolean green, edk::GUboolean blue, edk::GUboolean alpha ){ glColorMask( red, green, blue, alpha );edkEnd(); }
void edk::guAlphaFunc( edk::GUenum func, edk::GUclampf ref ){ glAlphaFunc( func, ref );edkEnd(); }
void edk::guBlendFunc( edk::GUenum sfactor, edk::GUenum dfactor ){ glBlendFunc( sfactor, dfactor );edkEnd(); }
void edk::guLogicOp( edk::GUenum opcode ){ glLogicOp( opcode );edkEnd(); }
void edk::guCullFace( edk::GUenum mode ){ glCullFace( mode );edkEnd(); }
void edk::guFrontFace( edk::GUenum mode ){ glFrontFace( mode );edkEnd(); }
void edk::guPointSize( edk::GUfloat size ){ glPointSize( size );edkEnd(); }
void edk::guLineWidth( edk::GUfloat width ){ glLineWidth( width );edkEnd(); }
void edk::guLineStipple( edk::GUint factor, edk::GUushort pattern ){ glLineStipple( factor, pattern );edkEnd(); }
void edk::guPolygonMode( edk::GUenum face, edk::GUenum mode ){ glPolygonMode( face, mode );edkEnd(); }
void edk::guPolygonOffset( edk::GUfloat factor, edk::GUfloat units ){ glPolygonOffset( factor, units );edkEnd(); }
void edk::guPolygonStipple( const edk::GUubyte *mask ){ glPolygonStipple( mask );edkEnd(); }
void edk::guGetPolygonStipple( edk::GUubyte *mask ){ glGetPolygonStipple( mask );edkEnd(); }
void edk::guEdgeFlag( edk::GUboolean flag ){ glEdgeFlag( flag );edkEnd(); }
void edk::guEdgeFlagv( const edk::GUboolean *flag ){ glEdgeFlagv( flag );edkEnd(); }
void edk::guScissor( edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height){ glScissor( x, y, width, height);edkEnd(); }
void edk::guClipPlane( edk::GUenum plane, const edk::GUdouble *equation ){ glClipPlane( plane, equation );edkEnd(); }
void edk::guGetClipPlane( edk::GUenum plane, edk::GUdouble* equation ){ glGetClipPlane( plane, equation );edkEnd(); }
void edk::guDrawBuffer( edk::GUenum mode ){ glDrawBuffer( mode );edkEnd(); }
void edk::guReadBuffer( edk::GUenum mode ){ glReadBuffer( mode );edkEnd(); }
void edk::guEnable( edk::GUenum cap ){ glEnable( cap );edkEnd(); }
void edk::guDisable( edk::GUenum cap ){ glDisable( cap );edkEnd(); }
edk::GUboolean edk::guIsEnabled( edk::GUenum cap ){ return (edk::GUboolean) glIsEnabled( cap );edkEnd();}
//using matrix
edk::GUboolean edk::guUsingMatrix(edk::GUenum mode){ return matrixMode==mode;edkEnd(); }
void edk::guEnableClientState( edk::GUenum cap ){ glEnableClientState( cap );edkEnd(); }
void edk::guDisableClientState( edk::GUenum cap ){ glDisableClientState( cap );edkEnd(); }
void edk::guGetBooleanv( edk::GUenum pname, edk::GUboolean *params ){ glGetBooleanv( pname, params );edkEnd(); }
void edk::guGetDoublev( edk::GUenum pname, edk::GUdouble *params ){ glGetDoublev( pname, params );edkEnd(); }
void edk::guGetFloatv( edk::GUenum pname, edk::GUfloat *params ){ glGetFloatv( pname, params );edkEnd(); }
void edk::guGetIntegerv( edk::GUenum pname, edk::GUint *params ){ glGetIntegerv( pname, params );edkEnd(); }
void edk::guPushAttrib( edk::GUbitfield mask ){ glPushAttrib( mask );edkEnd(); }
void edk::guPopAttrib(         void ){ glPopAttrib();edkEnd(); }
void edk::guPushClientAttrib( edk::GUbitfield mask ){ glPushClientAttrib( mask );edkEnd(); }
void edk::guPopClientAttrib(         void ){ glPopClientAttrib();edkEnd(); }
edk::GUint edk::guRenderMode( edk::GUenum mode ){return (edk::GUint)glRenderMode( mode );edkEnd();  }
edk::GUenum edk::guGetError( void ){ return (edk::GUenum )glGetError();edkEnd(); }
const edk::GUubyte* edk::guGetString( edk::GUenum name ){ return (const edk::GUubyte*)glGetString( name );edkEnd(); }
void edk::guFinish(         void ){ glFinish();edkEnd(); }
void edk::guFlush(         void ){ glFlush();edkEnd(); }
void edk::guHint( edk::GUenum target, edk::GUenum mode ){ glHint( target, mode );edkEnd(); }

// Depth Buffer
void edk::guClearDepth( edk::GUclampd depth ){ glClearDepth( depth );edkEnd(); }
void edk::guDepthFunc( edk::GUenum func ){ glDepthFunc( func );edkEnd(); }
void edk::guDepthMask( edk::GUboolean flag ){ glDepthMask( flag );edkEnd(); }
void edk::guDepthRange( edk::GUclampd near_val, edk::GUclampd far_val ){ glDepthRange( near_val, far_val );edkEnd(); }

// Accumulation Buffer
void edk::guClearAccum( edk::GUfloat red, edk::GUfloat green, edk::GUfloat blue, edk::GUfloat alpha ){ glClearAccum( red, green, blue, alpha );edkEnd(); }
void edk::guAccum( edk::GUenum op, edk::GUfloat value ){ glAccum( op, value );edkEnd(); }

// Transformation
void edk::guMatrixMode( edk::GUenum mode ){ glMatrixMode( mode );edkEnd(); matrixMode = mode;edkEnd(); }
void edk::guOrtho( edk::GUdouble left, edk::GUdouble right, edk::GUdouble bottom, edk::GUdouble top, edk::GUdouble near_val, edk::GUdouble far_val ){ glOrtho( left, right, bottom, top, near_val, far_val );edkEnd(); }
void edk::guFrustum( edk::GUdouble left, edk::GUdouble right, edk::GUdouble bottom, edk::GUdouble top, edk::GUdouble near_val, edk::GUdouble far_val ){ glFrustum( left, right, bottom, top, near_val, far_val );edkEnd(); }
void edk::guViewport( edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height ){ glViewport( x, y, width, height );edkEnd(); }
void edk::guPushMatrix( void ){ glPushMatrix();edkEnd(); }
void edk::guPopMatrix( void ){ glPopMatrix();edkEnd(); }
void edk::guLoadIdentity( void ){ glLoadIdentity();edkEnd(); }
void edk::guLoadMatrixd( const edk::GUdouble *m ){ glLoadMatrixd( m );edkEnd(); }
void edk::guLoadMatrixf( const edk::GUfloat *m ){ glLoadMatrixf( m );edkEnd(); }
void edk::guMultMatrixd( const edk::GUdouble *m ){ glMultMatrixd( m );edkEnd(); }
void edk::guMultMatrixf( const edk::GUfloat *m ){ glMultMatrixf( m );edkEnd(); }
void edk::guRotated( edk::GUdouble angle, edk::GUdouble x, edk::GUdouble y, edk::GUdouble z ){ glRotated( angle, x, y, z );edkEnd(); }
void edk::guRotatef( edk::GUfloat angle, edk::GUfloat x, edk::GUfloat y, edk::GUfloat z ){ glRotatef( angle, x, y, z );edkEnd(); }
void edk::guScaled( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z ){ glScaled( x, y, z );edkEnd(); }
void edk::guScalef( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z ){ glScalef( x, y, z );edkEnd(); }
void edk::guTranslated( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z ){ glTranslated( x, y, z );edkEnd(); }
void edk::guTranslatef( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z ){ glTranslatef( x, y, z );edkEnd(); }

// Display Lists
edk::GUboolean edk::guIsList( edk::GUuint list ){ return (edk::GUboolean)glIsList( list );edkEnd(); }
void edk::guDeleteLists( edk::GUuint list, edk::GUsizei range ){ glDeleteLists( list, range );edkEnd(); }
edk::GUuint edk::guGenLists( edk::GUsizei range ){return (edk::GUuint) glGenLists( range );edkEnd(); }
void edk::guNewList( edk::GUuint list, edk::GUenum mode ){ glNewList( list, mode );edkEnd(); }
void edk::guEndList(){ glEndList();edkEnd(); }
void edk::guCallList( edk::GUuint list ){ glCallList( list );edkEnd(); }
void edk::guCallLists(  edk::GUsizei n, edk::GUenum type, const edk::GUvoid *lists  ){ glCallLists(  n, type, lists  );edkEnd(); }
void edk::guListBase( edk::GUuint base ){ glListBase( base );edkEnd(); }

// Drawing Functions
void edk::guBegin( edk::GUenum mode ){ glBegin( mode );edkEnd(); }
void edk::guEnd(         void ){ glEnd();edkEnd(); }
void edk::guVertex2d( edk::GUdouble x, edk::GUdouble y ){ glVertex2d( x, y );edkEnd(); }
void edk::guVertex2f( edk::GUfloat x, edk::GUfloat y ){ glVertex2f( x, y );edkEnd(); }
void edk::guVertex2i( edk::GUint x, edk::GUint y ){ glVertex2i( x, y );edkEnd(); }
void edk::guVertex2s( edk::GUshort x, edk::GUshort y ){ glVertex2s( x, y );edkEnd(); }
void edk::guVertex3d( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z ){ glVertex3d( x, y, z );edkEnd(); }
void edk::guVertex3f( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z ){ glVertex3f( x, y, z );edkEnd(); }
void edk::guVertex3i( edk::GUint x, edk::GUint y, edk::GUint z ){ glVertex3i( x, y, z );edkEnd(); }
void edk::guVertex3s( edk::GUshort x, edk::GUshort y, edk::GUshort z ){ glVertex3s( x, y, z );edkEnd(); }
void edk::guVertex4d( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z, edk::GUdouble w ){ glVertex4d( x, y, z, w );edkEnd(); }
void edk::guVertex4f( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z, edk::GUfloat w ){ glVertex4f( x, y, z, w );edkEnd(); }
void edk::guVertex4i( edk::GUint x, edk::GUint y, edk::GUint z, edk::GUint w ){ glVertex4i( x, y, z, w );edkEnd(); }
void edk::guVertex4s( edk::GUshort x, edk::GUshort y, edk::GUshort z, edk::GUshort w ){ glVertex4s( x, y, z, w );edkEnd(); }
void edk::guVertex2dv( const edk::GUdouble *v ){ glVertex2dv( v );edkEnd(); }
void edk::guVertex2fv( const edk::GUfloat *v ){ glVertex2fv( v );edkEnd(); }
void edk::guVertex2iv( const edk::GUint *v ){ glVertex2iv( v );edkEnd(); }
void edk::guVertex2sv( const edk::GUshort *v ){ glVertex2sv( v );edkEnd(); }
void edk::guVertex3dv( const edk::GUdouble *v ){ glVertex3dv( v );edkEnd(); }
void edk::guVertex3fv( const edk::GUfloat *v ){ glVertex3fv( v );edkEnd(); }
void edk::guVertex3iv( const edk::GUint *v ){ glVertex3iv( v );edkEnd(); }
void edk::guVertex3sv( const edk::GUshort *v ){ glVertex3sv( v );edkEnd(); }
void edk::guVertex4dv( const edk::GUdouble *v ){ glVertex4dv( v );edkEnd(); }
void edk::guVertex4fv( const edk::GUfloat *v ){ glVertex4fv( v );edkEnd(); }
void edk::guVertex4iv( const edk::GUint *v ){ glVertex4iv( v );edkEnd(); }
void edk::guVertex4sv( const edk::GUshort *v ){ glVertex4sv( v );edkEnd(); }
void edk::guNormal3b( edk::GUbyte nx, edk::GUbyte ny, edk::GUbyte nz ){ glNormal3b( nx, ny, nz );edkEnd(); }
void edk::guNormal3d( edk::GUdouble nx, edk::GUdouble ny, edk::GUdouble nz ){ glNormal3d( nx, ny, nz );edkEnd(); }
void edk::guNormal3f( edk::GUfloat nx, edk::GUfloat ny, edk::GUfloat nz ){ glNormal3f( nx, ny, nz );edkEnd(); }
void edk::guNormal3i( edk::GUint nx, edk::GUint ny, edk::GUint nz ){ glNormal3i( nx, ny, nz );edkEnd(); }
void edk::guNormal3s( edk::GUshort nx, edk::GUshort ny, edk::GUshort nz ){ glNormal3s( nx, ny, nz );edkEnd(); }
void edk::guNormal3bv( const edk::GUbyte *v ){ glNormal3bv( v );edkEnd(); }
void edk::guNormal3dv( const edk::GUdouble *v ){ glNormal3dv( v );edkEnd(); }
void edk::guNormal3fv( const edk::GUfloat *v ){ glNormal3fv( v );edkEnd(); }
void edk::guNormal3iv( const edk::GUint *v ){ glNormal3iv( v );edkEnd(); }
void edk::guNormal3sv( const edk::GUshort *v ){ glNormal3sv( v );edkEnd(); }
void edk::guIndexd( edk::GUdouble c ){ glIndexd( c );edkEnd(); }
void edk::guIndexf( edk::GUfloat c ){ glIndexf( c );edkEnd(); }
void edk::guIndexi( edk::GUint c ){ glIndexi( c );edkEnd(); }
void edk::guIndexs( edk::GUshort c ){ glIndexs( c );edkEnd(); }
void edk::guIndexub( edk::GUubyte c ){ glIndexub( c );edkEnd(); }
void edk::guIndexdv( const edk::GUdouble *c ){ glIndexdv( c );edkEnd(); }
void edk::guIndexfv( const edk::GUfloat *c ){ glIndexfv( c );edkEnd(); }
void edk::guIndexiv( const edk::GUint *c ){ glIndexiv( c );edkEnd(); }
void edk::guIndexsv( const edk::GUshort *c ){ glIndexsv( c );edkEnd(); }
void edk::guIndexubv( const edk::GUubyte *c ){ glIndexubv( c );edkEnd(); }
void edk::guColor3b( edk::GUbyte red, edk::GUbyte green, edk::GUbyte blue ){ glColor3b( red, green, blue );edkEnd(); }
void edk::guColor3d( edk::GUdouble red, edk::GUdouble green, edk::GUdouble blue ){ glColor3d( red, green, blue );edkEnd(); }
void edk::guColor3f( edk::GUfloat red, edk::GUfloat green, edk::GUfloat blue ){ glColor3f( red, green, blue );edkEnd(); }
void edk::guColor3i( edk::GUint red, edk::GUint green, edk::GUint blue ){ glColor3i( red, green, blue );edkEnd(); }
void edk::guColor3s( edk::GUshort red, edk::GUshort green, edk::GUshort blue ){ glColor3s( red, green, blue );edkEnd(); }
void edk::guColor3ub( edk::GUubyte red, edk::GUubyte green, edk::GUubyte blue ){ glColor3ub( red, green, blue );edkEnd(); }
void edk::guColor3ui( edk::GUuint red, edk::GUuint green, edk::GUuint blue ){ glColor3ui( red, green, blue );edkEnd(); }
void edk::guColor3us( edk::GUushort red, edk::GUushort green, edk::GUushort blue ){ glColor3us( red, green, blue );edkEnd(); }
void edk::guColor4b( edk::GUbyte red, edk::GUbyte green, edk::GUbyte blue, edk::GUbyte alpha ){ glColor4b( red, green, blue, alpha );edkEnd(); }
void edk::guColor4d( edk::GUdouble red, edk::GUdouble green, edk::GUdouble blue, edk::GUdouble alpha ){ glColor4d( red, green, blue, alpha );edkEnd(); }
void edk::guColor4f( edk::GUfloat red, edk::GUfloat green, edk::GUfloat blue, edk::GUfloat alpha ){ glColor4f( red, green, blue, alpha );edkEnd(); }
void edk::guColor4i( edk::GUint red, edk::GUint green, edk::GUint blue, edk::GUint alpha ){ glColor4i( red, green, blue, alpha );edkEnd(); }
void edk::guColor4s( edk::GUshort red, edk::GUshort green, edk::GUshort blue, edk::GUshort alpha ){ glColor4s( red, green, blue, alpha );edkEnd(); }
void edk::guColor4ub( edk::GUubyte red, edk::GUubyte green, edk::GUubyte blue, edk::GUubyte alpha ){ glColor4ub( red, green, blue, alpha );edkEnd(); }
void edk::guColor4ui( edk::GUuint red, edk::GUuint green, edk::GUuint blue, edk::GUuint alpha ){ glColor4ui( red, green, blue, alpha );edkEnd(); }
void edk::guColor4us( edk::GUushort red, edk::GUushort green, edk::GUushort blue, edk::GUushort alpha ){ glColor4us( red, green, blue, alpha );edkEnd(); }
void edk::guColor3bv( const edk::GUbyte *v ){ glColor3bv( v );edkEnd(); }
void edk::guColor3dv( const edk::GUdouble *v ){ glColor3dv( v );edkEnd(); }
void edk::guColor3fv( const edk::GUfloat *v ){ glColor3fv( v );edkEnd(); }
void edk::guColor3iv( const edk::GUint *v ){ glColor3iv( v );edkEnd(); }
void edk::guColor3sv( const edk::GUshort *v ){ glColor3sv( v );edkEnd(); }
void edk::guColor3ubv( const edk::GUubyte *v ){ glColor3ubv( v );edkEnd(); }
void edk::guColor3uiv( const edk::GUuint *v ){ glColor3uiv( v );edkEnd(); }
void edk::guColor3usv( const edk::GUushort *v ){ glColor3usv( v );edkEnd(); }
void edk::guColor4bv( const edk::GUbyte *v ){ glColor4bv( v );edkEnd(); }
void edk::guColor4dv( const edk::GUdouble *v ){ glColor4dv( v );edkEnd(); }
void edk::guColor4fv( const edk::GUfloat *v ){ glColor4fv( v );edkEnd(); }
void edk::guColor4iv( const edk::GUint *v ){ glColor4iv( v );edkEnd(); }
void edk::guColor4sv( const edk::GUshort *v ){ glColor4sv( v );edkEnd(); }
void edk::guColor4ubv( const edk::GUubyte *v ){ glColor4ubv( v );edkEnd(); }
void edk::guColor4uiv( const edk::GUuint *v ){ glColor4uiv( v );edkEnd(); }
void edk::guColor4usv( const edk::GUushort *v ){ glColor4usv( v );edkEnd(); }
void edk::guTexCoord1d( edk::GUdouble s ){ glTexCoord1d( s );edkEnd(); }
void edk::guTexCoord1f( edk::GUfloat s ){ glTexCoord1f( s );edkEnd(); }
void edk::guTexCoord1i( edk::GUint s ){ glTexCoord1i( s );edkEnd(); }
void edk::guTexCoord1s( edk::GUshort s ){ glTexCoord1s( s );edkEnd(); }
void edk::guTexCoord2d( edk::GUdouble s, edk::GUdouble t ){ glTexCoord2d( s, t );edkEnd(); }
void edk::guTexCoord2f( edk::GUfloat s, edk::GUfloat t ){ glTexCoord2f( s, t );edkEnd(); }
void edk::guTexCoord2i( edk::GUint s, edk::GUint t ){ glTexCoord2i( s, t );edkEnd(); }
void edk::guTexCoord2s( edk::GUshort s, edk::GUshort t ){ glTexCoord2s( s, t );edkEnd(); }
void edk::guTexCoord3d( edk::GUdouble s, edk::GUdouble t, edk::GUdouble r ){ glTexCoord3d( s, t, r );edkEnd(); }
void edk::guTexCoord3f( edk::GUfloat s, edk::GUfloat t, edk::GUfloat r ){ glTexCoord3f( s, t, r );edkEnd(); }
void edk::guTexCoord3i( edk::GUint s, edk::GUint t, edk::GUint r ){ glTexCoord3i( s, t, r );edkEnd(); }
void edk::guTexCoord3s( edk::GUshort s, edk::GUshort t, edk::GUshort r ){ glTexCoord3s( s, t, r );edkEnd(); }
void edk::guTexCoord4d( edk::GUdouble s, edk::GUdouble t, edk::GUdouble r, edk::GUdouble q ){ glTexCoord4d( s, t, r, q );edkEnd(); }
void edk::guTexCoord4f( edk::GUfloat s, edk::GUfloat t, edk::GUfloat r, edk::GUfloat q ){ glTexCoord4f( s, t, r, q );edkEnd(); }
void edk::guTexCoord4i( edk::GUint s, edk::GUint t, edk::GUint r, edk::GUint q ){ glTexCoord4i( s, t, r, q );edkEnd(); }
void edk::guTexCoord4s( edk::GUshort s, edk::GUshort t, edk::GUshort r, edk::GUshort q ){ glTexCoord4s( s, t, r, q );edkEnd(); }
void edk::guTexCoord1dv( const edk::GUdouble *v ){ glTexCoord1dv( v );edkEnd(); }
void edk::guTexCoord1fv( const edk::GUfloat *v ){ glTexCoord1fv( v );edkEnd(); }
void edk::guTexCoord1iv( const edk::GUint *v ){ glTexCoord1iv( v );edkEnd(); }
void edk::guTexCoord1sv( const edk::GUshort *v ){ glTexCoord1sv( v );edkEnd(); }
void edk::guTexCoord2dv( const edk::GUdouble *v ){ glTexCoord2dv( v );edkEnd(); }
void edk::guTexCoord2fv( const edk::GUfloat *v ){ glTexCoord2fv( v );edkEnd(); }
void edk::guTexCoord2iv( const edk::GUint *v ){ glTexCoord2iv( v );edkEnd(); }
void edk::guTexCoord2sv( const edk::GUshort *v ){ glTexCoord2sv( v );edkEnd(); }
void edk::guTexCoord3dv( const edk::GUdouble *v ){ glTexCoord3dv( v );edkEnd(); }
void edk::guTexCoord3fv( const edk::GUfloat *v ){ glTexCoord3fv( v );edkEnd(); }
void edk::guTexCoord3iv( const edk::GUint *v ){ glTexCoord3iv( v );edkEnd(); }
void edk::guTexCoord3sv( const edk::GUshort *v ){ glTexCoord3sv( v );edkEnd(); }
void edk::guTexCoord4dv( const edk::GUdouble *v ){ glTexCoord4dv( v );edkEnd(); }
void edk::guTexCoord4fv( const edk::GUfloat *v ){ glTexCoord4fv( v );edkEnd(); }
void edk::guTexCoord4iv( const edk::GUint *v ){ glTexCoord4iv( v );edkEnd(); }
void edk::guTexCoord4sv( const edk::GUshort *v ){ glTexCoord4sv( v );edkEnd(); }
void edk::guRasterPos2d( edk::GUdouble x, edk::GUdouble y ){ glRasterPos2d( x, y );edkEnd(); }
void edk::guRasterPos2f( edk::GUfloat x, edk::GUfloat y ){ glRasterPos2f( x, y );edkEnd(); }
void edk::guRasterPos2i( edk::GUint x, edk::GUint y ){ glRasterPos2i( x, y );edkEnd(); }
void edk::guRasterPos2s( edk::GUshort x, edk::GUshort y ){ glRasterPos2s( x, y );edkEnd(); }
void edk::guRasterPos3d( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z ){ glRasterPos3d( x, y, z );edkEnd(); }
void edk::guRasterPos3f( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z ){ glRasterPos3f( x, y, z );edkEnd(); }
void edk::guRasterPos3i( edk::GUint x, edk::GUint y, edk::GUint z ){ glRasterPos3i( x, y, z );edkEnd(); }
void edk::guRasterPos3s( edk::GUshort x, edk::GUshort y, edk::GUshort z ){ glRasterPos3s( x, y, z );edkEnd(); }
void edk::guRasterPos4d( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z, edk::GUdouble w ){ glRasterPos4d( x, y, z, w );edkEnd(); }
void edk::guRasterPos4f( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z, edk::GUfloat w ){ glRasterPos4f( x, y, z, w );edkEnd(); }
void edk::guRasterPos4i( edk::GUint x, edk::GUint y, edk::GUint z, edk::GUint w ){ glRasterPos4i( x, y, z, w );edkEnd(); }
void edk::guRasterPos4s( edk::GUshort x, edk::GUshort y, edk::GUshort z, edk::GUshort w ){ glRasterPos4s( x, y, z, w );edkEnd(); }
void edk::guRasterPos2dv( const edk::GUdouble *v ){ glRasterPos2dv( v );edkEnd(); }
void edk::guRasterPos2fv( const edk::GUfloat *v ){ glRasterPos2fv( v );edkEnd(); }
void edk::guRasterPos2iv( const edk::GUint *v ){ glRasterPos2iv( v );edkEnd(); }
void edk::guRasterPos2sv( const edk::GUshort *v ){ glRasterPos2sv( v );edkEnd(); }
void edk::guRasterPos3dv( const edk::GUdouble *v ){ glRasterPos3dv( v );edkEnd(); }
void edk::guRasterPos3fv( const edk::GUfloat *v ){ glRasterPos3fv( v );edkEnd(); }
void edk::guRasterPos3iv( const edk::GUint *v ){ glRasterPos3iv( v );edkEnd(); }
void edk::guRasterPos3sv( const edk::GUshort *v ){ glRasterPos3sv( v );edkEnd(); }
void edk::guRasterPos4dv( const edk::GUdouble *v ){ glRasterPos4dv( v );edkEnd(); }
void edk::guRasterPos4fv( const edk::GUfloat *v ){ glRasterPos4fv( v );edkEnd(); }
void edk::guRasterPos4iv( const edk::GUint *v ){ glRasterPos4iv( v );edkEnd(); }
void edk::guRasterPos4sv( const edk::GUshort *v ){ glRasterPos4sv( v );edkEnd(); }
void edk::guRectd( edk::GUdouble x1, edk::GUdouble y1, edk::GUdouble x2, edk::GUdouble y2 ){ glRectd( x1, y1, x2, y2 );edkEnd(); }
void edk::guRectf( edk::GUfloat x1, edk::GUfloat y1, edk::GUfloat x2, edk::GUfloat y2 ){ glRectf( x1, y1, x2, y2 );edkEnd(); }
void edk::guRecti( edk::GUint x1, edk::GUint y1, edk::GUint x2, edk::GUint y2 ){ glRecti( x1, y1, x2, y2 );edkEnd(); }
void edk::guRects( edk::GUshort x1, edk::GUshort y1, edk::GUshort x2, edk::GUshort y2 ){ glRects( x1, y1, x2, y2 );edkEnd(); }
void edk::guRectdv( const edk::GUdouble *v1, const edk::GUdouble *v2 ){ glRectdv( v1, v2 );edkEnd(); }
void edk::guRectfv( const edk::GUfloat *v1, const edk::GUfloat *v2 ){ glRectfv( v1, v2 );edkEnd(); }
void edk::guRectiv( const edk::GUint *v1, const edk::GUint *v2 ){ glRectiv( v1, v2 );edkEnd(); }
void edk::guRectsv( const edk::GUshort *v1, const edk::GUshort *v2 ){ glRectsv( v1, v2 );edkEnd(); }

// Lighting
void edk::guShadeModel( edk::GUenum mode ){ glShadeModel( mode );edkEnd(); }
void edk::guLightf( edk::GUenum light, edk::GUenum pname, edk::GUfloat param ){ glLightf( light, pname, param );edkEnd(); }
void edk::guLighti( edk::GUenum light, edk::GUenum pname, edk::GUint param ){ glLighti( light, pname, param );edkEnd(); }
void edk::guLightfv( edk::GUenum light, edk::GUenum pname, const edk::GUfloat *params ){ glLightfv( light, pname, params );edkEnd(); }
void edk::guLightiv( edk::GUenum light, edk::GUenum pname, const edk::GUint *params ){ glLightiv( light, pname, params );edkEnd(); }
void edk::guGetLightfv( edk::GUenum light, edk::GUenum pname, edk::GUfloat *params ){ glGetLightfv( light, pname, params );edkEnd(); }
void edk::guGetLightiv( edk::GUenum light, edk::GUenum pname, edk::GUint *params ){ glGetLightiv( light, pname, params );edkEnd(); }
void edk::guLightModelf( edk::GUenum pname, edk::GUfloat param ){ glLightModelf( pname, param );edkEnd(); }
void edk::guLightModeli( edk::GUenum pname, edk::GUint param ){ glLightModeli( pname, param );edkEnd(); }
void edk::guLightModelfv( edk::GUenum pname, const edk::GUfloat *params ){ glLightModelfv( pname, params );edkEnd(); }
void edk::guLightModeliv( edk::GUenum pname, const edk::GUint *params ){ glLightModeliv( pname, params );edkEnd(); }
void edk::guMaterialf( edk::GUenum face, edk::GUenum pname, edk::GUfloat param ){ glMaterialf( face, pname, param );edkEnd(); }
void edk::guMateriali( edk::GUenum face, edk::GUenum pname, edk::GUint param ){ glMateriali( face, pname, param );edkEnd(); }
void edk::guMaterialfv( edk::GUenum face, edk::GUenum pname, const edk::GUfloat *params ){ glMaterialfv( face, pname, params );edkEnd(); }
void edk::guMaterialiv( edk::GUenum face, edk::GUenum pname, const edk::GUint *params ){ glMaterialiv( face, pname, params );edkEnd(); }
void edk::guGetMaterialfv( edk::GUenum face, edk::GUenum pname, edk::GUfloat *params ){ glGetMaterialfv( face, pname, params );edkEnd(); }
void edk::guGetMaterialiv( edk::GUenum face, edk::GUenum pname, edk::GUint *params ){ glGetMaterialiv( face, pname, params );edkEnd(); }
void edk::guColorMaterial( edk::GUenum face, edk::GUenum mode ){ glColorMaterial( face, mode );edkEnd(); }

// Raster functions
void edk::guPixelZoom( edk::GUfloat xfactor, edk::GUfloat yfactor ){ glPixelZoom( xfactor, yfactor );edkEnd(); }
void edk::guPixelStoref( edk::GUenum pname, edk::GUfloat param ){ glPixelStoref( pname, param );edkEnd(); }
void edk::guPixelStorei( edk::GUenum pname, edk::GUint param ){ glPixelStorei( pname, param );edkEnd(); }
void edk::guPixelTransferf( edk::GUenum pname, edk::GUfloat param ){ glPixelTransferf( pname, param );edkEnd(); }
void edk::guPixelTransferi( edk::GUenum pname, edk::GUint param ){ glPixelTransferi( pname, param );edkEnd(); }
void edk::guPixelMapfv( edk::GUenum map, edk::GUint mapsize, const edk::GUfloat *values ){ glPixelMapfv( map, mapsize, values );edkEnd(); }
void edk::guPixelMapuiv( edk::GUenum map, edk::GUint mapsize, const edk::GUuint *values ){ glPixelMapuiv( map, mapsize, values );edkEnd(); }
void edk::guPixelMapusv( edk::GUenum map, edk::GUint mapsize, const edk::GUushort *values ){ glPixelMapusv( map, mapsize, values );edkEnd(); }
void edk::guGetPixelMapfv( edk::GUenum map, edk::GUfloat *values ){ glGetPixelMapfv( map, values );edkEnd(); }
void edk::guGetPixelMapuiv( edk::GUenum map, edk::GUuint *values ){ glGetPixelMapuiv( map, values );edkEnd(); }
void edk::guGetPixelMapusv( edk::GUenum map, edk::GUushort *values ){ glGetPixelMapusv( map, values );edkEnd(); }
void edk::guBitmap( edk::GUsizei width, edk::GUsizei height, edk::GUfloat xorig, edk::GUfloat yorig, edk::GUfloat xmove, edk::GUfloat ymove, const edk::GUubyte *bitmap ){ glBitmap( width, height, xorig, yorig, xmove, ymove, bitmap );edkEnd(); }
void edk::guReadPixels( edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, edk::GUvoid *pixels ){ glReadPixels( x, y, width, height, format, type, pixels );edkEnd(); }
void edk::guDrawPixels( edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels ){ glDrawPixels( width, height, format, type, pixels );edkEnd(); }
void edk::guCopyPixels( edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height, edk::GUenum type ){ glCopyPixels( x, y, width, height, type );edkEnd(); }

// Stenciling
void edk::guStencilFunc( edk::GUenum func, edk::GUint ref, edk::GUuint mask ){ glStencilFunc( func, ref, mask );edkEnd(); }
void edk::guStencilMask( edk::GUuint mask ){ glStencilMask( mask );edkEnd(); }
void edk::guStencilOp( edk::GUenum fail, edk::GUenum zfail, edk::GUenum zpass ){ glStencilOp( fail, zfail, zpass );edkEnd(); }
void edk::guClearStencil( edk::GUint s ){ glClearStencil( s );edkEnd(); }

// Texture mapping
void edk::guTexGend( edk::GUenum coord, edk::GUenum pname, edk::GUdouble param ){ glTexGend( coord, pname, param );edkEnd(); }
void edk::guTexGenf( edk::GUenum coord, edk::GUenum pname, edk::GUfloat param ){ glTexGenf( coord, pname, param );edkEnd(); }
void edk::guTexGeni( edk::GUenum coord, edk::GUenum pname, edk::GUint param ){ glTexGeni( coord, pname, param );edkEnd(); }
void edk::guTexGendv( edk::GUenum coord, edk::GUenum pname, const edk::GUdouble *params ){ glTexGendv( coord, pname, params );edkEnd(); }
void edk::guTexGenfv( edk::GUenum coord, edk::GUenum pname, const edk::GUfloat *params ){ glTexGenfv( coord, pname, params );edkEnd(); }
void edk::guTexGeniv( edk::GUenum coord, edk::GUenum pname, const edk::GUint *params ){ glTexGeniv( coord, pname, params );edkEnd(); }
void edk::guGetTexGendv( edk::GUenum coord, edk::GUenum pname, edk::GUdouble *params ){ glGetTexGendv( coord, pname, params );edkEnd(); }
void edk::guGetTexGenfv( edk::GUenum coord, edk::GUenum pname, edk::GUfloat *params ){ glGetTexGenfv( coord, pname, params );edkEnd(); }
void edk::guGetTexGeniv( edk::GUenum coord, edk::GUenum pname, edk::GUint *params ){ glGetTexGeniv( coord, pname, params );edkEnd(); }
void edk::guTexEnvf( edk::GUenum target, edk::GUenum pname, edk::GUfloat param ){ glTexEnvf( target, pname, param );edkEnd(); }
void edk::guTexEnvi( edk::GUenum target, edk::GUenum pname, edk::GUint param ){ glTexEnvi( target, pname, param );edkEnd(); }
void edk::guTexEnvfv( edk::GUenum target, edk::GUenum pname, const edk::GUfloat *params ){ glTexEnvfv( target, pname, params );edkEnd(); }
void edk::guTexEnviv( edk::GUenum target, edk::GUenum pname, const edk::GUint *params ){ glTexEnviv( target, pname, params );edkEnd(); }
void edk::guGetTexEnvfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params ){ glGetTexEnvfv( target, pname, params );edkEnd(); }
void edk::guGetTexEnviv( edk::GUenum target, edk::GUenum pname, edk::GUint *params ){ glGetTexEnviv( target, pname, params );edkEnd(); }
void edk::guTexParameterf( edk::GUenum target, edk::GUenum pname, edk::GUfloat param ){ glTexParameterf( target, pname, param );edkEnd(); }
void edk::guTexParameteri( edk::GUenum target, edk::GUenum pname, edk::GUint param ){ glTexParameteri( target, pname, param );edkEnd(); }
void edk::guTexParameterfv( edk::GUenum target, edk::GUenum pname, const edk::GUfloat *params ){ glTexParameterfv( target, pname, params );edkEnd(); }
void edk::guTexParameteriv( edk::GUenum target, edk::GUenum pname, const edk::GUint *params ){ glTexParameteriv( target, pname, params );edkEnd(); }
void edk::guGetTexParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params){ glGetTexParameterfv( target, pname, params);edkEnd(); }
void edk::guGetTexParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params ){ glGetTexParameteriv( target, pname, params );edkEnd(); }
void edk::guGetTexLevelParameterfv( edk::GUenum target, edk::GUint level, edk::GUenum pname, edk::GUfloat *params ){ glGetTexLevelParameterfv( target, level, pname, params );edkEnd(); }
void edk::guGetTexLevelParameteriv( edk::GUenum target, edk::GUint level, edk::GUenum pname, edk::GUint *params ){ glGetTexLevelParameteriv( target, level, pname, params );edkEnd(); }
void edk::guTexImage1D( edk::GUenum target, edk::GUint level, edk::GUint internalFormat, edk::GUsizei width, edk::GUint border, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels ){ glTexImage1D( target, level, internalFormat, width, border, format, type, pixels );edkEnd(); }
void edk::guTexImage2D( edk::GUenum target, edk::GUint level, edk::GUint internalFormat, edk::GUsizei width, edk::GUsizei height, edk::GUint border, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels ){ glTexImage2D( target, level, internalFormat, width, height, border, format, type, pixels );edkEnd(); }
void edk::guGetTexImage( edk::GUenum target, edk::GUint level, edk::GUenum format, edk::GUenum type, edk::GUvoid *pixels ){ glGetTexImage( target, level, format, type, pixels );edkEnd(); }

// Evaluators
void edk::guMap1d( edk::GUenum target, edk::GUdouble u1, edk::GUdouble u2, edk::GUint stride, edk::GUint order, const edk::GUdouble *points ){ glMap1d( target, u1, u2, stride, order, points );edkEnd(); }
void edk::guMap1f( edk::GUenum target, edk::GUfloat u1, edk::GUfloat u2, edk::GUint stride, edk::GUint order, const edk::GUfloat *points ){ glMap1f( target, u1, u2, stride, order, points );edkEnd(); }
void edk::guMap2d( edk::GUenum target, edk::GUdouble u1, edk::GUdouble u2, edk::GUint ustride, edk::GUint uorder, edk::GUdouble v1, edk::GUdouble v2, edk::GUint vstride, edk::GUint vorder, const edk::GUdouble *points ){ glMap2d( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points );edkEnd(); }
void edk::guMap2f( edk::GUenum target, edk::GUfloat u1, edk::GUfloat u2, edk::GUint ustride, edk::GUint uorder, edk::GUfloat v1, edk::GUfloat v2, edk::GUint vstride, edk::GUint vorder, const edk::GUfloat *points ){ glMap2f( target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points );edkEnd(); }
void edk::guGetMapdv( edk::GUenum target, edk::GUenum query, edk::GUdouble *v ){ glGetMapdv( target, query, v );edkEnd(); }
void edk::guGetMapfv( edk::GUenum target, edk::GUenum query, edk::GUfloat *v ){ glGetMapfv( target, query, v );edkEnd(); }
void edk::guGetMapiv( edk::GUenum target, edk::GUenum query, edk::GUint *v ){ glGetMapiv( target, query, v );edkEnd(); }
void edk::guEvalCoord1d( edk::GUdouble u ){ glEvalCoord1d( u );edkEnd(); }
void edk::guEvalCoord1f( edk::GUfloat u ){ glEvalCoord1f( u );edkEnd(); }
void edk::guEvalCoord1dv( const edk::GUdouble *u ){ glEvalCoord1dv( u );edkEnd(); }
void edk::guEvalCoord1fv( const edk::GUfloat *u ){ glEvalCoord1fv( u );edkEnd(); }
void edk::guEvalCoord2d( edk::GUdouble u, edk::GUdouble v ){ glEvalCoord2d( u, v );edkEnd(); }
void edk::guEvalCoord2f( edk::GUfloat u, edk::GUfloat v ){ glEvalCoord2f( u, v );edkEnd(); }
void edk::guEvalCoord2dv( const edk::GUdouble *u ){ glEvalCoord2dv( u );edkEnd(); }
void edk::guEvalCoord2fv( const edk::GUfloat *u ){ glEvalCoord2fv( u );edkEnd(); }
void edk::guMapGrid1d( edk::GUint un, edk::GUdouble u1, edk::GUdouble u2 ){ glMapGrid1d( un, u1, u2 );edkEnd(); }
void edk::guMapGrid1f( edk::GUint un, edk::GUfloat u1, edk::GUfloat u2 ){ glMapGrid1f( un, u1, u2 );edkEnd(); }
void edk::guMapGrid2d( edk::GUint un, edk::GUdouble u1, edk::GUdouble u2, edk::GUint vn, edk::GUdouble v1, edk::GUdouble v2 ){ glMapGrid2d( un, u1, u2, vn, v1, v2 );edkEnd(); }
void edk::guMapGrid2f( edk::GUint un, edk::GUfloat u1, edk::GUfloat u2, edk::GUint vn, edk::GUfloat v1, edk::GUfloat v2 ){ glMapGrid2f( un, u1, u2, vn, v1, v2 );edkEnd(); }
void edk::guEvalPoint1( edk::GUint i ){ glEvalPoint1( i );edkEnd(); }
void edk::guEvalPoint2( edk::GUint i, edk::GUint j ){ glEvalPoint2( i, j );edkEnd(); }
void edk::guEvalMesh1( edk::GUenum mode, edk::GUint i1, edk::GUint i2 ){ glEvalMesh1( mode, i1, i2 );edkEnd(); }
void edk::guEvalMesh2( edk::GUenum mode, edk::GUint i1, edk::GUint i2, edk::GUint j1, edk::GUint j2 ){ glEvalMesh2( mode, i1, i2, j1, j2 );edkEnd(); }

// Fog
void edk::guFogf( edk::GUenum pname, edk::GUfloat param ){ glFogf( pname, param );edkEnd(); }
void edk::guFogi( edk::GUenum pname, edk::GUint param ){ glFogi( pname, param );edkEnd(); }
void edk::guFogfv( edk::GUenum pname, const edk::GUfloat *params ){ glFogfv( pname, params );edkEnd(); }
void edk::guFogiv( edk::GUenum pname, const edk::GUint *params ){ glFogiv( pname, params );edkEnd(); }

// Selection and Feedback
void edk::guFeedbackBuffer( edk::GUsizei size, edk::GUenum type, edk::GUfloat *buffer ){ glFeedbackBuffer( size, type, buffer );edkEnd(); }
void edk::guPassThrough( edk::GUfloat token ){ glPassThrough( token );edkEnd(); }
void edk::guSelectBuffer( edk::GUsizei size, edk::GUuint *buffer ){ glSelectBuffer( size, buffer );edkEnd(); }
void edk::guInitNames( void ){ glInitNames();edkEnd(); }
void edk::guLoadName( edk::GUuint name ){ glLoadName( name );edkEnd(); }
void edk::guPushName( edk::GUuint name ){ glPushName( name );edkEnd(); }
void edk::guPopName( void ){ glPopName( );edkEnd(); }


// 1.1 functions
// texture objects
void edk::guGenTextures( edk::GUsizei n, edk::GUuint *textures ){ glGenTextures( n, textures );edkEnd(); }
void edk::guDeleteTextures( edk::GUsizei n, const edk::GUuint *textures){ glDeleteTextures( n, textures);edkEnd(); }
void edk::guBindTexture( edk::GUenum target, edk::GUuint texture ){ glBindTexture( target, texture );edkEnd(); }
void edk::guPrioritizeTextures( edk::GUsizei n, const edk::GUuint *textures, const edk::GUclampf *priorities ){ glPrioritizeTextures( n, textures, priorities );edkEnd(); }
edk::GUboolean edk::guAreTexturesResident( edk::GUsizei n, const edk::GUuint *textures, edk::GUboolean *residences ){ return (edk::GUboolean )glAreTexturesResident( n, textures, residences );edkEnd(); }
edk::GUboolean edk::guIsTexture( edk::GUuint texture ){ return (edk::GUboolean)glIsTexture( texture );edkEnd(); }
// texture mapping
void edk::guTexSubImage1D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUsizei width, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels ){ glTexSubImage1D( target, level, xoffset, width, format, type, pixels );edkEnd(); }
void edk::guTexSubImage2D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels ){ glTexSubImage2D( target, level, xoffset, yoffset, width, height, format, type, pixels );edkEnd(); }
void edk::guCopyTexImage1D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUint border ){ glCopyTexImage1D( target, level, internalformat, x, y, width, border );edkEnd(); }
void edk::guCopyTexImage2D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height, edk::GUint border ){ glCopyTexImage2D( target, level, internalformat, x, y, width, height, border );edkEnd(); }
void edk::guCopyTexSubImage1D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint x, edk::GUint y, edk::GUsizei width ){ glCopyTexSubImage1D( target, level, xoffset, x, y, width );edkEnd(); }
void edk::guCopyTexSubImage2D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height ){ glCopyTexSubImage2D( target, level, xoffset, yoffset, x, y, width, height );edkEnd(); }
// vertex arrays
void edk::guVertexPointer( edk::GUint size, edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr ){ glVertexPointer( size, type, stride, ptr );edkEnd(); }
void edk::guNormalPointer( edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr ){ glNormalPointer( type, stride, ptr );edkEnd(); }
void edk::guColorPointer( edk::GUint size, edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr ){ glColorPointer( size, type, stride, ptr );edkEnd(); }
void edk::guIndexPointer( edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr ){ glIndexPointer( type, stride, ptr );edkEnd(); }
void edk::guTexCoordPointer( edk::GUint size, edk::GUenum type, edk::GUsizei stride, const edk::GUvoid *ptr ){ glTexCoordPointer( size, type, stride, ptr );edkEnd(); }
void edk::guEdgeFlagPointer( edk::GUsizei stride, const edk::GUvoid *ptr ){ glEdgeFlagPointer( stride, ptr );edkEnd(); }
void edk::guGetPointerv( edk::GUenum pname, edk::GUvoid **params ){ glGetPointerv( pname, params );edkEnd(); }
void edk::guArrayElement( edk::GUint i ){ glArrayElement( i );edkEnd(); }
void edk::guDrawArrays( edk::GUenum mode, edk::GUint first, edk::GUsizei count ){ glDrawArrays( mode, first, count );edkEnd(); }
void edk::guDrawElements( edk::GUenum mode, edk::GUsizei count, edk::GUenum type, const edk::GUvoid *indices ){ glDrawElements( mode, count, type, indices );edkEnd(); }
void edk::guInterleavedArrays( edk::GUenum format, edk::GUsizei stride, const edk::GUvoid *pointer ){ glInterleavedArrays( format, stride, pointer );edkEnd(); }



// Under Windows, we do not define Openedk::GU 1.2 & 1.3 functionality, since
it is treated as extensions (defined in edk::guext.h)
//#if !defined(__WIN32__)

// 1.2 functions
void edk::guDrawRangeElements( edk::GUenum mode, edk::GUuint start, edk::GUuint end, edk::GUsizei count, edk::GUenum type, const edk::GUvoid *indices ){
    #if !defined(__WIN32__)
     glDrawRangeElements( mode, start, end, count, type, indices );edkEnd();
      #endif
      }
void edk::guTexImage3D( edk::GUenum target, edk::GUint level, edk::GUenum internalFormat, edk::GUsizei width, edk::GUsizei height, edk::GUsizei depth, edk::GUint border, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels ){guTexImage3D( target, level, internalFormat, width, height, depth, border, format, type, pixels );edkEnd();  }
void edk::guTexSubImage3D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUint zoffset, edk::GUsizei width, edk::GUsizei height, edk::GUsizei depth, edk::GUenum format, edk::GUenum type, const edk::GUvoid *pixels){
    #if !defined(__WIN32__)
    glTexSubImage3D( target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);edkEnd();
    #endif
     }
void edk::guCopyTexSubImage3D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUint zoffset, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height ){
    #if !defined(__WIN32__)
     glCopyTexSubImage3D( target, level, xoffset, yoffset, zoffset, x, y, width, height );edkEnd();
     #endif
     }

// 1.2 imaging extension functions
void edk::guColorTable( edk::GUenum target, edk::GUenum internalformat, edk::GUsizei width, edk::GUenum format, edk::GUenum type, const edk::GUvoid *table ){
    #if !defined(__WIN32__)
    glColorTable( target, internalformat, width, format, type, table );edkEnd();
    #endif
}
void edk::guColorSubTable( edk::GUenum target, edk::GUsizei start, edk::GUsizei count, edk::GUenum format, edk::GUenum type, const edk::GUvoid *data ){
    #if !defined(__WIN32__)
    glColorSubTable( target, start, count, format, type, data );edkEnd();
    #endif
     }
void edk::guColorTableParameteriv(edk::GUenum target, edk::GUenum pname, const edk::GUint *params){
    #if !defined(__WIN32__)
    glColorTableParameteriv(target, pname, params);edkEnd();
    #endif
     }
void edk::guColorTableParameterfv(edk::GUenum target, edk::GUenum pname, const edk::GUfloat *params){
    #if !defined(__WIN32__)
    glColorTableParameterfv(target, pname, params);edkEnd();
    #endif
     }
void edk::guCopyColorSubTable( edk::GUenum target, edk::GUsizei start, edk::GUint x, edk::GUint y, edk::GUsizei width ){
    #if !defined(__WIN32__)
    glCopyColorSubTable( target, start, x, y, width );edkEnd();
    #endif
     }
void edk::guCopyColorTable( edk::GUenum target, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width ){
    #if !defined(__WIN32__)
    glCopyColorTable( target, internalformat, x, y, width );edkEnd();
    #endif
     }
void edk::guGetColorTable( edk::GUenum target, edk::GUenum format, edk::GUenum type, edk::GUvoid *table ){
    #if !defined(__WIN32__)
    glGetColorTable( target, format, type, table );edkEnd();
    #endif
     }
void edk::guGetColorTableParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params ){
    #if !defined(__WIN32__)
    glGetColorTableParameterfv( target, pname, params );edkEnd();
    #endif
     }
void edk::guGetColorTableParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params ){
    #if !defined(__WIN32__)
    glGetColorTableParameteriv( target, pname, params );edkEnd();
    #endif
     }
void edk::guBlendEquation( edk::GUenum mode ){
    #if !defined(__WIN32__)
    glBlendEquation( mode );edkEnd();
    #endif
     }
void edk::guBlendColor( edk::GUclampf red, edk::GUclampf green, edk::GUclampf blue, edk::GUclampf alpha ){
    #if !defined(__WIN32__)
    glBlendColor( red, green, blue, alpha );edkEnd();
    #endif
     }
void edk::guHistogram( edk::GUenum target, edk::GUsizei width, edk::GUenum internalformat, edk::GUboolean sink ){
    #if !defined(__WIN32__)
    glHistogram( target, width, internalformat, sink );edkEnd();
    #endif
     }
void edk::guResetHistogram( edk::GUenum target ){
    #if !defined(__WIN32__)
    glResetHistogram( target );edkEnd();
    #endif
     }
void edk::guGetHistogram( edk::GUenum target, edk::GUboolean reset, edk::GUenum format, edk::GUenum type, edk::GUvoid *values ){
    #if !defined(__WIN32__)
    glGetHistogram( target, reset, format, type, values );edkEnd();
    #endif
     }
void edk::guGetHistogramParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params ){
    #if !defined(__WIN32__)
    glGetHistogramParameterfv( target, pname, params );edkEnd();
    #endif
     }
void edk::guGetHistogramParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params ){
    #if !defined(__WIN32__)
    glGetHistogramParameteriv( target, pname, params );edkEnd();
    #endif
     }
void edk::guMinmax( edk::GUenum target, edk::GUenum internalformat, edk::GUboolean sink ){
    #if !defined(__WIN32__)
    glMinmax( target, internalformat, sink );edkEnd();
    #endif
     }
void edk::guResetMinmax( edk::GUenum target ){
    #if !defined(__WIN32__)
    glResetMinmax( target );edkEnd();
    #endif
     }
void edk::guGetMinmax( edk::GUenum target, edk::GUboolean reset, edk::GUenum format, edk::GUenum types, edk::GUvoid *values ){
    #if !defined(__WIN32__)
    glGetMinmax( target, reset, format, types, values );edkEnd();
    #endif
     }
void edk::guGetMinmaxParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params ){
    #if !defined(__WIN32__)
    glGetMinmaxParameterfv( target, pname, params );edkEnd();
    #endif
     }
void edk::guGetMinmaxParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params ){
    #if !defined(__WIN32__)
    glGetMinmaxParameteriv( target, pname, params );edkEnd();
    #endif
     }
void edk::guConvolutionFilter1D( edk::GUenum target, edk::GUenum internalformat, edk::GUsizei width, edk::GUenum format, edk::GUenum type, const edk::GUvoid *image ){
    #if !defined(__WIN32__)
    glConvolutionFilter1D( target, internalformat, width, format, type, image );edkEnd();
    #endif
     }
void edk::guConvolutionFilter2D( edk::GUenum target, edk::GUenum internalformat, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const edk::GUvoid *image ){
    #if !defined(__WIN32__)
    glConvolutionFilter2D( target,  internalformat, width, height, format, type, image );edkEnd();
    #endif
     }
void edk::guConvolutionParameterf( edk::GUenum target, edk::GUenum pname, edk::GUfloat params ){
    #if !defined(__WIN32__)
    glConvolutionParameterf( target, pname, params );edkEnd();
    #endif
     }
void edk::guConvolutionParameterfv( edk::GUenum target, edk::GUenum pname, const edk::GUfloat *params ){
    #if !defined(__WIN32__)
    glConvolutionParameterfv( target, pname, params );edkEnd();
    #endif
     }
void edk::guConvolutionParameteri( edk::GUenum target, edk::GUenum pname, edk::GUint params ){
    #if !defined(__WIN32__)
    glConvolutionParameteri( target, pname, params );edkEnd();
    #endif
     }
void edk::guConvolutionParameteriv( edk::GUenum target, edk::GUenum pname, const edk::GUint *params ){
    #if !defined(__WIN32__)
    glConvolutionParameteriv( target, pname, params );edkEnd();
    #endif
     }
void edk::guCopyConvolutionFilter1D( edk::GUenum target, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width ){
    #if !defined(__WIN32__)
    glCopyConvolutionFilter1D( target, internalformat, x, y, width );edkEnd();
    #endif
     }
void edk::guCopyConvolutionFilter2D( edk::GUenum target, edk::GUenum internalformat, edk::GUint x, edk::GUint y, edk::GUsizei width, edk::GUsizei height){
    #if !defined(__WIN32__)
     glCopyConvolutionFilter2D( target, internalformat, x, y, width, height);edkEnd();
     #endif
      }
void edk::guGetConvolutionFilter( edk::GUenum target, edk::GUenum format, edk::GUenum type, edk::GUvoid *image ){
    #if !defined(__WIN32__)
    glGetConvolutionFilter( target, format, type, image );edkEnd();
    #endif
     }
void edk::guGetConvolutionParameterfv( edk::GUenum target, edk::GUenum pname, edk::GUfloat *params ){
    #if !defined(__WIN32__)
    glGetConvolutionParameterfv( target, pname, params );edkEnd();
    #endif
     }
void edk::guGetConvolutionParameteriv( edk::GUenum target, edk::GUenum pname, edk::GUint *params ){
    #if !defined(__WIN32__)
    glGetConvolutionParameteriv( target, pname, params );edkEnd();
    #endif
     }
void edk::guSeparableFilter2D( edk::GUenum target, edk::GUenum internalformat, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const edk::GUvoid *row, const edk::GUvoid *column ){
    #if !defined(__WIN32__)
    glSeparableFilter2D( target, internalformat, width, height, format, type, row, column );edkEnd();
    #endif
     }
void edk::guGetSeparableFilter( edk::GUenum target, edk::GUenum format, edk::GUenum type, edk::GUvoid *row, edk::GUvoid *column, edk::GUvoid *span ){
    #if !defined(__WIN32__)
    glGetSeparableFilter( target, format, type, row, column, span );edkEnd();
    #endif
    }

// 1.3 functions
void edk::guActiveTexture( edk::GUenum texture ){
    #if !defined(__WIN32__)
     glActiveTexture( texture );edkEnd();
     #endif
     }
void edk::guClientActiveTexture( edk::GUenum texture ){
    #if !defined(__WIN32__)
    glClientActiveTexture( texture );edkEnd();
    #endif
    }
void edk::guCompressedTexImage1D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUsizei width, edk::GUint border, edk::GUsizei imageSize, const edk::GUvoid *data ){
    #if !defined(__WIN32__)
    glCompressedTexImage1D( target, level, internalformat, width, border, imageSize, data );edkEnd();
    #endif
     }
void edk::guCompressedTexImage2D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUsizei width, edk::GUsizei height, edk::GUint border, edk::GUsizei imageSize, const edk::GUvoid *data ){
    #if !defined(__WIN32__)
    glCompressedTexImage2D( target, level, internalformat, width, height, border, imageSize, data );edkEnd();
    #endif
     }
void edk::guCompressedTexImage3D( edk::GUenum target, edk::GUint level, edk::GUenum internalformat, edk::GUsizei width, edk::GUsizei height, edk::GUsizei depth, edk::GUint border, edk::GUsizei imageSize, const edk::GUvoid *data ){
    #if !defined(__WIN32__)
    glCompressedTexImage3D( target, level, internalformat, width, height, depth, border, imageSize, data );edkEnd();
    #endif
     }
void edk::guCompressedTexSubImage1D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUsizei width, edk::GUenum format, edk::GUsizei imageSize, const edk::GUvoid *data ){
    #if !defined(__WIN32__)
    glCompressedTexSubImage1D( target, level, xoffset, width, format, imageSize, data );edkEnd();
    #endif
     }
void edk::guCompressedTexSubImage2D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUsizei imageSize, const edk::GUvoid *data ){
    #if !defined(__WIN32__)
    glCompressedTexSubImage2D(
     target, level, xoffset, yoffset, width, height, format, imageSize, data );edkEnd();
     #endif
      }
void edk::guCompressedTexSubImage3D( edk::GUenum target, edk::GUint level, edk::GUint xoffset, edk::GUint yoffset, edk::GUint zoffset, edk::GUsizei width, edk::GUsizei height, edk::GUsizei depth, edk::GUenum format, edk::GUsizei imageSize, const edk::GUvoid *data ){
    #if !defined(__WIN32__)
     glCompressedTexSubImage3D( target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data );edkEnd();
     #endif
     }
void edk::guGetCompressedTexImage( edk::GUenum target, edk::GUint lod, edk::GUvoid *img ){
    #if !defined(__WIN32__)
    glGetCompressedTexImage( target, lod, img );edkEnd();
    #endif
    }
void edk::guMultiTexCoord1d( edk::GUenum target, edk::GUdouble s ){
    #if !defined(__WIN32__)
    glMultiTexCoord1d( target, s );edkEnd();
    #endif
     }
void edk::guMultiTexCoord1dv( edk::GUenum target, const edk::GUdouble *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord1dv( target, v );edkEnd();
    #endif
     }
void edk::guMultiTexCoord1f( edk::GUenum target, edk::GUfloat s ){
    #if !defined(__WIN32__)
    glMultiTexCoord1f( target, s );edkEnd();
    #endif
    }
void edk::guMultiTexCoord1fv( edk::GUenum target, const edk::GUfloat *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord1fv( target, v );edkEnd();
    #endif
     }
void edk::guMultiTexCoord1i( edk::GUenum target, edk::GUint s ){
    #if !defined(__WIN32__)
    glMultiTexCoord1i( target, s );edkEnd();
    #endif
     }
void edk::guMultiTexCoord1iv( edk::GUenum target, const edk::GUint *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord1iv( target, v );edkEnd();
    #endif
     }
void edk::guMultiTexCoord1s( edk::GUenum target, edk::GUshort s ){
    #if !defined(__WIN32__)
    glMultiTexCoord1s( target, s );edkEnd();
    #endif
     }
void edk::guMultiTexCoord1sv( edk::GUenum target, const edk::GUshort *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord1sv( target, v );edkEnd();
    #endif
     }
void edk::guMultiTexCoord2d( edk::GUenum target, edk::GUdouble s, edk::GUdouble t ){
    #if !defined(__WIN32__)
    glMultiTexCoord2d( target, s, t );edkEnd();
    #endif
     }
void edk::guMultiTexCoord2dv( edk::GUenum target, const edk::GUdouble *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord2dv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord2f( edk::GUenum target, edk::GUfloat s, edk::GUfloat t ){
    #if !defined(__WIN32__)
    glMultiTexCoord2f( target, s, t );edkEnd();
    #endif
    }
void edk::guMultiTexCoord2fv( edk::GUenum target, const edk::GUfloat *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord2fv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord2i( edk::GUenum target, edk::GUint s, edk::GUint t ){
    #if !defined(__WIN32__)
    glMultiTexCoord2i( target, s, t );edkEnd();
    #endif
    }
void edk::guMultiTexCoord2iv( edk::GUenum target, const edk::GUint *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord2iv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord2s( edk::GUenum target, edk::GUshort s, edk::GUshort t ){
    #if !defined(__WIN32__)
    glMultiTexCoord2s( target, s, t );edkEnd();
    #endif
    }
void edk::guMultiTexCoord2sv( edk::GUenum target, const edk::GUshort *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord2sv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord3d( edk::GUenum target, edk::GUdouble s, edk::GUdouble t, edk::GUdouble r ){
    #if !defined(__WIN32__)
    glMultiTexCoord3d( target, s, t, r );edkEnd();
    #endif
    }
void edk::guMultiTexCoord3dv( edk::GUenum target, const edk::GUdouble *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord3dv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord3f( edk::GUenum target, edk::GUfloat s, edk::GUfloat t, edk::GUfloat r ){
    #if !defined(__WIN32__)
    glMultiTexCoord3f( target, s, t, r );edkEnd();
    #endif
    }
void edk::guMultiTexCoord3fv( edk::GUenum target, const edk::GUfloat *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord3fv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord3i( edk::GUenum target, edk::GUint s, edk::GUint t, edk::GUint r ){
    #if !defined(__WIN32__)
    glMultiTexCoord3i( target, s, t, r );edkEnd();
    #endif
    }
void edk::guMultiTexCoord3iv( edk::GUenum target, const edk::GUint *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord3iv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord3s( edk::GUenum target, edk::GUshort s, edk::GUshort t, edk::GUshort r ){
    #if !defined(__WIN32__)
    glMultiTexCoord3s( target, s, t, r );edkEnd();
    #endif
    }
void edk::guMultiTexCoord3sv( edk::GUenum target, const edk::GUshort *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord3sv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord4d( edk::GUenum target, edk::GUdouble s, edk::GUdouble t, edk::GUdouble r, edk::GUdouble q ){
    #if !defined(__WIN32__)
    glMultiTexCoord4d( target, s, t, r, q );edkEnd();
    #endif
    }
void edk::guMultiTexCoord4dv( edk::GUenum target, const edk::GUdouble *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord4dv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord4f( edk::GUenum target, edk::GUfloat s, edk::GUfloat t, edk::GUfloat r, edk::GUfloat q ){
    #if !defined(__WIN32__)
    glMultiTexCoord4f( target, s, t, r, q );edkEnd();
    #endif
    }
void edk::guMultiTexCoord4fv( edk::GUenum target, const edk::GUfloat *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord4fv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord4i( edk::GUenum target, edk::GUint s, edk::GUint t, edk::GUint r, edk::GUint q ){
    #if !defined(__WIN32__)
    glMultiTexCoord4i( target, s, t, r, q );edkEnd();
    #endif
    }
void edk::guMultiTexCoord4iv( edk::GUenum target, const edk::GUint *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord4iv( target, v );edkEnd();
    #endif
    }
void edk::guMultiTexCoord4s( edk::GUenum target, edk::GUshort s, edk::GUshort t, edk::GUshort r, edk::GUshort q ){
    #if !defined(__WIN32__)
    glMultiTexCoord4s( target, s, t, r, q );edkEnd();
    #endif
    }
void edk::guMultiTexCoord4sv( edk::GUenum target, const edk::GUshort *v ){
    #if !defined(__WIN32__)
    glMultiTexCoord4sv( target, v );edkEnd();
    #endif
    }
void edk::guLoadTransposeMatrixd( const edk::GUdouble m[16] ){
    #if !defined(__WIN32__)
    glLoadTransposeMatrixd( m );edkEnd();
    #endif
    }
void edk::guLoadTransposeMatrixf( const edk::GUfloat m[16] ){
    #if !defined(__WIN32__)
    glLoadTransposeMatrixf( m);edkEnd();
    #endif
    }
void edk::guMultTransposeMatrixd( const edk::GUdouble m[16] ){
    #if !defined(__WIN32__)
    glMultTransposeMatrixd( m );edkEnd();
    #endif
    }
void edk::guMultTransposeMatrixf( const edk::GUfloat m[16] ){
    #if !defined(__WIN32__)
    glMultTransposeMatrixf( m );edkEnd();
    #endif
    }
void edk::guSampleCoverage( edk::GUclampf value, edk::GUboolean invert ){
    #if !defined(__WIN32__)
    glSampleCoverage( value, invert );edkEnd();
    #endif
    }
void edk::guSamplePass(edk::GUenum pass ){
    #if !defined(__WIN32__)
    //glSamplePass( pass );edkEnd();
    #endif
    }

//#endif // __WIN32__











//filter
GLenum edk::filterGUtoGLU(edk::GUenum id){
    //Test if is the GLU ID's
    switch(id){
        //#define GU_VERSION                        100800
        case GU_VERSION:
            return GLU_VERSION;edkEnd();

        //#define GU_EXTENSIONS                     100801
        case GU_EXTENSIONS:
            return GLU_EXTENSIONS;edkEnd();


        //#define GU_INVALID_ENUM                   100900
        case GU_INVALID_ENUM:
            return GLU_INVALID_ENUM;edkEnd();

        //#define GU_INVALID_VALUE                  100901
        case GU_INVALID_VALUE:
            return GLU_INVALID_VALUE;edkEnd();

        //#define GU_OUT_OF_MEMORY                  100902
        case GU_OUT_OF_MEMORY:
            return GLU_OUT_OF_MEMORY;edkEnd();

        //#define GU_INVALID_OPERATION              100904
        case GU_INVALID_OPERATION:
            return GLU_INVALID_OPERATION;edkEnd();

        //#define GU_POINT                          100010
        case GU_POINT:
            return GLU_POINT;edkEnd();

        //#define GU_LINE                           100011
        case GU_LINE:
            return GLU_LINE;edkEnd();

        //#define GU_FILL                           100012
        case GU_FILL:
            return GLU_FILL;edkEnd();

        //#define GU_SMOOTH                         100000
        case GU_SMOOTH:
            return GLU_SMOOTH;edkEnd();

        //#define GU_FLAT                           100001
        case GU_FLAT:
            return GLU_FLAT;edkEnd();

        //#define GU_NONE                           100002
        case GU_NONE:
            return GLU_NONE;edkEnd();

        //#define GU_EDGE_FLAG                      100104
        case GU_EDGE_FLAG:
            return GLU_EDGE_FLAG;edkEnd();

        //#define GU_CW                             100120
        case GU_CW:
            return GLU_CW;edkEnd();

        //#define GU_CCW                            100121
        case GU_CCW:
            return GLU_CCW;edkEnd();
    }

    //else return the same
    return id;edkEnd();
}


//GLU
void edk::guBeginCurve (edk::GUnurbs* nurb){ gluBeginCurve ((GLUnurbs*)nurb);edkEnd(); }
void edk::guBeginPolygon (edk::GUtesselator* tess){ gluBeginPolygon ((GLUtesselator*)tess);edkEnd(); }
void edk::guBeginSurface (edk::GUnurbs* nurb){ gluBeginSurface ((GLUnurbs*)nurb);edkEnd(); }
void edk::guBeginTrim (edk::GUnurbs* nurb){ gluBeginTrim ((GLUnurbs*)nurb);edkEnd(); }
edk::GUint edk::guBuild1DMipmaps (edk::GUenum target, edk::GUint internalFormat, edk::GUsizei width, edk::GUenum format, edk::GUenum type, const void *data){
        return(edk::GUint) gluBuild1DMipmaps (edk::filterGUtoGLU(target),
                                              internalFormat,
                                              width,
                                              edk::filterGUtoGLU(format),
                                              edk::filterGUtoGLU(type),
                                              data
                                              );edkEnd();
}
edk::GUint edk::guBuild2DMipmaps (edk::GUenum target, edk::GUint internalFormat, edk::GUsizei width, edk::GUsizei height, edk::GUenum format, edk::GUenum type, const void *data){
        return(edk::GUint) gluBuild2DMipmaps (
                                              edk::filterGUtoGLU(target),
                                              internalFormat,
                                              width,
                                              height,
                                              edk::filterGUtoGLU(format),
                                              edk::filterGUtoGLU(type),
                                              data
                                              );edkEnd();
     }
void edk::guCylinder (edk::GUquadric* quad, edk::GUdouble base, edk::GUdouble top, edk::GUdouble height, edk::GUint slices, edk::GUint stacks){ gluCylinder ((GLUquadric*) quad, (GLdouble) base, (GLdouble) top, (GLdouble) height, (GLint) slices, (GLint) stacks);edkEnd(); }
void edk::guDeleteNurbsRenderer (edk::GUnurbs* nurb){ gluDeleteNurbsRenderer ((GLUnurbs*) nurb);edkEnd(); }
void edk::guDeleteQuadric (edk::GUquadric* quad){ gluDeleteQuadric ((GLUquadric*) quad);edkEnd(); }
void edk::guDeleteTess (edk::GUtesselator* tess){ gluDeleteTess ((GLUtesselator*) tess);edkEnd(); }
void edk::guDisk(edk::GUquadric* quad, edk::GUdouble inner, edk::GUdouble outer, edk::GUint slices, edk::GUint loops){ gluDisk ((GLUquadric*) quad, inner, outer, slices, loops);edkEnd(); }
void edk::guEndCurve(edk::GUnurbs* nurb){ gluEndCurve((GLUnurbs*)nurb);edkEnd(); }
void edk::guEndPolygon(edk::GUtesselator* tess){ gluEndPolygon((GLUtesselator*) tess);edkEnd(); }
void edk::guEndSurface(edk::GUnurbs* nurb){ gluEndSurface((GLUnurbs*)nurb);edkEnd(); }
void edk::guEndTrim(edk::GUnurbs* nurb){ gluEndTrim((GLUnurbs*)nurb);edkEnd(); }
const edk::GUubyte* edk::guErrorString (edk::GUenum error){
        return (const edk::GUubyte*) gluErrorString(edk::filterGUtoGLU(error));edkEnd();
    }
//const wchar_t* edk::guErrorUnicodeStringEXT (edk::GUenum error){return(const wchar_t*) gluErrorUnicodeStringEXT (error);edkEnd();}
void edk::guGetNurbsProperty (edk::GUnurbs* nurb, edk::GUenum property, edk::GUfloat* data){
        gluGetNurbsProperty ((GLUnurbs*)nurb, edk::filterGUtoGLU(property), data);edkEnd();
}

//const edk::GUubyte* edk::guGetString (edk::GUenum name){return(const edk::GUubyte*) gluGetString (name);edkEnd(); }

void edk::guGetTessProperty(edk::GUtesselator* tess, edk::GUenum which, edk::GUdouble* data){
        gluGetTessProperty((GLUtesselator*)tess, edk::filterGUtoGLU(which), data);edkEnd();
}
void edk::guLoadSamplingMatrices(edk::GUnurbs* nurb, const edk::GUfloat *model, const edk::GUfloat *perspective, const edk::GUint *view){ gluLoadSamplingMatrices((GLUnurbs*)nurb, model, perspective, view);edkEnd(); }
void edk::guLookAt (edk::GUdouble eyeX, edk::GUdouble eyeY, edk::GUdouble eyeZ, edk::GUdouble centerX, edk::GUdouble centerY, edk::GUdouble centerZ, edk::GUdouble upX, edk::GUdouble upY, edk::GUdouble upZ){ gluLookAt (eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);edkEnd(); }
edk::GUnurbs* edk::guNewNurbsRenderer (void){ return(edk::GUnurbs*) edk::guNewNurbsRenderer ();edkEnd(); }
edk::GUquadric* edk::guNewQuadric (void){return (edk::GUquadric*) edk::guNewQuadric ();edkEnd(); }
edk::GUtesselator* edk::guNewTess (void){return(edk::GUtesselator*) gluNewTess ();edkEnd();}
void edk::guNextContour(edk::GUtesselator* tess, edk::GUenum type){
    gluNextContour((GLUtesselator*)tess, edk::filterGUtoGLU(type));edkEnd();
}
void edk::guNurbsCallback(edk::GUnurbs* nurb, edk::GUenum which, edk::_GUfuncptr CallBackFunc){
    #if defined(__APPLE__)
    gluNurbsCallback((GLUnurbs*)nurb, edk::filterGUtoGLU(which), CallBackFunc);edkEnd();
    #else
    gluNurbsCallback((GLUnurbs*)nurb, edk::filterGUtoGLU(which), (_GLUfuncptr )CallBackFunc);edkEnd();
    #endif
}
void edk::guNurbsCurve(edk::GUnurbs* nurb, edk::GUint knotCount, edk::GUfloat *knots, edk::GUint stride, edk::GUfloat *control, edk::GUint order, edk::GUenum type){ gluNurbsCurve((GLUnurbs*)nurb, knotCount, knots, stride, control, order, type);edkEnd(); }
void edk::guNurbsProperty(edk::GUnurbs* nurb, edk::GUenum property, edk::GUfloat value){
    gluNurbsProperty((GLUnurbs*)nurb, edk::filterGUtoGLU(property), value);edkEnd();
}
void edk::guNurbsSurface(edk::GUnurbs* nurb, edk::GUint sKnotCount, edk::GUfloat* sKnots, edk::GUint tKnotCount, edk::GUfloat* tKnots, edk::GUint sStride, edk::GUint tStride, edk::GUfloat* control, edk::GUint sOrder, edk::GUint tOrder, edk::GUenum type){ gluNurbsSurface((GLUnurbs*)nurb, sKnotCount, sKnots, tKnotCount, tKnots, sStride, tStride, control, sOrder, tOrder, type);edkEnd(); }
void edk::guOrtho2D(edk::GUdouble left, edk::GUdouble right, edk::GUdouble bottom, edk::GUdouble top){ gluOrtho2D(left, right, bottom, top);edkEnd(); }
void edk::guPartialDisk(edk::GUquadric* quad, edk::GUdouble inner, edk::GUdouble outer, edk::GUint slices, edk::GUint loops, edk::GUdouble start, edk::GUdouble sweep){ gluPartialDisk((GLUquadric*)quad, inner, outer, slices, loops, start, sweep);edkEnd(); }
void edk::guPerspective(edk::GUdouble fovy, edk::GUdouble aspect, edk::GUdouble zNear, edk::GUdouble zFar){ gluPerspective(fovy, aspect, zNear, zFar);edkEnd(); }
void edk::guPickMatrix(edk::GUdouble x, edk::GUdouble y, edk::GUdouble delX, edk::GUdouble delY, edk::GUint *viewport){ gluPickMatrix(x, y, delX, delY, viewport);edkEnd(); }
edk::GUint edk::guProject(edk::GUdouble objX, edk::GUdouble objY, edk::GUdouble objZ, const edk::GUdouble *model, const edk::GUdouble *proj, const edk::GUint *view, edk::GUdouble* winX, edk::GUdouble* winY, edk::GUdouble* winZ){return(edk::GUint ) gluProject(objX, objY, objZ, model, proj, view, winX, winY, winZ);edkEnd(); }
void edk::guPwlCurve(edk::GUnurbs* nurb, edk::GUint count, edk::GUfloat* data, edk::GUint stride, edk::GUenum type){
    gluPwlCurve((GLUnurbs*)nurb, count, data, stride, edk::filterGUtoGLU(type));edkEnd();
}
void edk::guQuadricCallback(edk::GUquadric* quad, edk::GUenum which, edk::_GUfuncptr CallBackFunc){
    #if defined(__APPLE__)
    gluQuadricCallback((GLUquadric*)quad, edk::filterGUtoGLU(which),CallBackFunc);edkEnd();
    #else
    gluQuadricCallback((GLUquadric*)quad, edk::filterGUtoGLU(which),(_GLUfuncptr)CallBackFunc);edkEnd();
    #endif
}
void edk::guQuadricDrawStyle(edk::GUquadric* quad, edk::GUenum draw){
    gluQuadricDrawStyle((GLUquadric*) quad, edk::filterGUtoGLU(draw));edkEnd();
}
void edk::guQuadricNormals(edk::GUquadric* quad, edk::GUenum normal){
    gluQuadricNormals((GLUquadric*)quad, edk::filterGUtoGLU(normal));edkEnd();
}
void edk::guQuadricOrientation(edk::GUquadric* quad, edk::GUenum orientation){
    gluQuadricOrientation((GLUquadric*)quad, edk::filterGUtoGLU(orientation));edkEnd();
}
void edk::guQuadricTexture(edk::GUquadric* quad, edk::GUboolean texture){ gluQuadricTexture((GLUquadric*)quad, texture);edkEnd(); }
edk::GUint edk::guScaleImage(edk::GUenum format, edk::GUsizei wIn, edk::GUsizei hIn, edk::GUenum typeIn, const void *dataIn, edk::GUsizei wOut, edk::GUsizei hOut, edk::GUenum typeOut, edk::GUvoid* dataOut){
    return(edk::GUint) gluScaleImage(edk::filterGUtoGLU(format), wIn, hIn, edk::filterGUtoGLU(typeIn), dataIn, wOut, hOut, edk::filterGUtoGLU(typeOut), dataOut);edkEnd();
}
void edk::guSphere(edk::GUquadric* quad, edk::GUdouble radius, edk::GUint slices, edk::GUint stacks){ gluSphere((GLUquadric*)quad, radius, slices, stacks);edkEnd(); }
void edk::guTessBeginContour(edk::GUtesselator* tess){ gluTessBeginContour((GLUtesselator*)tess);edkEnd(); }
void edk::guTessBeginPolygon(edk::GUtesselator* tess, edk::GUvoid* data){ gluTessBeginPolygon((GLUtesselator*)tess, data);edkEnd(); }
void edk::guTessCallback(edk::GUtesselator* tess, edk::GUenum which, edk::_GUfuncptr CallBackFunc){
    #if defined(__APPLE__)
    gluTessCallback((GLUtesselator*)tess, edk::filterGUtoGLU(which), CallBackFunc);edkEnd();
    #else
    gluTessCallback((GLUtesselator*)tess, edk::filterGUtoGLU(which), (_GLUfuncptr)CallBackFunc);edkEnd();
    #endif
}
void edk::guTessEndContour(edk::GUtesselator* tess){ gluTessEndContour((GLUtesselator*)tess);edkEnd(); }
void edk::guTessEndPolygon(edk::GUtesselator* tess){ gluTessEndPolygon((GLUtesselator*)tess);edkEnd(); }
void edk::guTessNormal(edk::GUtesselator* tess, edk::GUdouble valueX, edk::GUdouble valueY, edk::GUdouble valueZ){ gluTessNormal((GLUtesselator*)tess, valueX, valueY, valueZ);edkEnd(); }
void edk::guTessProperty(edk::GUtesselator* tess, edk::GUenum which, edk::GUdouble data){
    gluTessProperty((GLUtesselator*)tess, edk::filterGUtoGLU(which), data);edkEnd();
}
void edk::guTessVertex(edk::GUtesselator* tess, edk::GUdouble *location, edk::GUvoid* data){ gluTessVertex((GLUtesselator*)tess, location, data);edkEnd(); }
//
edk::GUint edk::guUnProject(edk::GUdouble winX, edk::GUdouble winY, edk::GUdouble winZ, const edk::GUdouble *model, const edk::GUdouble *proj, const edk::GUint *view, edk::GUdouble* objX, edk::GUdouble* objY, edk::GUdouble* objZ){return(edk::GUint ) gluUnProject(winX, winY, winZ, model, proj, view, objX, objY, objZ);edkEnd(); }
edk::GUint edk::guUnProject4(edk::GUdouble winX, edk::GUdouble winY, edk::GUdouble winZ, edk::GUdouble clipW, const edk::GUdouble *model, const edk::GUdouble *proj, const edk::GUint *view, edk::GUdouble nearVal, edk::GUdouble farVal, edk::GUdouble* objX, edk::GUdouble* objY, edk::GUdouble* objZ, edk::GUdouble* objW){return(edk::GUint) gluUnProject4(winX, winY, winZ, clipW, model, proj, view, nearVal, farVal, objX, objY, objZ, objW);edkEnd(); }

void edk::guGenBuffers(edk::GUsizei n,  edk::GUuint * ids){glGenBuffers(n,ids);edkEnd();}
void edk::guBindBuffer (edk::GUenum target, edk::GUuint buffer){glBindBuffer (target, buffer);edkEnd();}
void edk::guDeleteBuffers (edk::GUsizei n, const edk::GUuint *buffers){glDeleteBuffers (n, (const GLuint *)buffers);edkEnd();}
void edk::guFrameBufferTexture (edk::GUenum target, edk::GUenum attachment, edk::GUuint texture, edk::GUint level){glFramebufferTexture (target,attachment,texture,level);edkEnd();}
*/


//

//global variables
//GU_MODELVIEW
//GU_PROJECTION
//GU_TEXTURE
edk::uint32 matrixMode = GU_FALSE;

//construtor
edk::GU::GU(){
    //
}

//destrutor
edk::GU::~GU(){
    //
}

//Color
void edk::GU::guColor3f32(edk::color3f32 color){
    glColor3f(color.r,color.g,color.b);edkEnd();
}
void edk::GU::guColor3f64(edk::color3f64 color){
    glColor3d(color.r,color.g,color.b);edkEnd();
}
void edk::GU::guColor3f32(edk::float32 r,edk::float32 g,edk::float32 b){
    glColor3f(r,g,b);edkEnd();
}
void edk::GU::guColor3f64(edk::float64 r,edk::float64 g,edk::float64 b){
    glColor3d(r,g,b);edkEnd();
}
void edk::GU::guColor4f32(edk::color4f32 color){
    glColor4f(color.r,color.g,color.b,color.a);edkEnd();
}
void edk::GU::guColor4f64(edk::color4f64 color){
    glColor4d(color.r,color.g,color.b,color.a);edkEnd();
}
void edk::GU::guColor4f32(edk::float32 r,edk::float32 g,edk::float32 b,edk::float32 a){
    glColor4f(r,g,b,a);edkEnd();
}
void edk::GU::guColor4f64(edk::float64 r,edk::float64 g,edk::float64 b,edk::float64 a){
    glColor4d(r,g,b,a);edkEnd();
}

//clear dome buffer
void edk::GU::guClear(edk::uint32 mask){
    glClear(mask);edkEnd();
}

//return the openGL matrix are using
bool edk::GU::guUsingMatrix(edk::uint32 mode){
    return matrixMode==mode;edkEnd();
}
//set the usingMatrix
void edk::GU::guUseMatrix(edk::uint32 mode){
    //test if aready using the matrix
    if(mode!=matrixMode && mode!=GU_FALSE){
        //then set the matrixMode
        glMatrixMode(mode);edkEnd();
    }
}
//load the identity matrix
void edk::GU::guLoadIdentity(){
    glLoadIdentity();edkEnd();
}
//Push Matrix
void edk::GU::guPushMatrix(){
    glPushMatrix();edkEnd();
}
void edk::GU::guPopMatrix(){
    glPopMatrix();edkEnd();
}
//setViewport
void edk::GU::guSetViewport(edk::uint32 x,edk::uint32 y,edk::uint32 width,edk::uint32 height){
    glViewport(x,y,width,height);edkEnd();
}
void edk::GU::guSetViewportRect(edk::rectui32 rect){
    glViewport(rect.origin.x,rect.origin.y,rect.size.width,rect.size.height);edkEnd();
}
void edk::GU::guUseOrtho(edk::float32 left, edk::float32 right, edk::float32 botton, edk::float32 top, edk::float32 near, edk::float32 far){
    glOrtho(left,right,botton,top,near,far);edkEnd();
}
void edk::GU::guUsePerspective(edk::float32 fovy, edk::float32 aspect, edk::float32 near, edk::float32 far){
    gluPerspective(fovy, aspect, near, far);edkEnd();
}
void edk::GU::guLookAt(edk::float64 eyeX, edk::float64 eyeY, edk::float64 eyeZ, edk::float64 centerX, edk::float64 centerY, edk::float64 centerZ, edk::float64 upX, edk::float64 upY, edk::float64 upZ){
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
            ;edkEnd();
}
void edk::GU::guLookAt(edk::float32 eyeX, edk::float32 eyeY, edk::float32 eyeZ, edk::float32 centerX, edk::float32 centerY, edk::float32 centerZ, edk::float32 upX, edk::float32 upY, edk::float32 upZ){
    gluLookAt(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ);edkEnd();
}

//Create a texture
edk::uint32 edk::GU::guAllocTexture2D(edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test the mode
    if(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA){
        //alloc the texture ID
        edk::uint32 ID=0u;

        //Create the texture name
        glGenTextures(1u,&ID);edkEnd();

        //test the ID
        if(ID){
            //Set using texture
            glBindTexture(GL_TEXTURE_2D,ID);edkEnd();
            //Copy the texture
            glTexImage2D(GL_TEXTURE_2D,
                         0,
                         mode,
                         width,
                         height,
                         0,
                         mode,
                         GL_UNSIGNED_BYTE,
                         data
                         );edkEnd();
            /*
            glTexImage2D(GLenum  target,
                          GLint  level,
                          GLint  internalFormat,
                          GLsizei  width,
                          GLsizei  height,
                          GLint  border,
                          GLenum  format,
                          GLenum  type,
                          const GLvoid *  data
                          );edkEnd();
                          */

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);edkEnd();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);edkEnd();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);edkEnd();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);edkEnd();

            if(filter == GU_NEAREST_MIPMAP_LINEAR || filter == GU_NEAREST_MIPMAP_NEAREST || filter == GU_LINEAR_MIPMAP_LINEAR || filter == GU_LINEAR_MIPMAP_NEAREST){
                //load the mipmap
                glGenerateMipmap(GL_TEXTURE_2D);edkEnd();
            }

            //Clean use texture
            glBindTexture(GL_TEXTURE_2D, 0u);edkEnd();

            //return the ID
            return ID;edkEnd();
        }
    }
    return 0u;edkEnd();
}
bool edk::GU::guDrawToTexture(edk::uint32 ID,edk::uint32 width, edk::uint32 height, edk::uint32 mode, edk::uint32 filter, const edk::classID  data){
    //test the mode
    if(mode==GU_RGB || mode==GU_RGBA || mode==GU_LUMINANCE || mode==GU_LUMINANCE_ALPHA){
        //test the ID
        if(ID){
            //Set using texture
            glBindTexture(GL_TEXTURE_2D,ID);edkEnd();
            //Copy the texture
            glTexImage2D(GL_TEXTURE_2D,
                         0,
                         mode,
                         width,
                         height,
                         0,
                         mode,
                         GL_UNSIGNED_BYTE,
                         data
                         );edkEnd();
            /*
            glTexImage2D(GLenum  target,
                          GLint  level,
                          GLint  internalFormat,
                          GLsizei  width,
                          GLsizei  height,
                          GLint  border,
                          GLenum  format,
                          GLenum  type,
                          const GLvoid *  data
                          );edkEnd();
                          */

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);edkEnd();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);edkEnd();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);edkEnd();
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);edkEnd();

            if(filter == GU_NEAREST_MIPMAP_LINEAR || filter == GU_NEAREST_MIPMAP_NEAREST || filter == GU_LINEAR_MIPMAP_LINEAR || filter == GU_LINEAR_MIPMAP_NEAREST){
                //load the mipmap
                glGenerateMipmap(GL_TEXTURE_2D);edkEnd();
            }

            //Clean use texture
            glBindTexture(GL_TEXTURE_2D, 0u);edkEnd();

            return true;
        }
    }
    return false;
}

//delete texture
void edk::GU::guDeleteTexture(edk::uint32 ID){
    glDeleteTextures(1u,&ID);edkEnd();
}

void edk::GU::guBlendFunc( edk::uint32 sfactor, edk::uint32 dfactor ){ glBlendFunc( sfactor, dfactor );edkEnd(); }
//ENABLE_DISABLE
void edk::GU::guEnable( edk::uint32 cap ){
    glEnable(cap);edkEnd();
}
void edk::GU::guDisable( edk::uint32 cap ){
    glDisable(cap);edkEnd();
}
//disable all lights
void edk::GU::guDisableAllLights(){
    for(edk::uint32 i=GU_LIGHT0;i<=GU_LIGHT7;i++){
        edk::GU::guDisable(i);edkEnd();
    }
}

//TRANSFORMATIONS
//rotation
/*

void guRotated( edk::GUdouble angle, edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );edkEnd();
void guRotatef( edk::GUfloat angle, edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );edkEnd();
void guScaled( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );edkEnd();
void guScalef( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );edkEnd();
void guTranslated( edk::GUdouble x, edk::GUdouble y, edk::GUdouble z );edkEnd();
void guTranslatef( edk::GUfloat x, edk::GUfloat y, edk::GUfloat z );edkEnd();

*/
void edk::GU::guRotate3f32( edk::float32 angle, edk::vec3f32 vec){
    //
    edk::GU::guRotate3f32( angle, vec.x, vec.y, vec.z );edkEnd();
}
void edk::GU::guRotate3f32( edk::float32 angle, edk::float32 x, edk::float32 y, edk::float32 z ){
    //
    glRotatef( angle, x, y, z );edkEnd();
}
void edk::GU::guRotate3f64( edk::float64 angle, edk::vec3f64 vec){
    //
    edk::GU::guRotate3f64( angle, vec.x, vec.y, vec.z );edkEnd();
}
void edk::GU::guRotate3f64( edk::float64 angle, edk::float64 x, edk::float64 y, edk::float64 z ){
    //
    glRotated( angle, x, y, z );edkEnd();
}
void edk::GU::guRotateXf32(edk::float32 angle){
    //
    edk::GU::guRotate3f32( angle, 1.0f, 0.0f, 0.0f );edkEnd();
}
void edk::GU::guRotateXf64(edk::float64 angle){
    //
    edk::GU::guRotate3f64( angle, 1.0, 0.0, 0.0 );edkEnd();
}
void edk::GU::guRotateYf32(edk::float32 angle){
    //
    edk::GU::guRotate3f32( angle, 0.0f, 1.0f, 0.0f );edkEnd();
}
void edk::GU::guRotateYf64(edk::float64 angle){
    //
    edk::GU::guRotate3f64( angle, 0.0, 1.0, 0.0 );edkEnd();
}
void edk::GU::guRotateZf32(edk::float32 angle){
    //
    edk::GU::guRotate3f32( angle, 0.0f, 0.0f, 1.0f );edkEnd();
}
void edk::GU::guRotateZf64(edk::float64 angle){
    //
    edk::GU::guRotate3f64( angle, 0.0, 0.0, 1.0 );edkEnd();
}
//scale
void edk::GU::guScale3f32( edk::size3f32 size ){
    //
    guScale3f32( size.width, size.height, size.length );edkEnd();
}
void edk::GU::guScale3f32( edk::float32 x, edk::float32 y, edk::float32 z ){
    //
    glScalef(x,y,z);edkEnd();
}
void edk::GU::guScale3f64( edk::size3f64 size ){
    //
    edk::GU::guScale3f64( size.width, size.height, size.length );edkEnd();
}
void edk::GU::guScale3f64( edk::float64 x, edk::float64 y, edk::float64 z ){
    //
    glScaled(x,y,z);edkEnd();
}
void edk::GU::guScale2f32( edk::size2f32 size ){
    //
    guScale2f32( size.width, size.height);edkEnd();
}
void edk::GU::guScale2f32( edk::float32 x, edk::float32 y){
    //
    glScalef(x,y,1.0f);edkEnd();
}
void edk::GU::guScale2f64( edk::size2f64 size ){
    //
    guScale2f64( size.width, size.height);edkEnd();
}
void edk::GU::guScale2f64( edk::float64 x, edk::float64 y){
    //
    glScaled(x,y,1.0);edkEnd();
}
void edk::GU::guScaleXf32( edk::float64 x){
    //
    edk::GU::guScale3f32( x, 1.0f, 1.0f);edkEnd();
}
void edk::GU::guScaleXf64( edk::float64 x){
    //
    edk::GU::guScale3f64( x, 1.0, 1.0);edkEnd();
}
void edk::GU::guScaleYf32( edk::float64 y){
    //
    edk::GU::guScale3f32( 1.0f, y, 1.0f);edkEnd();
}
void edk::GU::guScaleYf64( edk::float64 y){
    //
    edk::GU::guScale3f64( 1.0, y, 1.0);edkEnd();
}
void edk::GU::guScaleZf32( edk::float64 z){
    //
    edk::GU::guScale3f32( 1.0f, 1.0f, z);edkEnd();
}
void edk::GU::guScaleZf64( edk::float64 z){
    //
    edk::GU::guScale3f64( 1.0, 1.0, z);edkEnd();
}
//translate
void edk::GU::guTranslate3f32( edk::vec3f32 vec){
    //
    guTranslate3f32( vec.x, vec.y, vec.z );edkEnd();
}
void edk::GU::guTranslate3f32( edk::float32 x, edk::float32 y, edk::float32 z ){
    //
    glTranslatef(x,y,z);edkEnd();
}
void edk::GU::guTranslate3f64( edk::vec3f64 vec){
    //
    guTranslate3f64( vec.x, vec.y, vec.z );edkEnd();
}
void edk::GU::guTranslate3f64( edk::float64 x, edk::float64 y, edk::float64 z ){
    //
    glTranslated(x,y,z);edkEnd();
}
void edk::GU::guTranslate2f32( edk::vec2f32 vec ){
    //
    edk::GU::guTranslate2f32( vec.x, vec.y );edkEnd();
}
void edk::GU::guTranslate2f32( edk::float32 x, edk::float32 y ){
    //
    glTranslatef(x,y,0.0f);edkEnd();
}
void edk::GU::guTranslate2f64( edk::vec2f64 vec ){
    //
    edk::GU::guTranslate2f64( vec.x, vec.y );edkEnd();
}
void edk::GU::guTranslate2f64( edk::float64 x, edk::float64 y ){
    //
    glTranslated(x,y,0.0);edkEnd();
}
void edk::GU::guTranslateXf32( edk::float32 x ){
    //
    edk::GU::guTranslate3f32(x,0.0f,0.0f);edkEnd();
}
void edk::GU::guTranslateXf64( edk::float64 x ){
    //
    edk::GU::guTranslate3f64(x,0.0,0.0);edkEnd();
}
void edk::GU::guTranslateYf32( edk::float32 y ){
    //
    edk::GU::guTranslate3f32(0.0f,y,0.0f);edkEnd();
}
void edk::GU::guTranslateYf64( edk::float64 y ){
    //
    edk::GU::guTranslate3f64(0.0,y,0.0);edkEnd();
}
void edk::GU::guTranslateZf32( edk::float32 z ){
    //
    edk::GU::guTranslate3f32(0.0f,0.0f,z);edkEnd();
}
void edk::GU::guTranslateZf64( edk::float64 z ){
    //
    edk::GU::guTranslate3f64(0.0,0.0,z);edkEnd();
}
//SIZES
void edk::GU::guPointSize(edk::float32 size){
    glPointSize(size);edkEnd();}
void edk::GU::guPointSize(edk::float64 size){
    glPointSize(size);edkEnd();}
void edk::GU::guPointSize(edk::int8 size){
    glPointSize((edk::float32)size);edkEnd();
}
void edk::GU::guPointSize(edk::int16 size){
    glPointSize((edk::float32)size);edkEnd();
}
void edk::GU::guPointSize(edk::int32 size){
    glPointSize((edk::float32)size);edkEnd();
}
void edk::GU::guPointSize(edk::int64 size){
    glPointSize((edk::float32)size);edkEnd();
}
void edk::GU::guPointSize(edk::uint8 size){
    glPointSize((edk::float32)size);edkEnd();
}
void edk::GU::guPointSize(edk::uint16 size){
    glPointSize((edk::float32)size);edkEnd();
}
void edk::GU::guPointSize(edk::uint32 size){
    glPointSize((edk::float32)size);edkEnd();
}
void edk::GU::guPointSize(edk::uint64 size){
    glPointSize((edk::float32)size);edkEnd();
}
void edk::GU::guLineWidth(edk::float32 size){
    glLineWidth(size);edkEnd();
}
void edk::GU::guLineWidth(edk::float64 size){
    glLineWidth(size);edkEnd();
}
void edk::GU::guLineWidth(edk::int8 size){
    glLineWidth((edk::float32)size);edkEnd();
}
void edk::GU::guLineWidth(edk::int16 size){
    glLineWidth((edk::float32)size);edkEnd();
}
void edk::GU::guLineWidth(edk::int32 size){
    glLineWidth((edk::float32)size);edkEnd();
}
void edk::GU::guLineWidth(edk::int64 size){
    glLineWidth((edk::float32)size);edkEnd();
}
void edk::GU::guLineWidth(edk::uint8 size){
    glLineWidth((edk::float32)size);edkEnd();
}
void edk::GU::guLineWidth(edk::uint16 size){
    glLineWidth((edk::float32)size);edkEnd();
}
void edk::GU::guLineWidth(edk::uint32 size){
    glLineWidth((edk::float32)size);edkEnd();
}
void edk::GU::guLineWidth(edk::uint64 size){
    glLineWidth((edk::float32)size);edkEnd();
}
//DRAW functions
void edk::GU::guBegin(edk::uint32 mode){
    glBegin( mode );edkEnd();}
void edk::GU::guEnd(){
    glEnd();edkEnd();
}
void edk::GU::guVertex2f32(edk::vec2f32 vec){
    glVertex2f(vec.x,vec.y);edkEnd();
}
void edk::GU::guVertex2f64(edk::vec2f64 vec){
    glVertex2d(vec.x,vec.y);edkEnd();
}
void edk::GU::guVertex2f32(edk::float32 x,edk::float32 y){
    glVertex2f(x,y);edkEnd();
}
void edk::GU::guVertex2f64(edk::float64 x,edk::float64 y){
    glVertex2d(x,y);edkEnd();
}
void edk::GU::guVertex3f32(edk::vec3f32 vec){
    glVertex3f(vec.x,vec.y,vec.z);edkEnd();
}
void edk::GU::guVertex3f64(edk::vec3f64 vec){
    glVertex3d(vec.x,vec.y,vec.z);edkEnd();
}
void edk::GU::guVertex3f32(edk::float32 x,edk::float32 y,edk::float32 z){
    glVertex3f(x,y,z);edkEnd();
}
void edk::GU::guVertex3f64(edk::float64 x,edk::float64 y,edk::float64 z){
    glVertex3d(x,y,z);edkEnd();
}
void edk::GU::guVertex4f32(edk::vec4f32 vec){
    glVertex4f(vec.x,vec.y,vec.z,vec.w);edkEnd();
}
void edk::GU::guVertex4f64(edk::vec4f64 vec){
    glVertex4d(vec.x,vec.y,vec.z,vec.w);edkEnd();
}
void edk::GU::guVertex4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    glVertex4f(x,y,z,w);edkEnd();
}
void edk::GU::guVertex4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w){
    glVertex4d(x,y,z,w);edkEnd();
}
void edk::GU::guVertexNormal3f32(edk::vec3f32 vec){
    glNormal3f(vec.x,vec.y,vec.z);edkEnd();
}
void edk::GU::guVertexNormal3f64(edk::vec3f64 vec){
    glNormal3d(vec.x,vec.y,vec.z);edkEnd();
}
void edk::GU::guVertexNormal3f32(edk::float32 x,edk::float32 y,edk::float32 z){
    glNormal3f(x,y,z);edkEnd();
}
void edk::GU::guVertexNormal3f64(edk::float64 x,edk::float64 y,edk::float64 z){
    glNormal3d(x,y,z);edkEnd();
}

// LIGHTING
void edk::GU::guShadeModel( edk::uint32 model ){
    glShadeModel(model);edkEnd();
}
void edk::GU::guLightf32( edk::uint32 light, edk::uint32 pname, edk::float32 param ){
    glLightf(light,pname,param);edkEnd();
}
void edk::GU::guLighti32( edk::uint32 light, edk::uint32 pname, edk::int32 param ){
    glLighti(light,pname,param);edkEnd();
}
void edk::GU::guLightfv32( edk::uint32 light, edk::uint32 pname, const edk::float32 *params ){
    glLightfv(light,pname,params);edkEnd();
}
void edk::GU::guLightiv32( edk::uint32 light, edk::uint32 pname, const edk::int32 *params ){
    glLightiv(light,pname,params);edkEnd();
}
void edk::GU::guGetLightfv32( edk::uint32 light, edk::uint32 pname, edk::float32 *params ){
    glGetLightfv(light,pname,params);edkEnd();
}
void edk::GU::guGetLightiv32( edk::uint32 light, edk::uint32 pname, edk::int32 *params ){
    glGetLightiv(light,pname,params);edkEnd();
}

//MATERIAL
void edk::GU::guMaterialf32( edk::uint32 face, edk::uint32 pname, edk::float32 param ){
    glMaterialf(face,pname,param);edkEnd();
}
void edk::GU::guMateriali32( edk::uint32 face, edk::uint32 pname, edk::int32 param ){
    glMateriali(face,pname,param);edkEnd();
}
void edk::GU::guMaterialfv32( edk::uint32 face, edk::uint32 pname, const edk::float32 *params ){
    glMaterialfv(face,pname,params);edkEnd();
}
void edk::GU::guMaterialiv32( edk::uint32 face, edk::uint32 pname, const edk::int32 *params ){
    glMaterialiv(face,pname,params);edkEnd();
}
void edk::GU::guGetMaterialfv32( edk::uint32 face, edk::uint32 pname, edk::float32 *params ){
    glGetMaterialfv(face,pname,params);edkEnd();
}
void edk::GU::guGetMaterialiv32( edk::uint32 face, edk::uint32 pname, edk::int32 *params ){
    glGetMaterialiv(face,pname,params);edkEnd();
}
void edk::GU::guColorMaterial( edk::uint32 face, edk::uint32 mode ){
    glColorMaterial(face,mode);edkEnd();
}

//DEPTH
void edk::GU::guDepthFunc(edk::uint32 func){
    glDepthFunc( func );edkEnd();
}
void edk::GU::guDepthRange( edk::float64 near_val, edk::float64 far_val ){
    glDepthRange(near_val,far_val);edkEnd();
}

//TEXTURE
void edk::GU::guUseTexture(edk::uint32 target, edk::uint32 texture){
    glBindTexture( target, texture );edkEnd();
}
void edk::GU::guUseTexture1D(edk::uint32 texture){
    glBindTexture( GU_TEXTURE_1D, texture );edkEnd();
}
void edk::GU::guUseTexture2D(edk::uint32 texture){
    glBindTexture( GU_TEXTURE_2D, texture );edkEnd();
}
void edk::GU::guUseTexture3D(edk::uint32 texture){
    glBindTexture( GU_TEXTURE_3D, texture );edkEnd();
}
void edk::GU::guVertexTex1f32(edk::float32 n){
    glTexCoord1f(n);edkEnd();
}
void edk::GU::guVertexTex1f64(edk::float64 n){
    glTexCoord1d(n);edkEnd();
}
void edk::GU::guVertexTex2f32(edk::vec2f32 vec){
    glTexCoord2f(vec.x,vec.y);edkEnd();
}
void edk::GU::guVertexTex2f64(edk::vec2f64 vec){
    glTexCoord2d(vec.x,vec.y);edkEnd();
}
void edk::GU::guVertexTex2f32(edk::float32 x,edk::float32 y){
    glTexCoord2f(x,y);edkEnd();
}
void edk::GU::guVertexTex2f64(edk::float64 x,edk::float64 y){
    glTexCoord2d(x,y);edkEnd();
}
void edk::GU::guVertexTex3f32(edk::vec3f32 vec){
    glTexCoord3f(vec.x,vec.y,vec.z);edkEnd();
}
void edk::GU::guVertexTex3f64(edk::vec3f64 vec){
    glTexCoord3d(vec.x,vec.y,vec.z);edkEnd();
}
void edk::GU::guVertexTex3f32(edk::float32 x,edk::float32 y,edk::float32 z){
    glTexCoord3f(x,y,z);edkEnd();
}
void edk::GU::guVertexTex3f64(edk::float64 x,edk::float64 y,edk::float64 z){
    glTexCoord3d(x,y,z);edkEnd();
}
void edk::GU::guVertexTex4f32(edk::vec4f32 vec){
    glTexCoord4f(vec.x,vec.y,vec.z,vec.w);edkEnd();
}
void edk::GU::guVertexTex4f64(edk::vec4f64 vec){
    glTexCoord4d(vec.x,vec.y,vec.z,vec.w);edkEnd();
}
void edk::GU::guVertexTex4f32(edk::float32 x,edk::float32 y,edk::float32 z,edk::float32 w){
    glTexCoord4f(x,y,z,w);edkEnd();
}
void edk::GU::guVertexTex4f64(edk::float64 x,edk::float64 y,edk::float64 z,edk::float64 w){
    glTexCoord4d(x,y,z,w);edkEnd();
}

//SELET BUFFER
//alloc the buffer
bool edk::GU::guSetSelectionBuffer(edk::uint32 size,edk::uint32* vector){
    if(vector && size){
        glSelectBuffer(size,vector);edkEnd();
        return true;
    }
    return false;
}
//Set renderMode
edk::int32 edk::GU::guRenderMode( edk::uint32 mode){
    return glRenderMode(mode);edkEnd();
}
//init the names
void edk::GU::guInitNames(){
    glInitNames();edkEnd();
}
//push a name
void edk::GU::guPushName(edk::uint32 id){
    glPushName(id);edkEnd();
}
void edk::GU::guPopName(){
    glPopName();edkEnd();
}

//set the pickMatrix
void edk::GU::guPickMatrix(edk::float64  x,  edk::float64  y,  edk::float64  delX,  edk::float64  delY){
    GLint viewport[4];edkEnd();
    glGetIntegerv(GL_VIEWPORT, viewport);edkEnd();
    gluPickMatrix(x,y,delX,delY,viewport);edkEnd();
}

//STRING
//GL_VENDOR
//Returns the company responsible for this GL implementation
edk::char8* edk::GU::guGetVendor(){return (edk::char8*)glGetString(GL_VENDOR);edkEnd();}
//GL_RENDERER
//Returns the name of the renderer
edk::char8* edk::GU::guGetRenderer(){return (edk::char8*)glGetString(GL_RENDERER);edkEnd();}
//GL_VERSION
//Returns a version or release number of the form
edk::char8* edk::GU::guGetVersion(){return (edk::char8*)glGetString(GL_VERSION);edkEnd();}
//GL_EXTENSIONS
//Returns a space-separated list of supported extensions to GL.
edk::char8* edk::GU::guGetExtensions(){return (edk::char8*)glGetString(GL_EXTENSIONS);edkEnd();}
