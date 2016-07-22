#include "UpdateDialog.h"
#include "ui_updatedialog.h"
#include "QSimpleUpdater.h"

UpdateDialog::UpdateDialog(const QString &url, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateDialog),
    updateUrl(url)
{
    ui->setupUi(this);

    setWindowTitle(tr("Update"));
    setFixedSize(540, 390);

    QSimpleUpdater * updater = QSimpleUpdater::getInstance();
    ui->changelog->setText(updater->getChangelog(updateUrl));

    QString title = "<h3>"
                    + tr ("Version %1 of %2 has been released!")
                    .arg (updater->getLatestVersion(url)).arg (updater->getModuleName(url))
                    + "</h3>";
    ui->title->setText(title);
}

UpdateDialog::~UpdateDialog()
{
    delete ui;
}

void UpdateDialog::on_download_clicked()
{
    accept();
}

void UpdateDialog::on_cancel_clicked()
{
    reject();
}
