#include "testimonials.h"
#include "ui_testimonials.h"

Testimonials::Testimonials(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testimonials)
{
    ui->setupUi(this);
}

Testimonials::~Testimonials()
{
    delete ui;
}

void Testimonials::on_pushButton_clicked()
{
    QString text = ui->add_testi_edit_box->toPlainText();
    qDebug() << text;
    QListWidget   *TheView = new QListWidget(ui->view_testis);
    QListWidgetItem *thing = new QListWidgetItem(text, TheView);
    TheView->addItem(thing);
    TheView->show();
}
