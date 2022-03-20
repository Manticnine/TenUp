// Copyright (c) 2017-2018 The TenUp developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZTUPCONTROLDIALOG_H
#define ZTUPCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "ztup/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZTupControlDialog;
}

class CZTupControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZTupControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZTupControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZTupControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZTupControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZTupControlDialog(QWidget *parent);
    ~ZTupControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZTupControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZTupControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZTUPCONTROLDIALOG_H
