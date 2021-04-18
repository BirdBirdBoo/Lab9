#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    setUpInputs();
}

MainWindow::~MainWindow() {
    for (Collection *c : collections) {
        free(c);
    }
    collections.clear();

    delete ui;
}

void MainWindow::setUpInputs() {
    ui->elementLineEdit->setValidator(new QIntValidator(INT32_MIN, INT32_MAX, this));
    ui->indexLineEdit->setValidator(new QIntValidator(0, INT32_MAX, this));

    setIndexEditorEnabled(false);
    setAddElementEnabled(false);
}

void MainWindow::on_addArrayButton_clicked() {
    auto *newArray = new Array();
    collections.push_back(newArray);
    handleCollectionAdded(*newArray);
}

void MainWindow::on_addSetButton_clicked() {
    auto *newSet = new Set();
    collections.push_back(newSet);
    handleCollectionAdded(*newSet);
}

void MainWindow::on_collectionList_currentRowChanged(int currentRow) {
    if (currentRow == -1) {
        setAddElementEnabled(false);
        setIndexEditorEnabled(false);
        return;
    }

    Collection *currentItem = collections[currentRow];
    bool isAppendable = dynamic_cast<Appendable *>(currentItem) != nullptr;
    bool isArray = dynamic_cast<Array *>(currentItem) != nullptr;

    setAddElementEnabled(isAppendable);
    setIndexEditorEnabled(isArray);
}

void MainWindow::on_addButton_clicked() {
    int row = ui->collectionList->currentRow();
    if (ui->elementLineEdit->hasAcceptableInput() && row != -1) {
        auto *appendable = dynamic_cast<Appendable *>(collections[row]);

        if (appendable != nullptr) {
            int element = ui->elementLineEdit->text().toInt();
            appendable->add(element);

            handleCollectionChanged(row);
        }
    }
}

void MainWindow::on_setButton_clicked() {
    int row = ui->collectionList->currentRow();
    if (ui->elementLineEdit->hasAcceptableInput() && ui->indexLineEdit->hasAcceptableInput() && row != -1) {
        auto *array = dynamic_cast<Array *>(collections[row]);

        if (array != nullptr) {
            int element = ui->elementLineEdit->text().toInt();
            size_t index = ui->indexLineEdit->text().toULongLong();

            if (index >= array->getLength()) {
                QMessageBox::critical(this,
                                      "Error",
                                      "Index is out of bounds!");
                return;
            }
            array->set(index, element);

            handleCollectionChanged(row);
        }
    }
}

void MainWindow::handleCollectionAdded(Collection &collection) {
    ui->collectionList->addItem(QString::fromStdString(collection.toString()));
}

void MainWindow::handleCollectionChanged(int index) {
    ui->collectionList->item(index)->setText(QString::fromStdString(collections[index]->toString()));
}

void MainWindow::setAddElementEnabled(bool enabled) {
    ui->elementLabel->setEnabled(enabled);
    ui->elementLineEdit->setEnabled(enabled);
    ui->addButton->setEnabled(enabled);
}

void MainWindow::setIndexEditorEnabled(bool enabled) {
    ui->indexLabel->setEnabled(enabled);
    ui->indexLineEdit->setEnabled(enabled);
    ui->setButton->setEnabled(enabled);
}

