#-------------------------------------------------
#
# Project created by QtCreator 2012-10-29T17:44:17
#
#-------------------------------------------------

#************************************************************************************
#
#  LICENSE INFORMATION
#
#  BCreator(tm)
#  Software for the control of the 3D Printer, "B9Creator"(tm)
#
#  Copyright 2011-2012 B9Creations, LLC
#  B9Creations(tm) and B9Creator(tm) are trademarks of B9Creations, LLC
#
#  This file is part of B9Creator
#
#    B9Creator is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    B9Creator is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with B9Creator .  If not, see <http://www.gnu.org/licenses/>.
#
#  The above copyright notice and this permission notice shall be
#    included in all copies or substantial portions of the Software.
#
#    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
#    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
#    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
#    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
#    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
#    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#
#*************************************************************************************

QT       += core gui
QT       += svg
QT       += opengl
QT       += network

TEMPLATE = app

INCLUDEPATH += b9slice
INCLUDEPATH += Edit
INCLUDEPATH += b9create

SOURCES += main.cpp\
        mainwindow.cpp \
    logfilemanager.cpp \
    loadingbar.cpp \
    crushbitmap.cpp \
    b9terminal.cpp \
    b9printercomm.cpp \
    b9projector.cpp \
    Edit/SliceEditView.cpp \
    Edit/FloodFill.cpp \
    Edit/DrawingContext.cpp \
    Edit/Edit.cpp \
    Edit/AboutBox.cpp \
    helpsystem.cpp \
    b9nativeapp.cpp \
    dlgcyclesettings.cpp \
    dlgmaterialsmanager.cpp \
    b9matcat.cpp \
    b9print.cpp \
    b9layout/WorldView.cpp \
    b9layout/Triangle3d.cpp \
    b9layout/SliceSet.cpp \
    b9layout/SliceContext.cpp \
    b9layout/Slice.cpp \
    b9layout/SliceExporter.cpp \
    b9layout/Segment.cpp \
    b9layout/ModelData.cpp \
    b9layout/Loop.cpp \
    b9layout/Layout.cpp \
    b9slice/b9slice.cpp \
    dlgprintprep.cpp \
    OS_Wrapper_Functions.cpp \
    screensaverwaker.cpp \
    b9material.cpp \
    b9printermodeldata.cpp \
    b9printermodelmanager.cpp \
    b9updatemanager.cpp \
    b9modelloader.cpp \
    b9layout/LayoutProjectData.cpp \
    b9layout/ModelInstance.cpp \
    b9supportstructure.cpp \
    b9layout/GeometricFunctions.cpp \
    b9layout/VerticalTricontainer.cpp \
    b9modelwriter.cpp \
    dlgcalbuildtable.cpp \
    dlgcalprojector.cpp \
    b9layout/Tesselator.cpp

HEADERS  += mainwindow.h \
    logfilemanager.h \
    loadingbar.h \
    crushbitmap.h \
    b9terminal.h \
    b9printercomm.h \
    b9projector.h \
    Edit/SliceEditView.h \
    Edit/FloodFill.h \
    Edit/DrawingContext.h \
    Edit/Edit.h \
    Edit/AboutBox.h \
    helpsystem.h \
    b9nativeapp.h \
    dlgcyclesettings.h \
    dlgmaterialsmanager.h \
    b9matcat.h \
    b9print.h \
    b9layout/WorldView.h \
    b9layout/Triangle3d.h \
    b9layout/SliceSet.h \
    b9layout/SliceContext.h \
    b9layout/Slice.h \
    b9layout/SliceExporter.h \
    b9layout/Segment.h \
    b9layout/ModelData.h \
    b9layout/Loop.h \
    OS_GL_Wrapper.h \
    b9layout/Layout.h \
    b9slice/b9slice.h \
    dlgprintprep.h \
    OS_Wrapper_Functions.h \
    screensaverwaker.h \
    b9material.h \
    b9printermodeldata.h \
    b9printermodelmanager.h \
    b9updatemanager.h \
    b9updateentry.h \
    b9modelloader.h \
    b9layout/LayoutProjectData.h \
    b9layout/ModelInstance.h \
    b9supportstructure.h \
    b9layout/GeometricFunctions.h \
    b9layout/VerticalTricontainer.h \
    b9modelwriter.h \
    dlgcalbuildtable.h \
    dlgcalprojector.h \
    b9layout/Tesselator.h

FORMS    += mainwindow.ui \
    b9terminal.ui \
    Edit/SliceEditView.ui \
    Edit/Edit.ui \
    Edit/AboutBox.ui \
    b9slice/b9slice.ui \
    dlgcyclesettings.ui \
    dlgmaterialsmanager.ui \
    b9print.ui \
    b9layout/SliceDebugWindow.ui \
    b9layout/3dMain.ui \
    dlgprintprep.ui \
    dlgcalbuildtable.ui \
    dlgcalprojector.ui

RESOURCES += \
    Edit/Edit.qrc \
    Edit/SliceEditView.qrc

include(qextserialport-1.2beta2/src/qextserialport.pri)

OTHER_FILES += \
    documentation/wildcardmatching.html \
    documentation/b9creator.qhp \
    documentation/b9creator.qhcp \
    documentation/b9creator.qhc \
    documentation/b9creator.qch \
    documentation/openfile.html \
    documentation/intro.html \
    documentation/index.html \
    documentation/findfile.html \
    documentation/filedialog.html \
    documentation/browse.html \
    documentation/about.txt \
    documentation/images/wildcard.png \
    documentation/images/open.png \
    documentation/images/mainwindow.png \
    documentation/images/icon.png \
    documentation/images/handbook.png \
    documentation/images/filedialog.png \
    documentation/images/fadedfilemenu.png \
    documentation/images/browse.png



#Windows Specifics-------------------------------------------------------------


win32{

#Recource File For Windows
#Includes information for app icon
RC_FILE = WindowsResources/b9c_win_resources.rc

#In windows this application needs elevated privileges to do self updates.
QMAKE_LFLAGS += /MANIFESTUAC:\"level=\'requireAdministrator\' uiAccess=\'false\'\"

TARGET = B9Creator


}


#Mac Specifics-------------------------------------------------------------

macx{

#Application Icon For Mac
ICON = MacResources/b9c_icon.icns

#Slightly Different Executable name
TARGET = B9Creator

CONFIG -= x86_64

#Mac CoreLibrary Functions
macx: LIBS += -framework CoreServices


}


#Linux Specifics-------------------------------------------------------------
unix:!macx: TARGET = B9Creator

unix:!macx: LIBS += -lGLU
unix:!macx: LIBS += -lz


