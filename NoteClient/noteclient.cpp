#include "noteclient.h"
#include "mysleep.h"
#include <QtGui>
#include <QtWidgets>

#define NOTEFILE_PATH "./note/"
#define CODESEPERATOR "--------CODE--------"

NoteClient::NoteClient(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	createStatusBar();
	setFont(10);
	setCurrentFile("");

	setStyleSheet("QLineEdit { backgroud-color: yellow;}");

	ui.codeLabel->hide();
	ui.codeTextEdit->hide();

	connect(ui.titleLineEdit, SIGNAL(textChanged()), this, SLOT(noteModified()));
	connect(ui.codeTextEdit, SIGNAL(textChanged()), this, SLOT(noteModified()));
	connect(ui.contentTextEdit, SIGNAL(textChanged()), this, SLOT(noteModified()));

	setWindowTitle(tr("%1 - %2  %3").arg(tr("NoteClient")).arg(tr("Version 1.0")).arg(tr("[By Limbo]")));
}

NoteClient::~NoteClient()
{

}

void NoteClient::on_geneButton_clicked() {

	if (ui.titleLineEdit->text().isEmpty()) {
		QMessageBox::warning(this, tr("NoteClient"), tr("Title cannot be empty !"));
		return ;
	}
	if (ui.titleLineEdit->text().contains("/")) {
		QMessageBox::warning(this, tr("NoteClient"), tr("Title cannot contain '/' !"));
		return;
	}
	if (ui.contentTextEdit->toPlainText().isEmpty()) {
		QMessageBox::warning(this, tr("NoteClient"), tr("Content cannot be empty !"));
		return ;
	}
	
	int r;
	if (ui.titleLineEdit->text() == parseFileName2Title(curFile)) { //if the file has existed.
		QMessageBox msgBox;
		msgBox.setText(tr("The file has existed.\n""What do you want to do ?"));
		QPushButton *newButton = msgBox.addButton(tr("CreateNew"), QMessageBox::ActionRole);
		QPushButton *replaceButton = msgBox.addButton(tr("Replace"), QMessageBox::ActionRole);
		QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);

		msgBox.exec();

		if (msgBox.clickedButton() == newButton) {
			// create a new
			r = geneFile("[" + getCurrentDateTime() + "]--" + ui.titleLineEdit->text() + ".txt");
		}
		else if (msgBox.clickedButton() == replaceButton) {
			// replace
			QFile::remove(tr(NOTEFILE_PATH) +"/"+ curFile + ".txt");
			r = geneFile("[" + getCurrentDateTime() + "]--" + ui.titleLineEdit->text() + ".txt");
		}
		else
			return ;
	}
	else {
		r = geneFile("[" + getCurrentDateTime() + "]--" + ui.titleLineEdit->text() + ".txt");
	}

	if (r) {
		QMessageBox::information(this, tr("NoteClient"), tr("Generate Succeed !"));
		triggerStatus(tr("Generate Succeed !"));
	}
	else
		triggerStatus(tr("Generate Failed !"));

}
bool NoteClient::geneFile(const QString &fileName) {

	QDir *dir = new QDir;
	bool exist = dir->exists(tr(NOTEFILE_PATH) + getCurrentYearMonth());
	if (exist) {
		return writeFile(tr(NOTEFILE_PATH) + getCurrentYearMonth() + "/" + fileName);
	}
	else
	{
		bool ok = dir->mkdir(tr(NOTEFILE_PATH) + getCurrentYearMonth());
		if (ok)
			return writeFile(tr(NOTEFILE_PATH) + getCurrentYearMonth() + "/" + fileName);
		return false;
	}
}
bool NoteClient::writeFile(const QString &fileName) {

	QFile file(fileName);

	if (!file.open(QIODevice::WriteOnly)) {
		QMessageBox::warning(this, tr("NoteClient"), tr("Cannot write file %1:\n%2.").arg(file.fileName()).arg(file.errorString()));
		return false;
	}

	QTextStream out(&file);
	out << ui.contentTextEdit->toPlainText() << "\n\n";
	out << CODESEPERATOR << "\n\n" << ui.codeTextEdit->toPlainText();

	setCurrentFile(parseFileName2YMBase(fileName));

	return true;

}
bool NoteClient::readFile(const QString &fileName) {
	QFile file(fileName);

	if (!file.open(QIODevice::ReadOnly)) {
		QMessageBox::warning(this, tr("NoteClient"), tr("Cannot read file %1:\n%2.").arg(file.fileName()).arg(file.errorString()));
		return false;
	}

	clearTextEdit();

	QTextStream in(&file);
	QString content;
	while (!in.atEnd()) {
		content = in.readLine();
		if (content == CODESEPERATOR)
			break;
		ui.contentTextEdit->append(content);
	}
	while (!in.atEnd()) {
		content = in.readLine();
		ui.codeTextEdit->append(content);
	}
	ui.titleLineEdit->setText(parseFileName2Title(QFileInfo(fileName).baseName()));

	setCurrentFile(parseFileName2YMBase(fileName));

	return true;
}
void NoteClient::on_selectFileButton_clicked() {
	QString initialName = NOTEFILE_PATH;
	if (initialName.isEmpty())
		initialName = QDir::homePath();
	QString fileName =
		QFileDialog::getOpenFileName(this, tr("Select File"),
			initialName);

	fileName = QDir::toNativeSeparators(fileName);

	if (!fileName.isEmpty()) {
		if(readFile(fileName))
			triggerStatus(tr("ReadFile Succeed !"));
		else
			triggerStatus(tr("ReadFile Failed !"));
	}
}
void NoteClient::on_clearButton_clicked() {
	clearTextEdit();
}
void NoteClient::createStatusBar(){

	statusLabel = new QLabel;
	statusLabel->setAlignment(Qt::AlignHCenter);
	statusLabel->setMinimumSize(statusLabel->sizeHint());

	statusBar()->addWidget(statusLabel);
}
void NoteClient::setFont(int fontsize) {
	ui.titleLineEdit->setFont(QFont("Timers", fontsize, QFont::Bold));
	ui.contentTextEdit->setFont(QFont("Timers", fontsize));
	ui.codeTextEdit->setFont(QFont("Timers", fontsize));
}
void NoteClient::clearTextEdit() {
	ui.titleLineEdit->clear();
	ui.contentTextEdit->clear();
	ui.codeTextEdit->clear();

	setCurrentFile("");
}
void NoteClient::setCurrentFile(const QString &fileName) {
	curFile = fileName;
	setWindowModified(false);
}
void NoteClient::triggerStatus(const QString &status) {
	
	statusLabel->setText(status);
	mysleep(3000);
	statusLabel->setText(tr(""));

}
QString NoteClient::getCurrentDateTime() { return QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm"); }
QString NoteClient::getCurrentYearMonth(){ return QDateTime::currentDateTime().toString("yyyy-MM"); }
QString NoteClient::parseFileName2Title(const QString &fileName) { //eg: ./note/2016-10/[2016..]--test -> test
	int i;
	for (i = 0; i < fileName.length(); i++)
		if (fileName.at(i) == ']')
			break;
	return fileName.mid(i + 3);
}
QString NoteClient::parseFileName2YMBase(const QString &fileName) {//eg: ./note/2016-10/[2016..]--test.txt -> 2016-10/[2016..]--test
	QFileInfo file(fileName);
	
	QString absoPath = file.absolutePath();
	int i = absoPath.length() - 1;

	for (; i >= 0; i--) {
		if (absoPath.at(i) == '/')
			break;
	}
	return absoPath.mid(i + 1) + "/" + file.baseName();

}
void NoteClient::setCodeButtonText(bool toggled) {
	if (toggled)
		ui.codeButton->setText(tr("Showcode <<"));
	else
		ui.codeButton->setText(tr("Showcode >>"));
}
bool NoteClient::okToContinue(){
	return true;
}
void NoteClient::noteModified() {
	setWindowModified(true);
}
//void NoteClient::resizeEvent(QResizeEvent *) {
//
//	int extraWidth = width() - minimumWidth();
//	int extraHeight = height() - minimumHeight();
//	ui.contentTextEdit->setGeometry(ui.contentTextEdit->x(), ui.contentTextEdit->y(), ui.contentTextEdit->width(), ui.contentTextEdit->width() + extraHeight);
//	ui.geneButton->setGeometry(ui.geneButton->x()+extraWidth, ui.geneButton->y() + extraHeight, ui.geneButton->width(), ui.geneButton->height());
//}
