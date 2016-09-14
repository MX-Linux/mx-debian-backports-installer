/**********************************************************************
 *  lockfile.cpp
**********************************************************************
* Copyright (C) 2016 MX Authors
*
* Authors: dolphin_oracle
*          Adrian
*          MX & MEPIS Community <http://forum.mepiscommunity.org>
*
* This file is part of mx-debian-backports-installer
*
* mx-test-repo-installer is free software: you can redistribute it and/or modify
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


#include "lockfile.h"
#include <unistd.h>
#include <sys/file.h>

#include <QDebug>

LockFile::LockFile(QString file_name)
{
    this->file_name = file_name;
}

//checks if file is locked by another process (if locked by the same process returns false)
bool LockFile::isLocked()
{
    fd = open(file_name.toUtf8(), O_RDONLY);
    if(fd < -1) {
        perror("open");
        return false;
    }
    return (lockf(fd, F_TEST, 0) != 0);
}

bool LockFile::lock()
{
    fd = open(file_name.toUtf8(), O_WRONLY);
    if(fd < -1) {
        perror("open");
        return false;
    }
    // create a file lock
    return(lockf(fd, F_LOCK, 0) == 0);
}

bool LockFile::unlock()
{
    fd = open(file_name.toUtf8(), O_WRONLY);
    close(fd);
    return true;
}
