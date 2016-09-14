/**********************************************************************
 *  lockfile.h
**********************************************************************
* Copyright (C) 2016 MX Authors
*
* Authors: dolphin_oracle
*          Adrian
*          MX & MEPIS Community <http://forum.mepiscommunity.org>
*
* This file is part of mx-debian-backports-installer
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* mx-test-repo-installer is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with mx-test-repo-installer.  If not, see <http://www.gnu.org/licenses/>.
**********************************************************************/

#ifndef LOCKFILE_H
#define LOCKFILE_H

#include <QString>
#include <QFile>


class LockFile
{
public:
    LockFile(QString fileName);

    bool isLocked();
    bool lock();
    bool unlock();

private:
    QString file_name;
    int fd;

};

#endif // LOCKFILE_H
