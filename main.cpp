#include "mainwindow.h"
#include "newmenu.h"
#include <QPushButton>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QHBoxLayout>
#include <QNetworkInterface>
#include <QMessageBox>
#include <QSettings>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator translator;

    QCoreApplication::setOrganizationName("Keep Pixel");
    QCoreApplication::setOrganizationDomain("https://keeppixel.store");
    QCoreApplication::setApplicationName("Apolo");

    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "apolo_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    // QSettings settings("Keep Pixel", "Apolo");
    // QString tr = settings.value("token", "false").toString();
    // QStringList arguments = a.arguments();
    // if (tr == "false"){
    //     if (arguments.count() > 0 && arguments[0]=="token"){
    //         QSettings settings("Keep Pixel", "Apolo");
    //         settings.setValue("token", arguments[1]);
    //         settings.sync();
    //         normal *sWindow = new normal();
     //        sWindow->setWindowState(Qt::WindowFullScreen);
     //        sWindow->show();
     //    }else{

    //     qDebug() << tr;
    // MainWindow *w = new MainWindow();
    // w->setWindowState(Qt::WindowFullScreen);
    // w->show();
     //    }
    // }else{
   //      normal *sWindow = new normal();
    //     sWindow->setWindowState(Qt::WindowFullScreen);
     //    sWindow->show();
    // }

    normal *sWindow = new normal();
       sWindow->setWindowState(Qt::WindowFullScreen);
      sWindow->show();
    return a.exec();
}


