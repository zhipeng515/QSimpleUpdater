#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>

namespace Ui {
class UpdateDialog;
}

class UpdateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateDialog(const QString &url, QWidget *parent = 0);
    ~UpdateDialog();

private slots:
    void on_download_clicked();

    void on_cancel_clicked();

private:
    Ui::UpdateDialog *ui;
    const QString updateUrl;
};

#endif // UPDATEDIALOG_H
