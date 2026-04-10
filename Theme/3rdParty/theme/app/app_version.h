/****************************************************************************
**
** Copyright (C) 2018 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 as published by the Free Software
** Foundation with exceptions as appearing in the file LICENSE.GPL3-EXCEPT
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
****************************************************************************/

#pragma once

#define IDE_VERSION_MAJOR   4
#define IDE_VERSION_MINOR   15
#define IDE_VERSION_RELEASE 2

/* #undef IDE_REVISION */

namespace Core {
namespace Constants {

const char IDE_VERSION_LONG[] = "4.15.2";
const char IDE_AUTHOR[]       = "The Qt Company Ltd";
const char IDE_YEAR[]         = "2021";

const char IDE_DISPLAY_NAME[] = "Qt Creator";
const char IDE_ID[]           = "qtcreator";
const char IDE_CASED_ID[]     = "QtCreator";

const char IDE_VERSION_DISPLAY[] = "4.15.2";
const char IDE_VERSION_COMPAT[] = "4.15.0";
const char IDE_REVISION_STR[]    = "";
const char IDE_REVISION_URL[] = "";

// changes the path where the settings are saved to
const char IDE_SETTINGSVARIANT_STR[] = "QtProject";
const char IDE_COPY_SETTINGS_FROM_VARIANT_STR[] = "Nokia";

} // Constants
} // Core
