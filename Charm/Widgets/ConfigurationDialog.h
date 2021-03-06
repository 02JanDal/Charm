/*
  ConfigurationDialog.h

  This file is part of Charm, a task-based time tracking application.

  Copyright (C) 2014-2018 Klarälvdalens Datakonsult AB, a KDAB Group company, info@kdab.com

  Author: Frank Osterfeld <frank.osterfeld@kdab.com>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIGURATIONDIALOG_H
#define CONFIGURATIONDIALOG_H

#include <QDialog>

#include "ApplicationCore.h"
#include "Core/Configuration.h"

#include "ui_ConfigurationDialog.h"

class ConfigurationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigurationDialog(const Configuration &, QWidget *parent);
    Configuration configuration() const;

private Q_SLOTS:
    void on_databaseLocationButton_clicked();
    void on_databaseLocation_textChanged(const QString &text);
    void on_nameLineEdit_textChanged(const QString &text);

    void accept() override;

private:
    void checkInput();
    Configuration m_config;
    Ui::ConfigurationDialog m_ui;
};
#endif
