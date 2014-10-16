/*
 *  OS_GL_Wrapper.h
 *
 *  Copyright 2014 Daniel Olsen
 *  Copyright 2011-2012 B9Creations, LLC
 *
 *  This file is part of qPAM
 *
 *    qPAM is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    qPAM is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with qPAM.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

//OpenGL has different headers across different platforms - this header adjusts acourdingly
//When you need to use openGL, include this header.

#ifndef OS_GL_WRAPPER_H
#define OS_GL_WRAPPER_H

    #ifdef Q_OS_LINUX
        #include <GL/gl.h>
        #include <GL/glu.h>
    #endif

    #ifdef Q_OS_MACX
        #include <OpenGL/gl.h>
        #include <OpenGL/glu.h>
    #endif

    #ifdef Q_OS_WIN
        #include <GL/gl.h>
        #include <GL/glu.h>
    #endif

#endif // OS_GL_WRAPPER_H
