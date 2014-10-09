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
    MainWindow.cpp \
    LogFileManager.cpp \
    LoadingBar.cpp \
    CrushBitmap.cpp \
    Terminal.cpp \
    PrinterComm.cpp \
    Projector.cpp \
    Edit/SliceEditView.cpp \
    Edit/FloodFill.cpp \
    Edit/DrawingContext.cpp \
    Edit/Edit.cpp \
    Edit/AboutBox.cpp \
    HelpSystem.cpp \
    NativeApp.cpp \
    DlgCycleSettings.cpp \
    DlgMaterialsManager.cpp \
    MatCat.cpp \
    Print.cpp \
    Layout/WorldView.cpp \
    Layout/Triangle3d.cpp \
    Layout/SliceSet.cpp \
    Layout/SliceContext.cpp \
    Layout/Slice.cpp \
    Layout/SliceExporter.cpp \
    Layout/Segment.cpp \
    Layout/ModelData.cpp \
    Layout/Loop.cpp \
    Layout/Layout.cpp \
    b9slice/b9slice.cpp \
    DlgPrintPrep.cpp \
    OS_Wrapper_Functions.cpp \
    ScreenSaverWaker.cpp \
    Material.cpp \
    PrinterModelData.cpp \
    PrinterModelManager.cpp \
    UpdateManager.cpp \
    ModelLoader.cpp \
    Layout/LayoutProjectData.cpp \
    Layout/ModelInstance.cpp \
    SupportStructure.cpp \
    Layout/GeometricFunctions.cpp \
    Layout/VerticalTricontainer.cpp \
    ModelWriter.cpp \
    DlgCalBuildTable.cpp \
    DlgCalProjector.cpp \
    Layout/Tesselator.cpp

HEADERS += mainwindow.h \
    LogFileManager.h \
    LoadingBar.h \
    CrushBitmap.h \
    Terminal.h \
    PrinterComm.h \
    Projector.h \
    Edit/SliceEditView.h \
    Edit/FloodFill.h \
    Edit/DrawingContext.h \
    Edit/Edit.h \
    Edit/AboutBox.h \
    HelpSystem.h \
    NativeApp.h \
    DlgCycleSettings.h \
    DlgMaterialsManager.h \
    MatCat.h \
    Print.h \
    Layout/WorldView.h \
    Layout/Triangle3d.h \
    Layout/SliceSet.h \
    Layout/SliceContext.h \
    Layout/Slice.h \
    Layout/SliceExporter.h \
    Layout/Segment.h \
    Layout/ModelData.h \
    Layout/Loop.h \
    OS_GL_Wrapper.h \
    Layout/Layout.h \
    b9slice/b9slice.h \
    DlgPrintPrep.h \
    OS_Wrapper_Functions.h \
    ScreenSaverWaker.h \
    Material.h \
    PrinterModelData.h \
    PrinterModelManager.h \
    UpdateManager.h \
    UpdateEntry.h \
    ModelLoader.h \
    Layout/LayoutProjectData.h \
    Layout/ModelInstance.h \
    SupportStructure.h \
    Layout/GeometricFunctions.h \
    Layout/VerticalTricontainer.h \
    ModelWriter.h \
    DlgCalBuildTable.h \
    DlgCalProjector.h \
    Layout/Tesselator.h

FORMS += MainWindow.ui \
    Terminal.ui \
    Edit/SliceEditView.ui \
    Edit/Edit.ui \
    Edit/AboutBox.ui \
    b9slice/b9slice.ui \
    DlgCycleSettings.ui \
    DlgMaterialsManager.ui \
    Print.ui \
    Layout/SliceDebugWindow.ui \
    Layout/3dMain.ui \
    DlgPrintPrep.ui \
    DlgCalBuildTable.ui \
    DlgCalProjector.ui

RESOURCES += \
    Edit/Edit.qrc \
    Edit/SliceEditView.qrc

include(qextserialport-1.2beta2/src/qextserialport.pri)

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
