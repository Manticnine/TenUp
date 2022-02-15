// Copyright (c) 2019 The TENUP developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLTUPWIDGET_H
#define COINCONTROLTUPWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlTupWidget;
}

class CoinControlTupWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlTupWidget(QWidget *parent = nullptr);
    ~CoinControlTupWidget();

private:
    Ui::CoinControlTupWidget *ui;
};

#endif // COINCONTROLTUPWIDGET_H
