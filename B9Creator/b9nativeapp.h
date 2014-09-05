/*************************************************************************************
//
//  LICENSE INFORMATION
//
//  BCreator(tm)
//  Software for the control of the 3D Printer, "B9Creator"(tm)
//
//  Copyright 2011-2012 B9Creations, LLC
//  B9Creations(tm) and B9Creator(tm) are trademarks of B9Creations, LLC
//
//  This file is part of B9Creator
//
//    B9Creator is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    B9Creator is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with B9Creator .  If not, see <http://www.gnu.org/licenses/>.
//
//  The above copyright notice and this permission notice shall be
//    included in all copies or substantial portions of the Software.
//
//    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
//    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
//    LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//    OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
//    WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//
*************************************************************************************/

#ifndef B9NATIVEAPP_H
#define B9NATIVEAPP_H

#include <QApplication>
#include "mainwindow.h"
#include "OS_Wrapper_Functions.h"

class B9NativeApp : public QApplication
{
public:
    B9NativeApp(int &argc, char **argv) : QApplication(argc, argv)
    {

        mainWindow = new MainWindow;
        this->argc = argc;

        for(int i = 0; i < argc; i++)
            this->argv.push_back(QString::fromAscii(argv[i]));

    }
    ~B9NativeApp()
    {
        delete mainWindow;
    }

    void ProccessArguments()
    {
    #ifdef Q_OS_WIN
        if(argc > 1)
        {
            QString openFile;
            //sometimes a file might not be incased in qoutes ""
            for(int i = 1; i < argc; i++)
            {
                openFile += argv[i];
                openFile += " ";
            }
            openFile = openFile.trimmed();


            if(QFileInfo(openFile).completeSuffix().toLower() == "b9l")
            {
                mainWindow->OpenLayoutFile(openFile);
            }
            else if(QFileInfo(openFile).completeSuffix().toLower() == "b9j")
            {
                mainWindow->OpenJobFile(openFile);
            }
        }
    #endif

    }




    MainWindow* mainWindow;



    virtual bool notify(QObject *receiver, QEvent *event)
    {
        if (event->type() == QEvent::Polish &&
            receiver &&
            receiver->isWidgetType())
        {
            set_smaller_text_osx(reinterpret_cast<QWidget *>(receiver));
        }

        return QApplication::notify(receiver, event);
    }
private:

    int argc;
    QStringList argv;


    void set_smaller_text_osx(QWidget *w);



protected:
   bool event(QEvent * event);//For Mac Os X file associations.


};

#endif // B9NATIVEAPP_H
