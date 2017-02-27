/**********************************************************************
 *  mainwindow.h
 **********************************************************************
 * Copyright (C) 2016 MX Authors
 *
 * Authors: dolphin_oracle
 *          Adrian
 *          MX Linux <http://mxlinux.org>
 *
 * This file is part of mx-debian-backports-installer
 *
 * mx-debian-backports-installer is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * mx-debian-backports-installer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with mx-debian-backports-installer.  If not, see <http://www.gnu.org/licenses/>.
 **********************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <lockfile.h>

#include <QTreeWidgetItem>
#include <QTimer>
#include <QProgressDialog>
#include <QProgressBar>
#include <QLineEdit>


namespace Ui {
class MainWindow;
}

// struct for outputing both the exit code and the strings when running a command
struct Output {
    int exit_code;
    QString str;
};

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString version;
    QStringList changeset;
    QStringList readMXlist();

    void displayMXlist(QStringList mxlist);
    void displayWarning();
    void start();
    void startProgressBar();
    void stopProgressBar();

    QString getVersion(QString name);
    Output runCmd(QString cmd);

private slots:
    void closeSearch();
    void disableWarning(bool checked);

    void findPackage();
    void procTime();
    void search();
    void on_buttonAbout_clicked();
    void on_buttonCancel_clicked();
    void on_buttonHelp_clicked();
    void on_buttonInstall_clicked();    
    void on_comboFilter_activated(const QString &arg1);
    void on_treeWidget_itemClicked(QTreeWidgetItem *item);          

private:
    LockFile *lock_file;
    QProgressDialog *progress;
    QTimer *timer;
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
